// SPDX-License-Identifier: GPL-2.0
/*
 * Copyright (c) 2019 Fuzhou Rockchip Electronics Co., Ltd
 */

#include <common.h>
#include <blk.h>
#include <boot_rkimg.h>
#include <dm.h>
#include <errno.h>
#include <image.h>
#include <malloc.h>
#include <mtd_blk.h>
#include <part.h>
#include <spl.h>
#include <spl_ab.h>
#include <spl_rkfw.h>
#include <asm/u-boot.h>
#include <dm/device-internal.h>
#include <linux/compiler.h>
#include <linux/mtd/mtd.h>

typedef struct {
	uint32_t header;	/* verify header: 0x12345678 */
	uint32_t len;		/* fdt len */
	uint32_t crc;		/* crc32 verify */
	char fdt[];			/* fdt data */
} Verify_INFO;
static char *g_fdt_addr = NULL;

static int spl_mtd_get_device_index(u32 boot_device)
{
	switch (boot_device) {
	case BOOT_DEVICE_MTD_BLK_NAND:
		return 0;
	case BOOT_DEVICE_MTD_BLK_SPI_NAND:
		return 1;
	case BOOT_DEVICE_MTD_BLK_SPI_NOR:
		return 2;
	}

#ifdef CONFIG_SPL_LIBCOMMON_SUPPORT
	printf("spl: unsupported mtd boot device.\n");
#endif

	return -ENODEV;
}

struct blk_desc *find_mtd_device(int dev_num)
{
	struct udevice *dev;
	struct blk_desc *desc;
	int ret;

	ret = blk_find_device(IF_TYPE_MTD, dev_num, &dev);

	if (ret) {
#if !defined(CONFIG_SPL_BUILD) || defined(CONFIG_SPL_LIBCOMMON_SUPPORT)
		printf("MTD Device %d not found\n", dev_num);
#endif
		return NULL;
	}

	ret = device_probe(dev);
	if (ret) {
#if !defined(CONFIG_SPL_BUILD) || defined(CONFIG_SPL_LIBCOMMON_SUPPORT)
		printf("MTD Device %d not found\n", dev_num);
#endif
		return NULL;
	}

	desc = dev_get_uclass_platdata(dev);
	if (!desc)
		return NULL;

	return desc;
}

static ulong mtd_spl_load_read(struct spl_load_info *load, ulong sector,
			       ulong count, void *buf)
{
	struct blk_desc *desc = load->dev;

	return blk_dread(desc, sector, count, buf);
}

#ifdef CONFIG_SPL_LOAD_RKFW
int spl_mtd_load_rkfw(struct spl_image_info *spl_image, struct blk_desc *desc)
{
	struct spl_load_info load;
	int ret;

	load.dev = desc;
	load.priv = NULL;
	load.filename = NULL;
	load.bl_len = desc->blksz;
	load.read = mtd_spl_load_read;

	ret = spl_load_rkfw_image(spl_image, &load);
	if (ret) {
#ifdef CONFIG_SPL_LIBCOMMON_SUPPORT
		puts("spl_mtd_load_rkfw: mtd block read error\n");
#endif
		return -1;
	}

	return 0;
}
#endif

int spl_mtd_load_image(struct spl_image_info *spl_image,
		       struct spl_boot_device *bootdev)
{
	struct image_header *header;
	struct blk_desc *desc;
	int ret = -1;
	lbaint_t image_sector = CONFIG_MTD_BLK_U_BOOT_OFFS;

	desc = find_mtd_device(spl_mtd_get_device_index(bootdev->boot_device));
	if (!desc)
		return -ENODEV;

#ifdef CONFIG_SPL_LIBDISK_SUPPORT
	disk_partition_t info;

	mtd_blk_map_partitions(desc);
	ret = part_get_info_by_name(desc, PART_UBOOT, &info);
	if (ret > 0)
		image_sector = info.start;

#endif
	if (IS_ENABLED(CONFIG_SPL_LOAD_FIT)) {
		header = (struct image_header *)(CONFIG_SYS_TEXT_BASE -
					 sizeof(struct image_header));
		ret = blk_dread(desc, image_sector, 1, header);
		if (ret != 1)
			return -ENODEV;

#ifdef CONFIG_SPL_FIT_IMAGE_MULTIPLE
		if (image_get_magic(header) == FDT_MAGIC ||
		    CONFIG_SPL_FIT_IMAGE_MULTIPLE > 1) {
#else
		if (image_get_magic(header) == FDT_MAGIC) {
#endif
			struct spl_load_info load;

			load.dev = desc;
			load.priv = NULL;
			load.filename = NULL;
			load.bl_len = desc->blksz;
			load.read = mtd_spl_load_read;

			ret = spl_load_simple_fit(spl_image, &load,
						  image_sector,
						  header);
		}
	}

	if (!ret)
		return 0;

	if (IS_ENABLED(CONFIG_SPL_LOAD_RKFW)) {
#ifdef CONFIG_SPL_LOAD_RKFW
		ret = spl_mtd_load_rkfw(spl_image, desc);
#endif
	}

	return ret;
}

#ifdef CONFIG_ENABLE_LEGARCY
int spl_mtd_load_kernel_image(struct spl_image_info *spl_image,
			   struct spl_boot_device *bootdev, struct blk_desc *desc_tmp)
{
	struct image_header *legacy_header;
	struct blk_desc *desc;
	int ret = -1;
	lbaint_t image_sector = CONFIG_MTD_BLK_U_BOOT_OFFS;
	/* Avoid conflicts between the decompressed address and the current address, */
	/* which will slow down the startup speed. */
	long os_addr =  0x800000;
	int cnt;

