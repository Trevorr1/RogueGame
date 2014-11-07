#pragma once
#include "Loader.h"

class LoaderManager
{
public:
	static LoaderManager * getInstance(); //use: LoaderManager::getInstance()
	~LoaderManager() {};

		void setLoader(Loader* aLoader) { m_Loader = aLoader; }
		Loader* getLoader() { return m_Loader; }
private:
	static LoaderManager * _instance;
	LoaderManager() { }
	//LoaderManager(LoaderManager const&);
	//void operator=(LoaderManager const&);

	/*static*/ Loader* m_Loader;
};


