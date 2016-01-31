#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int i = 0;
int chunkSize = 10;

int main(int argc, char* argv[]) {

    if(argc < 3) {
        printf("Not enough args\n");
    }

    ifstream inFile;
    ofstream outFile;

    inFile.open(argv[1]);
    outFile.open(argv[2]);

    char c;
    string chunk;

    while (inFile.get(c)){
        chunk.push_back(c);// push char into string
        if(i > chunkSize) {
            cout << chunk;

            outFile.write(chunk.c_str(), chunkSize); // dump string of size chunkSize into outFile

            chunk.clear();
            i = 0;
        } else {
            i++;
        }
    }

    if (inFile.eof())                      // check for EOF
        cout << "\n[EoF reached]\n";
    else
        cout << "\n[error reading]\n";

    inFile.close();                        // close file

    return 0;
}
