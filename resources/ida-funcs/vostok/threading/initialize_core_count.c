unsigned int vostok::threading::initialize_core_count()
{
  vostok::command_line::key *v0; // ecx
  unsigned int result; // eax
  vostok::command_line::key *v2; // ecx
  unsigned int v3; // ecx
  unsigned int dwNumberOfProcessors; // esi
  unsigned int v5; // eax
  unsigned int v6; // ecx
  const char *v7; // [esp+0h] [ebp-248h]
  vostok::buffer_string v8; // [esp+10h] [ebp-238h] BYREF
  _BYTE v9[512]; // [esp+1Ch] [ebp-22Ch] BYREF
  char v10; // [esp+21Ch] [ebp-2Ch] BYREF
  _SYSTEM_INFO SystemInfo; // [esp+220h] [ebp-28h] BYREF
  bool do_debug_break; // [esp+247h] [ebp-1h] BYREF

  GetSystemInfo(&SystemInfo);
  v8.m_begin = v9;
  v8.m_end = v9;
  v8.m_max_end = &v10;
  v9[0] = 0;
  result = vostok::command_line::key::is_set(v0, (int)&vostok::threading::g_debug_single_thread);
  if ( (_BYTE)result )
  {
    s_logical_core_count = 1;
    return result;
  }
  if ( !vostok::command_line::key::is_set_as_string(v2, &vostok::threading::g_core_affinity.m_string_value, &v8) )
    goto LABEL_9;
  v3 = v8.m_end - v8.m_begin;
  if ( v8.m_end == v8.m_begin )
  {
    if ( !debug_macro_helper_ignore_always_13 )
    {
      do_debug_break = 0;
      vostok::debug::on_error(
        &do_debug_break,
        process_error_true,
        0,
        "assertion_failed",
        "fatal error",
        ".\\threading_functions.cpp",
        "vostok::threading::initialize_core_count",
        (const char *)0xB8,
        "command line key: %s requires a non-null value",
        vostok::threading::g_core_affinity.m_full_name);
      if ( vostok::debug::is_debugger_present() || do_debug_break )
        __debugbreak();
    }
LABEL_9:
    result = SystemInfo.dwNumberOfProcessors;
    s_logical_core_count = SystemInfo.dwNumberOfProcessors;
    return result;
  }
  result = 0;
  for ( s_logical_core_count = 0; result < v3; ++result )
  {
    if ( v8.m_begin[result] != 48 )
      ++s_logical_core_count;
  }
  if ( !debug_macro_helper_ignore_always_14 )
  {
    dwNumberOfProcessors = SystemInfo.dwNumberOfProcessors;
    if ( v3 > SystemInfo.dwNumberOfProcessors )
    {
      v5 = occurances_left_12;
      if ( occurances_left_12 == -1 )
        v5 = 10;
      v6 = v5;
      result = v5 - 1;
      occurances_left_12 = result;
      if ( v6 )
      {
        do_debug_break = 0;
        vostok::debug::on_error(
          &do_debug_break,
          process_error_false,
          0,
          "assertion_failed",
          "core_affinity.length() <= physical_count",
          ".\\threading_functions.cpp",
          "vostok::threading::initialize_core_count",
          (const char *)0xC4,
          "core_affinity mask has more cores then system has",
          v7);
        result = vostok::debug::is_debugger_present();
        if ( (_BYTE)result || do_debug_break )
          __debugbreak();
      }
      s_logical_core_count = dwNumberOfProcessors;
    }
  }
  return result;
}
