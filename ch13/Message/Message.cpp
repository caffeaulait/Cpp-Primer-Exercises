#include "Message.h"

void Message::save(Folder &f){
	folders.insert(&f);
	f.addMsg(this);
}

void Message::remove(Folder &f){
	folders.erase(&f);
	f.remMsg(this);
}

void Message::add_to_Folders(const Message &m){
	for(auto f : m.folders)
		f->addMsg(this);
}

void Message::remove_from_Folders(){
	for(auto f : folders)
		f->remMsg(this);
}

Message::Message(const Message &m):
	contents(m.contents), folders(m.folders){
		add_to_Folders(m);
	}
	
Message::~Message(){
	remove_from_Folders();
}

Message& Message::operator =(const Message& rhs){
	remove_from_Folders();
	contents = rhs.contents;
	folders = rhs.folders;
	add_to_Folders(rhs);
	return *this;
}

void Message::print_debug(){
	cout<<contents<<endl;
}

void Folder::print_debug(){
	for(auto m : msgs)
		cout<<m->contents<<" ";
	cout<<"\n";
}

void swap(Message &lhs, Message &rhs){
	for(auto f : lhs.folders)
		f ->remMsg(&lhs);
	for(auto f : rhs.folders)
		f->remMsg(&rhs);
	swap(lhs.folders,rhs.folders);
	swap(lhs.contents,rhs.contents);
	for(auto f : lhs.folders)
		f->addMsg(&lhs);
	for(auto f : rhs.folders)
		f->addMsg(&rhs);
}

void swap(Folder &lhs, Folder &rhs){
	lhs.remove_from_Messages();
	rhs.remove_from_Messages();
	swap(lhs.msgs,rhs.msgs);
	
	lhs.add_to_Messages(lhs);
	rhs.add_to_Messages(rhs);
}

Folder::Folder(const Folder& f):msgs(f.msgs){
	add_to_Messages(f);
}

Folder& Folder::operator =(const Folder& rhs){
	remove_from_Messages();
	msgs = rhs.msgs;
	add_to_Messages(rhs);
	return *this;
}

Folder::~Folder(){
	remove_from_Messages();
}
void Folder::add_to_Messages(const Folder& f)
{
    for (auto m : f.msgs) m->addFldr(this);
}

void Folder::remove_from_Messages()
{
    for (auto m : msgs) m->remFldr(this);
}