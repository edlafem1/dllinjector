#define WIN32_LEAN_AND_MEAN
#include <windows.h>

extern "C" __declspec(dllexport)
DWORD WINAPI MessageBoxThread(LPCWSTR text) {
    MessageBox(NULL, text, L"Hello World!", NULL);
    return 0;
}

extern "C" __declspec(dllexport)
BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD ul_reason_for_call,
    LPVOID lpReserved) {
    

    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
        MessageBoxThread(L"PROC_ATTACH");
        break;
    case DLL_THREAD_ATTACH:
        MessageBoxThread(L"THREAD_ATTACH");
        break;
    case DLL_THREAD_DETACH:
        MessageBoxThread(L"THREAD_DETACH");
        break;
    case DLL_PROCESS_DETACH:
        MessageBoxThread(L"PROC_DETACH");
        break;
    }
    return TRUE;
}