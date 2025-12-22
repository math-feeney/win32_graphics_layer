#include <Windows.h>
#include "header.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nShowCmd)
{
    test_struct test = {0};

    MessageBoxA(0, "Hello", "test", MB_OK);

    return 0;
}