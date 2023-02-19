#pragma once


#ifdef MOCHI_PLATFORM_WINDOWS
extern Mochi::Application* Mochi::CreateApplication();
int main(int argc, char** argv) {
	

	auto app = Mochi::CreateApplication();
	app->Run();
	delete app;
}

#endif 
