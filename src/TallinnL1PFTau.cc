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

namespace
{
  ostream& operator<<(ostream& os, const l1t::PFCandidate& l1PFCand)
  {
    std::string type_string;
    if      ( l1PFCand.id() == l1t::PFCandidate::ChargedHadron ) type_string = "PFChargedHadron";
    else if ( l1PFCand.id() == l1t::PFCandidate::Electron      ) type_string = "PFElectron";
    else if ( l1PFCand.id() == l1t::PFCandidate::NeutralHadron ) type_string = "PFNeutralHadron";
    else if ( l1PFCand.id() == l1t::PFCandidate::Photon        ) type_string = "PFPhoton";
    else if ( l1PFCand.id() == l1t::PFCandidate::Muon          ) type_string = "PFMuon";
    else                                                         type_string = "N/A";
    os << type_string << " with pT = " << l1PFCand.pt()  << ", eta = " << l1PFCand.eta() << ", phi = " << l1PFCand.phi() << "," 
       << " mass = " << l1PFCand.mass() << ", charge = " << l1PFCand.charge() << std::endl;
    return os;
  }
}

// print to stream
ostream& operator<<(ostream& os, const l1t::TallinnL1PFTau& l1PFTau) 
{
  os << "pT = " << l1PFTau.pt()  << ", eta = " << l1PFTau.eta() << ", phi = " << l1PFTau.phi() 
     << " (type = " << l1PFTau.tauType() << ")" << std::endl;
  os << "leadChargedPFCand:";
  if ( l1PFTau.leadChargedPFCand().isNonnull() ) 
  {
    const l1t::PFCandidate& leadChargedPFCand = *l1PFTau.leadChargedPFCand();
    os << " pT = " << leadChargedPFCand.pt()  << ", eta = " << leadChargedPFCand.eta() << ", phi = " << leadChargedPFCand.phi(); 
  }
  else
  {
    os << " N/A";
  }
  os << std::endl;
  os << "seed:";
  if ( l1PFTau.isChargedPFCandSeeded() ) 
  {
    os << " chargedPFCand";
  }
  else if ( l1PFTau.isPFJetSeeded() ) 
  {
    os << " PFJet";
  }
  else assert(0);
  os << std::endl;
  os << "signalPFCands";
  for ( auto l1PFCand : l1PFTau.signalAllL1PFCandidates() )
  {
    os << " " << (*l1PFCand);
  }
  os << "isolationPFCands";
  for ( auto l1PFCand : l1PFTau.isoAllL1PFCandidates() )
  {
    os << " " << (*l1PFCand);
  }
  os << "isolation pT-sum: charged = " << l1PFTau.sumChargedIso() << ", neutral = " << l1PFTau.sumNeutralIso() << std::endl;
  return os;
}
