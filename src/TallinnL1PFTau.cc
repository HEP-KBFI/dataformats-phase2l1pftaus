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
  os << "pT = " << l1PFTau.pt()  << ", eta = " << l1PFTau.eta() << ", phi = " << l1PFTau.phi() 
     << " (type = " << l1PFTau.tauType() << ")" << std::endl;
  os << "lead. ChargedPFCand:" << std::endl;
  if ( l1PFTau.leadChargedPFCand().isNonnull() ) 
  {
    printPFCand(os, *l1PFTau.leadChargedPFCand(), l1PFTau.primaryVertex());
  }
  else
  {
    os << " N/A" << std::endl;
  }
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
  os << "signalPFCands:" << std::endl;
  for ( auto l1PFCand : l1PFTau.signalAllL1PFCandidates() )
  {
    printPFCand(os, *l1PFCand, l1PFTau.primaryVertex());
  }
  os << "isolationPFCands:" << std::endl;
  for ( auto l1PFCand : l1PFTau.isoAllL1PFCandidates() )
  {
    printPFCand(os, *l1PFCand, l1PFTau.primaryVertex());
  }
  os << "isolation pT-sum: charged = " << l1PFTau.sumChargedIso() << ", neutral = " << l1PFTau.sumNeutralIso() << std::endl;
  return os;
}

void printPFCand(ostream& os, const l1t::PFCandidate& l1PFCand, const l1t::VertexRef& primaryVertex)
{
  std::string type_string;
  if      ( l1PFCand.id() == l1t::PFCandidate::ChargedHadron ) type_string = "PFChargedHadron";
  else if ( l1PFCand.id() == l1t::PFCandidate::Electron      ) type_string = "PFElectron";
  else if ( l1PFCand.id() == l1t::PFCandidate::NeutralHadron ) type_string = "PFNeutralHadron";
  else if ( l1PFCand.id() == l1t::PFCandidate::Photon        ) type_string = "PFPhoton";
  else if ( l1PFCand.id() == l1t::PFCandidate::Muon          ) type_string = "PFMuon";
  else                                                         type_string = "N/A";
  os << " " << type_string << " with pT = " << l1PFCand.pt()  << ", eta = " << l1PFCand.eta() << ", phi = " << l1PFCand.phi() << "," 
     << " mass = " << l1PFCand.mass() << ", charge = " << l1PFCand.charge();
  if ( l1PFCand.charge() != 0 && primaryVertex.isNonnull() ) 
  {
    os << " (dz = " << std::fabs(l1PFCand.pfTrack()->vertex().z() - primaryVertex->z0()) << ")";
  }
  os << std::endl;
}
