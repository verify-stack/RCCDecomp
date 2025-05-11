#pragma once
#include "stdafx.h"

namespace RBX
{
	class RBXBaseClass Creatable {
	private:
		Creatable();
	public:
		template<class T>
		static boost::shared_ptr<T> create() // stolen from the source code leak, TODO: replace this
		{
			//boost::shared_ptr<T> obj = boost::shared_ptr<T>(new T());
            //boost::shared_ptr<T> (*thisFunction)() = &create;
			// we don't have this, don't include this
            //checkRbxCaller<kCallCheckCallersCode, callCheckSetBasicFlag<HATE_RETURN_CHECK> >(reinterpret_cast<void*>(thisFunction));
			return boost::shared_ptr<T>(new T());
		}
	}
}