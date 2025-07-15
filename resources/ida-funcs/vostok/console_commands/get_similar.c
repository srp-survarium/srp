unsigned int __cdecl vostok::console_commands::get_similar(
        char *starts_from,
        vostok::console_commands::console_command **dst)
{
  int v2; // ecx
  vostok::console_commands::console_command *v3; // esi
  vostok::console_commands::console_command *v4; // eax
  void *v5; // esp
  vostok::console_commands::console_command **v6; // ebx
  int v7; // eax
  unsigned int *p_dst_counta; // eax
  unsigned int v9; // esi
  vostok::console_commands::console_command *v11[3]; // [esp+0h] [ebp-18h] BYREF
  unsigned int v12; // [esp+Ch] [ebp-Ch] BYREF
  unsigned int dst_counta; // [esp+10h] [ebp-8h] BYREF
  vostok::console_commands::console_command **commands_end; // [esp+14h] [ebp-4h]

  v2 = vostok::testing::suite_base<vostok::core_test_suite>::s_suite_creation_flag.m_tests.m_mutex[0];
  v3 = vostok::console_commands::s_console_command_root;
  dst_counta = 10;
  if ( !LODWORD(vostok::testing::suite_base<vostok::core_test_suite>::s_suite_creation_flag.m_tests.m_mutex[0]) )
  {
    v4 = vostok::console_commands::s_console_command_root;
    if ( vostok::console_commands::s_console_command_root )
    {
      do
      {
        v4 = v4->m_prev;
        ++v2;
      }
      while ( v4 );
      LODWORD(vostok::testing::suite_base<vostok::core_test_suite>::s_suite_creation_flag.m_tests.m_mutex[0]) = v2;
    }
  }
  v5 = alloca(4 * v2);
  v6 = v11;
  commands_end = v11;
  if ( vostok::console_commands::s_console_command_root )
  {
    do
    {
      strstr((unsigned __int8 *)v3->m_name, (unsigned __int8 *)starts_from);
      if ( v7 )
        *v6++ = v3;
      v3 = v3->m_prev;
    }
    while ( v3 );
    commands_end = v6;
  }
  v12 = v6 - v11;
  p_dst_counta = &dst_counta;
  if ( v12 <= 0xA )
    p_dst_counta = &v12;
  v9 = *p_dst_counta;
  stlp_std::priv::__partial_sort<vostok::console_commands::console_command * *,vostok::console_commands::console_command *,vostok::console_commands::starts_from_predicate>(
    v11,
    &v11[*p_dst_counta],
    commands_end,
    (vostok::console_commands::console_command **)starts_from);
  memcpy((unsigned __int8 *)dst, (unsigned __int8 *)v11, 4 * v9);
  return v9;
}
