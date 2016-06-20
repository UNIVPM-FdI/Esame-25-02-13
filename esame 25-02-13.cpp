#include <iostream>
#include <fstream>
#define MAXSTAZIONI 40

using namespace std;

 struct localita {
	char nomelocalita[14];
	float min;
	float max;
};

fstream leggi;
int leggere_file(localita x[]);
int selezionastazioni(localita ar[],localita ar1[],int tot);
void stampare(localita ar1[], int sel);
float cercainnovamento(localita ar[], int tot);
void stanmpamigliore (float max_livello);

int main (int argc, char *argv[])
{
float max_assoluta;
localita array[MAXSTAZIONI];
leggere_file(array);
localita array1[MAXSTAZIONI];
int tot=leggere_file(array);
int Selezionate=selezionastazioni(array,array1,tot);
if (Selezionate>0)
stampare(array1,Selezionate);
max_assoluta=cercainnovamento (array,tot);
stanmpamigliore (max_assoluta);
return 0;
}

int leggere_file(localita x[])
{
	
	leggi.open ("neve.dat", ios::in);
	int d=0;
	while(leggi.good()) {
	leggi >> x[d].nomelocalita >> x[d].min >> x[d].max;
	d++;
	}
	leggi.close(); 
return d;
}
int selezionastazioni(localita ar[],localita ar1[],int tot)
{
	int cercate=0,i,altre;
	for(i=0;i<tot;i++)
	{
		if (ar[i].min>10 && ar[i].max<30)
		{ar1[cercate++]=ar[i];}
	
		altre=cercate;}
		for (i=0;i<tot;i++)
		{
			if (ar[i].min<=10 || ar[i].max>=30)
			{
				ar1[altre++]=ar[i];
			}
		}
	return cercate;
	}
void stampare(localita ar1[], int sel)
{
	int i;
	cout << "\nLocalita con l'innevamento richiesto (>10 e <30 cm)\n";
	for(i=0;i<sel;i++)
	{
		cout << ar1[i].nomelocalita << " " << ar1[i].min << " " << ar1[i].max << endl;
	}
}

float cercainnovamento(localita ar[], int tot)
{
	float max_inn=0;
	int i;
	for(i=0;i<tot;i++)
	{
	 if (ar[i].max>=max_inn)
	 max_inn=ar[i].max;
	}
	 return max_inn;
}

void stanmpamigliore (float max_livello)
{
	localita app;
leggi.open("neve.dat",ios::in);
cout << "\nLocalita con l'innevamento non inferiore al 10%\n";
while (leggi.good())
{
	leggi >> app.nomelocalita >> app.min >> app.max;
	if (app.max>=max_livello/10)
	cout << app.nomelocalita << " " << app.min << " " << app.max << endl;
}
leggi.close() ;
}
