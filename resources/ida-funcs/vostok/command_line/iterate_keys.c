void __cdecl vostok::command_line::iterate_keys<vostok::command_line::checker>()
{
  unsigned int v0; // eax
  char *m_begin; // ebx
  char *v2; // esi
  bool is_delimiter; // al
  vostok::fixed_string<512> *v4; // ecx
  char *v5; // esi
  unsigned __int8 v6; // al
  bool v7; // al
  vostok::fixed_string<512> *v8; // ecx
  vostok::command_line::key *v9; // edi
  char *v10; // esi
  char v11; // al
  char v12; // bl
  bool v13; // zf
  bool v14; // al
  unsigned __int8 v15; // al
  vostok::command_line::key *v16; // edi
  vostok::buffer_string *v17; // [esp-4h] [ebp-440h]
  vostok::fixed_string<512> *v18; // [esp-4h] [ebp-440h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v19; // [esp-4h] [ebp-440h]
  vostok::fixed_string<512> *v20; // [esp-4h] [ebp-440h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v21; // [esp-4h] [ebp-440h]
  const char *v22; // [esp+0h] [ebp-43Ch]
  _BYTE v23[528]; // [esp+Ch] [ebp-430h] BYREF
  vostok::command_line::key *v24; // [esp+21Ch] [ebp-220h] BYREF
  char *v25; // [esp+42Ch] [ebp-10h]
  char *begin_src; // [esp+430h] [ebp-Ch] BYREF
  char *end_src; // [esp+434h] [ebp-8h] BYREF
  bool do_debug_break; // [esp+43Bh] [ebp-1h] BYREF

  if ( !`vostok::command_line::iterate_keys<vostok::command_line::checker>'::`5'::debug_macro_helper_ignore_always
    && !LOBYTE(s_command_line_keys_creation.m_mutex[1]) )
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
        0,
        "assertion_failed",
        "s_command_line_ready",
        ".\\command_line.cpp",
        "vostok::command_line::iterate_keys",
        (const char *)0xBC,
        "please run initialize first",
        v22);
      if ( vostok::debug::is_debugger_present() || do_debug_break )
        __debugbreak();
    }
    return;
  }
  m_begin = vostok::command_line::g_command_line.m_begin;
  v13 = *vostok::command_line::g_command_line.m_begin == 0;
  v25 = vostok::command_line::g_command_line.m_begin;
  v2 = vostok::command_line::g_command_line.m_begin;
  if ( v13 )
    return;
  do
  {
    is_delimiter = vostok::command_line::is_delimiter(*v2, " \t");
    v4 = (vostok::fixed_string<512> *)v17;
    if ( is_delimiter )
      goto LABEL_41;
    if ( *v2 != 45 )
    {
      if ( vostok::command_line::s_command_line_error.m_end == vostok::command_line::s_command_line_error.m_begin )
        vostok::fs_new::path_string_impl::assignf(
          (int)&vostok::command_line::s_command_line_error,
          (vostok::buffer_string *)(v2 - m_begin),
          (vostok::buffer_string *)&stru_8029BC,
          (const char *)*v2,
          m_begin,
          v2 - m_begin);
      goto LABEL_41;
    }
    v5 = v2 + 1;
    v6 = *v5;
    end_src = v5;
    if ( !v6 || v6 == 45 && (++v5, v6 = *v5, end_src = v5, !v6) )
    {
      if ( vostok::command_line::s_command_line_error.m_end == vostok::command_line::s_command_line_error.m_begin )
        vostok::fs_new::path_string_impl::assignf(
          (int)&vostok::command_line::s_command_line_error,
          v17,
          (vostok::buffer_string *)"last command line key is empty: %s",
          m_begin);
      return;
    }
    begin_src = v5;
    while ( v6 )
    {
      v7 = vostok::command_line::is_delimiter(v6, " \t");
      v4 = v18;
      if ( v7 || *v5 == 61 )
        break;
      v6 = *++v5;
      end_src = v5;
    }
    vostok::fixed_string<512>::fixed_string<512>(v4, (int)&v24, &begin_src, (const char **)&end_src);
    v2 = end_src;
    if ( *end_src != 61 )
    {
      v9 = v24;
      if ( !vostok::command_line::find_key((char *)v24) )
        vostok::command_line::checker::operator()(v9, v19);
      goto LABEL_41;
    }
    v10 = end_src + 1;
    v11 = *++end_src;
    if ( !v11 )
    {
      if ( vostok::command_line::s_command_line_error.m_end == vostok::command_line::s_command_line_error.m_begin )
        vostok::fs_new::path_string_impl::assignf(
          (int)&vostok::command_line::s_command_line_error,
          v8,
          (vostok::buffer_string *)&stru_802A0C,
          begin_src);
      return;
    }
    v12 = 0;
    begin_src = v10;
    if ( v11 == 34 )
    {
      v12 = 1;
      begin_src = ++v10;
      goto LABEL_34;
    }
    while ( 1 )
    {
      v15 = *v10;
      if ( !*v10 )
        break;
      if ( v12 )
      {
        if ( v15 != 34 )
          goto LABEL_33;
        v13 = *(v10 - 1) == 92;
      }
      else
      {
        v14 = vostok::command_line::is_delimiter(v15, " \t");
        v8 = v20;
        v13 = !v14;
      }
      if ( !v13 )
        break;
LABEL_33:
      ++v10;
LABEL_34:
      end_src = v10;
    }
    vostok::fixed_string<512>::fixed_string<512>(v8, (int)v23, &begin_src, (const char **)&end_src);
    v2 = end_src;
    if ( v12 )
      v2 = end_src + 1;
    v16 = v24;
    if ( !vostok::command_line::find_key((char *)v24) )
      vostok::command_line::checker::operator()(v16, v21);
    m_begin = v25;
LABEL_41:
    ++v2;
  }
  while ( *v2 );
}


