FARPROC __cdecl win32_globallookup(const char *name)
{
  HMODULE LibraryA; // eax
  HMODULE v2; // esi
  HANDLE (__stdcall *CreateToolhelp32Snapshot)(DWORD, DWORD); // edi
  BOOL (__stdcall *Module32First)(HANDLE, LPMODULEENTRY32); // ebp
  HANDLE v6; // eax
  void *v7; // edi
  FARPROC ProcAddress; // ebp
  BOOL (__stdcall *Module32Next)(HANDLE, LPMODULEENTRY32); // [esp+10h] [ebp-230h]
  _DWORD v10[137]; // [esp+18h] [ebp-228h] BYREF

  LibraryA = LoadLibraryA("KERNEL32.DLL");
  v2 = LibraryA;
  if ( !LibraryA )
  {
    ERR_put_error(0x25u, 142, 108, ".\\crypto\\dso\\dso_win32.c", 792);
    return 0;
  }
  CreateToolhelp32Snapshot = (HANDLE (__stdcall *)(DWORD, DWORD))GetProcAddress(LibraryA, "CreateToolhelp32Snapshot");
  if ( !CreateToolhelp32Snapshot )
  {
    FreeLibrary(v2);
    ERR_put_error(0x25u, 142, 108, ".\\crypto\\dso\\dso_win32.c", 801);
    return 0;
  }
  Module32First = (BOOL (__stdcall *)(HANDLE, LPMODULEENTRY32))GetProcAddress(v2, "Module32First");
  Module32Next = (BOOL (__stdcall *)(HANDLE, LPMODULEENTRY32))GetProcAddress(v2, "Module32Next");
  v6 = CreateToolhelp32Snapshot(8, 0);
  v7 = v6;
  if ( v6 == (HANDLE)-1 )
  {
    FreeLibrary(v2);
    ERR_put_error(0x25u, 142, 108, ".\\crypto\\dso\\dso_win32.c", 818);
    return 0;
  }
  v10[0] = 548;
  if ( !Module32First(v6, (LPMODULEENTRY32)v10) )
  {
LABEL_10:
    CloseHandle(v7);
    FreeLibrary(v2);
    return 0;
  }
  while ( 1 )
  {
    ProcAddress = GetProcAddress((HMODULE)v10[7], name);
    if ( ProcAddress )
      break;
    if ( !Module32Next(v7, (LPMODULEENTRY32)v10) )
      goto LABEL_10;
  }
  CloseHandle(v7);
  FreeLibrary(v2);
  return ProcAddress;
}
