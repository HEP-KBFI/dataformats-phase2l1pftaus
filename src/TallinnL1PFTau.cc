#include "DataFormats/TallinnL1PFTaus/interface/TallinnL1PFTau.h"

// default constructor
l1t::TallinnL1PFTau::TallinnL1PFTau() 
  : tauType_(kUndefined)
  , sumChargedIso_(0.)
  , sumNeutralIso_(0.)
  , sumCombinedIso_(0.)
  , passTightIso_(false)
  , passMediumIso_(false)
  , passLooseIso_(false)
  , passVLooseIso_(false)
  , passTightRelIso_(false)
  , passMediumRelIso_(false)
  , passLooseRelIso_(false)
  , passVLooseRelIso_(false)
{}

// destructor
l1t::TallinnL1PFTau::~TallinnL1PFTau() 
{}

// print to stream
ostream& operator<<(ostream& os, const l1t::TallinnL1PFTau& l1PFTau) 
{
  os << "TallinnL1PFTau:";
  os << " pT = " << l1PFTau.pt()  << ", eta = " << l1PFTau.eta() << ", phi = " << l1PFTau.phi()
     << " (type = " << l1PFTau.tauType() << ")";
  os << std::endl;
  return os;
}
