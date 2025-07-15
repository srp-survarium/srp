void __thiscall survarium::intermediate_shared_statistics::serialize(
        survarium::intermediate_shared_statistics *this,
        const vostok::network_core::buffer_writer *writer,
        vostok::network_core::buffer_writer *time_offset,
        vostok::network_core::buffer_writer *a4)
{
  const vostok::network_core::buffer_writer *v4; // ebx
  vostok::network_core::buffer_writer *p_m_first; // esi
  vostok::network_core::buffer_writer *v6; // ecx
  vostok::network_core::buffer_writer *v7; // ecx
  float v8; // xmm0_4
  vostok::network_core::buffer_writer *v9; // ecx
  vostok::network_core::buffer_writer::serialization_operation_descriptor **v10; // eax
  vostok::network_core::buffer_writer *p_player_id; // ecx
  int v12; // ecx
  unsigned __int8 *v13; // eax
  float v14; // eax
  vostok::network_core::buffer_writer *v15; // ecx
  int v16; // eax
  vostok::network_core::buffer_writer *v17; // ecx
  float v18; // [esp+10h] [ebp-Ch] BYREF
  int v19; // [esp+14h] [ebp-8h]
  char *v20; // [esp+18h] [ebp-4h]

  v4 = writer;
  p_m_first = (vostok::network_core::buffer_writer *)&writer[3].serialization_operations_descriptors.m_first;
  HIBYTE(writer) = 0;
  v6 = (vostok::network_core::buffer_writer *)v4;
  if ( v4 != p_m_first )
  {
    do
    {
      if ( *(float *)&v6->serialization_operations_descriptors.m_size != 0.0 )
        ++HIBYTE(writer);
      v6 = (vostok::network_core::buffer_writer *)((char *)v6 + 4);
    }
    while ( v6 != p_m_first );
  }
  vostok::network_core::buffer_writer::w<unsigned char>(
    (unsigned __int8 *)&writer + 3,
    v6,
    time_offset,
    ".\\player_shared_statistics.cpp",
    (const char *)0x22,
    "survarium::intermediate_shared_statistics::serialize",
    "inflictors_count");
  v20 = (char *)v4;
  v19 = 0;
  do
  {
    v8 = *(float *)v20;
    if ( *(float *)v20 != 0.0 )
    {
      HIBYTE(writer) = v19 >> 2;
      v18 = v8;
      vostok::network_core::buffer_writer::w<unsigned char>(
        (unsigned __int8 *)&writer + 3,
        v7,
        time_offset,
        ".\\player_shared_statistics.cpp",
        (const char *)0x2B,
        "survarium::intermediate_shared_statistics::serialize",
        "inflictor");
      vostok::network_core::buffer_writer::w<float>(
        &v18,
        v9,
        time_offset,
        ".\\player_shared_statistics.cpp",
        (const char *)0x2C,
        "survarium::intermediate_shared_statistics::serialize",
        "damage");
    }
    v20 += 4;
    v19 += 4;
    v10 = &v4[3].serialization_operations_descriptors.m_first;
  }
  while ( v20 != (char *)&v4[3].serialization_operations_descriptors.m_first );
  HIBYTE(writer) = 0;
  p_player_id = (vostok::network_core::buffer_writer *)&v4[6].player_id;
  while ( v10 != (vostok::network_core::buffer_writer::serialization_operation_descriptor **)p_player_id )
  {
    if ( *v10 )
      ++HIBYTE(writer);
    ++v10;
  }
  vostok::network_core::buffer_writer::w<unsigned char>(
    (unsigned __int8 *)&writer + 3,
    p_player_id,
    time_offset,
    ".\\player_shared_statistics.cpp",
    (const char *)0x34,
    "survarium::intermediate_shared_statistics::serialize",
    "hit_receivers_count");
  v20 = (char *)&v4[3].serialization_operations_descriptors.m_first;
  v13 = &v4[6].player_id;
  if ( &v4[3].serialization_operations_descriptors.m_first != (vostok::network_core::buffer_writer::serialization_operation_descriptor **)&v4[6].player_id )
  {
    v12 = v20 - (char *)v4 - 80;
    v19 = v12;
    do
    {
      v14 = *(float *)v20;
      if ( *(_DWORD *)v20 )
      {
        HIBYTE(writer) = v12 >> 2;
        LODWORD(v18) = (char *)a4 + LODWORD(v14);
        vostok::network_core::buffer_writer::w<unsigned char>(
          (unsigned __int8 *)&writer + 3,
          a4,
          time_offset,
          ".\\player_shared_statistics.cpp",
          (const char *)0x3F,
          "survarium::intermediate_shared_statistics::serialize",
          "receiver");
        vostok::network_core::buffer_writer::w<unsigned int>(
          (unsigned __int8 *)&v18,
          v15,
          time_offset,
          ".\\player_shared_statistics.cpp",
          (const char *)0x40,
          "survarium::intermediate_shared_statistics::serialize",
          "time_in_ms");
        v12 = v19;
      }
      v20 += 4;
      v12 += 4;
      v13 = &v4[6].player_id;
      v19 = v12;
    }
    while ( v20 != (char *)&v4[6].player_id );
  }
  v16 = *(_DWORD *)v13;
  if ( v16 )
  {
    v12 = (int)a4;
    a4 = (vostok::network_core::buffer_writer *)((char *)a4 + v16);
  }
  else
  {
    a4 = 0;
  }
  vostok::network_core::buffer_writer::w<unsigned int>(
    (unsigned __int8 *)&a4,
    (vostok::network_core::buffer_writer *)v12,
    time_offset,
    ".\\player_shared_statistics.cpp",
    (const char *)0x43,
    "survarium::intermediate_shared_statistics::serialize",
    "last_killed_enemy_ms ? last_killed_enemy_ms + time_offset : 0");
  vostok::network_core::buffer_writer::w<unsigned char>(
    (unsigned __int8 *)&v4[6].m_buffer,
    v17,
    time_offset,
    ".\\player_shared_statistics.cpp",
    (const char *)0x44,
    "survarium::intermediate_shared_statistics::serialize",
    "last_hit_enemy_id");
}
