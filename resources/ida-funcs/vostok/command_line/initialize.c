void __cdecl vostok::command_line::initialize(int engine, char *command_line)
{
  int v2; // eax
  int v3; // eax
  unsigned int v4; // edi
  char v5; // dl
  vostok::buffer_string *v6; // ecx
  const char *v7; // [esp+0h] [ebp-2028h]
  vostok::buffer_string v8; // [esp+8h] [ebp-2020h] BYREF
  vostok::buffer_string v9[342]; // [esp+14h] [ebp-2014h] BYREF
  vostok::buffer_string out_dest; // [esp+101Ch] [ebp-100Ch] BYREF
  _BYTE v11[4096]; // [esp+1028h] [ebp-1000h] BYREF
  char vars0; // [esp+2028h] [ebp+0h] BYREF

  HIDWORD(s_command_line_keys_creation.m_mutex[1]) = engine;
  engine = 4096;
  vostok::buffer_string::buffer_string(v9, &v8, (char *)&engine, command_line, v7);
  if ( *v8.m_begin == 34 )
  {
    strchr(v8.m_begin + 1, 0x22u);
    if ( v2 )
      v3 = v2 - (unsigned int)v8.m_begin;
    else
      v3 = -1;
    out_dest.m_begin = v11;
    out_dest.m_end = v11;
    out_dest.m_max_end = &vars0;
    v4 = v3 + 1;
  }
  else
  {
    v4 = 0;
    if ( v8.m_end != v8.m_begin )
    {
      do
      {
        v5 = v8.m_begin[v4];
        if ( v5 == 32 )
          break;
        if ( v5 == 9 )
          break;
        ++v4;
      }
      while ( v4 < v8.m_end - v8.m_begin );
    }
    out_dest.m_begin = v11;
    out_dest.m_end = v11;
    out_dest.m_max_end = &vars0;
  }
  v11[0] = 0;
  vostok::buffer_string::substr(v4, (char *)0xFFFFFFFF, &out_dest, &v8);
  vostok::buffer_string::operator=(v6, &v8);
  LOBYTE(s_command_line_keys_creation.m_mutex[1]) = 1;
  vostok::buffer_string::operator=(&v8, &vostok::command_line::g_command_line);
  LOBYTE(engine) = 0;
  vostok::command_line::iterate_keys<vostok::command_line::initializer>();
  s_command_line_initialized = 1;
}
