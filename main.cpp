#define MAIN_CPP
#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include "baza_sq.hpp"
#include "el_zlaczny.cpp"
#include "blacha.cpp"
#include "inny.cpp"


#include <iomanip>
//*******************************************************
void 
int main()
{
	    //string plik_a;
	string plik_b="tabela.dxf";
    // ------------------------------------------------
	//cout << "Podaj nazwe pliku wejsciowego : ";
	//cin >> plik_a;
	//ifstream czyt(plik_a.c_str() );   // `1
	// ------------------------------------------------
	//cout << "Podaj nazwe pliku wyjsciowego : ";
	//cin >> plik_b;
    ofstream pisz(plik_b.c_str());
    
    
    cout << "Podaj ilosc pozycji w tabeli: ";
    int	il_poz,wys;
    cin >> il_poz;
    
    
    
    
    
    
    
        //SECTION TABLES - STYLE
    pisz<<"  0\nSECTION\n  2\nTABLES\n  0\nTABLE\n  2\nSTYLE\n 70\n"
    "     3\n  0\nSTYLE\n  2\nROMAND\n 70\n"
    "     0\n 40\n3.0\n 41\n1.0\n 50\n0.0\n 71\n"
    "     0\n 42\n3.0\n  3\nromans.shx\n  4\n\n  0\nENDTAB\n  0\nENDSEC\n";

	//SECTION ENTITIES
	pisz<<"  0\nSECTION\n  2\nENTITIES\n";


    //cout << "Ilosc pozycji w tabeli wynosi: " << il_poz << endl;
    //WYSOKOŒÆ CA£EJ TABELI
    wys=100+il_poz*80;
    //cout<<"Wysokosc tabeli wynosi "<<wys<<endl;

    //LINIE GRUBE POZIOME
    pisz<<"  0\nLINE\n  8\nGRUBA\n  62\n     3\n 10\n0\n 20\n0\n 11\n1800\n 21\n0\n";                // linia (0,0) (1800,0)
    pisz<<"  0\nLINE\n  8\nGRUBA\n  62\n     3\n 10\n0\n 20\n100\n 11\n1800\n 21\n100\n";            // linia (0,100) (1800,100)
    pisz<<"  0\nLINE\n  8\nGRUBA\n  62\n     3\n 10\n0\n 20\n"<<wys<<"\n 11\n1800\n 21\n"<<wys<<"\n";// linia (0,wys) (1800,wys)
    //LINIE CIENKIE POZIOME
    pisz<<"  0\nLINE\n  8\nCIENKA\n  62\n     1\n 10\n1550\n 20\n50\n 11\n1800\n 21\n50\n";       // linia (1550,50) (1800,50)
    for (int i=il_poz;i>1;i=--i)
    {
      pisz<<"  0\nLINE\n  8\nCIENKA\n  62\n     1\n 10\n0\n 20\n"<<20+i*80<<"\n 11\n1800\n 21\n"<<20+i*80<<"\n";// linia (0,wys) (1800,wys)
      //cout<<20+i*80<<endl;
    };
    //LINIE GRUBE PIONOWE
    pisz<<"  0\nLINE\n  8\nGRUBA\n  62\n     3\n 10\n0\n 20\n0\n 11\n0\n 21\n"<<wys<<"\n";        // linia (0,0)     (0,wys)
    pisz<<"  0\nLINE\n  8\nGRUBA\n  62\n     3\n 10\n100\n 20\n0\n 11\n100\n 21\n"<<wys<<"\n";    // linia (100,0)   (100,wys)
    pisz<<"  0\nLINE\n  8\nGRUBA\n  62\n     3\n 10\n850\n 20\n0\n 11\n850\n 21\n"<<wys<<"\n";    // linia (850,0)   (100,wys)
    pisz<<"  0\nLINE\n  8\nGRUBA\n  62\n     3\n 10\n950\n 20\n0\n 11\n950\n 21\n"<<wys<<"\n";    // linia (950,0)   (950,wys)
    pisz<<"  0\nLINE\n  8\nGRUBA\n  62\n     3\n 10\n1100\n 20\n0\n 11\n1100\n 21\n"<<wys<<"\n";  // linia (1100,0)  (1100,wys)
    pisz<<"  0\nLINE\n  8\nGRUBA\n  62\n     3\n 10\n1330\n 20\n0\n 11\n1330\n 21\n"<<wys<<"\n";  // linia (1330,0)  (1330,wys)
    pisz<<"  0\nLINE\n  8\nGRUBA\n  62\n     3\n 10\n1550\n 20\n0\n 11\n1550\n 21\n"<<wys<<"\n";  // linia (1550,0)  (1550,wys)
    pisz<<"  0\nLINE\n  8\nGRUBA\n  62\n     3\n 10\n1670\n 20\n50\n 11\n1670\n 21\n"<<wys<<"\n"; // linia (1670,50) (1670,wys)

    //CYFRY (Poz.)
    for (int i=il_poz;i>0;i=--i)
    {   pisz<<"0\nTEXT\n  7\nROMAND\n 8\n0\n 62\n"
        "     4\n 10\n10\n 20\n"<<40+i*80<<
        "\n 11\n50\n 21\n"<<40+i*80<<
        "\n 40\n40\n 72\n     1\n 1\n";
        pisz<<i<<endl;
    };
    
    
    
    
    
    
    
    
     
    for (int i=1;i<=il_poz;i++)
    {
    cout<<"\nPodaj rodzaj elementu dla poz. nr "<<i<<"\n";
    cout<<"[1] Blacha"<<endl;
    cout<<"[2] Element zlaczny"<<endl;
    cout<<"[3] Pret(plaskownik)"<<endl;
    cout<<"[4] Pret okragly"<<endl;
    cout<<"[5] Rura"<<endl;
    cout<<"[6] Ksztaltownik"<<endl;
    cout<<"[7] inny"<<endl;


    


    short x;
    cin >> x;
    switch(x)
        {
            case 1: blacha();
                break;
            case 2: element_zlaczny();//cout << element_zlaczny() << endl;
                break;
            case 3: cout << "Wybrano 3" << endl;
                break;
            case 4: cout << "Wybrano 4" << endl;
                break;
            case 5: cout << "Wybrano 5" << endl;
                break;
            case 6: cout << "Wybrano 6" << endl;
                break;
            case 7: inny();
                break;
            default: cout << "Wybrana liczba nie zawiera sie w [0,7]" << endl;
        };


        
    //Nazwa czêœci (zespo³u)
        pisz<<"0\nTEXT\n  7\nROMAND\n 8\n0\n 62\n"
        "     3\n 10\n110\n 20\n"<<45+i*80<<
        //"\n 11\n840\n 21\n"<<40+i*80<<
        "\n 40\n30\n 72\n     0\n 1\n";
        pisz<<nazwa_cz<<endl;
        //cout<<nazwa_cz;
        
        
    //Iloœæ
        pisz<<"0\nTEXT\n  7\nROMAND\n 8\n0\n 62\n"
        "     3\n 10\n860\n 20\n"<<45+i*80<<
        "\n 11\n900\n 21\n"<<45+i*80<<
        "\n 40\n30\n 72\n     1\n 1\n";
        pisz<<il_szt<<endl;
        //cout<<nazwa_cz;

    //Materia³
        pisz<<"0\nTEXT\n  7\nROMAND\n 8\n0\n 62\n"
        "     3\n 10\n960\n 20\n"<<45+i*80<<
        //"\n 11\n840\n 21\n"<<40+i*80<<
        "\n 40\n30\n 72\n     0\n 1\n";
        pisz<<mat<<endl;
        //cout<<nazwa_cz;

    //Nr normy materia³owej
        pisz<<"0\nTEXT\n  7\nROMAND\n 8\n0\n 62\n"
        "     3\n 10\n1110\n 20\n"<<45+i*80<<
        "\n 11\n1320\n 21\n"<<45+i*80<<
        "\n 40\n30\n 72\n     5\n 1\n";
        pisz<<norma_mat<<endl;
        //cout<<nazwa_cz;
        
    //Nr rysunku lub normy  
        pisz<<"0\nTEXT\n  7\nROMAND\n 8\n0\n 62\n"
        "     3\n 10\n1340\n 20\n"<<45+i*80<<
        "\n 11\n1540\n 21\n"<<45+i*80<<
        "\n 40\n30\n 72\n     5\n 1\n";
        pisz<<nr_normy<<endl;
        //cout<<nazwa_cz;
        
    //Masa jednostkowa w kg
        pisz<<"0\nTEXT\n  7\nROMAND\n 8\n0\n 62\n"
        "     3\n 10\n1560\n 20\n"<<45+i*80<<
        "\n 11\n1660\n 21\n"<<45+i*80<<
        "\n 40\n30\n 72\n     5\n 1\n";
        
        
            if (m_jedn>1) pisz << fixed << setprecision(2)<<m_jedn<<endl;
    else if (m_jedn>0.1) pisz << fixed << setprecision(3)<<m_jedn<<endl;
         else if (m_jedn>0.01) pisz << fixed << setprecision(4)<<m_jedn<<endl;
              else if (m_jedn>0.001) pisz << fixed
                                     << setprecision(5)<<m_jedn<<endl;
                   else if (m_jedn>0.000001)
                        pisz << fixed << setprecision(6)<<m_jedn<<endl;
                        else pisz << fixed << setprecision(2)<<m_jedn<<endl;


        //cout<<nazwa_cz;

    //Masa ca³kowita w kg
        pisz<<"0\nTEXT\n  7\nROMAND\n 8\n0\n 62\n"
        "     3\n 10\n1680\n 20\n"<<45+i*80<<
        "\n 11\n1790\n 21\n"<<45+i*80<<
        "\n 40\n30\n 72\n     5\n 1\n";
        pisz<< fixed << setprecision(2)<<m_calk<<endl;
        
        
  
        //cout<<nazwa_cz;
        
    }
    




    //Zawartoœæ tabelki - poszczególne elementy
    // il_szt mat norma_mat nr_normy m_jedn m_calk 
    

    
    //Zamkniêcie sekcji ENTITIES
	pisz<<"  0\nENDSEC\n  0\nEOF"; 
  
		

    system("pause");
}


