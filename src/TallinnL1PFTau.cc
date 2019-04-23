#include "DataFormats/TallinnL1PFTaus/interface/TallinnL1PFTau.h"

// default constructor
TallinnL1PFTau::TallinnL1PFTau() 
  : sumChargedIso_(0.)
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
TallinnL1PFTau::~TallinnL1PFTau() 
{}

// print to stream
/*
ostream& l1t::operator<<(ostream& os, const TallinnL1PFTau& tau) {

  os << "TallinnL1PFTau:";
  os << " Reco -> ET = " <<tau.p4().Pt();
          os <<" Eta = " <<tau.p4().Eta();
	  os <<" Phi = " <<tau.p4().Phi() << std::endl;

  os << " Tau Decay Mode = "<< tau.tauType() << std::endl;
  os << " Et = "      << tau.et();
  os << " towerEta = "<< tau.towerEta();
  os << " towerPhi = "<< tau.towerPhi()<<std::endl;

  os << " ecalEnergy = "<< tau.ecalEnergy();
  os << " hcalEnergy = "<< tau.hcalEnergy();
  os << " caloEnergy = "<< tau.caloEnergy()<<std::endl;

  os << " EoH = "<<tau.EoH();
  os  <<" HoE = "<<tau.HoE()<<std::endl;

  os  <<" rawIso = "<<tau.rawIso()<<std::endl;
  os  <<" relIso = "<<tau.relIso()<<std::endl;

  os << " raw = "<<tau.raw()<<std::endl;

  return os;
}
*/
