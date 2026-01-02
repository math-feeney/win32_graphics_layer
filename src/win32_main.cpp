#ifndef UNICODE
#define UNICODE
#endif

#include <Windows.h>
#include <WinDef.h>
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
    while(GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    } 

    return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    // Initialize a return value
    LRESULT Result = 0;

    switch(uMsg)
    {
        case WM_SIZE:
        {
            // TODO: maybe implement LOWORD and HIWORD myself
            int width = LOWORD(lParam);
            int heigth = HIWORD(lParam);

            // Respond to the message:
            // TODO: write this function 
            //OnSize(hwnd, (UINT)wParam, width, heigth);
        } break;

        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            // All painting occurs here, between BeginPaint and EndPaint

            FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW + 1));

            EndPaint(hwnd, &ps);
        } break;

        case WM_CLOSE:
        {
            if(MessageBox(hwnd, L"Really quit?", L"APPLICATION TEXT", MB_OKCANCEL) == IDOK)
            {
                DestroyWindow(hwnd);
            }
            return Result;
        } break; // NOTE: this break statement should probably never be reached

        default:
        {
            Result = DefWindowProc(hwnd, uMsg, wParam, lParam);
        }

    }

    return Result;
}
