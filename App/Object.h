#pragma once
#include "stdafx.h"

namespace RBX
{
	class RBXBaseClass Creatable {
	private:
		Creatable();
	public:
		template<class T>
		static boost::shared_ptr<T> create()
		{
			T classUnit;

			classUnit = new T();
			if (classUnit == NULL)
				classUnit = NULL
			else
				classUnit = NULL // TODO
		}

		//template<class T>
		//static boost::shared_ptr<T> create(auto P1)
		//{
		//}
	};
};