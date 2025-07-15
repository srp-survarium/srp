FARPROC __usercall win32_globallookup@<eax>(int a1@<ebx>, const char *name)
{
  HMODULE LibraryA; // eax
  HMODULE v3; // esi
  HANDLE (__stdcall *CreateToolhelp32Snapshot)(DWORD, DWORD); // edi
  BOOL (__stdcall *Module32First)(HANDLE, LPMODULEENTRY32); // ebp
  HANDLE v7; // eax
  void *v8; // edi
  FARPROC ProcAddress; // ebp
  BOOL (__stdcall *Module32Next)(HANDLE, LPMODULEENTRY32); // [esp+10h] [ebp-230h]
  _DWORD v11[137]; // [esp+18h] [ebp-228h] BYREF

  LibraryA = LoadLibraryA("KERNEL32.DLL");
  v3 = LibraryA;
  if ( !LibraryA )
  {
    ERR_put_error(a1, 0x25u, 142, 108, ".\\crypto\\dso\\dso_win32.c", 792);
    return 0;
  }
  CreateToolhelp32Snapshot = (HANDLE (__stdcall *)(DWORD, DWORD))GetProcAddress(LibraryA, "CreateToolhelp32Snapshot");
  if ( !CreateToolhelp32Snapshot )
  {
    FreeLibrary(v3);
    ERR_put_error((int)GetProcAddress, 0x25u, 142, 108, ".\\crypto\\dso\\dso_win32.c", 801);
    return 0;
  }
  Module32First = (BOOL (__stdcall *)(HANDLE, LPMODULEENTRY32))GetProcAddress(v3, "Module32First");
  Module32Next = (BOOL (__stdcall *)(HANDLE, LPMODULEENTRY32))GetProcAddress(v3, "Module32Next");
  v7 = CreateToolhelp32Snapshot(8, 0);
  v8 = v7;
  if ( v7 == (HANDLE)-1 )
  {
    FreeLibrary(v3);
    ERR_put_error((int)GetProcAddress, 0x25u, 142, 108, ".\\crypto\\dso\\dso_win32.c", 818);
    return 0;
  }
  v11[0] = 548;
  if ( !Module32First(v7, (LPMODULEENTRY32)v11) )
  {
LABEL_10:
    CloseHandle(v8);
    FreeLibrary(v3);
    return 0;
  }
  while ( 1 )
  {
    ProcAddress = GetProcAddress((HMODULE)v11[7], name);
    if ( ProcAddress )
      break;
    if ( !Module32Next(v8, (LPMODULEENTRY32)v11) )
      goto LABEL_10;
  }
  CloseHandle(v8);
  FreeLibrary(v3);
  return ProcAddress;
}
