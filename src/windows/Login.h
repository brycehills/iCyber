#ifndef WINDOWS_LOGIN_H_
#define WINDOWS_LOGIN_H_

#include "Window.h"
#include "../util/AdminClass.h"	// admin class
#include <string.h>
#include <algorithm>    // std::fill

class Login : public Window {
private:
	zr_edit_box usernameBox;
	zr_edit_box passwordBox;
	zr_char username_buffer[MAX_BUFFER];
	zr_char password_buffer[MAX_BUFFER];
	zr_size passwordBoxLength;
	zr_size oldPasswordBoxLength;
	zr_state passwordBoxState;

	int state;
	bool adminLogin;
	string username;
	string password;

	int GetCustomerLogin(string username, string password);
public:
	Login(MyStack<TestimonialClass>* t, vector<Customer>* c, int *c_i) : Window(t, c, c_i) {
		ID = LOGIN;
		state = 0;
		zr_edit_box_init_fixed(&usernameBox, username_buffer, MAX_BUFFER,
				NULL, NULL);
//		zr_edit_box_init_fixed(&passwordBox, password_buffer, MAX_BUFFER,
//				NULL, NULL);
		adminLogin = false;
		*customer_index = -1;
	}
	~Login() {}
	void render_main(zr_window *);
	void init() {
		zr_edit_box_clear(&usernameBox);
		zr_edit_box_clear(&passwordBox);
		state = 0;
		adminLogin = false;
		password = "";
		for (unsigned int i = 0; i < passwordBoxLength; i++) {
			password_buffer[i] = '\0';
		}
		passwordBoxLength = 0;
	}
};



#endif /* WINDOWS_LOGIN_H_ */
