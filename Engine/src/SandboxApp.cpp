#include <Mochi.h>

class Engine : public Mochi::Application {
	public:
		Engine() {

		}

		~Engine() {

		}
};

Mochi::Application* Mochi::CreateApplication() {
	return new Engine();
}