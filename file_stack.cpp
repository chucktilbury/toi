
#include <cstdio>
#include <string>
#include <cerrno>
#include <cstring>

#include "toi.h"

using namespace std;


FileStack::FileStack() {
    tlines = 0;
}

FileStack::~FileStack() { 

    while(!file_stack.empty())
        file_close(); 
}

// returns true if the file is now open
// throws an exception upon failure
void FileStack::file_open(string name) {

    Logging(DEBUG) << "opening file \"" << name << "\"";
    struct file_entry* fe = new struct file_entry;
    fe->fp = ifstream(name);

    if(fe->fp.is_open()) {
        fe->line_no = 1;
        fe->name = string(name);

        file_stack.push(fe);
    }
    else {
        Logging(FATAL) << "cannot open input file: \"" << name << "\": " << strerror(errno);
    }
}

int FileStack::read_character() {

    int retv = 0;

    if(!file_stack.empty()) {
        retv = file_stack.top()->fp.get();
        if(retv == EOF) { 
            // Note that if one reads the stack for a file and and a line 
            // number after this, it's the new file on the tos, not the 
            // one that matches the END_CONTEXT token. I don't think it's
            // a problem, but I am dropping this comment to mark the 
            // occourance.
            file_close();
            retv = 0x01;
        }
    }
    else {
        retv = 0x00;
    }

    if(retv == '\n') {
        file_stack.top()->line_no++;
        tlines++;
    }

    return retv;
}

void FileStack::unread_character(int ch) {
    if(!file_stack.empty()) {
        if(ch != '\n')
            file_stack.top()->fp.putback(ch);
    }
}

string FileStack::file_name() {
    
    if(!file_stack.empty())
        return file_stack.top()->name;
    else
        return string("no file");
}

int FileStack::line_number() {
    if(!file_stack.empty())
        return file_stack.top()->line_no;
    else
        return -1;
}

int FileStack::total_lines() {
    return tlines;
}

void FileStack::file_close() {
    // close the file and pop the stack
    if(!file_stack.empty()) {
        Logging(DEBUG) << "closing file \"" << file_stack.top()->name << "\"";
        struct file_entry* fe = file_stack.top();
        fe->fp.close();
        file_stack.pop();
        delete fe;
    }
    else
        Logging(DEBUG) << "no files to close";
}
