
#include "dntpch.h"
#include <cassert>

#include "Application.h"

 donatello::Application::Application()
{
	assert(application_ == nullptr);
	application_ = this;
}

donatello::Application* donatello::Application::application_ = nullptr;