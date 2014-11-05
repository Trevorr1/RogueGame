#include "MenuRoom.h"
#include <iostream>
#include <string>

using namespace std;

MenuRoom::MenuRoom()
{
	m_Text = "You're in a ";

	m_Options.push_back("fight");
	m_Options.push_back("run");
	m_Options.push_back("search");
	m_Options.push_back("rest");
	m_Options.push_back("items");
	m_Options.push_back("map");
	
	// old code
	/*printf("In MenuRoom state \n");
	printf("Je staat in kamer met in het midden een tafel met...\n");
	printf("vecht | vlucht | zoek | rust... \n");*/
}


MenuRoom::~MenuRoom()
{
}

void MenuRoom::handleInput(string input){
	printf("MenuRoom handled the input \n");
	
	if (input == "vecht"){
		fight();
	}else if (input == "vlucht"){
		flee();
	}else if (input == "zoek"){
		search();
	}else if (input == "rust uit"){
		rest();
	}else if (input == "bekijk spullen"){
		inventory();
	}else if (input == "bekijk kaart"){
		map();
	}
	else{
		printf("Probeer het nog eens! \n");
	}
}

void MenuRoom::fight(){

}
void MenuRoom::flee(){

}
void MenuRoom::search(){

}
void MenuRoom::rest(){

}
void MenuRoom::inventory(){

}
void MenuRoom::map(){

}
void MenuRoom::characterInfo(){

}
