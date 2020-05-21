#pragma once


namespace donatello::events
{
		template<typename T>
		class Event
		{
		public:
			virtual ~Event() = default;
		private:
			virtual T priority() = 0;
		};

		class KeyEvent : public Event<int>
		{
		public:

			KeyEvent()
			= default;
			int priority() override;
			~KeyEvent() override;
		};
}
