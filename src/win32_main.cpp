#ifndef UNICODE
#define UNICODE
#endif

#include <Windows.h>
#include "header.h"

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine, int nCmdShow)
{
    // Register the window class
    const wchar_t CLASS_NAME[] = L"CLASS WINDOW NAME";

    WNDCLASS wc = {0};

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        0,                      // Optional window styles
        CLASS_NAME,             // Window class (declared above)
        L"WINDOW TEXT",         // Window test (displayed in title bar)
        WS_OVERLAPPEDWINDOW,    // Window style (can be bitwise OR of available options)

        // Size and position
        CW_USEDEFAULT, // X
        CW_USEDEFAULT, // Y
        CW_USEDEFAULT, // nWidth
        CW_USEDEFAULT, // nHeight

        NULL, // Parent window
        NULL, // Menu
        hInstance, // Instance handle (first argument of WinMain)
        NULL // Additional application data

    );

    // CreateWindowEX() returns NULL if fails
    if(!hwnd)
    {
        return 1;
    }

    ShowWindow(hwnd, nCmdShow);

    // Run the message loop

    MSG msg ={0};
    while(GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    } // LEFT OFF HERE /////////////////////////////////////////////

    return 0;
}

