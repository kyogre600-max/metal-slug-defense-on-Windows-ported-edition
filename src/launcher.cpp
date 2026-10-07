#ifndef UNICODE
#define UNICODE
#endif
#ifndef _UNICODE
#define _UNICODE
#endif
#include <windows.h>
#include <string>

static const wchar_t* entry_for_name(const std::wstring& name) {
    if (_wcsicmp(name.c_str(), L"Start_MSD_All_Units_Level1.exe") == 0)
        return L"all_units_level1_launcher.py";
    if (_wcsicmp(name.c_str(), L"Start_MSD_All_Unlocked_Max_Level.exe") == 0)
        return L"all_unlocked_max_level_launcher.py";
    if (_wcsicmp(name.c_str(), L"Start_MSD_Max_Level.exe") == 0)
        return L"max_level_launcher.py";
    if (_wcsicmp(name.c_str(), L"Start_LAB.exe") == 0)
        return L"lab_launcher.py";
    return L"portable_launcher.py";
}

int WINAPI wWinMain(HINSTANCE,HINSTANCE,PWSTR command_line,int){
    wchar_t path[32768];DWORD n=GetModuleFileNameW(nullptr,path,32768);
    if(!n||n>=32768)return 1;
    std::wstring root(path,n);
    const size_t separator=root.find_last_of(L"\\/");
    const std::wstring name=root.substr(separator+1);
    const wchar_t* selected_entry=entry_for_name(name);
    root.resize(separator);
    std::wstring python=root+L"\\windows_runtime\\pythonw.exe";
    std::wstring entry=root+L"\\"+selected_entry;
    std::wstring args=L"\""+python+L"\" -B -I -S \""+entry+L"\"";
    if(_wcsicmp(name.c_str(),L"Start_LAB.exe")==0)args+=L" --windowed";
    if(command_line&&*command_line){args+=L" ";args+=command_line;}
    STARTUPINFOW si{};si.cb=sizeof(si);PROCESS_INFORMATION pi{};
    if(!CreateProcessW(python.c_str(),&args[0],nullptr,nullptr,FALSE,0,nullptr,root.c_str(),&si,&pi)){
        MessageBoxW(nullptr,L"Unable to start MSD WINDOWS S1XLV. Extract the complete package and keep its folders beside this launcher.",L"MSD WINDOWS S1XLV",MB_ICONERROR);return 1;
    }
    CloseHandle(pi.hThread);CloseHandle(pi.hProcess);return 0;
}
