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


void __cdecl vostok::command_line::iterate_keys<vostok::command_line::key_initializator>()
{
  unsigned int v0; // eax
  const char *m_begin; // ebx
  char *v2; // ebp
  int v3; // eax
  unsigned __int8 v4; // al
  unsigned __int8 *v5; // edi
  int v6; // eax
  char *v7; // esi
  vostok::command_line::key *key; // eax
  char v9; // al
  char v10; // bl
  unsigned __int8 *v11; // edi
  unsigned __int8 v12; // al
  bool v13; // zf
  int v14; // eax
  char *v15; // edi
  const char *v16; // [esp-4h] [ebp-43Ch]
  bool do_debug_break; // [esp+13h] [ebp-425h] BYREF
  const char *command_line; // [esp+14h] [ebp-424h]
  vostok::fixed_string<512> key_name; // [esp+18h] [ebp-420h] BYREF
  char v20; // [esp+224h] [ebp-214h] BYREF
  vostok::fixed_string<512> key_value; // [esp+228h] [ebp-210h] BYREF
  char v22; // [esp+434h] [ebp-4h] BYREF

  if ( !`vostok::command_line::iterate_keys<vostok::command_line::key_initializator>'::`5'::debug_macro_helper_ignore_always
    && !s_command_line_ready )
  {
    v0 = `vostok::command_line::iterate_keys<vostok::command_line::key_initializator>'::`8'::occurances_left;
    if ( `vostok::command_line::iterate_keys<vostok::command_line::key_initializator>'::`8'::occurances_left == -1 )
      v0 = 10;
    `vostok::command_line::iterate_keys<vostok::command_line::key_initializator>'::`8'::occurances_left = v0 - 1;
    if ( v0 )
    {
      do_debug_break = 0;
      vostok::debug::on_error(
        &do_debug_break,
        process_error_false,
        &`vostok::command_line::iterate_keys<vostok::command_line::key_initializator>'::`5'::debug_macro_helper_ignore_always,
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
  v13 = *vostok::command_line::g_command_line.m_begin == 0;
  command_line = vostok::command_line::g_command_line.m_begin;
  v2 = vostok::command_line::g_command_line.m_begin;
  if ( v13 )
    return;
  while ( 1 )
  {
    strchr(" \t", *v2);
    if ( v3 )
      goto LABEL_40;
    if ( *v2 != 45 )
    {
      if ( vostok::command_line::s_command_line_error.m_end == vostok::command_line::s_command_line_error.m_begin )
        vostok::buffer_string::assignf(
          &vostok::command_line::s_command_line_error,
          "expected '-' symbol and not %c at %s(%d)",
          *v2,
          m_begin,
          v2 - m_begin);
      goto LABEL_40;
    }
    v4 = *++v2;
    if ( !v4 )
    {
      if ( vostok::command_line::s_command_line_error.m_end != vostok::command_line::s_command_line_error.m_begin )
        return;
      goto LABEL_43;
    }
    if ( v4 == 45 )
    {
      v4 = *++v2;
      if ( !v4 )
      {
        if ( vostok::command_line::s_command_line_error.m_end != vostok::command_line::s_command_line_error.m_begin )
          return;
LABEL_43:
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
    key_name.m_max_end = &v20;
    memcpy((unsigned __int8 *)key_name.m_buffer, v5, v2 - (char *)v5);
    key_name.m_end = &key_name.m_buffer[v2 - (char *)v5];
    *key_name.m_end = 0;
    if ( *v2 == 61 )
      break;
    v7 = key_name.m_begin;
    key = vostok::command_line::find_key(key_name.m_begin);
    if ( key )
    {
      v16 = 0;
      goto LABEL_38;
    }
LABEL_40:
    if ( !*++v2 )
      return;
  }
  v9 = *++v2;
  if ( v9 )
  {
    v10 = 0;
    v11 = (unsigned __int8 *)v2;
    if ( v9 == 34 )
    {
      ++v2;
      v10 = 1;
      v11 = (unsigned __int8 *)v2;
    }
    v12 = *v2;
    if ( !*v2 )
    {
LABEL_34:
      key_value.m_begin = key_value.m_buffer;
      key_value.m_end = key_value.m_buffer;
      key_value.m_max_end = &v22;
      memcpy((unsigned __int8 *)key_value.m_buffer, v11, v2 - (char *)v11);
      key_value.m_end += v2 - (char *)v11;
      *key_value.m_end = 0;
      if ( v10 )
        ++v2;
      v15 = key_value.m_begin;
      v7 = key_name.m_begin;
      key = vostok::command_line::find_key(key_name.m_begin);
      if ( !key )
        goto LABEL_39;
      v16 = v15;
LABEL_38:
      vostok::command_line::key_initializator::operator()(key, v7, v16);
LABEL_39:
      m_begin = command_line;
      goto LABEL_40;
    }
    while ( 2 )
    {
      if ( v10 )
      {
        if ( v12 == 34 )
        {
          v13 = *(v2 - 1) == 92;
LABEL_32:
          if ( !v13 )
            goto LABEL_34;
        }
        v12 = *++v2;
        if ( !v12 )
          goto LABEL_34;
        continue;
      }
      break;
    }
    strchr(" \t", v12);
    v13 = v14 == 0;
    goto LABEL_32;
  }
  if ( vostok::command_line::s_command_line_error.m_end == vostok::command_line::s_command_line_error.m_begin )
    vostok::buffer_string::assignf(&vostok::command_line::s_command_line_error, "key value is empty: %s", v5);
}
