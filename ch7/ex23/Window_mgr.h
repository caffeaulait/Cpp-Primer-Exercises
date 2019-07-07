#ifndef WINDOW_MGR_H
#define WINDOW_MGR_H
using namespace std;

class Window_mgr
{
public:
	Window_mgr();
	~Window_mgr();
	
	using ScreenIndex = vector<Screen>::size_type;
	
	void clear(ScreenIndex);

private:
	vector<Screen> screens{Screen(24,80,' ')};
};

void Window_mgr::clear(ScreenIndex i){
	Screen& s = screens[i];
	s.contents = string(s.height*s.width,' ');
}

#endif // WINDOW_MGR_H
