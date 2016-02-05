#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int i = 0;
int chunkSize = 10;

int main(int argc, char* argv[]) {

    if(argc < 3) {
        cout << "Not enough args" << endl;
    }

    ifstream inFile;
    ofstream outFile;

    inFile.open(argv[1]);
    outFile.open(argv[2]);

    char c;
    string line;
    string chunk;

    while(getline(inFile, line)){                                   // while line, put it in line

        if(line.size() == 0) {
            outFile.put('\n');
        } else {
            for(i = 0; i < line.size(); i++){                           // iterate over each char in line
                chunk.push_back(line[i]);                               // put each char in chunk

                if(i == (line.size() - 1) && (i % chunkSize) == 0)      // if EoL and chunk is filled
                {
                    outFile.write(chunk.c_str(), chunk.size());         // dump chunk into outFile
                    chunk.clear();                                      // clear chunk
                    outFile.put('\n');                                  // print \n
                }
                else if(i == (line.size() - 1) && (i % chunkSize) != 0) // if EoL and chunk is NOT filled
                {
                    outFile.write(chunk.c_str(), chunk.size());         // dump chunk into outFile
                    chunk.clear();                                      // clear chunk
                    outFile.put('\n');                                  // print \n
                }
                else if((i % chunkSize) == 0)                           // if chunk filled
                {
                    outFile.write(chunk.c_str(), chunk.size());         // dump chunk into outFile
                    chunk.clear();                                      // clear chunk
                }
            }
        }
    }

    inFile.close();                                                 // close inFile
    outFile.close();                                                // close inFile

    return 0;
}
