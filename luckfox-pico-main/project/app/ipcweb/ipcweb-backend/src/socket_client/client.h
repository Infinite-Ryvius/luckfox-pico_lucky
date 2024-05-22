// isp
int rk_isp_set(const char *json);
int rk_isp_get_scenario(int cam_id, char **value);
int rk_isp_set_scenario(int cam_id, const char *value);
// isp adjustment
int rk_isp_get_contrast(int cam_id, int *value);
int rk_isp_set_contrast(int cam_id, int value);
int rk_isp_get_brightness(int cam_id, int *value);
int rk_isp_set_brightness(int cam_id, int value);
int rk_isp_get_saturation(int cam_id, int *value);
int rk_isp_set_saturation(int cam_id, int value);
int rk_isp_get_sharpness(int cam_id, int *value);
int rk_isp_set_sharpness(int cam_id, int value);
int rk_isp_get_hue(int cam_id, int *value);
int rk_isp_set_hue(int cam_id, int value);
// isp exposure
int rk_isp_get_exposure_mode(int cam_id, char **value);
int rk_isp_set_exposure_mode(int cam_id, const char *value);
int rk_isp_get_gain_mode(int cam_id, char **value);
int rk_isp_set_gain_mode(int cam_id, const char *value);
int rk_isp_get_exposure_time(int cam_id, char **value);
int rk_isp_set_exposure_time(int cam_id, const char *value);
int rk_isp_get_exposure_gain(int cam_id, int *value);
int rk_isp_set_exposure_gain(int cam_id, int value);
int rk_isp_get_frame_rate(int cam_id, int *value);
int rk_isp_set_frame_rate(int cam_id, int value);
// night_to_day
int rk_isp_get_night_to_day(int cam_id, char **value);
int rk_isp_set_night_to_day(int cam_id, const char *value);
int rk_isp_get_fill_light_mode(int cam_id, char **value);
int rk_isp_set_fill_light_mode(int cam_id, const char *value);
int rk_isp_get_light_brightness(int cam_id, int *value);
int rk_isp_set_light_brightness(int cam_id, int value);
int rk_isp_get_night_to_day_filter_level(int cam_id, int *value);
int rk_isp_set_night_to_day_filter_level(int cam_id, int value);
int rk_isp_get_night_to_day_filter_time(int cam_id, int *value);
int rk_isp_set_night_to_day_filter_time(int cam_id, int value);
// blc
int rk_isp_get_hdr(int cam_id, char **value);
int rk_isp_set_hdr(int cam_id, const char *value);
int rk_isp_get_blc_region(int cam_id, char **value);
int rk_isp_set_blc_region(int cam_id, const char *value);
int rk_isp_get_hlc(int cam_id, char **value);
int rk_isp_set_hlc(int cam_id, const char *value);
int rk_isp_get_hdr_level(int cam_id, int *value);
int rk_isp_set_hdr_level(int cam_id, int value);
int rk_isp_get_blc_strength(int cam_id, int *value);
int rk_isp_set_blc_strength(int cam_id, int value);
int rk_isp_get_hlc_level(int cam_id, int *value);
int rk_isp_set_hlc_level(int cam_id, int value);
int rk_isp_get_dark_boost_level(int cam_id, int *value);
int rk_isp_set_dark_boost_level(int cam_id, int value);
// white_blance
int rk_isp_get_white_blance_style(int cam_id, char **value);
int rk_isp_set_white_blance_style(int cam_id, const char *value);
int rk_isp_get_white_blance_red(int cam_id, int *value);
int rk_isp_set_white_blance_red(int cam_id, int value);
int rk_isp_get_white_blance_green(int cam_id, int *value);
int rk_isp_set_white_blance_green(int cam_id, int value);
int rk_isp_get_white_blance_blue(int cam_id, int *value);
int rk_isp_set_white_blance_blue(int cam_id, int value);
// enhancement
int rk_isp_get_noise_reduce_mode(int cam_id, char **value);
int rk_isp_set_noise_reduce_mode(int cam_id, const char *value);
int rk_isp_get_dehaze(int cam_id, char **value);
int rk_isp_set_dehaze(int cam_id, const char *value);
int rk_isp_get_gray_scale_mode(int cam_id, char **value);
int rk_isp_set_gray_scale_mode(int cam_id, const char *value);
int rk_isp_get_distortion_correction(int cam_id, char **value);
int rk_isp_set_distortion_correction(int cam_id, const char *value);
int rk_isp_get_spatial_denoise_level(int cam_id, int *value);
int rk_isp_set_spatial_denoise_level(int cam_id, int value);
int rk_isp_get_temporal_denoise_level(int cam_id, int *value);
int rk_isp_set_temporal_denoise_level(int cam_id, int value);
int rk_isp_get_dehaze_level(int cam_id, int *value);
int rk_isp_set_dehaze_level(int cam_id, int value);
int rk_isp_get_fec_level(int cam_id, int *value);
int rk_isp_set_fec_level(int cam_id, int value);
int rk_isp_get_ldch_level(int cam_id, int *value);
int rk_isp_set_ldch_level(int cam_id, int value);
// video_adjustment
int rk_isp_get_power_line_frequency_mode(int cam_id, char **value);
int rk_isp_set_power_line_frequency_mode(int cam_id, const char *value);
int rk_isp_get_image_flip(int cam_id, char **value);
int rk_isp_set_image_flip(int cam_id, const char *value);
// auto focus
int rk_isp_get_af_mode(int cam_id, char **value);
int rk_isp_set_af_mode(int cam_id, const char *mode);
int rk_isp_get_zoom_level(int cam_id, int *value);
int rk_isp_get_focus_level(int cam_id, int *value);
int rk_isp_af_zoom_in(int cam_id);
int rk_isp_af_zoom_out(int cam_id);
int rk_isp_af_focus_in(int cam_id);
int rk_isp_af_focus_out(int cam_id);
int rk_isp_af_focus_once(int cam_id);
// video
int rk_video_set(const char *json);
int rk_video_restart();
int rk_video_get_gop(int stream_id, int *value);
int rk_video_set_gop(int stream_id, int value);
int rk_video_get_max_rate(int stream_id, int *value);
int rk_video_set_max_rate(int stream_id, int value);
int rk_video_get_RC_mode(int stream_id, char **value);
int rk_video_set_RC_mode(int stream_id, const char *value);
int rk_video_get_output_data_type(int stream_id, char **value);
int rk_video_set_output_data_type(int stream_id, const char *value);
int rk_video_get_rc_quality(int stream_id, char **value);
int rk_video_set_rc_quality(int stream_id, const char *value);
int rk_video_get_smart(int stream_id, char **value);
int rk_video_set_smart(int stream_id, const char *value);
int rk_video_get_gop_mode(int stream_id, char **value);
int rk_video_set_gop_mode(int stream_id, const char *value);
int rk_video_get_stream_type(int stream_id, char **value);
int rk_video_set_stream_type(int stream_id, const char *value);
int rk_video_get_h264_profile(int stream_id, char **value);
int rk_video_set_h264_profile(int stream_id, const char *value);
int rk_video_get_resolution(int stream_id, char **value);
int rk_video_set_resolution(int stream_id, const char *value);
int rk_video_get_frame_rate(int stream_id, char **value);
int rk_video_set_frame_rate(int stream_id, const char *value);
int rk_video_get_frame_rate_in(int stream_id, char **value);
int rk_video_set_frame_rate_in(int stream_id, const char *value);
int rk_video_get_rotation(int *value);
int rk_video_set_rotation(int value);
// jpeg
int rk_video_get_enable_cycle_snapshot(int *value);
int rk_video_set_enable_cycle_snapshot(int value);
int rk_video_get_image_quality(int *value);
int rk_video_set_image_quality(int value);
int rk_video_get_snapshot_interval_ms(int *value);
int rk_video_set_snapshot_interval_ms(int value);
int rk_video_get_jpeg_resolution(char **value);
int rk_video_set_jpeg_resolution(const char *value);
// audio
int rk_audio_set(const char *json);
int rk_audio_restart();
int rk_audio_get_bit_rate(int stream_id, int *value);
int rk_audio_set_bit_rate(int stream_id, int value);
int rk_audio_get_sample_rate(int stream_id, int *value);
int rk_audio_set_sample_rate(int stream_id, int value);
int rk_audio_get_volume(int stream_id, int *value);
int rk_audio_set_volume(int stream_id, int value);
int rk_audio_get_enable_vqe(int stream_id, int *value);
int rk_audio_set_enable_vqe(int stream_id, int value);
int rk_audio_get_encode_type(int stream_id, char **value);
int rk_audio_set_encode_type(int stream_id, const char *value);
// system
int rk_system_capability_get_video(char *value);
int rk_system_capability_get_image_adjustment(char *value);
int rk_system_capability_get_image_blc(char *value);
int rk_system_capability_get_image_enhancement(char *value);
int rk_system_capability_get_image_exposure(char *value);
int rk_system_capability_get_image_night_to_day(char *value);
int rk_system_capability_get_image_video_adjustment(char *value);
int rk_system_capability_get_image_white_blance(char *value);
int rk_system_get_deivce_name(char **value);
int rk_system_get_telecontrol_id(char **value);
int rk_system_get_model(char **value);
int rk_system_get_serial_number(char **value);
int rk_system_get_firmware_version(char **value);
int rk_system_get_encoder_version(char **value);
int rk_system_get_web_version(char **value);
int rk_system_get_plugin_version(char **value);
int rk_system_get_channels_number(char **value);
int rk_system_get_hard_disks_number(char **value);
int rk_system_get_alarm_inputs_number(char **value);
int rk_system_get_alarm_outputs_number(char **value);
int rk_system_get_firmware_version_info(char **value);
int rk_system_get_manufacturer(char **value);
int rk_system_get_hardware_id(char **value);
int rk_system_set_deivce_name(const char *value);
int rk_system_set_telecontrol_id(const char *value);
// action
int rk_system_reboot();
int rk_system_factory_reset();
int rk_system_export_log(const char *path);
int rk_system_export_db(const char *path);
int rk_system_import_db(const char *path);
int rk_system_upgrade(const char *path);
// user
int rk_system_get_user_num(int *value);
int rk_system_set_user_num(int value);
int rk_system_get_user_level(int id, int *value);
int rk_system_set_user_level(int id, int value);
int rk_system_get_user_name(int id, char **value);
int rk_system_set_user_name(int id, const char *value);
int rk_system_get_password(int id, char **value);
int rk_system_set_password(int id, const char *value);
int rk_system_add_user(int id, int user_level, const char *user_name,
                       const char *password);
