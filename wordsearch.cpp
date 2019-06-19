#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "wordsearch.hpp"

using namespace std;

/*function... might want it in some class?*/
int getdir (string dir, vector<string> &files)
{
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return errno;
    }
    
    while ((dirp = readdir(dp)) != NULL) {
        files.push_back(string(dirp->d_name));
    }
    closedir(dp);
    return 0;
}


int main(int argc, char* argv[])
{
    string dir; //
    vector<string> files = vector<string>();
    
    if (argc < 2)
    {
        cout << "No Directory specified; Exiting ..." << endl;
        return(-1);
    }
    dir = string(argv[1]);
    if (getdir(dir,files)!=0)
    {
        cout << "Error opening " << dir << "; Exiting ..." << endl;
        return(-2);
    }
    
    
    string slash("/");
    
    Word arrayOfWords[1000];
    int used = 0;
    
    for (unsigned int i = 0;i < files.size();i++) {
        if (used == 1000) {
            cout << "Error! Capacity reached. Exiting." << endl;
            return 0;
        }
        if(files[i][0]=='.')continue; //skip hidden files
        
        ifstream fin((string(argv[1])+slash+files[i]).c_str()); //open using absolute path
        // ...read the file...
        string word;
        
        while(true){
            fin>>word;
            bool newMatch = false;
            for (int j = 0; j < used; j++) {
                if (word == arrayOfWords[j].get_word()) {
                    newMatch = true;
                    arrayOfWords[j].get_bag()->add(files[i]);
                }
            }
            if (!newMatch) {
                bag *tempBag = new bag;
                //tempBag -> add(files[i]);
                arrayOfWords[used].set_bag(*tempBag);
                arrayOfWords[used].set_word(word);
                arrayOfWords[used].get_bag()->add(files[i]);
                used++;
            }
            if(fin.eof()) {cout << "EOF " << files[i] << endl; break;}
            
            
            
        }
       
        fin.close();
    }
    
    //cout << "This is the next part of the program " << endl;
    while (true) {
        string input_word;
        cout << "Please enter a word to search or '-1' to quit. " <<endl;
        cin >> input_word;
        if (input_word == "-1") {
            break;
        }
        bool leMatch = false;
        for (int i = 0; i < used; i++) {
            if (input_word == arrayOfWords[i].get_word()) {
                leMatch = true;
                arrayOfWords[i].get_bag()->print();
            }
        }
        if (!leMatch) {
            cout << "Word not found. " << endl;
        }
    }
 
    return 0;
    
    
}



