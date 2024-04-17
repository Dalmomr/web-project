//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Apr 12 16:32:47 2024 by ROOT version 6.30/04
// from TTree Events/Events
// found on file: DYJetsToLL.root
//////////////////////////////////////////////////////////

#ifndef meu_h
#define meu_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class meu {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           run;
   UInt_t          luminosityBlock;
   ULong64_t       event;
   Bool_t          HLT_IsoMu24_eta2p1;
   Bool_t          HLT_IsoMu24;
   Bool_t          HLT_IsoMu17_eta2p1_LooseIsoPFTau20;
   Int_t           PV_npvs;
   Float_t         PV_x;
   Float_t         PV_y;
   Float_t         PV_z;
   UInt_t          nMuon;
   Float_t         Muon_pt[18];   //[nMuon]
   Float_t         Muon_eta[18];   //[nMuon]
   Float_t         Muon_phi[18];   //[nMuon]
   Float_t         Muon_mass[18];   //[nMuon]
   Int_t           Muon_charge[18];   //[nMuon]
   Float_t         Muon_pfRelIso03_all[18];   //[nMuon]
   Float_t         Muon_pfRelIso04_all[18];   //[nMuon]
   Bool_t          Muon_tightId[18];   //[nMuon]
   Bool_t          Muon_softId[18];   //[nMuon]
   Float_t         Muon_dxy[18];   //[nMuon]
   Float_t         Muon_dxyErr[18];   //[nMuon]
   Float_t         Muon_dz[18];   //[nMuon]
   Float_t         Muon_dzErr[18];   //[nMuon]
   Int_t           Muon_jetIdx[18];   //[nMuon]
   Int_t           Muon_genPartIdx[18];   //[nMuon]
   UInt_t          nTau;
   Float_t         Tau_pt[49];   //[nTau]
   Float_t         Tau_eta[49];   //[nTau]
   Float_t         Tau_phi[49];   //[nTau]
   Float_t         Tau_mass[49];   //[nTau]
   Int_t           Tau_charge[49];   //[nTau]
   Int_t           Tau_decayMode[49];   //[nTau]
   Float_t         Tau_relIso_all[49];   //[nTau]
   Int_t           Tau_jetIdx[49];   //[nTau]
   Int_t           Tau_genPartIdx[49];   //[nTau]
   Bool_t          Tau_idDecayMode[49];   //[nTau]
   Float_t         Tau_idIsoRaw[49];   //[nTau]
   Bool_t          Tau_idIsoVLoose[49];   //[nTau]
   Bool_t          Tau_idIsoLoose[49];   //[nTau]
   Bool_t          Tau_idIsoMedium[49];   //[nTau]
   Bool_t          Tau_idIsoTight[49];   //[nTau]
   Bool_t          Tau_idAntiEleLoose[49];   //[nTau]
   Bool_t          Tau_idAntiEleMedium[49];   //[nTau]
   Bool_t          Tau_idAntiEleTight[49];   //[nTau]
   Bool_t          Tau_idAntiMuLoose[49];   //[nTau]
   Bool_t          Tau_idAntiMuMedium[49];   //[nTau]
   Bool_t          Tau_idAntiMuTight[49];   //[nTau]
   Float_t         MET_pt;
   Float_t         MET_phi;
   Float_t         MET_sumet;
   Float_t         MET_significance;
   Float_t         MET_CovXX;
   Float_t         MET_CovXY;
   Float_t         MET_CovYY;
   UInt_t          nJet;
   Float_t         Jet_pt[61];   //[nJet]
   Float_t         Jet_eta[61];   //[nJet]
   Float_t         Jet_phi[61];   //[nJet]
   Float_t         Jet_mass[61];   //[nJet]
   Bool_t          Jet_puId[61];   //[nJet]
   Float_t         Jet_btag[61];   //[nJet]
   UInt_t          nGenPart;
   Float_t         GenPart_pt[50];   //[nGenPart]
   Float_t         GenPart_eta[50];   //[nGenPart]
   Float_t         GenPart_phi[50];   //[nGenPart]
   Float_t         GenPart_mass[50];   //[nGenPart]
   Int_t           GenPart_pdgId[50];   //[nGenPart]
   Int_t           GenPart_status[50];   //[nGenPart]

   // List of branches
   TBranch        *b_run;   //!
   TBranch        *b_luminosityBlock;   //!
   TBranch        *b_event;   //!
   TBranch        *b_HLT_IsoMu24_eta2p1;   //!
   TBranch        *b_HLT_IsoMu24;   //!
   TBranch        *b_HLT_IsoMu17_eta2p1_LooseIsoPFTau20;   //!
   TBranch        *b_PV_npvs;   //!
   TBranch        *b_PV_x;   //!
   TBranch        *b_PV_y;   //!
   TBranch        *b_PV_z;   //!
   TBranch        *b_nMuon;   //!
   TBranch        *b_Muon_pt;   //!
   TBranch        *b_Muon_eta;   //!
   TBranch        *b_Muon_phi;   //!
   TBranch        *b_Muon_mass;   //!
   TBranch        *b_Muon_charge;   //!
   TBranch        *b_Muon_pfRelIso03_all;   //!
   TBranch        *b_Muon_pfRelIso04_all;   //!
   TBranch        *b_Muon_tightId;   //!
   TBranch        *b_Muon_softId;   //!
   TBranch        *b_Muon_dxy;   //!
   TBranch        *b_Muon_dxyErr;   //!
   TBranch        *b_Muon_dz;   //!
   TBranch        *b_Muon_dzErr;   //!
   TBranch        *b_Muon_jetIdx;   //!
   TBranch        *b_Muon_genPartIdx;   //!
   TBranch        *b_nTau;   //!
   TBranch        *b_Tau_pt;   //!
   TBranch        *b_Tau_eta;   //!
   TBranch        *b_Tau_phi;   //!
   TBranch        *b_Tau_mass;   //!
   TBranch        *b_Tau_charge;   //!
   TBranch        *b_Tau_decayMode;   //!
   TBranch        *b_Tau_relIso_all;   //!
   TBranch        *b_Tau_jetIdx;   //!
   TBranch        *b_Tau_genPartIdx;   //!
   TBranch        *b_Tau_idDecayMode;   //!
   TBranch        *b_Tau_idIsoRaw;   //!
   TBranch        *b_Tau_idIsoVLoose;   //!
   TBranch        *b_Tau_idIsoLoose;   //!
   TBranch        *b_Tau_idIsoMedium;   //!
   TBranch        *b_Tau_idIsoTight;   //!
   TBranch        *b_Tau_idAntiEleLoose;   //!
   TBranch        *b_Tau_idAntiEleMedium;   //!
   TBranch        *b_Tau_idAntiEleTight;   //!
   TBranch        *b_Tau_idAntiMuLoose;   //!
   TBranch        *b_Tau_idAntiMuMedium;   //!
   TBranch        *b_Tau_idAntiMuTight;   //!
   TBranch        *b_MET_pt;   //!
   TBranch        *b_MET_phi;   //!
   TBranch        *b_MET_sumet;   //!
   TBranch        *b_MET_significance;   //!
   TBranch        *b_MET_CovXX;   //!
   TBranch        *b_MET_CovXY;   //!
   TBranch        *b_MET_CovYY;   //!
   TBranch        *b_nJet;   //!
   TBranch        *b_Jet_pt;   //!
   TBranch        *b_Jet_eta;   //!
   TBranch        *b_Jet_phi;   //!
   TBranch        *b_Jet_mass;   //!
   TBranch        *b_Jet_puId;   //!
   TBranch        *b_Jet_btag;   //!
   TBranch        *b_nGenPart;   //!
   TBranch        *b_GenPart_pt;   //!
   TBranch        *b_GenPart_eta;   //!
   TBranch        *b_GenPart_phi;   //!
   TBranch        *b_GenPart_mass;   //!
   TBranch        *b_GenPart_pdgId;   //!
   TBranch        *b_GenPart_status;   //!

   meu(TTree *tree=0);
   virtual ~meu();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop(TTree *tree1);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef meu_cxx
