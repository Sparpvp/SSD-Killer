#include <fstream>

using namespace std;

int main() 
{
    const char *path="/home/var.txt";
    bool l = 1; // Running on GNU/Linux boolean true
    bool w = 0; // Running on windows boolean false

    unsigned long int size_file = 536870912; // 512MB in bytes
    short int data(0);
    
    while(true)
    {
        ofstream file(path);
        for (int i = 0; i < size_file; i++) 
        {
            file << data;
        }
        remove("/home/var.txt"); // Delete, another r+w action :D
        
        // Restart data allocating 
    }

    return 0;
}
