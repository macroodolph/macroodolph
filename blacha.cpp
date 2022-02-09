#ifndef MAIN_CPP
#include <iostream>
#include <sstream>
using namespace std;
string nazwa_cz,nr_normy,mat,norma_mat;
float m_jedn,m_calk;
int il_szt;


#endif
#include <stdio.h>


void blacha()

{   cout << "Podaj ilosc sztuk" << endl;
    cin>>il_szt;
    float a,b,c,g=7.85;
    cout<<"Podaj grubosc blachy w mm"<<endl;
    cin>>a;
    cout<<"Podaj dlugosc blachy w mm"<<endl;
    cin>>b;
    cout<<"Podaj szerokosc blachy w mm"<<endl;
    cin>>c;
    m_jedn=a*b*c*7.85e-6;
    m_calk=il_szt*m_jedn;   
    cout<<"Masa blachy wynosi: ";
    printf("%.2f \n",  m_jedn);
    //nazwa_cz
    
    stringstream s,t,u;
    string wym;
    s<<a;
    s>>wym;
    cout<<wym<<endl;
    nazwa_cz="Blacha "+wym+"x";
    t<<b;
    t>>wym;
    cout<<wym<<endl;
    nazwa_cz=nazwa_cz+wym+"x";
    u<<c;
    u>>wym;
    cout<<wym<<endl;
    nazwa_cz=nazwa_cz+wym;
    cout<<nazwa_cz<<endl;
    mat="St3S";
    norma_mat="PN-88/H-84020";
    nr_normy="PN-80/H-92200";
    
    
}



#ifndef MAIN_CPP
int main()
{



    blacha();
    system("pause");
}
#endif
