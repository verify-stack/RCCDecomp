// recreated based on leaked source code
// we'll use this instead of puts and printf

#pragma once
#include "stdafx.h"

#include <string>
#include "boost/enable_shared_from_this.hpp"

namespace RBX
{
	typedef enum { 
		MESSAGE_OUTPUT,
		MESSAGE_INFO,
		MESSAGE_WARNING,
		MESSAGE_ERROR,
		MESSAGE_SENSITIVE,
        MESSAGE_TYPE_MAX
	} MessageType;

	class StandardOut : public boost::enable_shared_from_this<StandardOut>
	{
	private:
		StandardOut(); // use singleton instead
	public:
		static boost::shared_ptr<StandardOut> singleton();

		void print(MessageType type, const std::exception message);
		void print(MessageType type, const char* message);
	};
}


