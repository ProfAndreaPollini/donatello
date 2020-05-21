#include "dntpch.h"
#include "EventBus.h"

#include <iostream>
#include <cassert>
#include <Donatello\Events\Events.h>

donatello::EventBus::EventBus()
{
	assert(instance_ == nullptr);
	
}

std::shared_ptr<donatello::EventBus> donatello::EventBus::instance_ = nullptr;

template <>
void donatello::EventBus::Emit<donatello::events::KeyEvent>(const donatello::events::KeyEvent& params)
{
}

template <typename T>
void donatello::EventBus::Emit(const T& params)
{
	assert(false);
}
