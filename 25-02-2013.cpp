#include <iostream>
#include <cstring>
#include <fstream>
#define N 40
using namespace std;
struct localita{
char stazioni [14];
float min;
float max;
}app;
int Carica_da_file(localita [],char*);
int SelezioneStazione(localita [],localita [],int);
void Stampa (localita [],int );
float Cerca_innevamento_massimo(localita [],int );
void Stampa_Migliori(char*,float);
int main()
{
    int quante=0,selezione=0;
    float max_innev=0;
    localita array[N];
    localita array1[N];
    char nome[15];
    cout<<"Inserisci il nome del file"<<endl;
    cin>>nome;
    quante=Carica_da_file(array,nome);
    selezione=SelezioneStazione(array,array1,quante);
    if (selezione>0){
        cout<<"gli impianti con innevamento compreso tra 10 e 30 sono"<<endl;
        Stampa(array1,selezione);
    }
    max_innev=Cerca_innevamento_massimo(array,quante);
    Stampa_Migliori(nome,max_innev);
    return 0;
}

int Carica_da_file(localita array[],char* nomefile){
fstream input;
int i=0;
input.open(nomefile,ios::in);
if (input.fail()){
    cout<<"File Inesistente"<<endl;
    return 0;
}
else{
    while(input.good()){
    input>>array[i].stazioni>>array[i].min>>array[i].max;
    i++;
    }
}
return i;
input.close();
}

int SelezioneStazione(localita array[],localita array1[],int totali){
int c=0,al;
for(int i=0;i<totali;i++)
    if (array[i].min>10&&array[i].max<30){
        array1[c++]=array[i];
    }

al=c;
for(int i=0;i<totali;i++)
    if (array[i].min<=10||array[i].max>=30){
      array1[al++]=array[i];
    }

return c;
}

void Stampa(localita array1[],int sel){
for(int i=0;i<sel;i++){
    cout<<array1[i].stazioni<<" "<<array1[i].min<<" "<<array1[i].max<<endl;
}
}

float Cerca_innevamento_massimo(localita array[],int quante){
float massimo=0;
for(int i=0;i<=quante;i++){
    if(array[i].max>massimo){
        massimo=array[i].max;
    }
}
return massimo;
}

void Stampa_Migliori(char*nomefile,float max_innev){
cout<<"quelli con il 10%"<<endl;
fstream input;
input.open(nomefile,ios::in);
while(input.good()){
    input>>app.stazioni>>app.min>>app.max;
    if(app.max>=(max_innev/10)){
        cout<<app.stazioni<<" "<<app.min<<" "<<app.max<<endl;
    }
}
}

//Coded by DarkCerfa
