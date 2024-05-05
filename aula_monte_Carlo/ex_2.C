{


double differentialCrossSection(double E, double theta, double m, double alpha) {
    double r0 = (alpha*alpha) / (2*m*m);
	double E_prime= (E)/(1+ (E/m)*(1-std::cos(theta)));
    double dOmega = std::sin(theta);
	//cout<<E_prime<<endl;
    return (r0 * r0) * std::pow((E_prime / E), 2) * ((E_prime / E) + (E / E_prime) - dOmega * dOmega);
}

int N=100000;
double m=0.5;
double alpha= 0.0072992701;

TCanvas *c1= new TCanvas("c1","c1",500,800);
c1->Divide(3,1);
double E = 10; // Energia do fóton incidente (1 MeV)
//double E_prime = 9.0e5; // Energia do fóton espalhado (900 keV)
TNtuple *t1= new TNtuple("t1","t1","x");
TNtuple *t2= new TNtuple("t2","t2","x_aim:theta");

double random_number;
double x,x_aim,theta;
TRandom rand;
double max_value=0;
float aux=0;
for(float i=0; i<M_PI;i=i+0.01){
	if(i==0){
		max_value=differentialCrossSection(E,i,m,alpha);
	}
	else if(max_value<differentialCrossSection(E,i,m,alpha)){
		max_value=differentialCrossSection(E,i,m,alpha);
		aux=i;
		//cout<<aux<<endl;
	}
	//cout<< max_value<< " " << differentialCrossSection(E,i,m,alpha) <<endl;
}	



//max_value= differentialCrossSection(E,M_PI/2,m,alpha);
	for(int j=0; j<N;j++){	
		random_number = rand.Uniform();	
		x=max_value*random_number;
		
		random_number = rand.Uniform();
		theta=M_PI*random_number;	
		if(differentialCrossSection(E,theta,m,alpha)>x){
			x_aim=x;
			t2->Fill(x_aim,theta);
			//cout<<"aqui"<<endl;
			//j=1200;
		}
		t1->Fill(x);
		//cout<< x << "  " << differentialCrossSection(E,theta,m,alpha)<< endl;
	}	
	
c1->cd(1);
t1->Draw("x>>h2","","");
h2->GetXaxis()->SetTitle("d#sigma/d#Omega");
h2->SetTitle("Area Total");


c1->cd(2);
t2->Draw("theta>>h1","","");
h1->SetTitle("Area efetiva");
h1->GetXaxis()->SetTitle("#theta");


c1->cd(3);

t2->Draw("x_aim>>h3","","");
h3->SetTitle("Area efetiva");
h3->GetXaxis()->SetTitle("d#sigma/d#Omega");
}



