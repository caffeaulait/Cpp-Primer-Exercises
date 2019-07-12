#include <iostream>
#include "Message.h"

int main()
{
    Message firstMail("hello");
    Message signInMail("welcome to cppprimer");
    Folder mailBox;

    firstMail.print_debug(); // print: "hello"
    firstMail.save(mailBox); // send to mailBox
    mailBox.print_debug();   // print: "hello"

    signInMail.print_debug(); // print "welcome to cppprimer"
    signInMail.save(mailBox); // send to mailBox
    mailBox.print_debug();    // print "welcome to cppprimer hello"
}