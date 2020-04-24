#include <iostream>
#include "gra.h"
#include <conio.h>
#include <conio.h>
#include <cstdlib>
#include <vector>

using namespace std;

Rooms::Rooms(bool exist, string n, string desc)
{
    name=n;
    description=desc;
    existing=exist;
}


Player::Player(int a, int b, int s, int n, int i)
{
    strength=s;
    intelligence=i;
    agility=n;
    PlayerX=a;
    PlayerY=b;
}

void Player::Move(Rooms room[M][N])
{
    string Direction0;
    char c;
    cout<<endl<<"Wcisnij przycisk:"<<endl;
    c=getch();
    for (int i=0; i<M; i++)
    {
        for (int j=0; j<N; j++)
        {
            if (this->PlayerY==i&&this->PlayerX==j)
            {
                switch(c)
                {
                    case 'w':
                    {
                        if (room[this->PlayerY-1][this->PlayerX].existing==true)
                        {
                            this->PlayerY--;
                            Direction0="GORE";
                            cout<<"Koordynaty X gracza: "<<this->PlayerX<<endl;
                            cout<<"Koordynaty Y gracza: "<<this->PlayerY<<endl;
                            cout<<endl<<"Poruszyles sie w "<<Direction0<<endl;
                            j=N;
                            i=M;
                        }
                        else
                        {
                        cout<<"Niedostepne!"<<endl;
                        }
                        break;
                    }
                    case 's':
                    {
                        if (room[this->PlayerY+1][this->PlayerX].existing==true)
                        {
                            this->PlayerY++;
                            Direction0="DOL";
                            cout<<"Koordynaty X gracza: "<<this->PlayerX<<endl;
                            cout<<"Koordynaty Y gracza: "<<this->PlayerY<<endl;
                            cout<<endl<<"Poruszyles sie w "<<Direction0<<endl;
                            j=N;
                            i=M;
                        }
                        else
                        {
                        cout<<"Niedostepne!"<<endl;
                        }
                        break;
                    }
                    case 'd':
                    {
                        if (room[this->PlayerY][this->PlayerX+1].existing==true)
                        {
                            this->PlayerX++;
                            Direction0="PRAWO";
                            cout<<"Koordynaty X gracza: "<<this->PlayerX<<endl;
                            cout<<"Koordynaty Y gracza: "<<this->PlayerY<<endl;
                            cout<<endl<<"Poruszyles sie w "<<Direction0<<endl;
                            j=N;
                            i=M;
                        }
                        else
                        {
                        cout<<"Niedostepne!"<<endl;
                        }
                        break;
                    }
                    case 'a':
                    {
                        if (room[this->PlayerY][this->PlayerX-1].existing==true)
                        {
                            this->PlayerX--;
                            Direction0="LEWO";
                            cout<<"Koordynaty X gracza: "<<this->PlayerX<<endl;
                            cout<<"Koordynaty Y gracza: "<<this->PlayerY<<endl;
                            cout<<endl<<"Poruszyles sie w "<<Direction0<<endl;
                            j=N;
                            i=M;
                        }
                        else
                        {
                        cout<<"Niedostepne!"<<endl;
                        }
                        break;
                    }
                }
            }
        }
    }
}


void Rooms::Show()
{
    cout<<endl<<"Opis pomieszczenia:"<<endl;
    cout<<description;
}

void Player::Map(Rooms room[M][N])
{
    cout<<"MAPA:"<<endl;
    for (int i=0; i<M; i++)
    {
        for (int j=0; j<N; j++)
        {
            if (this->PlayerX==j&&this->PlayerY==i)
            {
                cout<<"x";
            }
            else if (room[i][j].existing)
            {
                cout<<"o";
            }
            else
            {
                cout<<"z";
            }
        }
        cout<<endl;
    }
}

void Game::ShowMenu()
{
    char choice;
    cout<<"MENU:"<<endl;
    cout<<"-----------------------"<<endl;
    cout<<"1. Ruch"<<endl;
    cout<<"2. Mapa"<<endl;
    cout<<"3. Ekwipunek"<<endl;
    cout<<"4. Dodaj przedmiot"<<endl;
    cout<<"5. Wyswietl wszystkie przedmioty"<<endl;
    cout<<"6. Dodaj przedmiot do ekwipunku"<<endl;
    cout<<"------------------------"<<endl;
    cout<<"WCISNIJ KLAWISZ ODPOWIADAJACY ODPOWIEDNIEJ CYFRZE"<<endl;
    choice=getch();
    switch(choice)
    {
    case '1':
        {
            pa.Move(r);
            break;
        }
    case '2':
        {
            pa.Map(r);
            break;
        }
    case '3':
        {
            eq.ShowEquipment();
            break;
        }
    case '4':
        {
            int n;
            cout<<"Wybierz przedmiot sposrod "<<I<<" dostepnych przedmiotow, ktore chcesz zmodyfikowac:"<<endl;
            cin>>n;
            items[n].ModifyItem();
            break;
        }
    case '5':
        {
            for (int i=0; i<I; i++)
            {
                cout<<"Przedmiot "<<i+1<<":"<<endl;
                items[i].DisplayItems();
            }
            break;
        }
    case '6':
        {
            eq.AddEquipment(items);
        }
    }
}

void Equipment::ShowEquipment()
{
    cout<<"Twoje przedmioty:"<<endl;
    if (!this->Inventory.empty())
    {
    for (int i=0; i<this->Inventory.size(); i++)
    {
        cout<<i+1<<". "<<this->Inventory[i].name<<endl;
    }
    }
    else
        cout<<"Nie posiadasz zadnych przedmiotow w ekwipunku."<<endl;

}

void Equipment::AddEquipment(Item i[I])
{
    int p;
    cout<<"Podaj numer przedmiotu ktory chcesz dodac do ekwipunku:"<<endl;
    cin>>p;
    this->Inventory.push_back(i[p]);
}

Item::Item(string n, string d, string q, int c)
{
    name=n;
    description=d;
    quality=q;
    cost=c;
}

void Item::ModifyItem()
{
    cout<<"Podaj nazwe przedmiotu:"<<endl;
    cin>>this->name;
    cout<<"Podaj opis przedmiotu:"<<endl;
    cin>>this->description;
    cout<<"Podaj rzadkosc przedmiotu:"<<endl;
    cin>>this->quality;
    cin.ignore();
    cout<<"Podaj cene przedmiotu:"<<endl;
    cin>>this->cost;
}

void Item::DisplayItems()
{
     cout<<"Nazwa: "<<this->name<<endl;
     cout<<"Opis: "<<endl<<this->description<<endl;
     cout<<"Jakosc: "<<this->quality<<endl;
     cout<<"Cena: "<<this->cost<<endl;
}

void Game::Init()
{
    items[0].name="Wyszczerbiony miecz";
    items[1].name="Stepiony topor";
    r[2][4].existing=true;
    r[2][3].existing=true;
    r[2][2].existing=true;
    r[2][1].existing=true;
    r[2][0].existing=true;
    r[3][2].existing=true;
    r[1][2].existing=true;
}