	if (desc_tmp != NULL)
	{
		desc = desc_tmp;
	}
	else
	{
		desc = find_mtd_device(spl_mtd_get_device_index(bootdev->boot_device));
		if (!desc)
			return -ENODEV;
	}

	disk_partition_t info = {0};

	ret = part_get_info_by_name(desc, PART_BOOT, &info);
	if (ret > 0)
		image_sector = info.start;

	/* load legacy image*/
	legacy_header = (struct image_header *)(CONFIG_SYS_TEXT_BASE - sizeof(struct image_header));

	ret = blk_dread(desc, image_sector, 1, legacy_header);
	if (ret != 1)
		return -ENODEV;

	/* legacy_hader */
	if (legacy_header->ih_magic != htonl(0x27051956))
	{
		return 0;
	}

	/* read legacy and fdt */
	memcpy((char*)os_addr, ((char*)legacy_header + sizeof(struct image_header)), desc->blksz - sizeof(struct image_header));
	cnt = (htonl(legacy_header->ih_size) + sizeof(struct image_header) - 1 ) / desc->blksz;
	blk_dread(desc, image_sector+1, cnt, (char *)os_addr + desc->blksz - sizeof(struct image_header));

	spl_image->name = "Linux";
	spl_image->os = IH_OS_LINUX;
	spl_image->load_addr   = os_addr;
	spl_image->entry_point = os_addr;
	spl_image->entry_point_os = os_addr;
	spl_image->fdt_addr = (void*)g_fdt_addr;
	return 0;
}

int bool_jump_uboot = 0;
int spl_mtd_load_image_select(struct spl_image_info *spl_image,
			  struct spl_boot_device *bootdev)
{
	if (bool_jump_uboot)
	{
		goto uboot;
	}

	disk_partition_t info = {0};
	struct blk_desc *desc;
	Verify_INFO *verify_info = (Verify_INFO *)(0xc00000);
	int ret = 0;
	int rest_len = 0;

	
	desc = find_mtd_device(spl_mtd_get_device_index(bootdev->boot_device));
	if (!desc)
	{
		printf("%s find_mtd_device failed!\n", __func__);
		goto uboot;
	}

	ret = part_get_info_by_name(desc, PART_VERIFY, &info);
	if (!ret)
	{
		printf("%s part_get_info_by_name %s failed!\n", __func__, PART_VERIFY);
		goto uboot;
	}
	

	blk_dread(desc, info.start, 1, (char*)verify_info);
	if (verify_info->header != 0x12345678)
	{
		printf("%s verify_info->header is invalid %x!\n", __func__, verify_info->header);
		goto uboot;
	}
	
	if (verify_info->len > (info.size * info.blksz))
	{
		printf("%s verify_info->len is too large %u!\n", __func__, verify_info->len);
		goto uboot;
	}

	rest_len = verify_info->len - info.blksz;
	/* read rest data */
	if (rest_len > 0)
	{
		rest_len = ((rest_len + info.blksz - 1) / info.blksz);
		blk_dread(desc, info.start + 1, rest_len, (char*)verify_info + info.blksz);
	}

	/* crc check */
#if 0
	if (verify_info->crc != crc32(0xFFFFFFFF, (unsigned char*)verify_info->fdt, verify_info->len))
	{
		printf("%s verify_info->crc check failed!\n", __func__);
		goto uboot;
	}
#endif
	g_fdt_addr = verify_info->fdt;

	return spl_mtd_load_kernel_image(spl_image, bootdev, desc);

uboot:
	return spl_mtd_load_image(spl_image, bootdev);
}
#endif


SPL_LOAD_IMAGE_METHOD("MTD0", 0, BOOT_DEVICE_MTD_BLK_NAND, spl_mtd_load_image);

#ifdef CONFIG_ENABLE_LEGARCY
SPL_LOAD_IMAGE_METHOD("MTD1", 0, BOOT_DEVICE_MTD_BLK_SPI_NAND, spl_mtd_load_image_select);
#else
SPL_LOAD_IMAGE_METHOD("MTD1", 0, BOOT_DEVICE_MTD_BLK_SPI_NAND, spl_mtd_load_image);
#endif

SPL_LOAD_IMAGE_METHOD("MTD2", 0, BOOT_DEVICE_MTD_BLK_SPI_NOR, spl_mtd_load_image);