meu::meu(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("DYJetsToLL.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("DYJetsToLL.root");
      }
      f->GetObject("Events",tree);

   }
   Init(tree);
}

meu::~meu()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t meu::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t meu::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void meu::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("luminosityBlock", &luminosityBlock, &b_luminosityBlock);
   fChain->SetBranchAddress("event", &event, &b_event);
   fChain->SetBranchAddress("HLT_IsoMu24_eta2p1", &HLT_IsoMu24_eta2p1, &b_HLT_IsoMu24_eta2p1);
   fChain->SetBranchAddress("HLT_IsoMu24", &HLT_IsoMu24, &b_HLT_IsoMu24);
   fChain->SetBranchAddress("HLT_IsoMu17_eta2p1_LooseIsoPFTau20", &HLT_IsoMu17_eta2p1_LooseIsoPFTau20, &b_HLT_IsoMu17_eta2p1_LooseIsoPFTau20);
   fChain->SetBranchAddress("PV_npvs", &PV_npvs, &b_PV_npvs);
   fChain->SetBranchAddress("PV_x", &PV_x, &b_PV_x);
   fChain->SetBranchAddress("PV_y", &PV_y, &b_PV_y);
   fChain->SetBranchAddress("PV_z", &PV_z, &b_PV_z);
   fChain->SetBranchAddress("nMuon", &nMuon, &b_nMuon);
   fChain->SetBranchAddress("Muon_pt", Muon_pt, &b_Muon_pt);
   fChain->SetBranchAddress("Muon_eta", Muon_eta, &b_Muon_eta);
   fChain->SetBranchAddress("Muon_phi", Muon_phi, &b_Muon_phi);
   fChain->SetBranchAddress("Muon_mass", Muon_mass, &b_Muon_mass);
   fChain->SetBranchAddress("Muon_charge", Muon_charge, &b_Muon_charge);
   fChain->SetBranchAddress("Muon_pfRelIso03_all", Muon_pfRelIso03_all, &b_Muon_pfRelIso03_all);
   fChain->SetBranchAddress("Muon_pfRelIso04_all", Muon_pfRelIso04_all, &b_Muon_pfRelIso04_all);
   fChain->SetBranchAddress("Muon_tightId", Muon_tightId, &b_Muon_tightId);
   fChain->SetBranchAddress("Muon_softId", Muon_softId, &b_Muon_softId);
   fChain->SetBranchAddress("Muon_dxy", Muon_dxy, &b_Muon_dxy);
   fChain->SetBranchAddress("Muon_dxyErr", Muon_dxyErr, &b_Muon_dxyErr);
   fChain->SetBranchAddress("Muon_dz", Muon_dz, &b_Muon_dz);
   fChain->SetBranchAddress("Muon_dzErr", Muon_dzErr, &b_Muon_dzErr);
   fChain->SetBranchAddress("Muon_jetIdx", Muon_jetIdx, &b_Muon_jetIdx);
   fChain->SetBranchAddress("Muon_genPartIdx", Muon_genPartIdx, &b_Muon_genPartIdx);
   fChain->SetBranchAddress("nTau", &nTau, &b_nTau);
   fChain->SetBranchAddress("Tau_pt", Tau_pt, &b_Tau_pt);
   fChain->SetBranchAddress("Tau_eta", Tau_eta, &b_Tau_eta);
   fChain->SetBranchAddress("Tau_phi", Tau_phi, &b_Tau_phi);
   fChain->SetBranchAddress("Tau_mass", Tau_mass, &b_Tau_mass);
   fChain->SetBranchAddress("Tau_charge", Tau_charge, &b_Tau_charge);
   fChain->SetBranchAddress("Tau_decayMode", Tau_decayMode, &b_Tau_decayMode);
   fChain->SetBranchAddress("Tau_relIso_all", Tau_relIso_all, &b_Tau_relIso_all);
   fChain->SetBranchAddress("Tau_jetIdx", Tau_jetIdx, &b_Tau_jetIdx);
   fChain->SetBranchAddress("Tau_genPartIdx", Tau_genPartIdx, &b_Tau_genPartIdx);
   fChain->SetBranchAddress("Tau_idDecayMode", Tau_idDecayMode, &b_Tau_idDecayMode);
   fChain->SetBranchAddress("Tau_idIsoRaw", Tau_idIsoRaw, &b_Tau_idIsoRaw);
   fChain->SetBranchAddress("Tau_idIsoVLoose", Tau_idIsoVLoose, &b_Tau_idIsoVLoose);
   fChain->SetBranchAddress("Tau_idIsoLoose", Tau_idIsoLoose, &b_Tau_idIsoLoose);
   fChain->SetBranchAddress("Tau_idIsoMedium", Tau_idIsoMedium, &b_Tau_idIsoMedium);
   fChain->SetBranchAddress("Tau_idIsoTight", Tau_idIsoTight, &b_Tau_idIsoTight);
   fChain->SetBranchAddress("Tau_idAntiEleLoose", Tau_idAntiEleLoose, &b_Tau_idAntiEleLoose);
   fChain->SetBranchAddress("Tau_idAntiEleMedium", Tau_idAntiEleMedium, &b_Tau_idAntiEleMedium);
   fChain->SetBranchAddress("Tau_idAntiEleTight", Tau_idAntiEleTight, &b_Tau_idAntiEleTight);
   fChain->SetBranchAddress("Tau_idAntiMuLoose", Tau_idAntiMuLoose, &b_Tau_idAntiMuLoose);
   fChain->SetBranchAddress("Tau_idAntiMuMedium", Tau_idAntiMuMedium, &b_Tau_idAntiMuMedium);
   fChain->SetBranchAddress("Tau_idAntiMuTight", Tau_idAntiMuTight, &b_Tau_idAntiMuTight);
   fChain->SetBranchAddress("MET_pt", &MET_pt, &b_MET_pt);
   fChain->SetBranchAddress("MET_phi", &MET_phi, &b_MET_phi);
   fChain->SetBranchAddress("MET_sumet", &MET_sumet, &b_MET_sumet);
   fChain->SetBranchAddress("MET_significance", &MET_significance, &b_MET_significance);
   fChain->SetBranchAddress("MET_CovXX", &MET_CovXX, &b_MET_CovXX);
   fChain->SetBranchAddress("MET_CovXY", &MET_CovXY, &b_MET_CovXY);
   fChain->SetBranchAddress("MET_CovYY", &MET_CovYY, &b_MET_CovYY);
   fChain->SetBranchAddress("nJet", &nJet, &b_nJet);
   fChain->SetBranchAddress("Jet_pt", Jet_pt, &b_Jet_pt);
   fChain->SetBranchAddress("Jet_eta", Jet_eta, &b_Jet_eta);
   fChain->SetBranchAddress("Jet_phi", Jet_phi, &b_Jet_phi);
   fChain->SetBranchAddress("Jet_mass", Jet_mass, &b_Jet_mass);
   fChain->SetBranchAddress("Jet_puId", Jet_puId, &b_Jet_puId);
   fChain->SetBranchAddress("Jet_btag", Jet_btag, &b_Jet_btag);
   fChain->SetBranchAddress("nGenPart", &nGenPart, &b_nGenPart);
   fChain->SetBranchAddress("GenPart_pt", GenPart_pt, &b_GenPart_pt);
   fChain->SetBranchAddress("GenPart_eta", GenPart_eta, &b_GenPart_eta);
   fChain->SetBranchAddress("GenPart_phi", GenPart_phi, &b_GenPart_phi);
   fChain->SetBranchAddress("GenPart_mass", GenPart_mass, &b_GenPart_mass);
   fChain->SetBranchAddress("GenPart_pdgId", GenPart_pdgId, &b_GenPart_pdgId);
   fChain->SetBranchAddress("GenPart_status", GenPart_status, &b_GenPart_status);
   Notify();
}

Bool_t meu::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void meu::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t meu::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef meu_cxx
