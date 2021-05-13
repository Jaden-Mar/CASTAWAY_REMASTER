#include <iostream>
#include <time.h>
#include <windows.h>
#include <limits>
#include<stdlib.h>
using namespace std;

//  Gracz* gracz=new Gracz();
void gotoxy(int x, int y)
{
	printf("%c[%d;%df", 0x1B, y, x);
}
void clrscr(void)
{
	system("CLS");
}
//enum item list
enum przedmioty
{
	puste = 0,
	kamien = 1,
	patyk = 2,
	kilof = 10
};
int pola[9];//Ekwipunek/ Pierdolnik postaci
class Gracz
{
public:
	int hp, pg, def;
	przedmioty ekwipunek[9];
	//
};
int ile[9];
void nadajilosc(Gracz* gracz)
{
	for (int i = 0; i < 10; i++)
	{
		if (gracz->ekwipunek[i] == przedmioty::puste)
		{
			ile[i] = 0;
		}
		if (gracz->ekwipunek[i] != przedmioty::puste)
		{
			ile[i] = 1;
		}
	}
}

Gracz* startAktu1()
{
	Gracz* gracz = new Gracz();
	gracz->hp = 10;
	gracz->pg = 100;
	gracz->def = 5;
	for (int i = 0; i < 10; i++)
	{
		gracz->ekwipunek[i] = przedmioty::puste;
	}
	return gracz;
}
void crafting(Gracz* gracz)
{
	if (pola[1] == 1 && pola[2] == 1 && pola[3] == 1 && pola[5] == 5 && pola[7] == 5)
	{
		for (int i = 0; i < 10; i++)
		{
			if (gracz->ekwipunek[i] == przedmioty::puste)
			{
				gracz->ekwipunek[i] = przedmioty::kilof;

				break;
			}
			if (gracz->ekwipunek[i] != przedmioty::puste)
			{
				cout << "brak miejsca" << endl;
				break;
			}
		}
	}
}

void wybor(Gracz* gracz)
{
	cout << "1. Ekwipunek" << endl;
	cout << "2. tworzenie" << endl;
	cout << "3. Otoczenie" << endl;
	cout << "4. Statystyki" << endl;
	cout << "5. czysty ekran" << endl;
	cout << "6. koniec gry" << endl;
	int a;
bool bCzyBlad = std::cin.fail();

//(edytowane)
//[23:36]

	cin >> a;
if (bCzyBlad){
  std::cin.clear();
  std::cin.ignore( std::numeric_limits < std::streamsize >::max(), '\n' );
}
	switch (a)
	{
	case 1:
		for (int i = 0; i < 10; i++)
		{
			switch (gracz->ekwipunek[i])
			{
			case przedmioty::puste:
				cout << "puste " << endl;//<<"liczba  "<<ile[i] <<endl;
				break;
			case przedmioty::kilof:
				cout << "kilof " << "ilosc  " << ile[i] << endl;
				break;
			case przedmioty::patyk:
				cout << "patyk " << "ilosc  " << ile[i] << endl;
				break;
			case przedmioty::kamien:
				cout << "kamien " << "ilosc " << ile[i] << endl;
				break;
			}
		}

		break;
	case 2:
		crafting(gracz);
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		clrscr();
		break;
	case 6:
		exit(3);
		break;
	default:
		cout << a<<endl;
	break;
	}
}

int main()
{
	int x = 10, y = 20;
	Gracz* gracz = startAktu1();
	pola[1] = 1;
	pola[2] = 1;
	pola[3] = 1;
	pola[5] = 5;
	pola[7] = 5;

	gracz->ekwipunek[1] = przedmioty::kamien;
	// crafting(gracz);
	while (1)
	{
		nadajilosc(gracz);
		wybor(gracz);
	}

	delete gracz;
	return 0;
}

/*
To Do:
tablica 3wym + czas do okreœlenia pozycji
system ekwipunku
system craftingu ##ZROBIONE##
Generowanie œwiata

TODO::END

int main()
{
	Gracz* gracz=startAktu1();
	cout<< gracz->ekwipunek[6]<<endl;
	gracz->ekwipunek[1]=przedmioty::kamien;
	 cout<< gracz->ekwipunek[1]<<endl;
  cout<<"+_+_+_+_+_+_+"<<endl;

  for(int i=0; i<10; i++)
	{
	  cout<< gracz->ekwipunek[i]<<endl;
	}
		delete gracz;
	return 0;
}

*/
