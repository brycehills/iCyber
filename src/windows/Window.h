#ifndef WINDOWS_WINDOW_H_
#define WINDOWS_WINDOW_H_

#define MAX_BUFFER  64

#include <math.h>
#include <string>
#include <sstream>
#include <iostream>
#include "../Member/Member.h"
#include "../gui/zahnrad.h"

using namespace std;

//make sure you add your window to the archive here!
const int LOADER = 0;

namespace patch { //this is for to_string
    template < typename T > std::string to_string( const T& n ) {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

class Window {
private:
	bool set, update, exit_prog;
	int ID_c;
protected:
	Member **members;
	int *num_members;
public:
	void * return_val;
	int ID;
	Window(Member **m, int *n_m) {
		update_data(m, n_m);
		set = false;
		ID_c = 0;
		return_val = NULL;
		ID = -1;
		update = false;
		exit_prog = false;
	}
	void issue_update() {
		update = true;
	}
	bool do_update() { //don't call this function
		if (update) {
			update = false;
			return true;
		}
		return false;
	}
	void update_data(Member **m, int *n_m) { //don't call this function
		members = m;
		num_members = n_m;
	}
	void set_data(Member **&m, int *&n_m) { //don't call this function
		m = members;
		n_m = num_members;
	}
	virtual ~Window() {}
	virtual void render_main(zr_window *) = 0;
	virtual void init() = 0;
	void changeWindow(int ID) {
		set = true;
		ID_c = ID;
	}
	int setWindow() { //don't call this function
		if (set) {
			set = false;
			return ID_c;
		}
		return ID;
	}
	void exit() {
		exit_prog = true;
	}
	bool exit_program() { //don't call this function
		return exit_prog;
	}
};

#endif /* WINDOWS_WINDOW_H_ */
