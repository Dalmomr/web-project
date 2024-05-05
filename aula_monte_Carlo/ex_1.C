{

	int d=2;
	int l=1;
	TCanvas *c1= new TCanvas("c1","c1",500,500);
	c1->Divide(4,3);

	TNtuple *t1= new TNtuple("t1","t1","x:theta");
	TF1 *sineFunc = new TF1("sineFunc", Form("(%.2i*0.5)*TMath::Sin(x)", l), 0, M_PI);

	TRandom rand;

	// Geração de um número aleatório entre 0 e 1
	double random_number;
	double random_angle;
	//M_PI;
	float x;
	float x_aim;
	int N=1000;
    std::vector<float> valores = {10, 50, 100, 1000,10000,5e5};
	int k=1;
	//TH2F **htemp=new TH2F*[12];
	
    for (int i = 0; i < valores.size(); i++) {
		N=valores[i];
		//cout<<N << " " <<i<<endl;
		for( int i=0; i<N; i++){
			
		random_number = rand.Uniform();	
		x=l*random_number;	
		random_number = rand.Uniform();	
		random_angle = 0 + (M_PI-0)*random_number;

		//x_aim=(l/2)*(sin(random_number));
				
			
		t1->Fill(x,random_angle);	
			
			
		}
		//std::string htemp_name="h"+std::to_string(i);
		//htemp[i]= new TH2F(htemp_name.c_str(), htemp_name.c_str(), N, 0, M_PI, N ,0,l);


		//TGraph *graph = new TGraph(); 
		//htemp_name="x:theta>>h"+std::to_string(i);
		//cout<<htemp_name<<endl;
		c1->cd(k);
		t1->Draw("x:theta","","");
	
		std::string message = Form(" N = %d", N);
		sineFunc->Draw("same");
		htemp->SetTitle(message.c_str());
		htemp->Delete();
		//htemp->Draw();
	
		//t1->Draw("theta","","");
		//sineFunc->Draw("");


	

		TNtuple *t2 = new TNtuple("message.c_str()","t2" , "x:theta");
		
		// Iterar sobre os pontos e adicionar aqueles que estão dentro da área do TF1 ao novo TNtuple
		for (int i = 0; i < t1->GetEntries(); i++) {
			t1->GetEntry(i);
			double x = t1->GetArgs()[0]; // Obtém o valor de x do TNtuple
			double theta = t1->GetArgs()[1]; // Obtém o valor de theta do TNtuple

			if (sineFunc->Eval(theta) >= x) {
				t2->Fill(x, theta); // Adiciona o ponto ao TNtuple t2
			}
		}

			// Plotar os pontos que estão dentro da área do TF1
		k++;
		c1->cd(k);
		//if(i>
		//std::string message = Form(" N = %d", N);
		

		
		t2->Draw("x:theta", "", "");
		//h1->GetXaxis()->SetTitle("#theta");
		int m;
		

		m= t2->GetEntries();
			
		double pi = (2.0 * N / m) * (float(l) / d);

		float I;
		
		I=d*M_PI*(float(m)/N);
		
		//cout<<(2.0 * N / m)<< " " << float(l / d)<< " " << l<< " " << d << endl;
		cout<< Form("O valor de pi para N= %.2i: ",N) << pi<< endl; 
		cout<< "Area efetiva  I:"<< I<< endl;
		//cout<<  float(m)/N<< endl;
		k++;
	}
}