{


TFile *fin = new TFile("example_data.root");
TNtuple *nt = (TNtuple*)fin->Get("nt");

// Definir a variável RooRealVar
RooRealVar mass("mass", "mass [GeV]", 0, 2.0);

// Criar o RooDataSet com a variável definida e o TNtuple
// I m p o r t a r   o   d a d o   u n b i n n e d
// --------------------------------------------------------------
// construtor do RooDataSet
RooDataSet rooData("data", "data", RooArgSet(mass), RooFit::Import(*nt));

// O método data.Print("v") imprime informações sobre o RooDataSet,
// incluindo os nomes das variáveis e os valores dos eventos,
// para que você possa verificar se os dados foram importados corretamente.
rooData.Print("v");


// Definindo variável e parâmetros da Crystal Ball

RooPlot *frame3 = mass.frame(RooFit::Title("Crystal Ball Fit"));
rooData.plotOn(frame3);

RooRealVar mean("mean", "mean", 1, 1, 1);
RooRealVar sigma("sigma", "sigma", 0.05, 0.0, 0.05);
RooRealVar alpha("alpha", "alpha", -0.5, -10, 10);
RooRealVar n("n", "n", 0, -10,10);

// Criando a PDF Crystal Ball
RooCBShape crystalBall("crystalBall", "Crystal Ball PDF", mass, mean, sigma, alpha, n);


RooFitResult *result = crystalBall.fitTo(rooData, RooFit::Save(true));
crystalBall.fitTo(rooData);

crystalBall.plotOn(frame3, RooFit::LineColor(kGreen));


TCanvas *c3 = new TCanvas("exemplo03","exemplo03",800,400);
TPaveText *statistics = new TPaveText(0.6, 0.6, 0.9, 0.9, "NDC");
statistics->SetFillColor(0);
statistics->AddText(Form("Data Statistics:"));
statistics->AddText(Form("Entries: %d", rooData.numEntries()));
statistics->AddText(Form("Model Statistics:"));
statistics->AddText(Form("Chi2/NdF: %.2f", frame3->chiSquare()));
statistics->AddText(Form("Mean: %.2f", mean.getVal()));
statistics->AddText(Form("Sigma: %.2f", sigma.getVal()));
statistics->AddText(Form("Alpha: %.2f", alpha.getVal()));
statistics->AddText(Form("N: %.2f", n.getVal()));

frame3->Draw();
c3->Draw();
statistics->Draw();





}