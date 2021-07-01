#pragma once
#include <iostream>
using namespace std;
#include <string>
#include "Item.h"

enum Direction
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3
};


struct Room
{
	Room();
	Room(string name, string description);
	void SetNeighbors(Room* rNorth, Room* rSouth, Room* rEast, Room* rWest, bool n, bool s, bool e, bool o);
	
	bool IHaveAnItem();
	void SetTheItemInTheRoom(int numOfTheItem, bool itemBool);

	void LockCloseDoor();
	
	void SetRoom(string name, string description);
	
	void OutputRoomInfo();
	void OutputNeighbors();
	void OutputCloseDoors();
	bool ICanGoTo(Direction direction);

	bool RoomIsClosed(Direction direction);

	

	string name;
	string description;
	Room* roomNeighbortNorth;
	Room* roomNeighbortSouth;
	Room* roomNeighbortEast;
	Room* roomNeighbortWest;
	bool conditionNorth;
	bool conditionSouth;
	bool conditionEast;
	bool conditionWest;
	
	bool iHaveAnItem = false;
	int numberOfTheItem;
	
};

