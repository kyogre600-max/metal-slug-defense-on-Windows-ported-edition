#ifndef UNICODE
#define UNICODE
#endif
#ifndef _UNICODE
#define _UNICODE
#endif
#include <windows.h>
#include <string>
int WINAPI wWinMain(HINSTANCE,HINSTANCE,PWSTR command_line,int){
    wchar_t path[32768];DWORD n=GetModuleFileNameW(nullptr,path,32768);
    if(!n||n>=32768)return 1;
    std::wstring root(path,n);root.resize(root.find_last_of(L"\\/"));
    std::wstring python=root+L"\\windows_runtime\\pythonw.exe";
    std::wstring entry=root+L"\\portable_launcher.py";
    std::wstring args=L"\""+python+L"\" -B -I -S \""+entry+L"\"";
    if(command_line&&*command_line){args+=L" ";args+=command_line;}
    STARTUPINFOW si{};si.cb=sizeof(si);PROCESS_INFORMATION pi{};
    if(!CreateProcessW(python.c_str(),&args[0],nullptr,nullptr,FALSE,0,nullptr,root.c_str(),&si,&pi)){
        MessageBoxW(nullptr,L"Unable to start MSD WINDOWS S1XLV. Extract the complete package and keep its folders beside this launcher.",L"MSD WINDOWS S1XLV",MB_ICONERROR);return 1;
    }
    CloseHandle(pi.hThread);CloseHandle(pi.hProcess);return 0;
}
