/*
 * Handling of common block commands
 *
 * Copyright (c) 2017 Google, Inc
 *
 * (C) Copyright 2000-2011
 * Wolfgang Denk, DENX Software Engineering, wd@denx.de.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <blk.h>

#ifdef HAVE_BLOCK_DEVICE

static int get_part_blk_cnt(char*part_name, ulong *blk, ulong *cnt, ulong *blksz)
{
	struct blk_desc *dev_desc;
	disk_partition_t part;
	extern struct blk_desc *rockchip_get_bootdev(void);
	dev_desc = rockchip_get_bootdev();
	if (dev_desc == NULL)
		return -1;
	
	if (part_get_info_by_name(dev_desc, part_name, &part) < 0)
	{
		 printf("No %s partition\n", part_name);
		 return -1;
	}

	*blk = part.start;
	*cnt = part.size;
	if (blksz != NULL)
	{
		*blksz = part.blksz;
	}
	
	return 0;
}

int blk_common_cmd(int argc, char * const argv[], enum if_type if_type,
		   int *cur_devnump)
{
	const char *if_name = blk_get_if_type_name(if_type);
	int ret;
	switch (argc) {
	case 0:
	case 1:
		return CMD_RET_USAGE;
	case 2:
		if (strncmp(argv[1], "inf", 3) == 0) {
			blk_list_devices(if_type);
			return 0;
		} else if (strncmp(argv[1], "dev", 3) == 0) {
			if (blk_print_device_num(if_type, *cur_devnump)) {
				printf("\nno %s devices available\n", if_name);
				return CMD_RET_FAILURE;
			}
			return 0;
		} else if (strncmp(argv[1], "part", 4) == 0) {
			if (blk_list_part(if_type))
				printf("\nno %s devices available\n", if_name);
			return 0;
		}
		return CMD_RET_USAGE;
	case 3:
/*
		if (strncmp(argv[1], "dev", 3) == 0) {
			int dev = (int)simple_strtoul(argv[2], NULL, 10);

			if (!blk_show_device(if_type, dev)) {
				*cur_devnump = dev;
				printf("... is now current device\n");
			} else {
				return CMD_RET_FAILURE;
			}
			return 0;
		} else if (strncmp(argv[1], "part", 4) == 0) {
			int dev = (int)simple_strtoul(argv[2], NULL, 10);

			if (blk_print_part_devnum(if_type, dev)) {
				printf("\n%s device %d not available\n",
				       if_name, dev);
				return CMD_RET_FAILURE;
			}
			return 0;
		}
*/
		//return CMD_RET_USAGE;

	default: /* at least 4 args */
		if (strncmp(argv[1], "read", 4) == 0) {
			ulong addr = simple_strtoul(argv[2], NULL, 16);
			lbaint_t blk = 0;
			ulong cnt = 0;
			ulong n = 0;
			if (strstr(argv[1], ".part") != NULL)
			{
				image_header_t *legacy_header = (image_header_t *)addr;
				ulong blksz = 0;
				ret = get_part_blk_cnt(argv[3], &blk, &cnt, &blksz);
				if (ret != 0)
				{
					return ret;
				}
				n = blk_read_devnum(if_type, *cur_devnump, blk, 1,
							(ulong *)addr);
				// reduce read num for Legacy Image
				if (htonl(legacy_header->ih_magic) == 0x27051956)
				{
					cnt = htonl(legacy_header->ih_size) / blksz + 2;
				}

			}
			else
			{
				blk = simple_strtoul(argv[3], NULL, 16);
				cnt = simple_strtoul(argv[4], NULL, 16);
			}
			printf("\n%s read: device %d block # "LBAFU", count %lu ... ",
				   if_name, *cur_devnump, blk, cnt);
			
			n = blk_read_devnum(if_type, *cur_devnump, blk, cnt,
						(ulong *)addr);
			printf("%ld blocks read: %s\n", n,
			       n == cnt ? "OK" : "ERROR");
			return n == cnt ? 0 : 1;
		} else if (strncmp(argv[1], "write", 5) == 0) {
			ulong addr = simple_strtoul(argv[2], NULL, 16);
			lbaint_t blk = 0;
			ulong cnt = 0; 
			ulong n;

			if (strstr(argv[1], ".part") != NULL)
			{
				ret = get_part_blk_cnt(argv[3], &blk, &cnt, NULL);
				if (ret != 0)
				{
					return ret;
				}
			}
			else
			{
				blk = simple_strtoul(argv[3], NULL, 16);
				cnt = simple_strtoul(argv[4], NULL, 16);
			}
			
			printf("\n%s write: device %d block # "LBAFU", count %lu ... ",
			       if_name, *cur_devnump, blk, cnt);

			n = blk_write_devnum(if_type, *cur_devnump, blk, cnt,
					     (ulong *)addr);

			printf("%ld blocks written: %s\n", n,
			       n == cnt ? "OK" : "ERROR");
			return n == cnt ? 0 : 1;
		} else if (strncmp(argv[1], "erase", 5) == 0) {
			lbaint_t blk = 0;
			ulong cnt = 0;
			ulong n;
			printf("start to erase!!!\n");
			if (strstr(argv[1], ".part") != NULL)
			{
				ret = get_part_blk_cnt(argv[2], &blk, &cnt, NULL);
				if (ret != 0)
				{
					return ret;
				}
			}
			else
			{
				blk = simple_strtoul(argv[2], NULL, 16);
				cnt = simple_strtoul(argv[3], NULL, 16);
			}
			printf("\n%s erase: device %d block # "LBAFU", count %lu ... ",
			       if_name, *cur_devnump, blk, cnt);

			n = blk_erase_devnum(if_type, *cur_devnump, blk, cnt);

			printf("%ld blocks erased: %s\n", n,
			       n == cnt ? "OK" : "ERROR");
			return n == cnt ? 0 : 1;
		} else {
			return CMD_RET_USAGE;
		}
	}
}
#endif
