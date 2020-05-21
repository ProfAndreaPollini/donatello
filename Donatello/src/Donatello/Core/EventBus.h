#pragma once

#include <cassert>
#include <memory>
#include <queue>


#include "Donatello/Events/Events.h"

namespace donatello
{
	class EventBus
	{
	public:
		EventBus();
		static EventBus* Get() { 
			if (instance_ == nullptr) 
				instance_= std::make_shared<EventBus>();
			return instance_.get();
		}

		template<typename T>
		void Emit(const T& params);
	private:
		static std::shared_ptr<EventBus> instance_;
		//std::priority_queue<events::Event*> events_queue_;
	};


}


