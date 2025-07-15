vostok::buffer_string *__userpurge vostok::buffer_string::replace@<eax>(
        vostok::buffer_string *this@<ecx>,
        vostok::buffer_string *a2@<edi>,
        char *what,
        char *with)
{
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned __int64 v6; // kr00_8
  int v7; // esi
  void *v8; // esp
  vostok::buffer_string *v9; // ecx
  char *m_begin; // eax
  char *v11; // ecx
  char *v12; // esi
  char v13; // dl
  char *m_end; // ecx
  char *i; // eax
  char v16; // dl
  char *v17; // esi
  unsigned int v18; // ebx
  char *v20; // [esp-4h] [ebp-1Ch]
  unsigned int v21[2]; // [esp+0h] [ebp-18h] BYREF
  vostok::buffer_string v22; // [esp+8h] [ebp-10h] BYREF
  unsigned int v23; // [esp+14h] [ebp-4h]

  v23 = strlen(what);
  v4 = strlen(with);
  if ( debug_macro_helper_ignore_always_15 || v23 )
  {
    v6 = (unsigned int)(a2->m_end - a2->m_begin) - (unsigned __int64)(v4 * ((a2->m_end - a2->m_begin) / v23 + 1));
    v7 = a2->m_end - a2->m_begin - (v6 & HIDWORD(v6)) + 1;
    v8 = alloca(v7);
    v9 = (vostok::buffer_string *)((char *)v21 + v7);
    v22.m_begin = (char *)v21;
    v22.m_end = (char *)v21;
    v22.m_max_end = (char *)v21 + v7;
    LOBYTE(v21[0]) = 0;
    while ( 1 )
    {
      v18 = vostok::buffer_string::find(v9, (unsigned __int8 **)a2, what, v21[0]);
      if ( v18 == -1 )
        break;
      m_begin = a2->m_begin;
      v11 = v22.m_begin;
      v12 = &a2->m_begin[v18];
      v22.m_end = v22.m_begin;
      *v22.m_begin = 0;
      if ( m_begin != v12 )
      {
        do
        {
          v13 = *m_begin++;
          *v11++ = v13;
        }
        while ( m_begin != v12 );
        v22.m_end = v11;
      }
      v20 = with;
      *v11 = 0;
      vostok::buffer_string::append((vostok::buffer_string *)v11, (int)&v22, v20);
      m_end = a2->m_end;
      for ( i = &a2->m_begin[v18 + v23]; i != m_end; ++i )
      {
        v16 = *i;
        v17 = v22.m_end++;
        *v17 = v16;
      }
      *v22.m_end = 0;
      vostok::buffer_string::operator=(&v22, a2);
    }
  }
  else
  {
    v5 = occurances_left_13;
    if ( occurances_left_13 == -1 )
      v5 = 10;
    occurances_left_13 = v5 - 1;
    if ( v5 )
    {
      HIBYTE(what) = 0;
      vostok::debug::on_error(
        (bool *)&what + 3,
        process_error_false,
        (bool *)"what_length",
        ".\\buffer_string.cpp",
        "vostok::buffer_string::replace",
        (const char *)0x6B);
      if ( vostok::debug::is_debugger_present() || HIBYTE(what) )
        __debugbreak();
    }
  }
  return a2;
}
