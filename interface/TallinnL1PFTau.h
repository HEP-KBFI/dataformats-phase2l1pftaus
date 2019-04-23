#ifndef DataFormats_TallinnL1PFTaus_TallinnL1PFTau_H
#define DataFormats_TallinnL1PFTaus_TallinnL1PFTau_H

#include "DataFormats/Phase2L1ParticleFlow/interface/PFCandidate.h" // l1t::PFCandidate
#include "DataFormats/Candidate/interface/LeafCandidate.h"          // reco::LeafCandidate 
#include "DataFormats/Candidate/interface/Particle.h"               // reco::Particle::LorentzVector

#include <ostream>

class TallinnL1PFTau;
typedef std::vector<TallinnL1PFTau> TallinnL1PFTauCollection;

class TallinnL1PFTau : public reco::LeafCandidate 
{
 public:

  enum IsoQual {
    kVLoose,
    kLoose,
    kMedium,
    kTight
  };

  /// default constructor
  TallinnL1PFTau();
    
  /// destructor
  ~TallinnL1PFTau();

  /// accessor functions for reco level quantities
  const l1t::PFCandidate& seedChargedPFCand() const { return seedChargedPFCand_; }
  const l1t::PFCandidate& leadChargedPFCand() const { return leadChargedPFCand_; }

  const reco::Particle::LorentzVector& strip_p4() const { return strip_p4_; };
  
  float sumChargedIso() const { return sumChargedIso_; }
  float sumNeutralIso() const { return sumNeutralIso_; }
  
  bool passTightIso()     const { return passTightIso_;     };
  bool passMediumIso()    const { return passMediumIso_;    };
  bool passLooseIso()     const { return passLooseIso_;     };
  bool passVLooseIso()    const { return passVLooseIso_;    };
  
  bool passTightRelIso()  const { return passTightRelIso_;  };
  bool passMediumRelIso() const { return passMediumRelIso_; };
  bool passLooseRelIso()  const { return passLooseRelIso_;  };
  bool passVLooseRelIso() const { return passVLooseRelIso_; };
  
  /// print to stream
  friend std::ostream& operator << (std::ostream& os, const TallinnL1PFTau& reg);

  friend class TallinnL1PFTauBuilder;

 private:
  l1t::PFCandidate seedChargedPFCand_;
  l1t::PFCandidate leadChargedPFCand_;

  reco::Particle::LorentzVector strip_p4_;

  float sumChargedIso_;
  float sumNeutralIso_;
  float sumCombinedIso_;
  
  bool passTightIso_;
  bool passMediumIso_;
  bool passLooseIso_;
  bool passVLooseIso_;
  
  bool passTightRelIso_;
  bool passMediumRelIso_;
  bool passLooseRelIso_;
  bool passVLooseRelIso_;
};

#endif 
