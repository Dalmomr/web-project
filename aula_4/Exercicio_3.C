{
	
using namespace RooFit;
	
	
TFile *fin = new TFile("DataSet_lowstat.root");
TNtuple *tree = (TNtuple*)fin->Get("data");
// Definir a variável RooRealVar
RooRealVar mass("mass", "mass [GeV]", 2, 6);

// Criar o RooDataSet com a variável definida e o TNtuple
// I m p o r t a r   o   d a d o   u n b i n n e d
// --------------------------------------------------------------
// construtor do RooDataSet
RooDataSet *rooData = new RooDataSet("data1", "data1", RooArgSet(mass), RooFit::Import(*tree));

// O método data.Print("v") imprime informações sobre o RooDataSet,
// incluindo os nomes das variáveis e os valores dos eventos,
// para que você possa verificar se os dados foram importados corretamente.
rooData->Print("v");


RooPlot* frame3 = mass.frame(RooFit::Title("Imported Unbinned Mass"));
rooData->plotOn(frame3);
frame3->Draw();

/*
// Fit a Gaussian p.d.f to the data
RooRealVar mu("mu", "mean parameter", 1, 1.0, 1.0);
RooRealVar sigma("sigma", "Width of Gaussian", 0.05, 0.0, 0.05);
   
RooRealVar slope("slope", "Slope", -0.5, -10, 10);
RooRealVar intercept("intercept", "Intercept", 0, -10,10);

RooGaussian gauss("gaus", "Gaussian PDF", mass, mu, sigma);
RooPolynomial linear("linear", "Linear PDF", mass, RooArgList(intercept, slope),1);

RooRealVar sinal("sinal", "sinal", 0.5, 0, 1);

RooAddPdf sum_pdf("sum_pdf", "Sum of Gaussian and Linear", RooArgList(gauss, linear), RooArgList(sinal));


RooFitResult* result = sum_pdf.fitTo(rooData, RooFit::Save());

linear.plotOn(frame3, RooFit::LineColor(kRed));
sum_pdf.plotOn(frame3, RooFit::LineColor(kGreen));
gauss.plotOn(frame3, RooFit::LineColor(kBlack));


sum_pdf.fitTo(rooData);

// Estatísticas dos dados
//rooData.statOn(frame3);

// Criar a canvas para o plot
TCanvas *c3 = new TCanvas("exemplo03","exemplo03",800,400);
TPaveText *statistics = new TPaveText(0.6, 0.6, 0.9, 0.9, "NDC");
statistics->SetFillColor(0);
statistics->AddText(Form("Chi2/NdF = %.2f", frame3->chiSquare()));
statistics->AddText(Form("Linear Parameters:"));
statistics->AddText(Form("   Slope = %.3f", slope.getVal()));
statistics->AddText(Form("   Intercept = %.3f", intercept.getVal()));
statistics->AddText(Form("Gaussian Parameters:"));
statistics->AddText(Form("   Mean = %.3f", mu.getVal()));
statistics->AddText(Form("   Sigma = %.3f", sigma.getVal()));
statistics->AddText(Form("   amplitude = %.3f", sinal.getVal()));
statistics->Draw();

frame3->Draw();
c3->Draw();
statistics->Draw();
linear.Print("t")
*/
}	