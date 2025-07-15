unsigned int __usercall win32_pathbyaddr@<eax>(
        int a1@<ebx>,
        unsigned int (__cdecl *addr)(int (__cdecl *addr)(void *addr, char *path, int sz), char *path, int sz),
        char *path,
        int sz)
{
  HMODULE LibraryA; // eax
  HMODULE v5; // esi
  HANDLE (__stdcall *CreateToolhelp32Snapshot)(DWORD, DWORD); // ebx
  BOOL (__stdcall *Module32First)(HANDLE, LPMODULEENTRY32); // ebp
  HANDLE v9; // eax
  void *v10; // edi
  signed int v11; // kr00_4
  unsigned int v12; // esi
  BOOL (__stdcall *Module32Next)(HANDLE, LPMODULEENTRY32); // [esp+14h] [ebp-22Ch]
  _DWORD v14[5]; // [esp+18h] [ebp-228h] BYREF
  unsigned int v15; // [esp+2Ch] [ebp-214h]
  int v16; // [esp+30h] [ebp-210h]
  __m128i src[16]; // [esp+138h] [ebp-108h] BYREF

  if ( !addr )
    addr = win32_pathbyaddr;
  LibraryA = LoadLibraryA("KERNEL32.DLL");
  v5 = LibraryA;
  if ( !LibraryA )
  {
    ERR_put_error(a1, 0x25u, 141, 108, ".\\crypto\\dso\\dso_win32.c", 704);
    return -1;
  }
  CreateToolhelp32Snapshot = (HANDLE (__stdcall *)(DWORD, DWORD))GetProcAddress(LibraryA, "CreateToolhelp32Snapshot");
  if ( !CreateToolhelp32Snapshot )
  {
    FreeLibrary(v5);
    ERR_put_error(0, 0x25u, 141, 108, ".\\crypto\\dso\\dso_win32.c", 713);
    return -1;
  }
  Module32First = (BOOL (__stdcall *)(HANDLE, LPMODULEENTRY32))GetProcAddress(v5, "Module32First");
  Module32Next = (BOOL (__stdcall *)(HANDLE, LPMODULEENTRY32))GetProcAddress(v5, "Module32Next");
  v9 = CreateToolhelp32Snapshot(8, 0);
  v10 = v9;
  if ( v9 == (HANDLE)-1 )
  {
    FreeLibrary(v5);
    ERR_put_error((int)CreateToolhelp32Snapshot, 0x25u, 141, 108, ".\\crypto\\dso\\dso_win32.c", 730);
    return -1;
  }
  v14[0] = 548;
  if ( !Module32First(v9, (LPMODULEENTRY32)v14) )
  {
    CloseHandle(v10);
    FreeLibrary(v5);
    ERR_put_error((int)CreateToolhelp32Snapshot, 0x25u, 141, 114, ".\\crypto\\dso\\dso_win32.c", 740);
    return -1;
  }
  while ( (unsigned int)addr < v15 || (unsigned int)addr >= v15 + v16 )
  {
    if ( !Module32Next(v10, (LPMODULEENTRY32)v14) )
    {
      CloseHandle(v10);
      FreeLibrary(v5);
      return 0;
    }
  }
  CloseHandle(v10);
  FreeLibrary(v5);
  v11 = strlen(src[0].m128i_i8);
  v12 = v11;
  if ( sz > 0 )
  {
    if ( v11 >= sz )
      v12 = sz - 1;
    memcpy((int)path, src, v12);
    path[v12] = 0;
  }
  return v12 + 1;
}
