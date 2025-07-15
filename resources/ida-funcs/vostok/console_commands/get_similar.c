int __usercall vostok::console_commands::get_similar@<eax>(
        char *starts_from@<eax>,
        vostok::console_commands::console_command **dst)
{
  vostok::console_commands::console_command *v2; // esi
  unsigned int v4; // eax
  vostok::console_commands::console_command *v5; // ecx
  void *v6; // esp
  int v7; // eax
  vostok::console_commands::console_command **v8; // eax
  int *v9; // eax
  int v10; // esi
  vostok::console_commands::console_command *v12[3]; // [esp+0h] [ebp-18h] BYREF
  unsigned int v13; // [esp+Ch] [ebp-Ch] BYREF
  int v14; // [esp+10h] [ebp-8h] BYREF
  vostok::console_commands::console_command **__last; // [esp+14h] [ebp-4h]

  v2 = vostok::console_commands::s_console_command_root;
  v4 = s_console_commands_count;
  v14 = 10;
  if ( !s_console_commands_count )
  {
    v5 = vostok::console_commands::s_console_command_root;
    if ( vostok::console_commands::s_console_command_root )
    {
      do
      {
        v5 = v5->m_prev;
        ++v4;
      }
      while ( v5 );
      s_console_commands_count = v4;
    }
  }
  v6 = alloca(4 * v4);
  __last = v12;
  while ( v2 )
  {
    strstr((unsigned __int8 *)v2->m_name, (unsigned __int8 *)starts_from);
    if ( v7 )
    {
      v8 = __last++;
      *v8 = v2;
    }
    v2 = v2->m_prev;
  }
  v13 = __last - v12;
  v9 = &v14;
  if ( v13 <= 0xA )
    v9 = (int *)&v13;
  v10 = *v9;
  stlp_std::priv::__partial_sort<vostok::console_commands::console_command * *,vostok::console_commands::console_command *,vostok::console_commands::starts_from_predicate>(
    v12,
    &v12[*v9],
    __last,
    (vostok::console_commands::console_command **)starts_from);
  memcpy((unsigned __int8 *)dst, (unsigned __int8 *)v12, 4 * v10);
  return v10;
}
