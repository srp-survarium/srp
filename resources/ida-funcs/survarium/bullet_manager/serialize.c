void __userpurge survarium::bullet_manager::serialize(
        survarium::bullet_manager *this@<ecx>,
        int a2@<esi>,
        vostok::network_core::buffer_writer *writer,
        int time_offset)
{
  vostok::network_core::buffer_writer *v4; // ecx
  vostok::network_core::buffer_writer *v5; // ecx
  vostok::network_core::buffer_writer *v6; // ecx
  survarium::bullet *v7; // ecx
  vostok::network_core::buffer_writer **i; // edi
  int v9; // [esp+Ch] [ebp-4h] BYREF

  v9 = time_offset + *(_DWORD *)(a2 + 172);
  vostok::network_core::buffer_writer::w<unsigned int>(
    (unsigned __int8 *)&v9,
    (vostok::network_core::buffer_writer *)this,
    writer,
    ".\\bullet_manager.cpp",
    (const char *)0x71,
    "survarium::bullet_manager::serialize",
    "m_current_time_in_ms + time_offset");
  v9 = *(_DWORD *)a2;
  vostok::network_core::buffer_writer::w<unsigned int>(
    (unsigned __int8 *)&v9,
    v4,
    writer,
    ".\\bullet_manager.cpp",
    (const char *)0x72,
    "survarium::bullet_manager::serialize",
    "m_random.seed()");
  vostok::network_core::buffer_writer::w<unsigned int>(
    (unsigned __int8 *)(a2 + 4),
    v5,
    writer,
    ".\\bullet_manager.cpp",
    (const char *)0x73,
    "survarium::bullet_manager::serialize",
    "m_current_bullet_id");
  v9 = (*(_DWORD *)(a2 + 12) - *(_DWORD *)(a2 + 8)) >> 2;
  vostok::network_core::buffer_writer::w<unsigned int>(
    (unsigned __int8 *)&v9,
    v6,
    writer,
    ".\\bullet_manager.cpp",
    (const char *)0x74,
    "survarium::bullet_manager::serialize",
    "m_bullets.size()");
  for ( i = *(vostok::network_core::buffer_writer ***)(a2 + 8);
        i != *(vostok::network_core::buffer_writer ***)(a2 + 12);
        ++i )
  {
    survarium::bullet::serialize(v7, *i, writer, time_offset);
  }
}
