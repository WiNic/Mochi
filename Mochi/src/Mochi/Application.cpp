#include "Application.h"

#include "Mochi/Events/ApplicationEvent.h"
#include "Mochi/Log.h"

namespace Mochi {

	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication)) {
			MOCHI_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput)) 
			MOCHI_TRACE(e); {
		}
		while (true);
	}

}