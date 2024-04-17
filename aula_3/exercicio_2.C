{
	
ifstream arq1;
ifstream arq2;

arq1.open("graphdata.txt");
arq2.open("graphdata_error.txt");


float x[10],y[10];
float x_1[10], ex[10],y_1[10], ey[10];

int i=0;
 
while(!arq1.eof() and !arq2.eof()){

arq1>>x[i]>>y[i];
arq2>>x_1[i]>>y_1[i]>>ex[i]>>ey[i];

cout<<x[i]<<" "<<y[i]<<endl;

cout<<x_1[i]<<" "<<y_1[i]<<" "<<ex[i]<<" "<<ey[i]<<endl;


i++;


}	

TCanvas *c1= new TCanvas("c1","c1",1000,500);

c1->Divide(2,1);
c1->cd(1);
TGraph *t= new TGraph(10,x,y);
t->Draw();
t->SetTitle("Plot sem barra de erros");

c1->cd(2);
TGraphErrors *t1= new TGraphErrors(10,x_1,y_1,ex,ey);
t1->Draw();
t1->SetTitle("Plot com barra de erros");

}