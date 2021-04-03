#ifndef ENABLEPOLYMORPHICSHARED_HPP
#define ENABLEPOLYMORPHICSHARED_HPP

#include <memory>

template <class Base, class Derived>
struct EnablePolymorphicShared : public Base
{
	std::shared_ptr<Derived> shared_from_this()
	{
		return std::static_pointer_cast<Derived>(Base::shared_from_this());
	}
	std::weak_ptr<Derived> weak_from_this()
	{
		return std::static_pointer_cast<Derived>(Base::weak_from_this());
	}
};

#endif