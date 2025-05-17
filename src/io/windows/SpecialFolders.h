#pragma once

#ifdef _WIN32

#include <string>
#include <shlobj.h>

#pragma comment(lib, "shell32.lib")
#pragma comment(lib, "ole32.lib")

namespace Verbeal::IO::Windows
{
	std::string GetKnownPath(const GUID folderIdentifier);
}

#endif