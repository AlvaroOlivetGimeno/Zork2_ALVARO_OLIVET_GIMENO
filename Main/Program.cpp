#include "Program.h"


Program :: Program()
{
	p_currentRoom = nullptr;
	p_done = false;
	SetupRooms();
	
}



int Program::CreateRoom(string name, string description)
{

	Room* room = new Room;

	room->SetRoom(name, description);
	p_rooms.push_back(room);

	return p_rooms.size() -1;
}


int Program::CreateItems(string name, string description)
{

	Item* item = new Item;

	item->SetItem(name, description);
	p_items.push_back(item);

	return p_items.size() - 1;
}

void Program::SetupRooms()
{
	//DIFERENTS SALES------------------------------------------------------------------------------------------------------
	int entranceHouse = CreateRoom("Entrada de la casa", "Delante de ti se postra una gran mansion abandonada.");
	int parkcar = CreateRoom("Aparcamiento", "Aquí es donde has aparcado tu coche al venir.");
	int garden = CreateRoom("Jardin", "Un inmenso jardin de enredaderas y avetos salvajes se encuentra delante de ti.");
	int hallPrincipal = CreateRoom("Hall principal", "La mansion se encuentra en un estado decadente. Un gran cuadro renacentista cuelga de la pared enfrente de ti.");
	int salaVisitas = CreateRoom("Sala de visitas", "Las arañas son dueñas del lugar. Tambien se encuentra una estatua de Poseidon en el centro de la estancia. ");
	int biblioteca = CreateRoom("Biblioteca", "Miles de libros descnasan en viejas estanterias");
	int pasilloOeste = CreateRoom("Pasillo oeste", "Un estrecho pasillo se extiende delante de ti. En la puerta del sud aprecias la silueta de un pulpo... estranyo.");
	int pasilloEste= CreateRoom("Pasillo este", "Un estrecho pasillo se extiende delante de ti. Un cuadro extraño se encuentra colgado en una de las paredes.");
	int comedor = CreateRoom("Comedor", "Te encuentras en una estancia gigantesca. La puerta al sud esta cerrada, pero podria forzarse con algo afilado.");
	int cocina = CreateRoom("Cocina", "Ollas, platos, cuchillos y polvo se amontonan hasta donde alcanza la vista.");
	int habitacionServicio = CreateRoom("Habitacion del Servició", "Logras identificar cuatro literas pequeñas y un armario enano.");
	int habitacionSeñor = CreateRoom("Habitacion del Señor de la casa", "Una gran cama con detalles de oro se postra en medio. A un lado, una pequeña caja fuerte descansa con timidez con la puerta entreavierta.");
	//-----------------------------------------------------------------------------------------------------------------
	

	//UNION DE LAS SALS------------------------------------------------------------------------------------------------------
	//0
	p_rooms[entranceHouse]->SetNeighbors(nullptr, p_rooms[hallPrincipal], p_rooms[parkcar], p_rooms[garden], true, false, true, true);
	//1
	p_rooms[parkcar]->SetNeighbors(nullptr, nullptr, nullptr, p_rooms[entranceHouse], true, true, true, true);
	//2
	p_rooms[garden]->SetNeighbors(nullptr, nullptr, p_rooms[entranceHouse], nullptr, true, true, true, true);
	//3
	p_rooms[hallPrincipal]->SetNeighbors(p_rooms[entranceHouse],nullptr, p_rooms[biblioteca], p_rooms[salaVisitas], true, true, true, true);
	//4
	p_rooms[biblioteca]->SetNeighbors(nullptr, p_rooms[pasilloEste], nullptr, p_rooms[hallPrincipal], true, true, true, true);
	//5
	p_rooms[salaVisitas]->SetNeighbors(nullptr, p_rooms[pasilloOeste], p_rooms[hallPrincipal], nullptr, true, true, true, true);
	//6
	p_rooms[comedor]->SetNeighbors(nullptr, p_rooms[habitacionSeñor], p_rooms[pasilloEste], p_rooms[pasilloOeste], true, false, true, true);
	//7
	p_rooms[pasilloEste]->SetNeighbors(p_rooms[biblioteca], p_rooms[habitacionServicio], nullptr, p_rooms[comedor], true, true, true, true);
	//8
	p_rooms[pasilloOeste]->SetNeighbors(p_rooms[salaVisitas], p_rooms[cocina], p_rooms[comedor], nullptr, true, false, true, true);
	//9
	p_rooms[cocina]->SetNeighbors(p_rooms[pasilloOeste], nullptr,nullptr, nullptr, true, true, true, true);
	//10
	p_rooms[habitacionServicio]->SetNeighbors(p_rooms[pasilloEste], nullptr, nullptr, nullptr, true, true, true, true);
	//11
	p_rooms[habitacionSeñor]->SetNeighbors(p_rooms[comedor], nullptr, nullptr, nullptr, true, true, true, true);
	
	//-----------------------------------------------------------------------------------------------------------------


	//ITEMS------------------------------------------------------------------------------------------------------------
	int carItem = CreateItems("llave", "Parece que  te has dejado una llave vieja."); //0
	int pulpoItem = CreateItems("pulpo", "Parece que ves una pequeña insignia de un pulpo en el suelo. Donde has visto esto antes..."); //1
	int cuchilloItem = CreateItems("cuchillo", "Un enorme cuchillo con el mango de madera. Esta muy afilado"); //2
	int tesoroItem = CreateItems("tesoro", "Ves algo que brilla dentro de la caja fuerte. Un diamante! Cojelo y el juego terminara."); //3
	//------------------------------------------------------------------------------------------------------------------

	//SET ITEMS INTO THE ROOMS-------------------------------------------------------------------------------------------
	p_rooms[parkcar]->SetTheItemInTheRoom(carItem, true);
	p_rooms[habitacionServicio]->SetTheItemInTheRoom(pulpoItem, true);
	p_rooms[cocina]->SetTheItemInTheRoom(cuchilloItem, true);
	p_rooms[habitacionSeñor]->SetTheItemInTheRoom(tesoroItem, true);


	//------------------------------------------------------------------------------------------------------------------

	//SALA DES DE LA QUE SE EMPIEZA
	p_currentRoom = p_rooms[entranceHouse];	
	
}

