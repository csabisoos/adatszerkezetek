#include <vector>
#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main()
{
	int statikus_tomb[5]; // C#-ban ugyanez int[] statikus_tomb = new int[5];
	// nem newzunk meg semmit, de ettol meg van new, csak mashogy hasznaljak

	cerr << "A tomb (array) elemei: "; // Console.Error.Writeline

	for (unsigned int i = 0; i < 5; i++)
	{
		cout << statikus_tomb[i] << " ";
	}
	cout << endl;

	int meg_kisebb = statikus_tomb[2] - 1;
	cout << meg_kisebb << endl;

	// delete...

	// ma mar elavultnak szamit, bar tenyleg sokan hasznaljak

	/* vector */

	vector<int> lista; // C#-ban ugyanez: List<int> statikus_tomb = new List<int>();

	lista.push_back(2);
	lista.push_back(3);
	lista.push_back(4);
	lista.push_back(5);

	//for + TAB
	cerr << "A lista (vector) elemei: ";
	for (int i = 0; i < lista.size(); i++)
	{
		cout << lista[i] << " ";
	}
	cout << endl;

	// forr + TAB (for reversed)
	for (int i = lista.size() - 1; i >= 0; i--) // a gepi kodban 1 sorral rovidebb, de nem eszreveheto
	{
		cout << lista[i] << " ";
	}
	cout << endl;

	//rfor + TAB
	for (auto& elem : lista) // a default azert nem i mert index, hanem mert iterator, az autot ott lehet hagyni, olyan int a var
	{
		cout << elem << " ";
	}
	cout << endl;


	vector<int> otdbegyes(5, 1);
	for (size_t i = 0; i < otdbegyes.size(); i++)
	{
		cout << otdbegyes[i] << " ";
	}
	cout << endl;

	//hozzunk letre vektort dinamikusan
	// C#: List<int> lista = new List<int>();
	//C++
	vector<int>* listamutato;
	listamutato = new vector<int>;

	cout << listamutato << "\n"; // ezen a cimen van

	vector<int> ezmarlista = *listamutato; // itt egy vadiuj lista jon letre

	ezmarlista.push_back(3);
	(*listamutato).push_back(5); // zarojel nem elhagythato, a mutato vegen kevo listaba pakolunk elemeket
	listamutato->push_back(7);
	for (auto& elem : *listamutato)
	{
		cout << elem << " ";
	}
	cout << endl;
	for (auto& elem : ezmarlista)
	{
		cout << elem << " ";
	}
	cout << endl;

	//matrixok, tobbdimenzios tombok
	// ez egy 2D-s 3x3-as csupaegyes matrix: //  sor*oszlop
	vector<vector<int>> matrix;
	vector<int>* sormutato;

	for (size_t i = 0; i < 3; i++)
	{
//		vector<int> sor(5, i); // ez mukodik de ronda
		sormutato = new vector<int>(5, i); // nincs most neve neki, csak a helyet tudjuk
		matrix.push_back(*sormutato);
	}
	cout << "A matrix jelenleg:" << endl;
	for (size_t i = 0; i < 3; i++)// soronkent
	{
		for (size_t j = 0; j < 5; j++) // sorokon belul oszloponkent
		{
			cout << matrix[i][j] << " ";
		}//amikor vegere er a sornak
		cout << endl;
	}
	cout << endl;

	int x = 10;

	cout << "x:" << x << endl; // 10
	cout << "&x:"<< &x << endl; // ez valami meoriacimet ad
//	cout << "*x:" << *x << endl; // hibat ad mert nem memoriacim
	cout << "*&x:" << *&x << endl; // 10
//	cout << "&*x:" << &*x << endl; // hibat ad mert *x-vel kezdi a munkat, amivel nem lehet
	cout << "*&*&*&*&*&*&*&*&*&*&*&x:" << *&*&*&*&*&*&*&*&*&*&*&x << endl; // 10
//	cout << "&&x:" << && x << endl; // nem mukodik, de amugy nem teljesen ertelmetlen gondolat, lasd:
	
	int* m1 = &x;
	int** m2 = &m1;
	int*** m3 = &m2;
	//m3 -> m2 -> m1 -> x
	cout << "menjunk vegig:" << ***m3 << endl;

	//szotarak -- ketfele van
	//map es undordered_map

	map<string, int> szotar;
	szotar["bla"] = 5;
	szotar["asdf"] = 7;
	szotar["zoli"] = -3;

	cout << "bla " << szotar["bla"] << endl;
	cout << "asdf " << szotar["asdf"] << endl;
	cout << "zoli " << szotar["zoli"] << endl;

	string szoveg = "asdfghjklqwertzuioyxcvbnmaaaaaaaaaa";
	// GROUP BY feladat
	//csinaljunk statisztikat arrol, hogy melyik betu milyen gyakorisaggal szerepel

	map<char, int> statisztika;

	// "a" -> 3
	// "s" -> 2
	// "f" -> 2
	// "g" -> 1

	for (auto& karakter : szoveg)
	{
		// statisztika.find(szoveg[i]) visszaadja a keresett elem HELYET, vagy ha nem talalta meg akkor a statisztika veget adja meg
		if (statisztika.find(karakter) != statisztika.end())// ez azt jelenti, hogy a kereses soran nem ert vegere
		{
			statisztika[karakter]++;
		}
		else
		{
			statisztika[karakter] = 1;
		}
	}
	for (auto& elem : statisztika)
	{
		cout << elem.first << "->" << elem.second << endl;
	}
}

