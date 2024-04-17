{
using namespace RooFit;


// Definindo variável e parâmetros da Crystal Ball
RooRealVar x("x", "x", -10, 10);
RooRealVar mean("mean", "mean", 0, -10, 10);
RooRealVar sigma("sigma", "sigma", 1, 0.1, 10);
RooRealVar alpha("alpha", "alpha", 1.5, 0.1, 10);
RooRealVar n("n", "n", 5, 0.1, 10);

// Criando a PDF Crystal Ball
RooCBShape crystalBall("crystalBall", "Crystal Ball PDF", x, mean, sigma, alpha, n);

// Gerando toy data
RooDataSet *data = crystalBall.generate(x, 1000);

// Ajustando os dados
RooFitResult *result = crystalBall.fitTo(*data, RooFit::Save(true));

// Criando o frame para o plot
RooPlot *frame = x.frame(RooFit::Title("Crystal Ball Fit"));

// Plotando os dados
data->plotOn(frame);

// Plotando a PDF ajustada
crystalBall.plotOn(frame);

// Criando a canvas para o plot
TCanvas *canvas = new TCanvas("canvas", "Crystal Ball Fit", 800, 600);

// Adicionando a caixa de informação estatística para os dados e o modelo
TPaveText *statistics = new TPaveText(0.6, 0.6, 0.9, 0.9, "NDC");
statistics->SetFillColor(0);
statistics->AddText(Form("Data Statistics:"));
statistics->AddText(Form("Entries: %d", data->numEntries()));
statistics->AddText(Form("Model Statistics:"));
statistics->AddText(Form("Chi2/NdF: %.2f", frame->chiSquare()));
statistics->AddText(Form("Mean: %.2f", mean.getVal()));
statistics->AddText(Form("Sigma: %.2f", sigma.getVal()));
statistics->AddText(Form("Alpha: %.2f", alpha.getVal()));
statistics->AddText(Form("N: %.2f", n.getVal()));

// Desenhando o frame
frame->Draw();

// Desenhando a canvas
canvas->Draw();	
statistics->Draw();

	
}	