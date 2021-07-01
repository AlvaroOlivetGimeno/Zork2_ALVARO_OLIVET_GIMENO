#include "Item.h"

Item::Item()
{

}

Item::Item(string name, string description)
{
	SetItem(name, description);
}

void Item::SetItem(string itemName, string itemDescription)
{
	this->name = itemName;
	this->description = itemDescription;
}

void Item::OutputItemInfo()
{
	cout << "Hay un/a " << name << endl;
	cout << description << endl;
}