vostok::buffer_string *__userpurge vostok::buffer_string::replace@<eax>(
        vostok::buffer_string *this@<ecx>,
        vostok::buffer_string *a2@<edi>,
        char *what,
        char *with)
{
  unsigned int v4; // ebx
  unsigned int v5; // esi
  unsigned int v6; // eax
  void *v8; // esp
  unsigned __int8 *v9; // esi
  int v10; // eax
  unsigned __int8 *m_begin; // ecx
  unsigned int v12; // eax
  unsigned __int8 *v13; // edx
  unsigned __int8 *v14; // eax
  const char *v15; // eax
  unsigned int v16; // ebx
  unsigned __int8 *v17; // esi
  char *m_end; // ecx
  char *i; // eax
  unsigned __int8 *v20; // eax
  unsigned int v21; // esi
  _BYTE v22[8]; // [esp+0h] [ebp-20h] BYREF
  vostok::buffer_string temp; // [esp+8h] [ebp-18h] BYREF
  unsigned int what_length; // [esp+14h] [ebp-Ch]
  unsigned int pos; // [esp+18h] [ebp-8h]
  unsigned __int8 *src; // [esp+1Ch] [ebp-4h]

  v4 = strlen(what);
  what_length = v4;
  v5 = strlen(with);
  if ( debug_macro_helper_ignore_always_12 || v4 )
  {
    v8 = alloca(vostok::math::max(a2->m_end - a2->m_begin, v5 * ((a2->m_end - a2->m_begin) / v4 + 1)) + 1);
    v9 = v22;
    src = v22;
    v22[0] = 0;
    while ( 1 )
    {
      strstr((unsigned __int8 *)a2->m_begin, (unsigned __int8 *)what);
      if ( !v10 )
        break;
      m_begin = (unsigned __int8 *)a2->m_begin;
      v12 = v10 - (unsigned int)a2->m_begin;
      pos = v12;
      if ( v12 == -1 )
        break;
      v13 = &m_begin[v12];
      *v9 = 0;
      if ( m_begin != &m_begin[v12] )
      {
        v14 = m_begin;
        do
          *v9++ = *v14++;
        while ( v14 != v13 );
      }
      v15 = with;
      *v9 = 0;
      v16 = strlen(v15);
      memcpy(v9, (unsigned __int8 *)with, v16);
      v17 = &v9[v16];
      *v17 = 0;
      m_end = a2->m_end;
      for ( i = &a2->m_begin[pos + what_length]; i != m_end; ++v17 )
        *v17 = *i++;
      *v17 = 0;
      if ( a2 != &temp )
      {
        v20 = (unsigned __int8 *)a2->m_begin;
        a2->m_end = a2->m_begin;
        *v20 = 0;
        v21 = v17 - src;
        memcpy((unsigned __int8 *)a2->m_end, src, v21);
        a2->m_end += v21;
        *a2->m_end = 0;
      }
      v9 = src;
    }
  }
  else
  {
    v6 = occurances_left_12;
    if ( occurances_left_12 == -1 )
      v6 = 10;
    occurances_left_12 = v6 - 1;
    if ( v6 )
    {
      HIBYTE(with) = 0;
      vostok::debug::on_error(
        0,
        (bool *)&with + 3,
        process_error_false,
        &debug_macro_helper_ignore_always_12,
        assert_untyped,
        "assertion_failed",
        "what_length",
        ".\\buffer_string.cpp",
        "vostok::buffer_string::replace",
        0x6Au);
      if ( vostok::debug::is_debugger_present() || HIBYTE(with) )
        __debugbreak();
    }
  }
  return a2;
}
