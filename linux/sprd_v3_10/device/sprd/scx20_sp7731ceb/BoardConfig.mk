#
# Copyright (C) 2011 The Android Open-Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

# secure boot
BOARD_SECURE_BOOT_ENABLE := false
SECURE_BOOT_SIGNAL_KEY := false

-include device/sprd/scx20/BoardConfigCommon.mk
-include device/sprd/scx20/emmc/BoardConfigEmmc.mk

#ext4 partition
-include device/sprd/scx20_sp7731ceb/BoardPartitionConfig.mk

# board configs
TARGET_BOOTLOADER_BOARD_NAME := sp7731ceb
UBOOT_DEFCONFIG := sp7731ceb
ifeq ($(strip $(BOARD_KERNEL_SEPARATED_DT)),true)
KERNEL_DEFCONFIG := sp7731ceb_dt_defconfig
else
KERNEL_DEFCONFIG := sp7731ceb_defconfig
endif

TARGET_BOARD_CAMERA_POLE_SUPPORT := true

#camera preview/video only support 720p
TARGET_BOARD_CAMERA_SUPPORT_720P := true
#Path1's line buffer width of pike is 1280, so camera preview can just support max size 1280x960
TARGET_BOARD_FRONT_CAMERA_SUPPORT_720P := true

# select camera 2M,3M,5M,8M
CAMERA_SUPPORT_SIZE := 5M
TARGET_BOARD_NO_FRONT_SENSOR := false
TARGET_BOARD_FRONT_CAMERA_ROTATION := false
TARGET_BOARD_CAMERA_FLASH_CTRL := false

# camera sensor type
CAMERA_SENSOR_TYPE_BACK := "ov5670_mipi_raw"
CAMERA_SENSOR_TYPE_FRONT := "GC0310_MIPI_yuv"

#face detect
TARGET_BOARD_CAMERA_FACE_DETECT := true

#hdr capture
TARGET_BOARD_CAMERA_HDR_CAPTURE := true
TARGET_BOARD_CAMERA_HDR_SPRD_LIB := true

#uv denoise
TARGET_BOARD_CAMERA_UV_DENOISE := false

#capture mem
TARGET_BOARD_LOW_CAPTURE_MEM := true

#snesor interface
TARGET_BOARD_BACK_CAMERA_INTERFACE := mipi
TARGET_BOARD_FRONT_CAMERA_INTERFACE := mipi

#select camera zsl cap mode
TARGET_BOARD_CAMERA_CAPTURE_MODE := false

#rotation capture
TARGET_BOARD_CAMERA_ROTATION_CAPTURE := true

#select camera not support autofocus
TARGET_BOARD_CAMERA_NO_AUTOFOCUS_DEV := true

#select continuous auto focus
TARGET_BOARD_CAMERA_CAF := false

#select sprd af alg
TARGET_BOARD_CAMERA_AF_ALG_SPRD := true

TARGET_BOARD_CAMERA_NO_FLASH_DEV := false
TARGET_BOARD_FRONT_CAMERA_FLASH_DEV := false

#image angle in different project
TARGET_BOARD_CAMERA_ADAPTER_IMAGE := 180

#pre_allocate capture memory
TARGET_BOARD_CAMERA_PRE_ALLOC_CAPTURE_MEM := true

#sc8830g isp ver 0;sc9630 isp ver 1;sp9830iea isp version 2
TARGET_BOARD_CAMERA_ISP_SOFTWARE_VERSION := 3

#support auto anti-flicker
TARGET_BOARD_CAMERA_ANTI_FLICKER := true

#low capture memory
TARGET_BOARD_LOW_CAPTURE_MEM := true

#sprd private zsl
TARGET_BOARD_CAMERA_SPRD_PRIVATE_ZSL := true

#select mipi d-phy mode(none, phya, phyb, phyab)
TARGET_BOARD_FRONT_CAMERA_MIPI := phyb
TARGET_BOARD_BACK_CAMERA_MIPI := phya

#select ccir pclk src(source0, source1)
TARGET_BOARD_FRONT_CAMERA_CCIR_PCLK := source0
TARGET_BOARD_BACK_CAMERA_CCIR_PCLK := source0

# select WCN
BOARD_HAVE_BLUETOOTH := true
ifeq ($(strip $(USE_SPRD_WCN)),true)
BOARD_SPRD_WCNBT_SR2351 := true
BOARD_HAVE_FM_TROUT := true
BOARD_USE_SPRD_FMAPP := true
endif

#2351 GPS
#change by zhoujiajia 2015.12.09
ifneq ($(strip $(GST_NOT_SUPPORT_GPS)),true)
BOARD_USE_SPRD_4IN1_GPS := true
endif

# WIFI configs
BOARD_WPA_SUPPLICANT_DRIVER := NL80211
WPA_SUPPLICANT_VERSION      := VER_2_1_DEVEL
BOARD_WPA_SUPPLICANT_PRIVATE_LIB := lib_driver_cmd_sprdwl
BOARD_HOSTAPD_DRIVER        := NL80211
BOARD_HOSTAPD_PRIVATE_LIB   := lib_driver_cmd_sprdwl
BOARD_WLAN_DEVICE           := sc2351
WIFI_DRIVER_FW_PATH_PARAM   := "/data/misc/wifi/fwpath"
WIFI_DRIVER_FW_PATH_STA     := "sta_mode"
WIFI_DRIVER_FW_PATH_P2P     := "p2p_mode"
WIFI_DRIVER_FW_PATH_AP      := "ap_mode"
WIFI_DRIVER_MODULE_PATH     := "/system/lib/modules/sprdwl.ko"
WIFI_DRIVER_MODULE_NAME     := "sprdwl"

# Enable dex-preoptimization of user products
ifeq ($(TARGET_BUILD_VARIANT),user)
    WITH_DEXPREOPT := true
    WITH_DEXPREOPT_PIC := true
endif

# select sensor
#USE_INVENSENSE_LIB := true
USE_SPRD_SENSOR_LIB := true
BOARD_HAVE_ACC := Lis3dh
BOARD_ACC_INSTALL := 6
BOARD_HAVE_ORI := NULL
BOARD_ORI_INSTALL := NULL
BOARD_HAVE_PLS := EPL2182
BOARD_PLS_COMPATIBLE := true


DEVICE_GSP_NOT_SCALING_UP_TWICE := true
TARGET_USES_LOGD := false

#UCAM feature
TARGET_BOARD_CAMERA_FACE_BEAUTY := true # hal config
TARGET_TS_UCAM_MAKEUP_ALL := true #prove we have UCAM function
#Camera for WideanglePanorama
TARGET_TS_UCAM_MAKEUP_WIDEANGLE_NENABLE:= true
#UCAM for V gesture
TARGET_TS_UCAM_MAKEUP_VGESTURE_NENABLE:= false
