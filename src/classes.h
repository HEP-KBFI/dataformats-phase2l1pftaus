#include "Rtypes.h"

#include "DataFormats/TallinnL1PFTaus/interface/TallinnL1PFTau.h"
#include "DataFormats/TallinnL1PFTaus/interface/TallinnL1PFTauFwd.h"

namespace DataFormats_TallinnL1PFTaus
{
  struct dictionary 
  {
    l1t::TallinnL1PFTau l1pftau;
    l1t::TallinnL1PFTauCollection l1pftauCollection;
    edm::Wrapper<l1t::TallinnL1PFTauCollection> l1pftauCWrapper;
  };
}
