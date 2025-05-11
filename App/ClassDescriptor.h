#pragma once
#include "stdafx.h"

#include "Descriptor.h"
#include "RBXName.h"
#include "boost/thread/recursive_mutex.hpp"

namespace RBX
{
	namespace Reflection
	{
		class ClassDescriptor;

		typedef std::vector<ClassDescriptor *, std::allocator<ClassDescriptor *>> vectorClasses;

		class ClassDescriptor : public Descriptor
		{
		private:
			boost::recursive_mutex& sync();
		public:
			ClassDescriptor();
			ClassDescriptor(ClassDescriptor *baseClass, char *name);
			~ClassDescriptor();

			bool operator==(ClassDescriptor *a);

			Name *className;
			ClassDescriptor *base;
			vectorClasses derivedClasses;
		};
	}
}