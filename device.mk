#
# Copyright (C) 2020 The LineageOS Project
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

LOCAL_PATH := device/samsung/noblelte

# Audio
PRODUCT_COPY_FILES += \
	$(LOCAL_PATH)/configs/audio/mixer_paths.xml:$(TARGET_COPY_OUT_VENDOR)/etc/mixer_paths_0.xml

PRODUCT_COPY_FILES += \
	device/samsung/universal7420-common/configs/init/rild.rc:$(TARGET_COPY_OUT_VENDOR)/etc/init/rild.legacy.rc

# Overlays
DEVICE_PACKAGE_OVERLAYS += $(LOCAL_PATH)/overlay

# Wi-Fi
PRODUCT_PACKAGES += \
	WifiOverlay

# Inherit from universal7420-common
$(call inherit-product, device/samsung/universal7420-common/device-common.mk)

# Call the proprietary
$(call inherit-product, vendor/samsung/noblelte/noblelte-vendor.mk)
