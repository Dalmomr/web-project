{

using namespace RooFit;

TFile file("output.root");	
TTree* tree = dynamic_cast<TTree*>(file.Get("tree_pythia"));	
tree->Draw("particle_pz","particle_pz>-10 && particle_pz<10","");

std::vector<float>* pz_vec = nullptr;
std::vector<float>* py_vec = nullptr;
std::vector<float>* px_vec = nullptr;

tree->SetBranchAddress("particle_pz", &pz_vec);
tree->SetBranchAddress("particle_py", &py_vec);
tree->SetBranchAddress("particle_px", &px_vec);

if (!pz_vec || !py_vec || !px_vec) {
	std::cerr << "Erro: Não foi possível associar os branches do TTree." << std::endl;
	return;
}

// Crie vetores para armazenar os valores das variáveis
std::vector<float> pz_values;
std::vector<float> py_values;
std::vector<float> px_values;

// Preencha os vetores com os valores do TTree
for (Long64_t i = 0; i < tree->GetEntries(); ++i) {
	tree->GetEntry(i);
	
	for (size_t j = 0; j < pz_vec->size(); ++j) {
		pz_values.push_back(pz_vec->at(j));
		py_values.push_back(py_vec->at(j));
		px_values.push_back(px_vec->at(j));
	}
}

// Crie RooRealVar para cada variável
RooRealVar pz_var("pz_var", "pz", -8000., 8000.);
RooRealVar py_var("py_var", "py", -10000., 10000.);
RooRealVar px_var("px_var", "px", -10000., 10000.);

// Crie RooDataSet
RooDataSet rooData("data", "data", RooArgSet(pz_var, py_var, px_var));
for (size_t i = 0; i < pz_values.size(); ++i) {
	pz_var.setVal(pz_values[i]);
	py_var.setVal(py_values[i]);
	px_var.setVal(px_values[i]);
	rooData.add(RooArgSet(pz_var, py_var, px_var));
}




// Plote o RooDataSet
RooPlot* frame3 = pz_var.frame(Title("Pz"));
rooData.plotOn(frame3);
frame3->Draw();

RooRealVar mean1("mean1", "mean of first Gaussian", -6500, -6700, -6400);
RooRealVar sigma1("sigma1", "width of first Gaussian", 30, 20, 50);
RooRealVar mean2("mean2", "mean of second Gaussian", 0, -1000, 1000);
RooRealVar sigma2("sigma2", "width of second Gaussian", 100, 50, 200);
RooRealVar mean3("mean3", "mean of third Gaussian", 6500, 6500, 6700);
RooRealVar sigma3("sigma3", "width of third Gaussian", 30, 20, 50);

// Crie as três Gaussianas
RooGaussian gauss1("gauss1", "first Gaussian PDF", pz_var, mean1, sigma1);
RooGaussian gauss2("gauss2", "second Gaussian PDF", pz_var, mean2, sigma2);
RooGaussian gauss3("gauss3", "third Gaussian PDF", pz_var, mean3, sigma3);

// Crie RooRealVar para os coeficientes de cada Gaussiana
RooRealVar coef1("coef1", "coefficient of first Gaussian", 0.5, 0., 3);
RooRealVar coef2("coef2", "coefficient of second Gaussian", 80, 0., 100);
RooRealVar coef3("coef3", "coefficient of third Gaussian", 0.5, 0., 3);

// Crie a PDF de soma das três Gaussianas
RooAddPdf sum_pdf("sum_pdf", "Sum of three Gaussians", RooArgList(gauss1, gauss2, gauss3), RooArgList(coef1, coef2, coef3));

// Faça o ajuste
RooFitResult* result = sum_pdf.fitTo(rooData, RooFit::Save());



// Criar a canvas para o plot
TCanvas *c3 = new TCanvas("exemplo03","exemplo03",800,400);
TPaveText *statistics = new TPaveText(0.6, 0.6, 0.9, 0.9, "NDC");
statistics->SetFillColor(0);
statistics->AddText(Form("Chi2/NdF = %.2f", frame3->chiSquare()));
//statistics->AddText(Form("Linear Parameters:"));
//statistics->AddText(Form("   Slope = %.3f", slope.getVal()));
//statistics->AddText(Form("   Intercept = %.3f", intercept.getVal()));
statistics->AddText(Form("Gaussian Parameters:"));
statistics->AddText(Form("   Mean_1 = %.3f", mean1.getVal()));
statistics->AddText(Form("   Sigma = %.3f", sigma1.getVal()));
statistics->AddText(Form("   Mean_2 = %.3f", mean2.getVal()));
statistics->AddText(Form("   Sigma_2 = %.3f", sigma2.getVal()));
statistics->AddText(Form("   Mean_3 = %.3f", mean3.getVal()));
statistics->AddText(Form("   Sigma_3 = %.3f", sigma3.getVal()));
statistics->AddText(Form("   cof_1 = %.3f", coef1.getVal()));
statistics->AddText(Form("   cof_2 = %.3f", coef2.getVal()));
statistics->AddText(Form("   cof_3 = %.3f", coef3.getVal()));
//statistics->AddText(Form("   amplitude = %.3f", sinal.getVal()));
statistics->Draw();
sum_pdf.plotOn(frame3, RooFit::LineColor(kRed));
frame3->Draw();
sum_pdf.plotOn(frame3, RooFit::LineColor(kRed));
c3->Draw();
statistics->Draw();

//linear.Print("t");

/*
linear.plotOn(frame3, RooFit::LineColor(kRed));
sum_pdf.plotOn(frame3, RooFit::LineColor(kGreen));
gauss3.plotOn(frame3, RooFit::LineColor(kRed));
*/

}