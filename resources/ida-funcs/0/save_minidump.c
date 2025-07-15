void __cdecl save_minidump(const char *output_file_name, _EXCEPTION_POINTERS *const exception_information)
{
  const char *v2; // eax
  HMODULE LibraryA; // eax
  BOOL (__stdcall *MiniDumpWriteDump)(HANDLE, DWORD, HANDLE, MINIDUMP_TYPE, PMINIDUMP_EXCEPTION_INFORMATION, PMINIDUMP_USER_STREAM_INFORMATION, PMINIDUMP_CALLBACK_INFORMATION); // edi
  HANDLE FileA; // esi
  HANDLE CurrentProcess; // eax
  DWORD CurrentProcessId; // [esp-18h] [ebp-134h]
  char _Dst[260]; // [esp+Ch] [ebp-110h] BYREF
  _DWORD v9[3]; // [esp+110h] [ebp-Ch] BYREF

  v2 = s_debug_engine->current_directory(s_debug_engine);
  strcpy_s(_Dst, 0x104u, v2);
  strcat_s(_Dst, 0x104u, "dbghelp.dll");
  LibraryA = LoadLibraryA(_Dst);
  if ( LibraryA || (LibraryA = LoadLibraryA("dbghelp.dll")) != 0 )
  {
    MiniDumpWriteDump = (BOOL (__stdcall *)(HANDLE, DWORD, HANDLE, MINIDUMP_TYPE, PMINIDUMP_EXCEPTION_INFORMATION, PMINIDUMP_USER_STREAM_INFORMATION, PMINIDUMP_CALLBACK_INFORMATION))GetProcAddress(LibraryA, "MiniDumpWriteDump");
    if ( MiniDumpWriteDump )
    {
      s_debug_engine->create_folder_r(s_debug_engine, output_file_name, 0);
      FileA = CreateFileA(output_file_name, 0x40000000u, 2u, 0, 2u, 0x80u, 0);
      if ( FileA != (HANDLE)-1 )
      {
        v9[0] = GetCurrentThreadId();
        v9[1] = exception_information;
        v9[2] = 0;
        CurrentProcessId = GetCurrentProcessId();
        CurrentProcess = GetCurrentProcess();
        MiniDumpWriteDump(
          CurrentProcess,
          CurrentProcessId,
          FileA,
          MiniDumpNormal,
          (PMINIDUMP_EXCEPTION_INFORMATION)v9,
          0,
          0);
        CloseHandle(FileA);
      }
    }
  }
}
