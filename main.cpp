#include <iostream>
#include <time.h>
#include <windows.h>
#include <limits>
#include <stdlib.h>
using namespace std;
bool czypuste[9];
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

int pola[9]; //Ekwipunek/ Pierdolnik postaci

class Gracz
{
public:
    int hp, pg, def;
    przedmioty ekwipunek[9];
    //
};
int ile[9];
/*
void sprawdztyp(Gracz* gracz)
{
      for (int i = 0; i < 10; i++)
    {
     if (gracz->ekwipunek[i] == przedmioty::puste){}
    else if (gracz->ekwipunek[i] == przedmioty::kamien){}
    else if (gracz->ekwipunek[i] == przedmioty::patyk){}
     else if (gracz->ekwipunek[i] == przedmioty::kilof){}
    }

    }
*/


void nadajilosc(Gracz *gracz)
{
    for (int i = 0; i < 10; i++)
    {
        if (gracz->ekwipunek[i] == przedmioty::puste)
        {

        czypuste[i]=true;

            ile[i] = 0;
        }
        if (gracz->ekwipunek[i] != przedmioty::puste)
        {
         czypuste[i]=false;
                 }
    }
}

Gracz *startAktu1()
{
    Gracz *gracz = new Gracz();
    gracz->hp = 10;
    gracz->pg = 100;
    gracz->def = 5;
    for (int i = 0; i < 10; i++)
    {
        gracz->ekwipunek[i] = przedmioty::puste;
    }
    return gracz;
}
    bool czystworzono = false;
void crafting(Gracz *gracz)
{
    for (int i = 0; i < 10; i++){
if(czypuste[i]==false)
   {
   }

}

        }





void wybor(Gracz *gracz)
{
    cout << "1. Ekwipunek" << endl;
    cout << "2. tworzenie" << endl;
    cout << "3. Otoczenie" << endl;
    cout << "4. Statystyki" << endl;
    cout << "5. czysty ekran" << endl;
    cout << "6. koniec gry" << endl;
    int a;
    bool bCzyBlad = std::cin.fail();


    cin >> a;
    if (bCzyBlad)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    switch (a)
    {
    case 1:
        for (int i = 0; i < 10; i++)
        {
            switch (gracz->ekwipunek[i])
            {
            case przedmioty::puste:
                cout << "puste " <<endl;//"czy puste? "<<czypuste[i]<< endl; //<<"liczba  "<<ile[i] <<endl;
                break;
            case przedmioty::kilof:
                cout << "kilof "<< "ilosc " << ile[i]<<endl;// <<"czy puste? "<<czypuste[i]<< endl;
                break;
            case przedmioty::patyk:
                cout << "patyk "<< "ilosc " << ile[i] <<endl;//"czy puste? "<<czypuste[i]<< endl;
                break;
            case przedmioty::kamien:
                cout << "kamien "<< "ilosc " << ile[i] <<endl;//"czy puste? "<<czypuste[i]<< endl;
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
        cout << a << endl;
        break;
    }
}

int main()
{
    int x = 10, y = 20;
    Gracz *gracz = startAktu1();
/*    pola[1] = 1;
    pola[2] = 1;
    pola[3] = 1;
    pola[5] = 5;
    pola[7] = 5;*/
    gracz->ekwipunek[2] = przedmioty::patyk; ile[2]=2;
    gracz->ekwipunek[1] = przedmioty::kamien; ile[1]=3;
  //   crafting(gracz);
   nadajilosc(gracz);
       crafting(gracz);
    while (1)
    {

        wybor(gracz);
    }

    delete gracz;
    return 0;
}

/*
To Do:


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
