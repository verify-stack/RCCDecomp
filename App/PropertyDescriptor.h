// prop stuff
#include "stdafx.h"

#include "Descriptor.h"

namespace RBX
{
	namespace Reflection // yes this is a namespace
	{
		class PropertyDescriptor : public Descriptor
		{
		public:
			PropertyDescriptor();
			~PropertyDescriptor(); // keep this here just in case

			int read();
		};
	}
}