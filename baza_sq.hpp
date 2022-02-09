#include <sstream>


#include <vector>


namespace squeaky {
namespace baza {

class Tabela {
private:
	std::vector<std::string> naglowki;
	std::vector<double *> rekordy;
	int ilosc_kolumn;
	int ilosc_wierszy;
public:
	~Tabela();
	void wczytaj(const std::string & nazwa);
	void wypisz();
	double szukaj(double dlugosc, const std::string & etykieta);
};

Tabela::~Tabela()
{
	for(std::vector<double *>::iterator iter = rekordy.begin();
        iter != rekordy.end(); iter++)
        {
		delete *iter;
	    }
}

void Tabela::wczytaj(const std::string & nazwa) {
	std::ifstream plik;
	plik.open(nazwa.c_str());

	//wczytaj naglowki
	std::string naglowek;
	std::getline(plik, naglowek);

	std::istringstream naglowekStream(naglowek);

	while(!naglowekStream.eof()) {
		std::string etykieta;
		naglowekStream >> etykieta;
		naglowki.push_back(etykieta);
	}


	ilosc_kolumn = naglowki.size();

	//wczytaj dane
	std::string linia;
	while(std::getline(plik, linia)) {
		std::istringstream liniaStream(linia);

		double * rekord = new double[ilosc_kolumn];

		for(int i = 0; i < ilosc_kolumn; i++) {
			liniaStream >> rekord[i];
		}

		rekordy.push_back(rekord);

		ilosc_wierszy++;
	}

	plik.close();
}


double Tabela::szukaj(double dlugosc, const std::string & etykieta) {
	int index = std::find(naglowki.begin(), naglowki.end(),
                          etykieta()) - naglowki.begin();

	for(std::vector<double *>::iterator iter = rekordy.begin();
        iter != rekordy.end(); ++iter) {
		if((*iter)[0] == dlugosc) {
			return (*iter)[index];
		}
	}
}

}
}


