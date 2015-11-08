/*************************************************************************
 * AUTHOR	     : Steve Fajardo
 * STUDENT ID    : 832032
 * ASSIGNMENT #6 : Pointers
 * CLASS	     : CS1C
 * SECTION       : MW 5:30 P.M.
 * DUE DATE      : 9/28/15
 ************************************************************************/
#ifndef WINDOWS_LOGIN_H_
#define WINDOWS_LOGIN_H_

#include "Window.h"

class Login : public Window {
private:
	zr_edit_box usernameBox;
	zr_edit_box passwordBox;
	zr_char username_buffer[MAX_BUFFER];
	zr_char password_buffer[MAX_BUFFER];
	int state;
	bool adminLogin;
	string username;
	string password;
public:
	Login(Member **m, int *n_m) : Window(m, n_m) {
		ID = LOGIN;
		state = 0;
		adminLogin = false;
		zr_edit_box_init_fixed(&usernameBox, username_buffer, MAX_BUFFER, NULL, NULL);
		zr_edit_box_init_fixed(&passwordBox, password_buffer, MAX_BUFFER, NULL, NULL);
	}
	~Login() {}
	void render_main(zr_window *);
	void init() {
		zr_edit_box_clear(&usernameBox);
		zr_edit_box_clear(&passwordBox);
		state = 0;
	}
};



#endif /* WINDOWS_LOGIN_H_ */