void Program::Pause()
{
	cout << "\n";
	cout << "Press Enter to Continue";
	cin.ignore();
}


void Program::PlayerDesition()
{
	string userInput;
	string status = "";

	cout << "Que quieres hacer ahora??";
	cout << '\n';
	cout << '\n';
	getline(cin, userInput);
	cout << '\n';
	cout << '\n';

	if (userInput == "norte" || userInput == "Norte" || userInput == "NORTE" || userInput == "N" || userInput == "n")
	{
		if (p_currentRoom->ICanGoTo(NORTH))
		{
			status = "Avanzas hacia el NORTE";
			p_currentRoom = p_currentRoom->roomNeighbortNorth;
		}
		else
		{
			status = "No puedes ir en esa dirección, quizas porque te falta un objeto";

		}

	}
	else if (userInput == "sud" || userInput == "SUD" || userInput == "Sud" || userInput == "S" || userInput == "s")
	{
		if (p_currentRoom->ICanGoTo(SOUTH))
		{
			status = "Avanzas hacia el SUD";
			p_currentRoom = p_currentRoom->roomNeighbortSouth;
		}
		else
		{
			status = "No puedes ir en esa dirección";

		}

	}
	else if (userInput == "este" || userInput == "Este" || userInput == "ESTE" || userInput == "E" || userInput == "e")
	{
		if (p_currentRoom->ICanGoTo(EAST))
		{
			status = "Avanzas hacia el ESTE";
			p_currentRoom = p_currentRoom->roomNeighbortEast;
		}
		else
		{
			status = "No puedes ir en esa dirección";

		}

	}
	else if (userInput == "oeste" || userInput == "Oeste" || userInput == "OESTE" || userInput == "O" || userInput == "o")
	{
		if (p_currentRoom->ICanGoTo(WEST))
		{
			status = "Avanzas hacia el OESTE";
			p_currentRoom = p_currentRoom->roomNeighbortWest;
		}
		else
		{
			status = "No puedes ir en esa dirección";

		}

	}
	else if (p_currentRoom->iHaveAnItem)
	{
		if (userInput == p_items[p_currentRoom->numberOfTheItem]->name)
		{
			if (p_currentItem == nullptr)
			{
				p_currentItem = p_items[p_currentRoom->numberOfTheItem];
				p_currentRoom->iHaveAnItem = false;
				DesbloqueoDePuertas(p_items[p_currentRoom->numberOfTheItem]->name);
				status = "Item encontrado :))";
			}
			else
			{
				status = "Suelta el objeto actual en otra sala antes de cojer este";
				
			}
			
		}
		else
		{
			status = "Accion incorrecta";
		}
	}
	else if (userInput == "SOLTAR" || userInput == "soltar" || userInput == "Soltar")
	{
		if (p_currentItem != nullptr)
		{
			if (p_currentRoom->iHaveAnItem)
			{
				status = "Ya hay un item aquí. No puedes soltar el que llevas ahora.";
			}
			else
			{
				if (p_currentItem->name == "llave")
				{
					p_currentRoom->SetTheItemInTheRoom(0, true);
				}
				else if (p_currentItem->name == "pulpo")
				{
					p_currentRoom->SetTheItemInTheRoom(1, true);
				}
				else if (p_currentItem->name == "cuchillo")
				{
					p_currentRoom->SetTheItemInTheRoom(2, true);
				}

				p_currentItem = nullptr;
				status = "Has soltado el objeto (este vuelve a su sitio de origen)";
			}
		}
		else
		{
			status = "No tienes ningun objeto que soltar.";
		}
		
		
	
	}
	else
	{
		status = "Accion incorrecta";
	}
	cout << status << endl;
	Pause();
	
}

