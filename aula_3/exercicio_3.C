{
	
TRandom *t= new TRandom;
TH1F *h1= new TH1F("Fit gauss","Fit gauss",50,0,10);

for(int i=0; i<10000;i++){
	
	float random_gauss= t->Gaus(5,2);
	
	h1->Fill(random_gauss);
}	

h1->Draw();
h1->Fit("gaus");
gStyle->SetOptFit(1111);
}