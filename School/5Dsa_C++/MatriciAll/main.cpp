#include <cstdlib>
#include <iostream>
#define R 10
#define C 10
//Ricorda riscrivere il programma ;)

using namespace std;

class matrici
{
public:
	int m1[R][C], res[R][C];
	int dim;

	matrici()
	{
		cout << "Matrice inizialied waiting function to run" << endl;
		system("clear");
	}

	void LoadBidimensionalArray(int uniqueDimension)
	{
		dim = uniqueDimension;
		int i, j;
		for (i = 0; i < dim; i++)
		{
			for (j = 0; j < dim; j++)
			{
				cout << "Inserire numero da caricare nella matrice nella posizione [" << i + 1 << ";" << j + 1 << "]" << endl;
				cin >> m1[i][j];
			}
		}
	}
	int LoadDim()
	{
		do
		{
			cout << "Inserisci dimensione";
			cin >> dim;
			if (dim >= C)
			{
				cout << "Error dimension too big error"<<endl;
			}
		} while (dim > C);
		
		return dim;
	}
	void DisplayBidimensional()
	{
		int i, j;
		for (i = 0; i < dim; i++)
		{
			for (j = 0; j < dim; j++)
			{
				cout << "Ecco l'elemento caricato nella posizione [" << i + 1 << ":" << j + 1 << "]"
					 << ": " << m1[i][j] << endl;
			}
		}
		cout << "*********End Matrice Print**********" << endl;
	}
	void DisplayRes()
	{
		int i, j;
		for (i = 0; i < dim; i++)
		{
			for (j = 0; j < dim; j++)
			{
				cout << "Ecco l'elemento caricato nella posizione [" << i + 1 << ":" << j + 1 << "]"
					 << ": " << res[i][j] << endl;
			}
		}
		cout << "*********End Matrice Print**********" << endl;
	}

	int getBidimesionDimension()
	{
		return dim;
	}
	
	~matrici()
	{
		cout << "Matrix destroyed";
	}
};

void somma()
{
	int dim;
	matrici m1;
	matrici m2;
	dim = m1.LoadDim();
	m1.LoadBidimensionalArray(dim);
	m2.LoadBidimensionalArray(dim);
	m2.DisplayBidimensional(); // Display Matrix
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			m1.res[i][j] = m1.m1[i][j] + m2.m1[i][j]; //Matrix sum
		}
	}
	m1.DisplayRes(); //display res
	m1.~matrici();
	m2.~matrici();
}

void diffMatrix()
{
	int dim;
	matrici m1, m2;
	dim = m1.LoadDim();
	m1.LoadBidimensionalArray(dim);
	m1.DisplayBidimensional(); // Display Matrix
	m2.LoadBidimensionalArray(dim);
	m2.DisplayBidimensional(); // Display Matrix
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; i++)
		{
			m1.res[i][j] = m1.m1[i][j] + m2.m1[i][j]; //Matrix difference
		}
	}
	m1.DisplayRes(); //display res
	m1.~matrici();
	m2.~matrici();
}

void trasposta()
{
	int dim;
	matrici m;
	dim = m.LoadDim();
	m.LoadBidimensionalArray(dim);
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; i++)
		{
			m.m1[i][j] = m.m1[j][i];
		}
	}
	m.DisplayBidimensional();
	m.~matrici();
}


//Laplace 
int det (int m1 [R][C], int card)
{
	int dim, determinante, row, col;
	determinante = 0;
	matrici m;
	dim = m.LoadDim();
	m.LoadBidimensionalArray(dim);
	if(dim == 1) determinante = m.m1[0][0];
	if(dim == 2) determinante = m.m1[1][1] * m.m1[0][0] - m.m1[0][1] * m.m1[1][0]; 
	else
	{
		for (int i = 0; i < dim; i++)
		{
			for (int i = 0; i < dim -1; i++)
			{
				for (int j = 0; i < dim -1 ; j++)
				{
					row = (i < row ?i:i+1);
					col = i+1;
					m.res[i][j] = m.m1[row][col];
				}
				
			}
			if (row % 2 == 0) determinante += m.m1[row][0]*det(m.res, dim - 1);
			else determinante -= m.m1[row][0] * det(m.res, dim-1);
			
		}
		
	}
	return determinante;
	
}

class Menu
{
public:
	int chooice;
	Menu()
	{
		cout << "Initializing Menu..." << endl;
		system("clear");
	}
	void Displaymenu()
	{
		cout << "1. Somma" << endl;
		cout << "2. Differenza" << endl;
		cout << "3. Trasposta" << endl;
		cout << "4. Determinante (Laplace)"<<endl;
		cout << "Press the number of your choise 0 to exit";
	}
	int LogicMenu(int chooice)
	{
		switch (chooice)
		{
		case 1:
			somma();
			break;
		case 2:
			diffMatrix();
			system("clear");
			break;
		case 3:
			trasposta();
			system("clear");
			break;
		case 4:
			cout<<"Not inplemented yet programm will restart";
			system("CLS");
		break;
		default:
			cout << "Error option not valid";
			system("clear");
			break;
		}
	}
};

int main()
{
	int choose;
	Menu menu;
	do
	{
		menu.Displaymenu();
		cin >> choose;
		menu.LogicMenu(choose);
		continue;
	} while (choose == 0);

	system("PAUSE");
}
