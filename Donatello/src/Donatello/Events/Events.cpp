#include "dntpch.h"
#include "Events.h"

int donatello::events::KeyEvent::priority()
{
	return 0;
}

donatello::events::KeyEvent::~KeyEvent()
= default;
