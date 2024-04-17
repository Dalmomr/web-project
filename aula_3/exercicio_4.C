{
TCanvas *c1= new TCanvas("c1","c1",1500,800);	

TFile *input = new TFile("tree.root","read");
TTree *t = (TTree *)input->Get("tree1");

gStyle->SetOptFit(1111);

TF1 *gauss = new TF1("g1","gaus",0,10);


c1->Divide(3,1);
c1->cd(1);
t->Draw("ebeam>>h1");
h1->Fit(gauss);

float mean=gauss->GetParameter(1);
float sigma=gauss->GetParameter(2); 

c1->cd(2);

char cut[20];

sprintf(cut,"ebeam>%f",0.2 + mean);

t->Draw("px+py+pz>>h2",cut,"");


h2->Fit(gauss);
h2->SetTitle("px+py+pz (ebeam>0.2 + Mean_{ebeam})");

c1->cd(3);


t->Draw("px+py+pz>>h3","","");

h3->Fit(gauss);
h3->SetTitle("px+py+pz");

c1->Print("exercicio4.png","png");
}