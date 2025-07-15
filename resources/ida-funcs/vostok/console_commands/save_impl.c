void __cdecl vostok::console_commands::save_impl(char *file_name)
{
  vostok::console_commands::save_storage *v1; // ecx
  vostok::console_commands::console_command *v2; // edi
  vostok::memory::writer *v3; // ecx
  vostok::console_commands::save_storage *v4; // ecx
  bool v5; // [esp+0h] [ebp-48h]
  vostok::memory::writer v6; // [esp+8h] [ebp-40h] BYREF
  survarium::anomaly_state **v7[5]; // [esp+34h] [ebp-14h] BYREF

  vostok::memory::writer::writer(&v6, &vostok::memory::g_mt_allocator);
  v7[0] = 0;
  v7[1] = 0;
  v2 = vostok::console_commands::s_console_command_root;
  v7[3] = 0;
  v7[2] = (survarium::anomaly_state **)&vostok::memory::g_mt_allocator;
  v7[4] = (survarium::anomaly_state **)&vostok::memory::g_mt_allocator;
  while ( v2 )
  {
    if ( v2->m_serializable && v2->m_command_type == command_type_user_specific )
      v2->save_to(v2, (vostok::console_commands::save_storage *)v7, &vostok::memory::g_mt_allocator);
    v2 = v2->m_prev;
  }
  vostok::console_commands::save_storage::save_to(v1, v7, &v6);
  vostok::memory::writer::save_to(v3, (int)&v6, file_name, v5);
  vostok::console_commands::save_storage::~save_storage(v4, (int)v7);
  vostok::memory::writer::~writer(&v6);
}
