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

    //l1t::TauRef   refTau_;
    //l1t::TauRefVector   refVecTau_;
    //l1t::TauVectorRef   vecRefTau_;
    //edm::Wrapper<l1t::TauRef>   w_refTau_;
    //edm::Wrapper<l1t::TauRefVector>   w_refVecTau_;
    //edm::Wrapper<l1t::TauVectorRef>   w_vecRefTau_;

    l1t::TallinnL1PFTau l1pftau;
    edm::Wrapper<l1t::TallinnL1PFTauCollection> w_l1pftau;
    std::vector<l1t::TallinnL1PFTau> vecRefPFTau_;
    edm::Wrapper<l1t::TallinnL1PFTauCollection> w_vecRefPFTau_;
    
  };
}
