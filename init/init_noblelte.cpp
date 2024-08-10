/*
   Copyright (c) 2016, The Linux Foundation. All rights reserved.
   Copyright (c) 2017-2020, The LineageOS Project. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <android-base/logging.h>

#include <android-base/file.h>
#include <android-base/logging.h>
#include <android-base/strings.h>
#include <android-base/properties.h>

#include "property_service.h"

#include "init_universal7420.h"

using android::base::GetProperty;
using android::base::ReadFileToString;
using android::base::Trim;

void set_sim_info()
{
	const char *simslot_count_path = "/proc/simslot_count";
	std::string simslot_count;

	if (ReadFileToString(simslot_count_path, &simslot_count)) {
		simslot_count = Trim(simslot_count); // strip newline
		property_override("ro.vendor.multisim.simslotcount", simslot_count.c_str());
	}
	else {
		LOG(ERROR) << "Could not open '" << simslot_count_path << "'\n";
	}
}

void vendor_load_properties()
{
    std::string bootloader = GetProperty("ro.bootloader", "");
    if (bootloader.find("N920C") == 0) {
        property_override("ro.build.description", "nobleltejv-user 7.0 NRD90M N920CXXS5CRH3 release-keys");
        set_ro_product_prop("device", "noblelte");
        set_ro_build_prop("fingerprint", "samsung/nobleltejv/noblelte:7.0/NRD90M/N920CXXS5CRH3:user/release-keys");
        set_ro_product_prop("model", "SM-N920C");
        set_ro_product_prop("name", "noblelte");
    } else if (bootloader.find("N920K") == 0) {
        property_override("ro.build.description", "nobleltektt-user 7.0 NRD90M N920KKKU2DVG1 release-keys");
        set_ro_product_prop("device", "nobleltektt");
        set_ro_build_prop("fingerprint", "samsung/nobleltektt/noblelte:7.0/NRD90M/N920KKKU2DVG1:user/release-keys");
        set_ro_product_prop("model", "SM-N920K");
        set_ro_product_prop("name", "nobleltektt");
    } else if (bootloader.find("N920S") == 0) {
        property_override("ro.build.description", "noblelteskt-user 7.0 NRD90M N920SKSU2DVG1 release-keys");
        set_ro_product_prop("device", "noblelteskt");
        set_ro_build_prop("fingerprint", "samsung/noblelteskt/noblelte:7.0/NRD90M/N920SKSU2DVG1:user/release-keys");
        set_ro_product_prop("model", "SM-N920S");
        set_ro_product_prop("name", "noblelteskt");
    } else if (bootloader.find("N920L") == 0) {
        property_override("ro.build.description", "nobleltelgt-user 7.0 NRD90M N920LKLU2DVG1 release-keys");
        set_ro_product_prop("device", "nobleltelgt");
        set_ro_build_prop("fingerprint", "samsung/nobleltelgt/noblelte:7.0/NRD90M/N920LKLU2DVG1:user/release-keys");
        set_ro_product_prop("model", "SM-N920L");
        set_ro_product_prop("name", "nobleltelgt");
    } else if (bootloader.find("N920G") == 0) {
        property_override("ro.build.description", "nobleltedd-user 7.0 NRD90M N920GUBU5CVGN release-keys");
        set_ro_product_prop("device", "nobleltedd");
        set_ro_build_prop("fingerprint", "samsung/nobleltedd/noblelte:7.0/NRD90M/N920GUBU5CVGN:user/release-keys");
        set_ro_product_prop("model", "SM-N920G");
        set_ro_product_prop("name", "nobleltedd");
    } else if (bootloader.find("N920I") == 0) {
        property_override("ro.build.description", "nobleltedv-user 7.0 NRD90M N920IDVU5CVG3 release-keys");
        set_ro_product_prop("device", "nobleltedv");
        set_ro_build_prop("fingerprint", "samsung/nobleltedv/noblelte:7.0/NRD90M/N920IDVU5CVG3:user/release-keys");
        set_ro_product_prop("model", "SM-N920I");
        set_ro_product_prop("name", "nobleltedv");
    } else if (bootloader.find("N920W8") == 0) {
        property_override("ro.build.description", "nobleltebmc-user 7.0 NRD90M N920W8VLU6CVG1 release-keys");
        set_ro_product_prop("device", "nobleltebmc");
        set_ro_build_prop("fingerprint", "samsung/nobleltebmc/noblelte:7.0/NRD90M/N920W8VLU6CVG1:user/release-keys");
        set_ro_product_prop("model", "SM-N920W8");
        set_ro_product_prop("name", "nobleltebmc");
    } else if (bootloader.find("N920T") == 0) {
        property_override("ro.build.description", "nobleltetmo-user 7.0 NRD90M  N920TUVU6EVG2 release-keys");
        set_ro_product_prop("device", "nobleltetmo");
        set_ro_build_prop("fingerprint", "samsung/nobleltetmo/noblelte:7.0/NRD90M/ N920TUVU6EVG2:user/release-keys");
        set_ro_product_prop("model", "SM-N920T");
        set_ro_product_prop("name", "nobleltetmo");
    } else if (bootloader.find("N920P") == 0) {
        property_override("ro.build.description", "nobleltespr-user 7.0 NRD90M N920PVPS3DRH1 release-keys");
        set_ro_product_prop("device", "nobleltespr");
        set_ro_build_prop("fingerprint", "samsung/nobleltespr/noblelte:7.0/NRD90M/N920PVPS3DRH1:user/release-keys");
        set_ro_product_prop("model", "SM-N920P");
        set_ro_product_prop("name", "nobleltespr");
    }
    gsm_properties("9");
    set_sim_info();

    std::string device = GetProperty("ro.product.device", "");
    LOG(ERROR) << "Found bootloader id " << bootloader <<  " setting build properties for "
        << device <<  " device" << std::endl;
}
