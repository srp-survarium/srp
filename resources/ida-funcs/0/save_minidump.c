void __cdecl save_minidump(const char *output_file_name, _EXCEPTION_POINTERS *const exception_information)
{
  HANDLE CurrentProcess; // eax
  DWORD CurrentProcessId; // [esp-18h] [ebp-144h]
  void *v4; // [esp-14h] [ebp-140h]
  vostok::debug::engine *v5; // [esp+0h] [ebp-12Ch]
  vostok::debug::engine *v6; // [esp+4h] [ebp-128h]
  char *_Src; // [esp+8h] [ebp-124h]
  char file_name[260]; // [esp+Ch] [ebp-120h] BYREF
  _MINIDUMP_EXCEPTION_INFORMATION info; // [esp+114h] [ebp-18h] BYREF
  void *minidump_handle; // [esp+120h] [ebp-Ch]
  int (__stdcall *MiniDumpWriteDump)(void *, unsigned int, void *, _MINIDUMP_TYPE, _MINIDUMP_EXCEPTION_INFORMATION *const, _MINIDUMP_USER_STREAM_INFORMATION *const, _MINIDUMP_CALLBACK_INFORMATION *const); // [esp+124h] [ebp-8h]
  HINSTANCE__ *library_handle; // [esp+128h] [ebp-4h]

  library_handle = 0;
  v6 = vostok::debug::debug_engine();
  _Src = (char *)v6->current_directory(v6);
  strcpy_s(file_name, 0x104u, _Src);
  strcat_s<260>((char (*)[260])file_name, library_id);
  library_handle = LoadLibraryA(file_name);
  if ( library_handle || (library_handle = LoadLibraryA(library_id)) != 0 )
  {
    MiniDumpWriteDump = (int (__stdcall *)(void *, unsigned int, void *, _MINIDUMP_TYPE, _MINIDUMP_EXCEPTION_INFORMATION *const, _MINIDUMP_USER_STREAM_INFORMATION *const, _MINIDUMP_CALLBACK_INFORMATION *const))GetProcAddress(library_handle, "MiniDumpWriteDump");
    if ( MiniDumpWriteDump )
    {
      v5 = vostok::debug::debug_engine();
      v5->create_folder_r(v5, output_file_name, 0);
      minidump_handle = CreateFileA(output_file_name, 0x40000000u, 2u, 0, 2u, 0x80u, 0);
      if ( minidump_handle != (void *)-1 )
      {
        info.ThreadId = GetCurrentThreadId();
        info.ExceptionPointers = exception_information;
        info.ClientPointers = 0;
        v4 = minidump_handle;
        CurrentProcessId = GetCurrentProcessId();
        CurrentProcess = GetCurrentProcess();
        MiniDumpWriteDump(CurrentProcess, CurrentProcessId, v4, MiniDumpNormal, &info, 0, 0);
        CloseHandle(minidump_handle);
      }
    }
  }
}
