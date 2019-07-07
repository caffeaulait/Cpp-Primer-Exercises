#ifndef SCREEN_H
#define SCREEN_H
#include <string>
#include <iostream>
using namespace std;

class Screen
{
	friend class Window_mgr;
	
	using pos = string::size_type;
	
public:
	Screen()=default;
	Screen(pos ht, pos wd):
		height(ht),width(wd),contents(ht*wd,' '){}
	Screen(pos ht, pos wd, char c):
		height(ht),width(wd),contents(ht*wd,c) {}
	~Screen();
	
	char get() const {return contents[cursor];}
	char get(pos r, pos c) const { return contents[r*width+c];}
	
	Screen& move(pos r, pos c);
	Screen& set(char);
	Screen& set(pos,pos,char);
	Screen& display(ostream& os){
		do_display(os);
		return *this;
	}
	
	const Screen& display(ostream& os) const{
		do_display(os);
		return *this;
	}

private:
	pos cursor =0;
	pos height =0, width = 0;
	string contents;
	void do_display(ostream& os) const {
		os<<contents;
	}

};

inline Screen& Screen::move(pos r, pos c){
	cursor = r *width +c;
	return *this;
}

inline Screen& Screen::set(char c){
	contents[cursor]=c;
	return *this;
}

inline Screen& Screen::set(pos r,pos c,char ch){
	contents[r*width+c]=ch;
	return *this;
}

#endif // SCREEN_H
