#include <windows.h>
#include <windowsx.h>
#include <iostream>
#include <vector>
#include <stack>
#include "windows/Loader.h"
#include "windows/Admin.h"
#include "windows/Login.h"
#include "windows/OrderProducts.h"
#include "windows/Testimonials.h"
#include "windows/CustomerMenu.h"
#include "windows/CustomerListWindow.h"
#include "windows/AddUser.h"
#include "gui/zahnrad.h"
#include "GUI.h"
#include "util/Loader.h"
#include "Member/Member.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define MAX_MEMORY  (32 * 1024)
#define MAX_ITEMS 256

using namespace std;

//variable declaration

//GUI related stuff, you don't need to modify
XWindow xw;
Attributes gui;
Window **windows;
int window_index = 0;
int window; //for saving window data

//Number of windows, add as you move forward
int num_windows = 8;

stack<string> *testimonials;
vector<Customer> *customers;
int *customer_index;

//INSTRUCTIONS TO ADD gdi32!!
//"BulkClub"->Properties->C/C++ Build->Settings->
//MinGW C++ Linker->Libraries->Libraries (-l)->
//*click icon with green plus sign*->Type "gdi32" without quotes->
//Ok->Apply->Ok

//GUI documentation: https://github.com/vurtun/zahnrad

// How to add a window
// 1. Add new .h and .cpp file to 'windows' folder
// 2. Create class and include Window publically
// 3. Implement class. Take a look at other windows as an example.
// 4. Include .h file above
// 5. Go to line 133 (approx.) here and initialize you class (follow format exactly of other classes)
// 6. Go to Window.h and add a const int for your class
// 7. Happiness!

LRESULT CALLBACK wnd_proc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
    case WM_DESTROY:
        PostQuitMessage(WM_QUIT);
        gui.running = false;
        break;
    case WM_SIZE:
        if (xw.backbuffer) {
        xw.width = LOWORD(lParam);
        xw.height = HIWORD(lParam);
        surface_resize(xw.backbuffer, xw.hdc, xw.width, xw.height);
        } break;
    default:
        return DefWindowProc(hWnd, msg, wParam, lParam);
    }
    return 0;
}

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE prev, LPSTR lpCmdLine, int shown) {
	//init GUI
	FreeConsole();
    xw.wc.style = CS_HREDRAW|CS_VREDRAW;
    xw.wc.lpfnWndProc = wnd_proc;
    xw.wc.hInstance = hInstance;
    xw.wc.lpszClassName = "GUI";
    RegisterClass(&xw.wc);
    xw.hWnd = CreateWindowEx(
        0, xw.wc.lpszClassName, "iCyber",
        WS_OVERLAPPED|WS_CAPTION|WS_SYSMENU|WS_MINIMIZEBOX|WS_MAXIMIZEBOX|WS_VISIBLE,
        CW_USEDEFAULT, CW_USEDEFAULT,
        WINDOW_WIDTH, WINDOW_HEIGHT,
        0, 0, hInstance, 0);

    xw.hdc = GetDC(xw.hWnd);
    GetClientRect(xw.hWnd, &xw.rect);
    xw.backbuffer = surface_new(xw.hdc, xw.rect.right, xw.rect.bottom);
    xw.font = font_new(xw.hdc, "Times New Roman", 16);
    xw.width = xw.rect.right;
    xw.height = xw.rect.bottom;

    gui.font.userdata = zr_handle_ptr(&xw);
    gui.font.height = (zr_float)xw.font->height;
    gui.font.width =  font_get_text_width;
    zr_style_default(&gui.style, ZR_DEFAULT_ALL, &gui.font);
    zr_command_queue_init_fixed(&gui.queue, malloc(MAX_MEMORY), MAX_MEMORY);

    zr_window_init(&gui.window, zr_rect(5, 5, WINDOW_WIDTH - 20, WINDOW_HEIGHT - 40),
	ZR_WINDOW_BORDER,
	&gui.queue, &gui.style, &gui.input);

    set_style(&gui.style);

    //this is where you initialize all the program specific stuff
	testimonials = new stack<string>;
	customers = new vector<Customer>;
	customer_index = new int;
	LoadTestimonials(testimonials);
	LoadCustomers(customers);


    windows = new Window*[num_windows];
    for (int i = 0; i < num_windows; i++) windows[i] = NULL;
    windows[LOGIN] = new Login(testimonials, customers, customer_index);
    windows[ADMIN] = new Admin(testimonials, customers, customer_index);
    windows[ORDER_PRODUCTS] = new OrderProducts(testimonials, customers, customer_index);
    windows[TESTIMONIALS] = new Testimonials(testimonials, customers, customer_index);
    windows[CUSTOMER_MENU] = new CustomerMenu(testimonials, customers, customer_index);
    windows[CUSTOMER_LIST] = new CustomerListWindow(testimonials, customers, customer_index);
    windows[ADD_USER] = new AddUser(testimonials, customers, customer_index);
    //load your windows here!

    gui.running = true;

    //Don't worry about any of the rest of this, it's all GUI stuff
    while (gui.running) {
        /* Input */
        MSG msg;
        zr_input_begin(&gui.input);
        while (PeekMessage(&msg, xw.hWnd, 0, 0, PM_REMOVE)) {
        	if (msg.message == WM_KEYDOWN)
        		input_key(&gui.input, &msg, zr_true);
			else if (msg.message == WM_KEYUP)
				input_key(&gui.input, &msg, zr_false);
			else if (msg.message == WM_LBUTTONDOWN)
				input_btn(&gui.input, &msg, zr_true);
			else if (msg.message == WM_LBUTTONUP)
				input_btn(&gui.input, &msg, zr_false);
			else if (msg.message == WM_MOUSEMOVE)
				input_motion(&gui.input, &msg);
			else if (msg.message == WM_CHAR)
				input_text(&gui.input, &msg);
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        zr_input_end(&gui.input);

        windows[window_index]->render_main(&gui.window);
        if (windows[window_index]->exit_program()) gui.running = false;
        if (windows[window_index]->do_update()) {
        	windows[window_index]->set_data(members, num_members);
        	for (int i = 0; i < num_windows; i++){
        		if (i != window_index && windows[i] != NULL) windows[i]->update_data(members, num_members);
        	}
        }
        window = windows[window_index]->setWindow();
        if (window_index != window) {
        	windows[window_index]->init();
        	window_index = window;
        }

        surface_begin(xw.backbuffer);
        surface_clear(xw.backbuffer, 100, 100, 100);
        draw(xw.backbuffer, &gui.queue);
        surface_end(xw.backbuffer, xw.hdc);
    }

    free(zr_buffer_memory(&gui.queue.buffer));
    font_del(xw.font);
    surface_del(xw.backbuffer);
    ReleaseDC(xw.hWnd, xw.hdc);
    return 0;
}
