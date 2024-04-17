#define meu_cxx
#include "meu.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void meu::Loop(TTree* tree1)
{
	TFile *file = new TFile("exercicio_0", "RECREATE");
	
	    if (!file || file->IsZombie()) {
        throw std::runtime_error("Erro ao abrir o arquivo para escrita");
    }

    if (!tree1) {
        throw std::runtime_error("Erro: Ponteiro de árvore inválido");
    }

    // Define as variáveis que serão preenchidas na TTree
    Float_t muon_mass;
    Float_t tau_mass;

    // Associa as variáveis aos ramos da TTree
    tree1->Branch("muon_mass", &muon_mass, "muon_mass/F");
    tree1->Branch("tau_mass", &tau_mass, "tau_mass/F");

    if (!fChain) {
        throw std::runtime_error("Erro: fChain não está inicializado");
    }

    Long64_t nentries = fChain->GetEntriesFast();
    Long64_t nbytes = 0, nb = 0;

    for (Long64_t jentry = 0; jentry < nentries; jentry++) {
        Long64_t ientry = LoadTree(jentry);
        if (ientry < 0) break;

        nb = fChain->GetEntry(jentry);   
        nbytes += nb;

        // Verifica se Muon_mass e Tau_mass têm pelo menos um elemento
        if (Muon_mass[0] && Tau_mass[0]) {
            // Preenche as variáveis com os valores dos ramos
            muon_mass = Muon_mass[0];
            tau_mass = Tau_mass[0];

            // Preenche os ramos da TTree com os valores das variáveis
            tree1->Fill();
        } else {
            std::cerr << "Acesso inválido aos dados de Muon_mass ou Tau_mass na entrada " << jentry << std::endl;
        }
		tree1->Write();
    }
}