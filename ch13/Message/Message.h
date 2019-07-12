#ifndef MESSAGE_H
#define MESSAGE_H
#include <string>
#include <set>
#include <iostream>
using namespace std;

class Folder;


class Message
{
	friend class Folder;
	friend void swap(Message&, Message&);
	friend void swap(Folder&, Folder&);
	
public:
	Message(const string& str = ""):contents(str){}
	
	Message(const Message&);
	
	Message& operator=(const Message&);
	
	~Message();
	
	void save(Folder&);
	
	void remove(Folder&);
	
	void print_debug();
	

private:
	string contents;
	set<Folder*> folders;
	void add_to_Folders(const Message&);
	void remove_from_Folders();
	
	void addFldr(Folder* f){
		folders.insert(f);
	}
	
	void remFldr(Folder* f){
		folders.erase(f);
	}
};

class Folder{
	friend class Message;
	friend void swap(Message&, Message&);
	friend void swap(Folder&, Folder&);
	
public:
	Folder()=default;
	Folder(const Folder&);
	Folder& operator=(const Folder&);
	~Folder();
	
	void print_debug();

private:
	set<Message*> msgs;
	
	void add_to_Messages(const Folder&);
	void remove_from_Messages();
	void addMsg(Message* m){
		msgs.insert(m);
	}
	void remMsg(Message *m){
		msgs.erase(m);
	}
};

void swap(Message&, Message&);
void swap(Folder&, Folder&);

#endif // MESSAGE_H
