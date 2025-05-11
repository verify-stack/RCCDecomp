#include "stdafx.h"

#include <map>
#include "boost/thread/once.hpp"

namespace RBX
{
	class RBXBaseClass Name : public boost::noncopyable
	{
	public:
		Name();
		~Name();

		// should these two be a class or function?
		class NamMap : public std::map<const char *, Name *> {};
		class dictionary : public std::map<int, Name *, std::less<int>, std::allocator<std::pair<const int, Name *>>> {};
		
		static NamMap *namMap();
		static Name *declare(char *name, int flag);
		static void declareNullName();
		
		int dictionaryIndex;
		std::string name;
	};

	//class Name::NamMap
	//{
	//public:
		//NamMap();
		//~NamMap();
	//}
}