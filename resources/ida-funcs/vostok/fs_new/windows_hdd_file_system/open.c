bool __thiscall vostok::fs_new::windows_hdd_file_system::open(
        vostok::fs_new::windows_hdd_file_system *this,
        void **const out_handle,
        const vostok::fs_new::native_path_string *absolute_path,
        DWORD params)
{
  DWORD v4; // esi
  int v5; // eax
  int v6; // eax
  void *m_archive_handle; // ebx
  char *FileA; // eax
  vostok::buffer_string *v10; // ecx
  char *v11; // ebx
  vostok::fixed_string<128> *v12; // eax
  vostok::fixed_string<128> *v13; // [esp-8h] [ebp-ACh]
  vostok::fs_new::file_mode::mode_enum v14; // [esp-4h] [ebp-A8h]
  vostok::fixed_string<128> v15; // [esp+Ch] [ebp-98h] BYREF
  vostok::fs_new::windows_hdd_file_system *v16; // [esp+98h] [ebp-Ch]
  DWORD dwFlagsAndAttributes; // [esp+9Ch] [ebp-8h]
  DWORD dwDesiredAccess; // [esp+A0h] [ebp-4h]

  v4 = params;
  v16 = this;
  dwFlagsAndAttributes = 128;
  if ( !*(_DWORD *)(params + 16) )
    dwFlagsAndAttributes = 536871040;
  v5 = *(_DWORD *)(params + 4);
  dwDesiredAccess = 0;
  if ( v5 == 1 )
  {
    dwDesiredAccess = 0x80000000;
  }
  else if ( v5 )
  {
    if ( v5 == 2 )
      dwDesiredAccess = -1073741824;
  }
  else
  {
    dwDesiredAccess = 0x40000000;
  }
  v6 = *(_DWORD *)params;
  params = 0;
  if ( v6 )
  {
    if ( v6 == 1 )
    {
      params = 3;
    }
    else if ( v6 == 2 )
    {
      params = 4;
    }
  }
  else
  {
    params = 2;
  }
  m_archive_handle = this->m_archive_handle;
  if ( m_archive_handle == (void *)-1
    || !vostok::buffer_string::ends_with((vostok::buffer_string *)this, (int)absolute_path, ".db") )
  {
    FileA = (char *)CreateFileA(
                      absolute_path->m_string.m_begin,
                      dwDesiredAccess,
                      3u,
                      0,
                      params,
                      dwFlagsAndAttributes,
                      0);
    v11 = FileA;
    if ( FileA == (char *)-1 )
    {
      if ( *(_DWORD *)(v4 + 8) )
      {
        if ( !debug_macro_helper_ignore_always_2 )
        {
          v14 = *(_DWORD *)(v4 + 4);
          v13 = *(vostok::fixed_string<128> **)v4;
          HIBYTE(params) = 0;
          v12 = vostok::fs_new::file_open_flags_to_string(&v15, v13, v14);
          vostok::debug::on_error(
            (bool *)&params + 3,
            process_error_true,
            0,
            "assertion_failed",
            "fatal error",
            ".\\windows_hdd_file_system.cpp",
            "vostok::fs_new::windows_hdd_file_system::open",
            (const char *)0x61,
            (char *)&stru_7FC1E4.filter_stack.m_last,
            absolute_path->m_string.m_begin,
            v12->m_begin);
          if ( vostok::debug::is_debugger_present() || HIBYTE(params) )
            __debugbreak();
        }
      }
    }
    else if ( *(_DWORD *)v4 == 2 )
    {
      SetFilePointer(FileA, 0, 0, 2u);
    }
    *out_handle = v11;
    if ( vostok::buffer_string::ends_with(v10, (int)absolute_path, ".db") )
      v16->m_archive_handle = v11;
    return v11 + 1 != 0;
  }
  else
  {
    *out_handle = m_archive_handle;
    return 1;
  }
}
