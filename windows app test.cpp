#include "pch.h"
#include <windows.h>
#include "resource.h"
#include <string>
#include <map>
#include <vector>

// Forward declarations of functions
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void AddMenus(HWND);
void ShowAboutDialog(HWND);
void InstallSoftware(const std::wstring& software);
void HandleError(const std::wstring& message);

// Global variables
HMENU hMenu;
std::map<std::wstring, std::wstring> softwareMap = {
    {L"python", L"Python.Python.3"},
    {L"visual studio code", L"Microsoft.VisualStudioCode"},
    {L"git", L"Git.Git"},
    {L"node.js", L"OpenJS.NodeJS"},
    {L"docker", L"Docker.DockerDesktop"},
    {L"java", L"Oracle.JavaRuntimeEnvironment"},
    {L"notepad++", L"Notepad++.Notepad++"}
};

// Entry point
int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PWSTR pCmdLine, _In_ int nCmdShow) {
    // Register the window class
    WNDCLASSW wc = {};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = L"WindowsAppTest";
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    RegisterClassW(&wc);

    // Create the window
    HWND hwnd = CreateWindowExW(
        0,
        L"WindowsAppTest",
        L"Windows App Test",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 500, 300,
        NULL, NULL, hInstance, NULL
    );

    if (hwnd == NULL) {
        HandleError(L"Failed to create window");
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    // Run the message loop
    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

// Window procedure
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
    case WM_CREATE:
        AddMenus(hwnd);
        break;
    case WM_COMMAND:
        switch (LOWORD(wParam)) {
        case IDM_ABOUT:
            ShowAboutDialog(hwnd);
            break;
        case IDM_EXIT:
            PostQuitMessage(0);
            break;
        case 40003: // Example for installing Python
            InstallSoftware(L"python");
            break;
            // Add cases for other software
        case 40004:
            InstallSoftware(L"visual studio code");
            break;
        case 40005:
            InstallSoftware(L"git");
            break;
        case 40006:
            InstallSoftware(L"node.js");
            break;
        case 40007:
            InstallSoftware(L"docker");
            break;
        case 40008:
            InstallSoftware(L"java");
            break;
        case 40009:
            InstallSoftware(L"notepad++");
            break;
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

// Show About dialog
void ShowAboutDialog(HWND hwnd) {
    MessageBox(hwnd, L"Windows App Test\nVersion 1.0\n\nCopyright (c) 2024", L"About Windows App Test", MB_OK | MB_ICONINFORMATION);
}

// Add menus
void AddMenus(HWND hwnd) {
    hMenu = CreateMenu();

    HMENU hFileMenu = CreateMenu();
    HMENU hHelpMenu = CreateMenu();
    HMENU hInstallMenu = CreateMenu();

    AppendMenu(hFileMenu, MF_STRING, IDM_EXIT, L"Exit");
    AppendMenu(hHelpMenu, MF_STRING, IDM_ABOUT, L"About");

    // Adding all software installation options
    AppendMenu(hInstallMenu, MF_STRING, 40003, L"Install Python");
    AppendMenu(hInstallMenu, MF_STRING, 40004, L"Install Visual Studio Code");
    AppendMenu(hInstallMenu, MF_STRING, 40005, L"Install Git");
    AppendMenu(hInstallMenu, MF_STRING, 40006, L"Install Node.js");
    AppendMenu(hInstallMenu, MF_STRING, 40007, L"Install Docker");
    AppendMenu(hInstallMenu, MF_STRING, 40008, L"Install Java");
    AppendMenu(hInstallMenu, MF_STRING, 40009, L"Install Notepad++");

    AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hFileMenu, L"File");
    AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hHelpMenu, L"Help");
    AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hInstallMenu, L"Install");

    SetMenu(hwnd, hMenu);
}

// Install Software
void InstallSoftware(const std::wstring& software) {
    auto it = softwareMap.find(software);
    if (it != softwareMap.end()) {
        std::wstring command = L"winget install " + it->second;
        _wsystem(command.c_str());
        MessageBox(NULL, (L"Installing " + software).c_str(), L"Install Software", MB_OK | MB_ICONINFORMATION);
    }
    else {
        HandleError(L"Software not found");
    }
}

// Handle error
void HandleError(const std::wstring& message) {
    MessageBox(NULL, message.c_str(), L"Error", MB_OK | MB_ICONERROR);
}
