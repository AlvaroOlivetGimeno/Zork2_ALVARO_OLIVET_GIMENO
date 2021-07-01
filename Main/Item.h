#pragma once
#include <iostream>
using namespace std;
#include <string>

struct Item
{

public:

	Item();

	string name;
	string description;

	Item(string name, string description);

	void SetItem(string itemName, string itemDescription);

	void OutputItemInfo();

private:



};

