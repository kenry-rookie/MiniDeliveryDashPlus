#include "gameplay/game/Game.h"

#ifdef __APPLE__
#include <mach-o/dyld.h>
#include <unistd.h>
#include <string>
#include <limits.h>
#endif

int main()
{
#ifdef __APPLE__
    char path[PATH_MAX];
    uint32_t size = sizeof(path);

    if (_NSGetExecutablePath(path, &size) == 0)
    {
        std::string exePath(path);

        size_t pos = exePath.find_last_of('/');
        if (pos != std::string::npos)
        {
            std::string exeDir = exePath.substr(0, pos);

            // Cambiar directorio actual a donde está el ejecutable
            std::string resourcesDir = exeDir + "/../Resources";
            chdir(resourcesDir.c_str());
        }
    }
#endif

    Game game;
    return game.Run();
}