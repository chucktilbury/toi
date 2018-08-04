#ifndef _FILE_STACK_H_
#define _FILE_STACK_H_

#include <cstdio>
#include <fstream>
#include <iostream>
#include <stack>
using namespace std;


/*
    Manages the stack of files created by "importing" files.
*/
class FileStack {

public:
    FileStack();
    ~FileStack();
    void file_open(string name);
    int read_character();
    void unread_character(int ch);

    string file_name();
    int line_number();
    int total_lines();
    
private:
    struct file_entry {
        string name;
        ifstream fp;
        int line_no;
    };

    stack <struct file_entry*> file_stack;
    unsigned int tlines;
    void file_close(void);
};

#endif /* _FILE_STACK_H_ */
