#ifndef MAIN_CPP
#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include "baza_sq.hpp"
//string nazwa_cz,nr_normy,mat,norma_mat;
//float m_jedn,m_calk;
//int il_szt;
#endif
using squeaky::baza::Tabela;
string sred;
#include <sstream>
string nazwa_cz,nr_normy,mat,norma_mat;
float m_jedn,m_calk;
int il_szt;



void sr_nom()
{   cout << "Podaj ilosc sztuk" << endl;
    cin>>il_szt;
    cout << "Podaj srednice nominalna w mm" << endl;
    cin >> sred;
    sred="M"+sred;
    cout<<sred<<endl;
}
void sruba()
{
    cout << "Podaj rodzaj sruby:" << endl;
    cout << "[1] Sruba ze lbem szesciokatnym z gwintem krotkim" << endl;
    cout << "[2] Sruba ze lbem szesciokatnym z gwintem na ca³ej dlugosci"
         << endl;
    int rodz_sruby;
    cin >> rodz_sruby;
    int dl_sruby;
    string plik_normy;
    Tabela dane;
    switch(rodz_sruby)
    {
        case 1: dane.wczytaj("ISO4014.txt");nr_normy="EN-PN-ISO4014";break;
        case 2: dane.wczytaj("ISO4017.txt");nr_normy="EN-PN-ISO4017";break;
        dafault: std::cout<<"Wybrana wartosc jest poza zakresem.";
    }
    cout << "Podaj dlugosc sruby w mm" << endl;
    cin>>dl_sruby;
    m_jedn=dane.szukaj(dl_sruby, sred);
    if (m_jedn!=0)
    {
    cout << "Sruba "<<sred<< " o dl 60 cm wazy: " <<m_jedn<<std::endl;
    //nazwa_cz="Sruba "+sred+"x"+dl_sruby+"-5.8-B";
    stringstream s;
    string dl;
    s<<dl_sruby;
    s>>dl;
    nazwa_cz="Sruba "+sred+"x"+dl+"-5.8";
    //nr_normy=dl_sruby;
    m_calk=il_szt*m_jedn;
    mat="St3S";
    norma_mat="PN-88/H-84020";
    cout<<"Ilosc szuk wynosi: "<<il_szt<<endl;
    cout<<"Nazwa czesci: "<<nazwa_cz<<endl;
	cout<<"Numer normy: "<<nr_normy<<endl;
	cout<<"Masa jednostkowa: "<<m_jedn<<endl;
	cout<<"Masa calkowita: "<<m_calk<<endl;
	cout<<"Material: "<<mat<<endl;
	cout<<"Norma mat: "<<norma_mat<<endl;
    }
    else
    
        cout<<"Wybrana dlugosc nie miesci sie w normie"<<endl;
    
}
void nakretka()
{
}
void podkladka()
{
}

void element_zlaczny()
{
    cout << "Wybierz element zlaczny" << endl;
    cout << "[1] sruba" <<endl;
    cout << "[2] nakretka" <<endl;
    cout << "[3] podkladka" <<endl;
    cout << "[4] sruba+nakretka" <<endl;
    cout << "[5] nakretka+podkladka" <<endl;
    cout << "[6] sruba+nakretka+podkladka" << endl;
    short x;
    cin >> x;
    switch(x)
        {
            case 1: sr_nom();sruba();
                break;
            case 2: sr_nom();nakretka();
                break;
            case 3: sr_nom();podkladka();
                break;
            case 4: sr_nom();sruba();nakretka();
                break;
            case 5: sr_nom();nakretka();podkladka();
                break;
            case 6: sr_nom();sruba();nakretka();podkladka();
                break;
            default: cout << "Wybrana liczba nie zawiera sie w [0,6]" << endl;
        }

}
#ifndef MAIN_CPP
int main()
{
    
        
                                                                               
   element_zlaczny();
    system("pause");
}
#endif
