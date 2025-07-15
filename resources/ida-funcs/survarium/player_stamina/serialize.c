void __thiscall survarium::player_stamina::serialize(
        survarium::player_stamina *this,
        const vostok::network_core::buffer_writer *writer,
        vostok::network_core::buffer_writer *time_offset,
        int a4)
{
  const vostok::network_core::buffer_writer *v4; // ebx
  vostok::network_core::buffer_writer *v5; // ecx
  vostok::network_core::buffer_writer *v6; // ecx
  int v7; // eax
  vostok::network_core::buffer_writer *v8; // ecx
  vostok::network_core::buffer_writer *v9; // ecx
  vostok::network_core::buffer_writer *v10; // ecx

  v4 = writer;
  vostok::network_core::buffer_writer::w<float>(
    (float *)&writer[5].m_buffer,
    (vostok::network_core::buffer_writer *)this,
    time_offset,
    ".\\player_stamina.cpp",
    (const char *)0x37,
    "survarium::player_stamina::serialize",
    "m_value");
  writer = (const vostok::network_core::buffer_writer *)(a4 + v4[6].serialization_operations_descriptors.m_size);
  vostok::network_core::buffer_writer::w<unsigned int>(
    (unsigned __int8 *)&writer,
    v5,
    time_offset,
    ".\\player_stamina.cpp",
    (const char *)0x39,
    "survarium::player_stamina::serialize",
    "m_current_time_in_ms + time_offset");
  v7 = *(_DWORD *)&v4[6].serialization_operations_descriptors.gap4;
  if ( v7 == -1 )
  {
    a4 = -1;
  }
  else
  {
    v6 = (vostok::network_core::buffer_writer *)a4;
    a4 += v7;
  }
  vostok::network_core::buffer_writer::w<unsigned int>(
    (unsigned __int8 *)&a4,
    v6,
    time_offset,
    ".\\player_stamina.cpp",
    (const char *)0x3A,
    "survarium::player_stamina::serialize",
    "m_last_spending_time_in_ms != u32( -1 ) ? m_last_spending_time_in_ms + time_offset : u32( -1 )");
  vostok::network_core::buffer_writer::w<bool>(
    (const bool *)&v4[6].serialization_operations_descriptors.m_first,
    v8,
    time_offset,
    ".\\player_stamina.cpp",
    (const char *)0x3B,
    "survarium::player_stamina::serialize",
    "m_is_low_stamina");
  vostok::network_core::buffer_writer::w<float>(
    (float *)&v4[5].serialization_operations_descriptors.gap4,
    v9,
    time_offset,
    ".\\player_stamina.cpp",
    (const char *)0x3C,
    "survarium::player_stamina::serialize",
    "m_spending_speed_modifier.value");
  vostok::network_core::buffer_writer::w<float>(
    (float *)&v4[5].serialization_operations_descriptors.m_last,
    v10,
    time_offset,
    ".\\player_stamina.cpp",
    (const char *)0x3D,
    "survarium::player_stamina::serialize",
    "m_movement_speed_modifier.value");
}
