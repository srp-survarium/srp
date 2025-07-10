bool __thiscall vostok::core::core_debug_engine::create_folder_r(
        vostok::core::core_debug_engine *this,
        char *path,
        bool create_last)
{
  vostok::fs_new::synchronous_device_interface *m_variable; // esi
  char *m_buffer; // eax
  char *v5; // ecx
  vostok::fs_new::path_string_impl v7; // [esp+8h] [ebp-114h] BYREF

  m_variable = s_core_synchronous_device.m_variable;
  m_buffer = v7.m_string.m_buffer;
  v7.m_string.m_max_end = &v7.m_separator;
  v5 = path;
  v7.m_string.m_begin = v7.m_string.m_buffer;
  v7.m_string.m_end = v7.m_string.m_buffer;
  v7.m_string.m_buffer[0] = 0;
  v7.m_separator = 92;
  if ( v7.m_string.m_buffer != path )
  {
    v7.m_string.m_end = v7.m_string.m_buffer;
    v7.m_string.m_buffer[0] = 0;
    if ( path )
    {
      if ( *path )
      {
        do
        {
          if ( m_buffer >= v7.m_string.m_max_end )
            break;
          *m_buffer = *v5;
          m_buffer = v7.m_string.m_end + 1;
          ++v5;
          ++v7.m_string.m_end;
        }
        while ( *v5 );
      }
      *m_buffer = 0;
      m_buffer = v7.m_string.m_end;
    }
  }
  vostok::fs_new::path_string_impl::convert(&v7, v7.m_string.m_begin, m_buffer);
  return vostok::fs_new::create_folder_r(m_variable, (const vostok::fs_new::native_path_string *)&v7, create_last);
}