void __cdecl vostok::command_line::iterate_keys<vostok::command_line::initializer>()
{
  unsigned int v0; // eax
  char *m_begin; // ebx
  char *v2; // esi
  bool is_delimiter; // al
  vostok::fixed_string<512> *v4; // ecx
  char *v5; // esi
  unsigned __int8 v6; // al
  bool v7; // al
  vostok::fixed_string<512> *v8; // ecx
  vostok::command_line::key *key; // eax
  char *v10; // esi
  char v11; // al
  char v12; // bl
  bool v13; // zf
  bool v14; // al
  unsigned __int8 v15; // al
  char *v16; // edi
  vostok::command_line::key *v17; // eax
  vostok::buffer_string *v18; // [esp-4h] [ebp-440h]
  vostok::fixed_string<512> *v19; // [esp-4h] [ebp-440h]
  vostok::fixed_string<512> *v20; // [esp-4h] [ebp-440h]
  const char *v21; // [esp+0h] [ebp-43Ch]
  char *v22; // [esp+Ch] [ebp-430h] BYREF
  char *v23; // [esp+21Ch] [ebp-220h] BYREF
  char *v24; // [esp+42Ch] [ebp-10h]
  char *begin_src; // [esp+430h] [ebp-Ch] BYREF
  char *end_src; // [esp+434h] [ebp-8h] BYREF
  bool do_debug_break; // [esp+43Bh] [ebp-1h] BYREF

  if ( !`vostok::command_line::iterate_keys<vostok::command_line::initializer>'::`5'::debug_macro_helper_ignore_always
    && !LOBYTE(s_command_line_keys_creation.m_mutex[1]) )
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
        0,
        "assertion_failed",
        "s_command_line_ready",
        ".\\command_line.cpp",
        "vostok::command_line::iterate_keys",
        (const char *)0xBC,
        "please run initialize first",
        v21);
      if ( vostok::debug::is_debugger_present() || do_debug_break )
        __debugbreak();
    }
    return;
  }
  m_begin = vostok::command_line::g_command_line.m_begin;
  v13 = *vostok::command_line::g_command_line.m_begin == 0;
  v24 = vostok::command_line::g_command_line.m_begin;
  v2 = vostok::command_line::g_command_line.m_begin;
  if ( v13 )
    return;
  do
  {
    is_delimiter = vostok::command_line::is_delimiter(*v2, " \t");
    v4 = (vostok::fixed_string<512> *)v18;
    if ( is_delimiter )
      goto LABEL_41;
    if ( *v2 != 45 )
    {
      if ( vostok::command_line::s_command_line_error.m_end == vostok::command_line::s_command_line_error.m_begin )
        vostok::fs_new::path_string_impl::assignf(
          (int)&vostok::command_line::s_command_line_error,
          (vostok::buffer_string *)(v2 - m_begin),
          (vostok::buffer_string *)&stru_8029BC,
          (const char *)*v2,
          m_begin,
          v2 - m_begin);
      goto LABEL_41;
    }
    v5 = v2 + 1;
    v6 = *v5;
    end_src = v5;
    if ( !v6 || v6 == 45 && (++v5, v6 = *v5, end_src = v5, !v6) )
    {
      if ( vostok::command_line::s_command_line_error.m_end == vostok::command_line::s_command_line_error.m_begin )
        vostok::fs_new::path_string_impl::assignf(
          (int)&vostok::command_line::s_command_line_error,
          v18,
          (vostok::buffer_string *)"last command line key is empty: %s",
          m_begin);
      return;
    }
    begin_src = v5;
    while ( v6 )
    {
      v7 = vostok::command_line::is_delimiter(v6, " \t");
      v4 = v19;
      if ( v7 || *v5 == 61 )
        break;
      v6 = *++v5;
      end_src = v5;
    }
    vostok::fixed_string<512>::fixed_string<512>(v4, (int)&v23, &begin_src, (const char **)&end_src);
    v2 = end_src;
    if ( *end_src != 61 )
    {
      key = vostok::command_line::find_key(v23);
      if ( key )
        key->m_type = type_void;
      goto LABEL_41;
    }
    v10 = end_src + 1;
    v11 = *++end_src;
    if ( !v11 )
    {
      if ( vostok::command_line::s_command_line_error.m_end == vostok::command_line::s_command_line_error.m_begin )
        vostok::fs_new::path_string_impl::assignf(
          (int)&vostok::command_line::s_command_line_error,
          v8,
          (vostok::buffer_string *)&stru_802A0C,
          begin_src);
      return;
    }
    v12 = 0;
    begin_src = v10;
    if ( v11 == 34 )
    {
      v12 = 1;
      begin_src = ++v10;
      goto LABEL_34;
    }
    while ( 1 )
    {
      v15 = *v10;
      if ( !*v10 )
        break;
      if ( v12 )
      {
        if ( v15 != 34 )
          goto LABEL_33;
        v13 = *(v10 - 1) == 92;
      }
      else
      {
        v14 = vostok::command_line::is_delimiter(v15, " \t");
        v8 = v20;
        v13 = !v14;
      }
      if ( !v13 )
        break;
LABEL_33:
      ++v10;
LABEL_34:
      end_src = v10;
    }
    vostok::fixed_string<512>::fixed_string<512>(v8, (int)&v22, &begin_src, (const char **)&end_src);
    v2 = end_src;
    if ( v12 )
      v2 = end_src + 1;
    v16 = v22;
    v17 = vostok::command_line::find_key(v23);
    if ( v17 )
      vostok::command_line::key::initialize(v16, v17);
    m_begin = v24;
LABEL_41:
    ++v2;
  }
  while ( *v2 );
}


