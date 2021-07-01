
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Room.h"
#include "Item.h"
#include "stdlib.h"



using namespace std;

class Program
{
public:
	Program();

	void SumPuntuation();

	void SumMovments();
	
	void Run();

	int CreateItems(string name, string description);

	void SetupRooms();

	void Pause();


	int CreateRoom(string name, string description);
	void PlayerDesition();

	void Title();

	void ShowItemOfTheRoom();

	void DesbloqueoDePuertas(string nameOfItem);

private:

	Room* p_currentRoom;
	vector<Room*> p_rooms;

	Item* p_currentItem;
	vector<Item*> p_items;



	bool p_done;

	int puntuation = 0;
	int movments =0;


};

