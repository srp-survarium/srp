void __thiscall vostok::animation::hand_to_weapon_ik_solver::serialize(
        vostok::animation::hand_to_weapon_ik_solver *this,
        const vostok::network_core::buffer_writer *writer,
        vostok::network_core::buffer_writer *time_offset,
        vostok::network_core::buffer_writer *a4)
{
  vostok::network_core::buffer_writer *v4; // ecx
  unsigned int m_size; // eax
  vostok::network_core::buffer_writer *v6; // ecx
  vostok::network_core::buffer_writer *v7; // ecx
  vostok::network_core::buffer_writer *v8; // ecx
  int v9; // eax
  vostok::network_core::buffer_writer *v10; // ecx
  vostok::network_core::buffer_writer *v11; // ecx
  unsigned __int8 player_id; // [esp+13h] [ebp-5h] BYREF
  char *v13; // [esp+14h] [ebp-4h] BYREF

  LOBYTE(this) = LOBYTE(writer[26].serialization_operations_descriptors.m_size) != 0;
  player_id = (unsigned __int8)this | (writer[52].serialization_operations_descriptors.gap4 == 0 ? 0 : 2);
  vostok::network_core::buffer_writer::w<unsigned char>(
    &player_id,
    (vostok::network_core::buffer_writer *)this,
    time_offset,
    ".\\hand_to_weapon_ik_solver.cpp",
    (const char *)0x146,
    "vostok::animation::hand_to_weapon_ik_solver::serialize",
    "active_hands");
  m_size = writer[25].serialization_operations_descriptors.m_size;
  if ( m_size )
  {
    v4 = a4;
    v13 = (char *)a4 + m_size;
  }
  else
  {
    v13 = 0;
  }
  vostok::network_core::buffer_writer::w<unsigned int>(
    (unsigned __int8 *)&v13,
    v4,
    time_offset,
    ".\\hand_to_weapon_ik_solver.cpp",
    (const char *)0x148,
    "vostok::animation::hand_to_weapon_ik_solver::serialize",
    "m_hands[left].start_transition_time_in_ms ? m_hands[left].start_transition_time_in_ms + time_offset : 0");
  player_id = writer[25].player_id;
  vostok::network_core::buffer_writer::w<unsigned char>(
    &player_id,
    v6,
    time_offset,
    ".\\hand_to_weapon_ik_solver.cpp",
    (const char *)0x149,
    "vostok::animation::hand_to_weapon_ik_solver::serialize",
    "(u8)m_hands[left].locator_id");
  player_id = (unsigned __int8)writer[25].m_buffer;
  vostok::network_core::buffer_writer::w<unsigned char>(
    &player_id,
    v7,
    time_offset,
    ".\\hand_to_weapon_ik_solver.cpp",
    (const char *)0x14A,
    "vostok::animation::hand_to_weapon_ik_solver::serialize",
    "(u8)m_hands[left].previous_locator_id");
  v9 = *(_DWORD *)&writer[51].serialization_operations_descriptors.gap4;
  if ( v9 )
  {
    v8 = a4;
    v13 = (char *)a4 + v9;
  }
  else
  {
    v13 = 0;
  }
  vostok::network_core::buffer_writer::w<unsigned int>(
    (unsigned __int8 *)&v13,
    v8,
    time_offset,
    ".\\hand_to_weapon_ik_solver.cpp",
    (const char *)0x14C,
    "vostok::animation::hand_to_weapon_ik_solver::serialize",
    "m_hands[right].start_transition_time_in_ms ? m_hands[right].start_transition_time_in_ms + time_offset : 0");
  player_id = (unsigned __int8)writer[51].m_buffer;
  vostok::network_core::buffer_writer::w<unsigned char>(
    &player_id,
    v10,
    time_offset,
    ".\\hand_to_weapon_ik_solver.cpp",
    (const char *)0x14D,
    "vostok::animation::hand_to_weapon_ik_solver::serialize",
    "(u8)m_hands[right].locator_id");
  player_id = writer[52].serialization_operations_descriptors.m_size;
  vostok::network_core::buffer_writer::w<unsigned char>(
    &player_id,
    v11,
    time_offset,
    ".\\hand_to_weapon_ik_solver.cpp",
    (const char *)0x14E,
    "vostok::animation::hand_to_weapon_ik_solver::serialize",
    "(u8)m_hands[right].previous_locator_id");
}