void __cdecl vostok::command_line::iterate_keys<vostok::command_line::key_initializator>()
{
  unsigned int v0; // eax
  char *m_begin; // esi
  char *v2; // edi
  bool is_delimiter; // al
  vostok::fixed_string<512> *v4; // ecx
  char *v5; // edi
  unsigned __int8 v6; // al
  bool v7; // al
  vostok::fixed_string<512> *v8; // ecx
  char *v9; // esi
  vostok::command_line::key *key; // eax
  char *v11; // edi
  char v12; // al
  bool v13; // zf
  bool v14; // al
  unsigned __int8 v15; // al
  char *v16; // ebx
  char *v17; // esi
  vostok::command_line::key *v18; // eax
  vostok::buffer_string *v19; // [esp-4h] [ebp-444h]
  vostok::fixed_string<512> *v20; // [esp-4h] [ebp-444h]
  vostok::fixed_string<512> *v21; // [esp-4h] [ebp-444h]
  const char *v22; // [esp+0h] [ebp-440h]
  bool do_debug_break; // [esp+13h] [ebp-42Dh] BYREF
  char *end_src; // [esp+14h] [ebp-42Ch] BYREF
  char *begin_src; // [esp+18h] [ebp-428h] BYREF
  char *v26; // [esp+1Ch] [ebp-424h]
  char *v27; // [esp+20h] [ebp-420h] BYREF
  char *v28; // [esp+230h] [ebp-210h] BYREF

  if ( !`vostok::command_line::iterate_keys<vostok::command_line::key_initializator>'::`5'::debug_macro_helper_ignore_always
    && !LOBYTE(s_command_line_keys_creation.m_mutex[1]) )
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
        0,
        "assertion_failed",
        "s_command_line_ready",
        ".\\command_line.cpp",
        "vostok::command_line::iterate_keys",
        (const char *)0xBC,
        "please run initialize first",
        v22);
      if ( vostok::debug::is_debugger_present() || do_debug_break )
        __debugbreak();
    }
    return;
  }
  m_begin = vostok::command_line::g_command_line.m_begin;
  v13 = *vostok::command_line::g_command_line.m_begin == 0;
  v26 = vostok::command_line::g_command_line.m_begin;
  v2 = vostok::command_line::g_command_line.m_begin;
  if ( v13 )
    return;
  while ( 2 )
  {
    is_delimiter = vostok::command_line::is_delimiter(*v2, " \t");
    v4 = (vostok::fixed_string<512> *)v19;
    if ( is_delimiter )
      goto LABEL_42;
    if ( *v2 != 45 )
    {
      if ( vostok::command_line::s_command_line_error.m_end == vostok::command_line::s_command_line_error.m_begin )
        vostok::fs_new::path_string_impl::assignf(
          (int)&vostok::command_line::s_command_line_error,
          (vostok::buffer_string *)(v2 - m_begin),
          (vostok::buffer_string *)&stru_8029BC,
          (const char *)*v2,
          m_begin,
          v2 - m_begin);
      goto LABEL_42;
    }
    v5 = v2 + 1;
    v6 = *v5;
    end_src = v5;
    if ( !v6 || v6 == 45 && (++v5, v6 = *v5, end_src = v5, !v6) )
    {
      if ( vostok::command_line::s_command_line_error.m_end == vostok::command_line::s_command_line_error.m_begin )
        vostok::fs_new::path_string_impl::assignf(
          (int)&vostok::command_line::s_command_line_error,
          v19,
          (vostok::buffer_string *)"last command line key is empty: %s",
          m_begin);
      return;
    }
    begin_src = v5;
    while ( v6 )
    {
      v7 = vostok::command_line::is_delimiter(v6, " \t");
      v4 = v20;
      if ( v7 || *v5 == 61 )
        break;
      v6 = *++v5;
      end_src = v5;
    }
    vostok::fixed_string<512>::fixed_string<512>(v4, (int)&v27, &begin_src, (const char **)&end_src);
    v2 = end_src;
    if ( *end_src != 61 )
    {
      v9 = v27;
      key = vostok::command_line::find_key(v27);
      if ( key )
        vostok::command_line::key_initializator::operator()(key, v9, 0);
      goto LABEL_42;
    }
    v11 = end_src + 1;
    v12 = *++end_src;
    if ( !v12 )
    {
      if ( vostok::command_line::s_command_line_error.m_end == vostok::command_line::s_command_line_error.m_begin )
        vostok::fs_new::path_string_impl::assignf(
          (int)&vostok::command_line::s_command_line_error,
          v8,
          (vostok::buffer_string *)&stru_802A0C,
          begin_src);
      return;
    }
    begin_src = v11;
    do_debug_break = 0;
    if ( v12 == 34 )
    {
      ++v11;
      do_debug_break = 1;
      begin_src = v11;
      goto LABEL_36;
    }
    while ( 1 )
    {
      v15 = *v11;
      if ( !*v11 )
        break;
      if ( do_debug_break )
      {
        if ( v15 != 34 )
          goto LABEL_35;
        v13 = *(v11 - 1) == 92;
      }
      else
      {
        v14 = vostok::command_line::is_delimiter(v15, " \t");
        v8 = v21;
        v13 = !v14;
      }
      if ( !v13 )
        break;
LABEL_35:
      ++v11;
LABEL_36:
      end_src = v11;
    }
    vostok::fixed_string<512>::fixed_string<512>(v8, (int)&v28, &begin_src, (const char **)&end_src);
    v2 = end_src;
    if ( do_debug_break )
      v2 = end_src + 1;
    v16 = v27;
    v17 = v28;
    v18 = vostok::command_line::find_key(v27);
    if ( v18 )
      vostok::command_line::key_initializator::operator()(v18, v16, v17);
LABEL_42:
    if ( *++v2 )
    {
      m_begin = v26;
      continue;
    }
    break;
  }
}
