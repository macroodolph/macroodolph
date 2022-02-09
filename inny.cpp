#ifndef MAIN_CPP
#include <iostream>
using namespace std;
#include <fstream>
#include <iostream>
///#include "pl.cpp"
using namespace std;
	string plik_b="tabela.txt";
    ofstream pisz(plik_b.c_str());

#endif





//std::string PL(std::string Znak);

void inny()
{
    string nazwa_cz;
    cout << "Podaj nzawê czêœci: " << endl;
    getline(cin,nazwa_cz);
    cout<<nazwa_cz<<endl;
    cout<<"Podaj nr normy materia³owej"<<endl;
 
    pisz<<nazwa_cz;   
    
}
#ifndef MAIN_CPP
int main()
{
    
    
	string plik_b="tabela.txt";
    ofstream pisz(plik_b.c_str());
  system("mode con: cp select=1250");
  //system("cls");
  inny();

  
    //cout<<PL(nazwa_cz);
   // pisz<< PL(nazwa_cz);


    system("pause");
}

#endif

