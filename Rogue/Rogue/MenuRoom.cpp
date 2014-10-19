#include "MenuRoom.h"

MenuRoom::MenuRoom()
{
	printf("In MenuRoom state \n");
	printf("Je staat in kamer met in het midden een tafel met...\n");
	printf("vecht | vlucht | zoek | rust... \n");
}


MenuRoom::~MenuRoom()
{
}

void MenuRoom::handleInput(string input){
	printf("MenuRoom handled the input \n");
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
