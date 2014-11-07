#include "LoaderManager.h"

// Allocating and initializing GlobalClass's
// static data member.  The pointer is being
// allocated - not the object inself.
LoaderManager * LoaderManager::_instance = 0;

LoaderManager* LoaderManager::getInstance()
{
	if (_instance == NULL){
		_instance = new LoaderManager;
	}
	return _instance;
}