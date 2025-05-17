#include "SpecialFolders.h"

#ifdef _WIN32

#endif
std::string Verbeal::IO::Windows::GetKnownPath(const GUID folderIdentifier)
{
	PWSTR path = nullptr;
    HRESULT r;

    r = SHGetKnownFolderPath(FOLDERID_SavedGames, KF_FLAG_CREATE, nullptr, &path);
    if (path != nullptr)
    {
        printf("%ls", path);
        CoTaskMemFree(path);
    }
}
