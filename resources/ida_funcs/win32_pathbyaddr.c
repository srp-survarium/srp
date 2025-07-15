unsigned int __cdecl win32_pathbyaddr(int (__cdecl *addr)(void *addr, char *path, int sz), char *path, int sz)
{
  HMODULE LibraryA; // eax
  HMODULE v4; // esi
  HANDLE (__stdcall *CreateToolhelp32Snapshot)(DWORD, DWORD); // ebx
  BOOL (__stdcall *Module32First)(HANDLE, LPMODULEENTRY32); // ebp
  HANDLE v8; // eax
  void *v9; // edi
  signed int v10; // kr00_4
  unsigned int v11; // esi
  BOOL (__stdcall *Module32Next)(HANDLE, LPMODULEENTRY32); // [esp+14h] [ebp-22Ch]
  _DWORD v13[5]; // [esp+18h] [ebp-228h] BYREF
  unsigned int v14; // [esp+2Ch] [ebp-214h]
  int v15; // [esp+30h] [ebp-210h]
  unsigned __int8 src[260]; // [esp+138h] [ebp-108h] BYREF

  if ( !addr )
    addr = win32_pathbyaddr;
  LibraryA = LoadLibraryA("KERNEL32.DLL");
  v4 = LibraryA;
  if ( !LibraryA )
  {
    ERR_put_error(0x25u, 141, 108, ".\\crypto\\dso\\dso_win32.c", 704);
    return -1;
  }
  CreateToolhelp32Snapshot = (HANDLE (__stdcall *)(DWORD, DWORD))GetProcAddress(LibraryA, "CreateToolhelp32Snapshot");
  if ( !CreateToolhelp32Snapshot )
  {
    FreeLibrary(v4);
    ERR_put_error(0x25u, 141, 108, ".\\crypto\\dso\\dso_win32.c", 713);
    return -1;
  }
  Module32First = (BOOL (__stdcall *)(HANDLE, LPMODULEENTRY32))GetProcAddress(v4, "Module32First");
  Module32Next = (BOOL (__stdcall *)(HANDLE, LPMODULEENTRY32))GetProcAddress(v4, "Module32Next");
  v8 = CreateToolhelp32Snapshot(8, 0);
  v9 = v8;
  if ( v8 == (HANDLE)-1 )
  {
    FreeLibrary(v4);
    ERR_put_error(0x25u, 141, 108, ".\\crypto\\dso\\dso_win32.c", 730);
    return -1;
  }
  v13[0] = 548;
  if ( !Module32First(v8, (LPMODULEENTRY32)v13) )
  {
    CloseHandle(v9);
    FreeLibrary(v4);
    ERR_put_error(0x25u, 141, 114, ".\\crypto\\dso\\dso_win32.c", 740);
    return -1;
  }
  while ( (unsigned int)addr < v14 || (unsigned int)addr >= v14 + v15 )
  {
    if ( !Module32Next(v9, (LPMODULEENTRY32)v13) )
    {
      CloseHandle(v9);
      FreeLibrary(v4);
      return 0;
    }
  }
  CloseHandle(v9);
  FreeLibrary(v4);
  v10 = strlen((const char *)src);
  v11 = v10;
  if ( sz > 0 )
  {
    if ( v10 >= sz )
      v11 = sz - 1;
    memcpy((unsigned __int8 *)path, src, v11);
    path[v11] = 0;
  }
  return v11 + 1;
}
