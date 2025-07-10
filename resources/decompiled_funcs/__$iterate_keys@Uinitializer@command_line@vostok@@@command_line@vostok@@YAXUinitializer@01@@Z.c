void __cdecl vostok::command_line::iterate_keys<vostok::command_line::initializer>()
{
  unsigned int v0; // eax
  const char *m_begin; // ebp
  char *v2; // esi
  int v3; // eax
  unsigned __int8 v4; // al
  unsigned __int8 *v5; // ebx
  int v6; // eax
  vostok::command_line::key *key; // eax
  char v8; // al
  char v9; // bl
  unsigned __int8 *v10; // ebp
  unsigned __int8 v11; // al
  bool v12; // zf
  int v13; // eax
  char *v14; // edi
  vostok::command_line::key *v15; // eax
  bool do_debug_break; // [esp+13h] [ebp-425h] BYREF
  const char *command_line; // [esp+14h] [ebp-424h]
  vostok::fixed_string<512> key_name; // [esp+18h] [ebp-420h] BYREF
  char v19; // [esp+224h] [ebp-214h] BYREF
  vostok::fixed_string<512> key_value; // [esp+228h] [ebp-210h] BYREF
  char v21; // [esp+434h] [ebp-4h] BYREF

  if ( !`vostok::command_line::iterate_keys<vostok::command_line::initializer>'::`5'::debug_macro_helper_ignore_always
    && !s_command_line_ready )
  {
    v0 = `vostok::command_line::iterate_keys<vostok::command_line::initializer>'::`8'::occurances_left;
    if ( `vostok::command_line::iterate_keys<vostok::command_line::initializer>'::`8'::occurances_left == -1 )
      v0 = 10;
    `vostok::command_line::iterate_keys<vostok::command_line::initializer>'::`8'::occurances_left = v0 - 1;
    if ( v0 )
    {
      do_debug_break = 0;
      vostok::debug::on_error(
        &do_debug_break,
        process_error_false,
        &`vostok::command_line::iterate_keys<vostok::command_line::initializer>'::`5'::debug_macro_helper_ignore_always,
        assert_untyped,
        "assertion_failed",
        "s_command_line_ready",
        ".\\command_line.cpp",
        "vostok::command_line::iterate_keys",
        0xBBu,
        "please run initialize first");
      if ( vostok::debug::is_debugger_present() || do_debug_break )
        __debugbreak();
    }
    return;
  }
  m_begin = vostok::command_line::g_command_line.m_begin;
  v12 = *vostok::command_line::g_command_line.m_begin == 0;
  command_line = vostok::command_line::g_command_line.m_begin;
  v2 = vostok::command_line::g_command_line.m_begin;
  if ( v12 )
    return;
  while ( 1 )
  {
    strchr(" \t", *v2);
    if ( !v3 )
      break;
LABEL_39:
    if ( !*++v2 )
      return;
  }
  if ( *v2 != 45 )
  {
    if ( vostok::command_line::s_command_line_error.m_end == vostok::command_line::s_command_line_error.m_begin )
      vostok::buffer_string::assignf(
        &vostok::command_line::s_command_line_error,
        "expected '-' symbol and not %c at %s(%d)",
        *v2,
        m_begin,
        v2 - m_begin);
    goto LABEL_39;
  }
  v4 = *++v2;
  if ( !v4 )
  {
    if ( vostok::command_line::s_command_line_error.m_end != vostok::command_line::s_command_line_error.m_begin )
      return;
    goto LABEL_42;
  }
  if ( v4 == 45 )
  {
    v4 = *++v2;
    if ( !v4 )
    {
      if ( vostok::command_line::s_command_line_error.m_end != vostok::command_line::s_command_line_error.m_begin )
        return;
LABEL_42:
      vostok::buffer_string::assignf(
        &vostok::command_line::s_command_line_error,
        "last command line key is empty: %s",
        m_begin);
      return;
    }
  }
  v5 = (unsigned __int8 *)v2;
  do
  {
    strchr(" \t", v4);
    if ( v6 )
      break;
    if ( *v2 == 61 )
      break;
    v4 = *++v2;
  }
  while ( v4 );
  key_name.m_begin = key_name.m_buffer;
  key_name.m_max_end = &v19;
  memcpy((unsigned __int8 *)key_name.m_buffer, v5, v2 - (char *)v5);
  key_name.m_end = &key_name.m_buffer[v2 - (char *)v5];
  *key_name.m_end = 0;
  if ( *v2 != 61 )
  {
    key = vostok::command_line::find_key(key_name.m_begin);
    if ( key )
      key->m_type = type_non_recursive;
    goto LABEL_39;
  }
  v8 = *++v2;
  if ( v8 )
  {
    v9 = 0;
    v10 = (unsigned __int8 *)v2;
    if ( v8 == 34 )
    {
      ++v2;
      v9 = 1;
      v10 = (unsigned __int8 *)v2;
    }
    v11 = *v2;
    if ( !*v2 )
    {
LABEL_34:
      key_value.m_begin = key_value.m_buffer;
      key_value.m_end = key_value.m_buffer;
      key_value.m_max_end = &v21;
      memcpy((unsigned __int8 *)key_value.m_buffer, v10, v2 - (char *)v10);
      key_value.m_end += v2 - (char *)v10;
      *key_value.m_end = 0;
      if ( v9 )
        ++v2;
      v14 = key_value.m_begin;
      v15 = vostok::command_line::find_key(key_name.m_begin);
      if ( v15 )
        vostok::command_line::key::initialize(v15, v14);
      m_begin = command_line;
      goto LABEL_39;
    }
    while ( 2 )
    {
      if ( v9 )
      {
        if ( v11 == 34 )
        {
          v12 = *(v2 - 1) == 92;
LABEL_32:
          if ( !v12 )
            goto LABEL_34;
        }
        v11 = *++v2;
        if ( !v11 )
          goto LABEL_34;
        continue;
      }
      break;
    }
    strchr(" \t", v11);
    v12 = v13 == 0;
    goto LABEL_32;
  }
  if ( vostok::command_line::s_command_line_error.m_end == vostok::command_line::s_command_line_error.m_begin )
    vostok::buffer_string::assignf(&vostok::command_line::s_command_line_error, "key value is empty: %s", v5);
}
