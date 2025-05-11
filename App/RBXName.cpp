#include "StdAfx.h"
#include "RBXName.h"

#include "boost/thread/mutex.hpp"
#include "boost/thread/locks.hpp"

// time for roblox crack-o mode
static boost::once_flag mooFlag = BOOST_ONCE_INIT;

boost::mutex& moo2()
{
	static boost::mutex mutex2;
	return mutex2;
}
void initMoo()
{
	moo2(); // or, we can repeat via macro
}

namespace RBX
{
	//NamMap::NamMap()
	//{}

	//NamMap::~NamMap()
	//{
		//NamMap *namSelf;
		
		//namSelf = this;
		//while (true)
		//{
			//if (namSelf == NULL) || (namSelf != this)
			//{
				//UNKNOWN();
			//}
		//}
	//}

	Name *nullName;

	// focus on these later
	Name::Name()
	{
	}

	Name::~Name()
	{
	}
	
	// return a std::map until we can find out what this does
	Name::NamMap *Name::namMap()
	{
		NamMap *defaultMap;
		return defaultMap;
	}

	// for some strange reason
	// this is what inits the class
	Name *Name::declare(char *name, int flag)
	{
		if (name == NULL)
		{
			boost::call_once(&declareNullName, mooFlag);
			return nullName;
		}
		
		boost::call_once(&initMoo, mooFlag);
		boost::mutex& mutex2 = moo2();
		mutex2.lock();

		// convert name to string
		std::string sName = name;
		Name::NamMap *nameMap = namMap();
		
		// if some condition meets this, then we do this
		// currently i don't know what this is
		// most likely sends a nullish name
		// so here is some cleaned up code
		//if (auStack_40._0_4_ != auStack_40._16_4_)
		//{
			    //if (name != NULL {
					//ppcVar9 = &param_1;
					//pmVar4 = dictionary();
					//piVar5 = pmVar4[ppcVar9]; // ppcVar9 is in the Number class type (whole other rabbit hole)
				//}
				//pNVar6 = *(Name **)(auStack_40._0_4_ + 0x28);
				//boost::mutex::do_unlock(this);
				//return pNVar6;
		//}

		Name *currentName = new Name();
		if (currentName == NULL) // if null, make it null! makes perfect sense
			currentName = NULL;
		else
			currentName->dictionaryIndex = sizeof(name); // (int)name

		mutex2.unlock();
		return currentName;
	}

	void Name::declareNullName()
	{
		nullName = Name::declare("", 0);
	}
}