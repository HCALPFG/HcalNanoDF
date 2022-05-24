#ifndef HcalChannelInfo_h
#define HcalChannelInfo_h

// system include files
#include <memory>

#include "DataFormats/HcalDetId/interface/HcalSubdetector.h"
#include "DataFormats/HcalDetId/interface/HcalDetId.h"
#include "DataFormats/HcalDetId/interface/HcalGenericDetId.h"
#include "DataFormats/HcalDetId/interface/HcalElectronicsId.h"
#include "CondFormats/HcalObjects/interface/HcalElectronicsMap.h"

namespace hcalnano {
	typedef std::vector<HcalDetId> HcalDIDList;
	typedef std::vector<HcalElectronicsId> HcalEIDList;

	struct HcalChannelInfo {
	public:
		std::map<HcalSubdetector, hcalnano::HcalDIDList> dids;
		std::map<HcalSubdetector, hcalnano::HcalEIDList> eids;

		HcalChannelInfo() {
			std::vector<HcalSubdetector> subdets = {HcalBarrel, HcalEndcap, HcalForward, HcalOuter};
			for (auto& it_subdet : subdets) {
				dids[it_subdet] = {};
				eids[it_subdet] = {};
			}
		};
	};
};

#endif