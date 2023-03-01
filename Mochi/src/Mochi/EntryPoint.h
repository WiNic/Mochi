#pragma once


#ifdef MOCHI_PLATFORM_WINDOWS

extern Mochi::Application* Mochi::CreateApplication();

int main(int argc, char** argv) {
	Mochi::Log::Init();
	MOCHI_CORE_WARN("Initialized Log!");
	MOCHI_INFO("Hello");
	
	auto app = Mochi::CreateApplication();
	app->Run();
	delete app;
}

#endif 
 