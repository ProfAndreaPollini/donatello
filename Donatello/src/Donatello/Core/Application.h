#pragma once



namespace donatello
{
	class Application
	{
	public:
		Application();
		inline static Application* Get() { return application_; }
	private:
		static Application* application_;
	};



}
