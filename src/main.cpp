#include "Application.h"

int main()
{
	using namespace Verbeal;

	Application app;
	app.Init();
	app.Run();
	app.Cleanup();
}
