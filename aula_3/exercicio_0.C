{
TCanvas *c1= new TCanvas("c1","c1",1500,800);	

c1->Divide(3,1);


TFile *input = new TFile("DYJetsToLL.root","read");
TTree *t = (TTree *)input->Get("Events");

c1->cd(1);

c1->cd(2);

c1->cd(3);

/*
t->Draw("Muon_mass");



t->Draw("Muon_charge");




t->Draw("run");
*/
t->MakeClass("meu");

/*.L meu.C

meu l;

*/
}