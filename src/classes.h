#include "Rtypes.h"
#include "Math/Cartesian3D.h"
#include "Math/Polar3D.h"
#include "Math/CylindricalEta3D.h"
#include "Math/PxPyPzE4D.h"
#include <boost/cstdint.hpp>
#include "DataFormats/Common/interface/Wrapper.h"
#include "DataFormats/Common/interface/RefVector.h"
#include "DataFormats/Common/interface/RefProd.h"
#include "DataFormats/TallinnL1PFTaus/interface/TallinnL1PFTau.h"

namespace DataFormats_L1Trigger {
  struct dictionary {

    TallinnL1PFTau l1pftau;
    edm::Wrapper<TallinnL1PFTauCollection> w_l1pftau;
    std::vector<TallinnL1PFTau> vecRefPFTau_;
    edm::Wrapper<TallinnL1PFTauCollection> w_vecRefPFTau_;
    
  };
}
