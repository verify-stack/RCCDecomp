#include "stdafx.h"
#include "ClassDescriptor.h"

namespace RBX
{
	namespace Reflection
	{
		boost::recursive_mutex& ClassDescriptor::sync()
		{
			boost::recursive_mutex recMutex;
			return recMutex;
		}

		ClassDescriptor::ClassDescriptor()
		{
			Name *rootName = Name::declare("<<ROOT>>", -1);
			this->className = rootName;
			this->base = NULL;
		}

		ClassDescriptor::ClassDescriptor(ClassDescriptor *baseClass, char *name)
		{
			//MemberDescriptorContainer *memContainer;
			int memContainer = NULL; // MemberDescriptorContainer doesn't exist yet

			this->className = Name::declare(name, -1);
			if (baseClass == NULL)
				memContainer = NULL;
			else
				memContainer = NULL; // baseClass->field_0x8
			this->base = baseClass;

			boost::recursive_mutex& recMutex = sync();
			recMutex.lock();
			
			// TODO: remove this statement
			if (baseClass != NULL) // this wasn't in the code, but inorder for it to not error do this
				//baseClass->derivedClasses.push_back(name);
				baseClass->derivedClasses.push_back(new ClassDescriptor(NULL, name));
			
			recMutex.unlock();
		}

		ClassDescriptor::~ClassDescriptor()
		{
			if (this->derivedClasses[0] != NULL)
				delete this->derivedClasses[0];

			vectorClasses emptyVector;
			emptyVector.swap(derivedClasses);
		}

		bool ClassDescriptor::operator==(ClassDescriptor *a)
		{
			return this == a;
		}
	}
}