void __cdecl vostok::command_line::initialize(vostok::core::engine *engine)
{
  char *command_line; // ecx
  char *v2; // eax
  int v3; // eax
  int v4; // eax
  _BYTE *v5; // esi
  char *m_end; // ecx
  char *v7; // eax
  char *v8; // eax
  char *m_begin; // edx
  unsigned int v10; // esi
  unsigned int v11; // edi
  char *v12; // ecx
  char *v13; // eax
  _BYTE *v14; // edi
  int v15; // esi
  int v16; // esi
  vostok::buffer_string v17; // [esp+10h] [ebp-2020h] BYREF
  _BYTE v18[4096]; // [esp+1Ch] [ebp-2014h] BYREF
  char v19; // [esp+101Ch] [ebp-1014h] BYREF
  unsigned __int8 *src; // [esp+1024h] [ebp-100Ch]
  _BYTE *v21; // [esp+1028h] [ebp-1008h]
  _UNKNOWN **v22; // [esp+102Ch] [ebp-1004h]
  _BYTE v23[4096]; // [esp+1030h] [ebp-1000h] BYREF
  _UNKNOWN *retaddr; // [esp+2030h] [ebp+0h] BYREF

  s_engine = engine;
  v2 = v18;
  v17.m_begin = v18;
  v17.m_end = v18;
  v17.m_max_end = &v19;
  v18[0] = 0;
  if ( command_line )
  {
    for ( ; *command_line; ++v17.m_end )
    {
      if ( v2 >= v17.m_max_end )
        break;
      *v2 = *command_line;
      v2 = v17.m_end + 1;
      ++command_line;
    }
    *v2 = 0;
  }
  if ( *vostok::buffer_string::operator[](&v17, 0) == 34 )
  {
    strchr(v17.m_begin + 1, 0x22u);
    if ( v3 )
      v4 = v3 - (unsigned int)v17.m_begin;
    else
      v4 = -1;
    v5 = v23;
    src = v23;
    v22 = &retaddr;
    m_end = v17.m_end;
    v7 = &v17.m_begin[v4 + 1];
    v21 = v23;
    v23[0] = 0;
    if ( v7 != v17.m_end )
    {
      do
      {
        *v5 = *v7++;
        v5 = ++v21;
      }
      while ( v7 != m_end );
    }
    *v5 = 0;
  }
  else
  {
    v8 = v17.m_end;
    m_begin = v17.m_begin;
    v10 = 0;
    v11 = v17.m_end - v17.m_begin;
    if ( v17.m_end != v17.m_begin )
    {
      do
      {
        if ( *vostok::buffer_string::operator[](&v17, v10) == 32 )
          break;
        if ( *vostok::buffer_string::operator[](&v17, v10) == 9 )
          break;
        ++v10;
      }
      while ( v10 < v11 );
      v8 = v17.m_end;
      m_begin = v17.m_begin;
    }
    src = v23;
    v22 = &retaddr;
    v12 = v8;
    v13 = &m_begin[v10];
    v14 = v23;
    v21 = v23;
    for ( v23[0] = 0; v13 != v12; ++v21 )
    {
      *v14 = *v13++;
      v14 = v21 + 1;
    }
    *v14 = 0;
  }
  v17.m_end = v17.m_begin;
  *v17.m_begin = 0;
  v15 = v21 - src;
  memcpy((unsigned __int8 *)v17.m_end, src, v21 - src);
  v17.m_end += v15;
  *v17.m_end = 0;
  vostok::command_line::g_command_line.m_end = vostok::command_line::g_command_line.m_begin;
  s_command_line_ready = 1;
  *vostok::command_line::g_command_line.m_begin = 0;
  v16 = v17.m_end - v17.m_begin;
  memcpy(
    (unsigned __int8 *)vostok::command_line::g_command_line.m_end,
    (unsigned __int8 *)v17.m_begin,
    v17.m_end - v17.m_begin);
  vostok::command_line::g_command_line.m_end += v16;
  *vostok::command_line::g_command_line.m_end = 0;
  vostok::command_line::iterate_keys<vostok::command_line::initializer>();
  s_command_line_initialized = 1;
}