int rk_system_del_user(int id);
// osd
// osd.common
int rk_osd_get_is_presistent_text(int *value);
int rk_osd_set_is_presistent_text(int value);
int rk_osd_get_font_size(int *value);
int rk_osd_set_font_size(int value);
int rk_osd_get_boundary(int *value);
int rk_osd_set_boundary(int value);
int rk_osd_get_normalized_screen_width(int *value);
int rk_osd_get_normalized_screen_height(int *value);
int rk_osd_get_attribute(char **value);
int rk_osd_set_attribute(const char *value);
int rk_osd_get_font_color_mode(char **value);
int rk_osd_set_font_color_mode(const char *value);
int rk_osd_get_font_color(char **value);
int rk_osd_set_font_color(const char *value);
int rk_osd_get_alignment(char **value);
int rk_osd_set_alignment(const char *value);
int rk_osd_get_font_path(char **value);
int rk_osd_set_font_path(const char *value);
// osd.x
int rk_osd_get_enabled(int id, int *value);
int rk_osd_set_enabled(int id, int value);
int rk_osd_get_position_x(int id, int *value);
int rk_osd_set_position_x(int id, int value);
int rk_osd_get_position_y(int id, int *value);
int rk_osd_set_position_y(int id, int value);
int rk_osd_get_height(int id, int *value);
int rk_osd_set_height(int id, int value);
int rk_osd_get_width(int id, int *value);
int rk_osd_set_width(int id, int value);
int rk_osd_get_display_week_enabled(int id, int *value);
int rk_osd_set_display_week_enabled(int id, int value);
int rk_osd_get_date_style(int id, char **value);
int rk_osd_set_date_style(int id, const char *value);
int rk_osd_get_time_style(int id, char **value);
int rk_osd_set_time_style(int id, const char *value);
int rk_osd_get_type(int id, char **value);
int rk_osd_set_type(int id, const char *value);
int rk_osd_get_display_text(int id, char **value);
int rk_osd_set_display_text(int id, const char *value);
int rk_osd_get_image_path(int id, char **value);
int rk_osd_set_image_path(int id, const char *value);
int rk_osd_restart();
// roi.x
int rk_roi_get_stream_type(int id, char **value);
int rk_roi_set_stream_type(int id, const char *value);
int rk_roi_get_name(int id, char **value);
int rk_roi_set_name(int id, const char *value);
int rk_roi_get_id(int id, int *value);
int rk_roi_set_id(int id, int value);
int rk_roi_get_enabled(int id, int *value);
int rk_roi_set_enabled(int id, int value);
int rk_roi_get_position_x(int id, int *value);
int rk_roi_set_position_x(int id, int value);
int rk_roi_get_position_y(int id, int *value);
int rk_roi_set_position_y(int id, int value);
int rk_roi_get_height(int id, int *value);
int rk_roi_set_height(int id, int value);
int rk_roi_get_width(int id, int *value);
int rk_roi_set_width(int id, int value);
int rk_roi_get_quality_level(int id, int *value);
int rk_roi_set_quality_level(int id, int value);
int rk_roi_set_all();
// region_clip.x
int rk_region_clip_get_enabled(int id, int *value);
int rk_region_clip_set_enabled(int id, int value);
int rk_region_clip_get_position_x(int id, int *value);
int rk_region_clip_set_position_x(int id, int value);
int rk_region_clip_get_position_y(int id, int *value);
int rk_region_clip_set_position_y(int id, int value);
int rk_region_clip_get_height(int id, int *value);
int rk_region_clip_set_height(int id, int value);
int rk_region_clip_get_width(int id, int *value);
int rk_region_clip_set_width(int id, int value);
int rk_region_clip_set_all();
// network
int rk_network_ipv4_get(const char *interface, char *method, char *address,
                        char *netmask, char *gateway);
