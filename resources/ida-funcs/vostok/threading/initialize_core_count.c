void __cdecl vostok::threading::initialize_core_count()
{
  char *m_end; // eax
  unsigned int v1; // edi
  unsigned int v2; // esi
  unsigned int dwNumberOfProcessors; // esi
  unsigned int v4; // eax
  bool do_debug_break[5]; // [esp+13h] [ebp-239h] BYREF
  _SYSTEM_INFO SystemInfo; // [esp+18h] [ebp-234h] BYREF
  vostok::fixed_string<512> core_affinity; // [esp+3Ch] [ebp-210h] BYREF
  char v8; // [esp+248h] [ebp-4h] BYREF

  GetSystemInfo(&SystemInfo);
  core_affinity.m_begin = core_affinity.m_buffer;
  core_affinity.m_end = core_affinity.m_buffer;
  core_affinity.m_max_end = &v8;
  core_affinity.m_buffer[0] = 0;
  if ( vostok::threading::g_debug_single_thread.m_type == type_unset )
  {
    do_debug_break[1] = 0;
    vostok::threading::g_debug_single_thread.m_type = type_recursive;
    vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
  }
  if ( vostok::threading::g_debug_single_thread.m_type == type_recursive )
  {
    if ( vostok::command_line::key::is_set_as_string(
           &vostok::threading::g_core_affinity,
           (vostok::command_line::key *)&core_affinity) )
    {
      m_end = core_affinity.m_end;
      v1 = core_affinity.m_end - core_affinity.m_begin;
      if ( core_affinity.m_end == core_affinity.m_begin )
      {
        s_logical_core_count = SystemInfo.dwNumberOfProcessors;
      }
      else
      {
        v2 = 0;
        s_logical_core_count = 0;
        if ( v1 )
        {
          do
          {
            if ( *vostok::buffer_string::operator[](&core_affinity, v2) != 48 )
              ++s_logical_core_count;
            ++v2;
          }
          while ( v2 < v1 );
          m_end = core_affinity.m_end;
        }
        if ( !debug_macro_helper_ignore_always_13 )
        {
          dwNumberOfProcessors = SystemInfo.dwNumberOfProcessors;
          if ( m_end - core_affinity.m_begin > SystemInfo.dwNumberOfProcessors )
          {
            v4 = occurances_left_13;
            if ( occurances_left_13 == -1 )
              v4 = 10;
            occurances_left_13 = v4 - 1;
            if ( v4 )
            {
              do_debug_break[0] = 0;
              vostok::debug::on_error(
                0,
                do_debug_break,
                process_error_false,
                &debug_macro_helper_ignore_always_13,
                assert_untyped,
                "assertion_failed",
                "core_affinity.length() <= physical_count",
                ".\\threading_functions.cpp",
                "vostok::threading::initialize_core_count",
                0xB8u,
                "core_affinity mask has more cores then system has");
              if ( vostok::debug::is_debugger_present() || do_debug_break[0] )
                __debugbreak();
            }
            s_logical_core_count = dwNumberOfProcessors;
          }
        }
      }
    }
    else
    {
      s_logical_core_count = SystemInfo.dwNumberOfProcessors;
    }
  }
  else
  {
    s_logical_core_count = 1;
  }
}
