#include "Room.h"

Room::Room()
{

}


Room::Room(string name, string description)
{
	SetRoom(name, description);

}
void Room::SetNeighbors(Room* rNorth, Room* rSouth, Room* rEast, Room* rWest, bool n, bool s, bool e, bool o)
{
	roomNeighbortNorth = rNorth;
	roomNeighbortSouth = rSouth;
	roomNeighbortEast = rEast;
	roomNeighbortWest = rWest;
	conditionNorth = n;
	conditionSouth = s;
	conditionEast = e;
	conditionWest = o;
}

void Room::SetRoom(string name , string description )
{
	this->name = name;
	this->description = description;

	roomNeighbortNorth = nullptr;
	roomNeighbortSouth = nullptr;
	roomNeighbortEast = nullptr;
	roomNeighbortWest = nullptr;
}

void Room::OutputNeighbors()
{
	cout << "Puedes ir hacia: ";

		if (roomNeighbortNorth != nullptr)
		{
			cout << " Norte ('N'),";
		}
		if (roomNeighbortSouth != nullptr)
		{
			cout << " Sud ('S'),";
		}
		if (roomNeighbortEast != nullptr)
		{
			cout << " Este ('E'),";
		}
		if (roomNeighbortWest != nullptr)
		{
			cout << " Oeste ('O')";
		}

		cout << endl; 
}

void Room::OutputCloseDoors()
{
	

	if (!conditionNorth)
	{
		cout << "Se encuentra cerrada la puerta del ";
		cout << "Norte.";
	}
	if (!conditionSouth)
	{
		cout << "Se encuentra cerrada la puerta del ";
		cout << "Sud.";
	}
	if (!conditionEast)
	{
		cout << "Se encuentra cerrada la puerta del ";
		cout << "Este.";
	}
	if (!conditionWest)
	{
		cout << "Se encuentra cerrada la puerta del ";
		cout << "Oeste.";
	}

	cout << endl;
}

void Room::OutputRoomInfo()
{
	cout << "---------------------" << endl << endl
		<<this->name << endl << this->description << endl;
	OutputNeighbors();
	OutputCloseDoors();
	cout  << endl << "---------------------" << endl;
	cout << endl;
}

bool Room::ICanGoTo(Direction direction)
{
	if (direction == NORTH && roomNeighbortNorth != nullptr )
	{
		return true;
	}
	else if (direction == SOUTH && roomNeighbortSouth != nullptr)
	{
		return true;
	}
	else if (direction == EAST && roomNeighbortEast != nullptr)
	{
		return true;
	}
	else if (direction == WEST && roomNeighbortWest != nullptr )
	{
		return true;
	}

	return false;
}

bool Room::RoomIsClosed(Direction direction)
{
	if (direction == NORTH && conditionNorth)
	{
		return true;
	}
	else if (direction == SOUTH && conditionSouth)
	{
		return true;
	}
	else if (direction == EAST && conditionEast)
	{
		return true;

	}
	else if (direction == WEST && conditionWest)
	{
		return true;
	}
	return false;
}



bool Room::IHaveAnItem()
{
	if (iHaveAnItem)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}
void Room::SetTheItemInTheRoom(int numOfTheItem, bool itemBool)
{
	this->numberOfTheItem = numOfTheItem;
	this->iHaveAnItem = true;
}

void Room::LockCloseDoor()
{	
	this->conditionNorth = true;	
	this->conditionSouth = true;
	this->conditionEast = true;
	this->conditionWest = true;	
}