int rk_network_ipv4_set(char *interface, char *method, char *address,
                        char *netmask, char *gateway);
int rk_network_dns_get(char *ethernet_v4_dns, char *ethernet_v4_dns2);
int rk_network_dns_set(char *dns1, char *dns2);
int rk_network_get_mac(const char *ifname, char *mac);
int rk_network_nicspeed_get(const char *ifname, int *speed, int *duplex,
                            int *autoneg);
int rk_network_nicspeed_set(const char *ifname, int speed, int duplex,
                            int autoneg);
int rk_network_nicspeed_support_get(const char *ifname, char *nic_supported);
int rk_wifi_power_get(int *on);
int rk_wifi_power_set(int on);
int rk_wifi_scan_wifi();
int rk_wifi_get_list(char **wifi_list);
int rk_wifi_connect_with_ssid(const char *ssid, const char *psk);
int rk_wifi_forget_with_ssid(const char *ssid);
// storage
int rk_storage_record_start();
int rk_storage_record_stop();
int rk_storage_record_statue_get(int *value);
int rk_take_photo();
// event
int rk_event_ri_get_enabled(int *value);
int rk_event_ri_set_enabled(int value);
int rk_event_ri_get_position_x(int *value);
int rk_event_ri_set_position_x(int value);
int rk_event_ri_get_position_y(int *value);
int rk_event_ri_set_position_y(int value);
int rk_event_ri_get_width(int *value);
int rk_event_ri_set_width(int value);
int rk_event_ri_get_height(int *value);
int rk_event_ri_set_height(int value);
int rk_event_ri_get_proportion(int *value);
int rk_event_ri_set_proportion(int value);
int rk_event_ri_get_sensitivity_level(int *value);
int rk_event_ri_set_sensitivity_level(int value);
int rk_event_ri_get_time_threshold(int *value);
int rk_event_ri_set_time_threshold(int value);