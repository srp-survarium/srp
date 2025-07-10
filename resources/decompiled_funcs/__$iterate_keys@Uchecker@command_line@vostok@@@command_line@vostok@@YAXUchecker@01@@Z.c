void __cdecl vostok::command_line::iterate_keys<vostok::command_line::checker>()
{
  unsigned int v0; // eax
  const char *m_begin; // ebp
  char *v2; // esi
  int v3; // eax
  unsigned __int8 v4; // al
  unsigned __int8 *v5; // ebx
  int v6; // eax
  char v7; // al
  char v8; // bl
  unsigned __int8 *v9; // ebp
  unsigned __int8 v10; // al
  bool v11; // zf
  int v12; // eax
  const char *v13; // [esp+0h] [ebp-438h]
  bool do_debug_break; // [esp+13h] [ebp-425h] BYREF
  const char *command_line; // [esp+14h] [ebp-424h]
  vostok::fixed_string<512> key_name; // [esp+18h] [ebp-420h] BYREF
  char v17; // [esp+224h] [ebp-214h] BYREF
  vostok::fixed_string<512> key_value; // [esp+228h] [ebp-210h] BYREF
  char v19; // [esp+434h] [ebp-4h] BYREF

  if ( !`vostok::command_line::iterate_keys<vostok::command_line::checker>'::`5'::debug_macro_helper_ignore_always
    && !s_command_line_ready )
  {
    v0 = `vostok::command_line::iterate_keys<vostok::command_line::checker>'::`8'::occurances_left;
    if ( `vostok::command_line::iterate_keys<vostok::command_line::checker>'::`8'::occurances_left == -1 )
      v0 = 10;
    `vostok::command_line::iterate_keys<vostok::command_line::checker>'::`8'::occurances_left = v0 - 1;
    if ( v0 )
    {
      do_debug_break = 0;
      vostok::debug::on_error(
        &do_debug_break,
        process_error_false,
        &`vostok::command_line::iterate_keys<vostok::command_line::checker>'::`5'::debug_macro_helper_ignore_always,
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
  v11 = *vostok::command_line::g_command_line.m_begin == 0;
  command_line = vostok::command_line::g_command_line.m_begin;
  v2 = vostok::command_line::g_command_line.m_begin;
  if ( v11 )
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
  key_name.m_max_end = &v17;
  memcpy((unsigned __int8 *)key_name.m_buffer, v5, v2 - (char *)v5);
  key_name.m_end = &key_name.m_buffer[v2 - (char *)v5];
  *key_name.m_end = 0;
  if ( *v2 != 61 )
  {
    if ( !vostok::command_line::find_key(key_name.m_begin) )
      vostok::command_line::checker::operator()(key_name.m_begin, v13);
    goto LABEL_39;
  }
  v7 = *++v2;
  if ( v7 )
  {
    v8 = 0;
    v9 = (unsigned __int8 *)v2;
    if ( v7 == 34 )
    {
      ++v2;
      v8 = 1;
      v9 = (unsigned __int8 *)v2;
    }
    v10 = *v2;
    if ( !*v2 )
    {
LABEL_34:
      key_value.m_begin = key_value.m_buffer;
      key_value.m_end = key_value.m_buffer;
      key_value.m_max_end = &v19;
      memcpy((unsigned __int8 *)key_value.m_buffer, v9, v2 - (char *)v9);
      key_value.m_end += v2 - (char *)v9;
      *key_value.m_end = 0;
      if ( v8 )
        ++v2;
      if ( !vostok::command_line::find_key(key_name.m_begin) )
        vostok::command_line::checker::operator()(key_name.m_begin, v13);
      m_begin = command_line;
      goto LABEL_39;
    }
    while ( 2 )
    {
      if ( v8 )
      {
        if ( v10 == 34 )
        {
          v11 = *(v2 - 1) == 92;
LABEL_32:
          if ( !v11 )
            goto LABEL_34;
        }
        v10 = *++v2;
        if ( !v10 )
          goto LABEL_34;
        continue;
      }
      break;
    }
    strchr(" \t", v10);
    v11 = v12 == 0;
    goto LABEL_32;
  }
  if ( vostok::command_line::s_command_line_error.m_end == vostok::command_line::s_command_line_error.m_begin )
    vostok::buffer_string::assignf(&vostok::command_line::s_command_line_error, "key value is empty: %s", v5);
}
