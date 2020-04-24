#include <iostream>
#include <windows.h>
#include <vector>

using namespace std;

const int M=6;
const int N=6;
const int I=20;


class Rooms
{
private:
    bool existing;
    string description;
    string name;
public:
    Rooms(bool exist=false, string n="BRAK", string desc="BRAK");
    void Show();
    friend class Player;
    friend class Game;

};

class Player
{
private:
    string name;
    int strength;
    int agility;
    int intelligence;
public:
    int PlayerX;
    int PlayerY;
    Player(int a=2, int b=2, int s=10, int n=10, int i=10);
    void Move(Rooms room[M][N]);
    void Map(Rooms room[M][N]);
    friend class Rooms;
    friend class Game;
};

class Item
{
private:
    string name;
    string description;
    string quality;
    int cost;
public:
    Item(string n="BRAK", string d="BRAK", string q="BRAK", int c=0);
    void ModifyItem();
    void DisplayItems();
    friend class Equipment;
    friend class Game;
};

class Equipment
{
private:
    vector<Item>Inventory;
public:
    void ShowEquipment();
    void AddEquipment(Item i[I]);
    friend class Game;
};

class Game
{
private:
    Player pa;
    Rooms r[M][N];
    Equipment eq;
    Item items[20];
public:
    void Init();
    void ShowMenu();
    void Update();
};

