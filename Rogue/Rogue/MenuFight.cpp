#include "MenuFight.h"

MenuFight::MenuFight()
{
	printf("In MenuFight state \n");
	printf("Je bent in een gevecht met: \n");
	printf("Rat 1 ...\n");
	printf("Rat 2 ...\n \n");

	printf("Acties tegenstanders: \n");
	printf("Rat 2 bijt... \n \n");
	printf("Je hebt nog 15 van 18 levenspunten over \n");
	printf("Wat doe je? \n");
	printf("[aanval|vlucht|drink drankje|gebruik object] \n");
	printf("Actie: \n");
}


MenuFight::~MenuFight()
{
}

void MenuFight::handleInput(string input){
	printf("MenuFight handled the input \n");
}

void MenuFight::attack(){

}

void MenuFight::flee(){

}
void MenuFight::drink(){

}
void MenuFight::useObject(){

}