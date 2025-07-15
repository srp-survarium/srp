void __thiscall vostok::logging::log_file::flush(vostok::logging::log_file *in_file_name)
{
  vostok::logging::log_file *v1; // esi
  vostok::logging::log_file *v3; // ecx
  int v4; // eax
  int v5; // edi
  int v6; // eax
  vostok::logging::log_file *v7; // [esp+20h] [ebp-1014h]
  int v8; // [esp+30h] [ebp-1004h]
  _BYTE v9[4096]; // [esp+34h] [ebp-1000h] BYREF

  v1 = vostok::core::g_log_file;
  if ( vostok::core::g_log_file->m_file )
  {
    vostok::logging::log_file::start_transaction(in_file_name, (int)vostok::core::g_log_file);
    v1->m_file->flush(v1->m_file);
    if ( in_file_name )
    {
      v4 = _stricmp(v1->m_file_name, in_file_name->m_cache);
      v3 = v7;
      if ( v4 )
      {
        ((void (__thiscall *)(vostok::logging::base_fs_file *volatile, _DWORD, _DWORD, _DWORD))v1->m_file->seek)(
          v1->m_file,
          0,
          0,
          0);
        v1->m_device->create_folder_r(v1->m_device, in_file_name->m_cache, dont_create_last);
        v5 = (int)v1->m_device->open_file(v1->m_device, in_file_name->m_cache, create_always_mode, write_access);
        if ( v5 )
        {
          do
          {
            v6 = v1->m_file->read(v1->m_file, v9, 4096u);
            v8 = v6;
            if ( v6 )
              (*(void (__thiscall **)(int, _BYTE *, int))(*(_DWORD *)v5 + 12))(v5, v9, v6);
          }
          while ( v8 == 4096 );
          (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 16))(v5);
          v1->m_device->close_file(v1->m_device, (vostok::logging::base_fs_file *)v5);
        }
      }
    }
    vostok::logging::log_file::end_transaction(v3, (int)v1);
  }
}
