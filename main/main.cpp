
#include <iostream>
#include <stdio.h>
#include <tchar.h>
#include <Windows.h>

using namespace std;

int main()
{
    int dw_ammo = 0x24;
    int ad_ammo = 0x35640DC0;
    int write_ammo = 100;
    int read_ammo = 0;


    DWORD Ammo = (DWORD)(ad_ammo + dw_ammo); //convertir a dword
    HWND hwnd = FindWindowA(NULL, "Clownfield 2042");
    
    if (hwnd == NULL) {
        cout << "No se encuentra el juego" << endl;
        Sleep(3000);
        exit(-1);
    }
    else {
        DWORD procID;
        GetWindowThreadProcessId(hwnd, &procID);
        HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, procID);
        cout << "Proceso encontrado " << endl;
        if (procID == NULL) {
            cout << "proceso no encontrado" << endl;
            Sleep(3000);
            exit(-1);

        }
        else {
            cout << "proceso encontrado" << endl;
            for (;;) {
                ReadProcessMemory(handle, (PBYTE*)Ammo, &read_ammo, sizeof(read_ammo), 0);
                cout << read_ammo << endl;
                if (read_ammo < 10) {
                    WriteProcessMemory(handle, (PBYTE*)Ammo, &write_ammo, sizeof(write_ammo), 0);
                    cout << "municion restaurada" << endl;
                }
                Sleep(1000);
            }
        }
    
    }

    return 0;

}

