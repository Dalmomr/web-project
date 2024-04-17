{
	
TF1 * f1 = new TF1("f1","[0]*sin([1]*x)/x", -500, +500);
	
f1->SetParameter(0, 1); // p0 = 1
f1->SetParameter(1, 2); // p1 = 2
f1->SetLineColor(kBlue);   


TCanvas *c1 = new TCanvas("c1", "Function Plot", 800, 600);

f1->Draw();


// Calcula o valor da função para x = 1
double functionValue = f1->Eval(1);
printf("a. Function value for x = 1: %.4f\n", functionValue);

// Calcula a derivada da função para x = 1
double functionDerivative = f1->Derivative(1);
printf("b. Function derivative for x = 1: %.4f\n", functionDerivative);

// Calcula a integral da função entre 0 e 3
double integral = f1->Integral(0, 3);
printf("c. Integral of the function between 0 and 3: %.4f\n", integral);


}