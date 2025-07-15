void __cdecl vostok::console_commands::save_impl(vostok::memory::writer *file_name)
{
  vostok::console_commands::console_command *v1; // esi
  vostok::console_commands::save_storage *v2; // ecx
  const char *v3; // [esp+0h] [ebp-4Ch]
  bool v4; // [esp+4h] [ebp-48h]
  vostok::console_commands::save_storage s; // [esp+Ch] [ebp-40h] BYREF
  vostok::memory::writer f; // [esp+20h] [ebp-2Ch] BYREF

  v1 = vostok::console_commands::s_console_command_root;
  f.m_allocator = &vostok::memory::g_mt_allocator;
  f.m_chunk_pos._M_impl._M_start = 0;
  f.m_chunk_pos._M_impl._M_finish = 0;
  f.m_chunk_pos._M_impl._M_end_of_storage.m_allocator = &vostok::memory::g_mt_allocator;
  f.m_chunk_pos._M_impl._M_end_of_storage._M_data = 0;
  f.__vftable = (vostok::memory::writer_vtbl *)&vostok::memory::writer::`vftable';
  memset(&f.m_data, 0, 16);
  f.external_data = 0;
  s.m_lines._M_impl._M_start = 0;
  s.m_lines._M_impl._M_finish = 0;
  s.m_lines._M_impl._M_end_of_storage.m_allocator = &vostok::memory::g_mt_allocator;
  s.m_lines._M_impl._M_end_of_storage._M_data = 0;
  s.m_allocator = &vostok::memory::g_mt_allocator;
  if ( vostok::console_commands::s_console_command_root )
  {
    do
    {
      if ( v1->m_serializable && v1->m_command_type == command_type_user_specific )
        v1->save_to(v1, &s, &vostok::memory::g_mt_allocator);
      v1 = v1->m_prev;
    }
    while ( v1 );
  }
  vostok::console_commands::save_storage::save_to(&f, &s);
  vostok::memory::writer::save_to(file_name, v3, v4);
  vostok::console_commands::save_storage::~save_storage(v2, (const char ***)&s);
  vostok::memory::writer::~writer(&f);
}
