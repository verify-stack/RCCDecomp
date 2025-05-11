// instance type
#include "stdafx.h"

#include <vector>

namespace RBX
{
	class Instance
	{
	private:
		// children list
		std::vector<boost::shared_ptr<Instance>> children;

		// core props
		std::string name;
		Instance *parent; // should we use shared_ptr<Instance>?
		bool archivable;
	public:
		Instance();
		Instance(char *name);
		~Instance();

		std::string getName() { return name; };
		Instance *getParent() { return parent; };
	};
}