void Program::Title()
{
	cout << '\n';
	cout << "\t" << "\t" << "\t" << " -------------------" << endl;
	cout << "\t" << "\t" << "\t" << "|   ALVARO's ZORK   |" << endl;
	cout << "\t" << "\t" << "\t" << " -------------------" << endl;
	cout << endl << endl;
	cout << "Item: ";
	if (p_currentItem != nullptr)
	{
		cout << p_currentItem->name;
	}
	else
	{
		cout << "Nada";
	}
}

void Program::ShowItemOfTheRoom()
{
	//cout <<p_currentRoom->IHaveAnItem();
	if (p_currentRoom->IHaveAnItem())
	{
		p_items[p_currentRoom->numberOfTheItem]->OutputItemInfo();
		
	}
	else
	{
		cout << endl;
		cout << "No hay nada con lo que interactuar aqui.";
		cout << '\n'; 
	}
}

void Program::DesbloqueoDePuertas(string nameOfItem)
{
	if (nameOfItem == "llave")
	{
		p_rooms[0]->LockCloseDoor();
	}
	if (nameOfItem == "pulpo")
	{
		p_rooms[6]->LockCloseDoor();
	}
	if (nameOfItem == "cuchillo")
	{
		p_rooms[8]->LockCloseDoor();
	}
	if (nameOfItem == "cuchillo")
	{
		p_rooms[8]->LockCloseDoor();
	}
	if (nameOfItem == "tesoro")
	{
		exit(1);
	}
}


void Program::Run()
{
	
	while (!p_done)
	{
		system("cls");
		//cout << p_rooms[1]->name << p_rooms[2]->name << p_rooms[3]->name << p_rooms[4]->name << p_rooms[5]->name << p_rooms[6]->name << p_rooms[6]->name << p_rooms[7]->name << p_rooms[8]->name << p_rooms[9]->name << p_rooms[10]->name << p_rooms[11]->name;
		Title();
		
		cout << '\n';
		p_currentRoom->OutputRoomInfo();
		ShowItemOfTheRoom();
		cout << '\n';
		PlayerDesition();

	}
}
