#include <vector>
#include <iostream>
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
	for (auto& elem: ezmarlista)
	{
		cout << elem << " ";
	}
	cout << endl;

	//matrixok, tobbdimenzios tombok
	// ez egy 2D-s 3x3-as csupaegyes matrix:
	/** /
	vector<vector<int>> matrix;

	vector<int> sor;
	for (size_t i = 0; i < 3; i++)
	{
		sor =
		for (size_t j = 0; j < 5; j++)
		{	
			matrix[i][j] = 1;
		}
	}
	/**/
}
