void __thiscall vostok::animation::fingers_to_weapon_corrector::serialize(
        vostok::animation::fingers_to_weapon_corrector *this,
        const vostok::network_core::buffer_writer *writer,
        vostok::network_core::buffer_writer *time_offset,
        vostok::network_core::buffer_writer *a4)
{
  vostok::network_core::buffer_writer *v4; // ecx
  vostok::network_core::buffer_writer::serialization_operation_descriptor *m_last; // eax
  vostok::network_core::buffer_writer *v6; // ecx
  vostok::network_core::buffer_writer *v7; // ecx
  vostok::network_core::buffer_writer *v8; // ecx
  int v9; // eax
  vostok::network_core::buffer_writer *v10; // ecx
  vostok::network_core::buffer_writer *v11; // ecx
  unsigned __int8 player_id; // [esp+13h] [ebp-5h] BYREF
  char *v13; // [esp+14h] [ebp-4h] BYREF

  LOBYTE(this) = LOBYTE(writer[123].serialization_operations_descriptors.m_size) != 0;
  player_id = (unsigned __int8)this | (writer[246].serialization_operations_descriptors.gap4 == 0 ? 0 : 2);
  vostok::network_core::buffer_writer::w<unsigned char>(
    &player_id,
    (vostok::network_core::buffer_writer *)this,
    time_offset,
    ".\\fingers_to_weapon_corrector.cpp",
    (const char *)0x11C,
    "vostok::animation::fingers_to_weapon_corrector::serialize",
    "active_hands");
  m_last = writer[122].serialization_operations_descriptors.m_last;
  if ( m_last )
  {
    v4 = a4;
    v13 = (char *)m_last + (_DWORD)a4;
  }
  else
  {
    v13 = 0;
  }
  vostok::network_core::buffer_writer::w<unsigned int>(
    (unsigned __int8 *)&v13,
    v4,
    time_offset,
    ".\\fingers_to_weapon_corrector.cpp",
    (const char *)0x11E,
    "vostok::animation::fingers_to_weapon_corrector::serialize",
    "m_hands[left].start_transition_time_in_ms ? m_hands[left].start_transition_time_in_ms + time_offset : 0");
  player_id = writer[122].player_id;
  vostok::network_core::buffer_writer::w<unsigned char>(
    &player_id,
    v6,
    time_offset,
    ".\\fingers_to_weapon_corrector.cpp",
    (const char *)0x11F,
    "vostok::animation::fingers_to_weapon_corrector::serialize",
    "(u8)m_hands[left].locator_set_id");
  player_id = (unsigned __int8)writer[122].m_buffer;
  vostok::network_core::buffer_writer::w<unsigned char>(
    &player_id,
    v7,
    time_offset,
    ".\\fingers_to_weapon_corrector.cpp",
    (const char *)0x120,
    "vostok::animation::fingers_to_weapon_corrector::serialize",
    "(u8)m_hands[left].previous_locator_set_id");
  v9 = *(_DWORD *)&writer[245].player_id;
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
    ".\\fingers_to_weapon_corrector.cpp",
    (const char *)0x122,
    "vostok::animation::fingers_to_weapon_corrector::serialize",
    "m_hands[right].start_transition_time_in_ms ? m_hands[right].start_transition_time_in_ms + time_offset : 0");
  player_id = (unsigned __int8)writer[245].m_buffer;
  vostok::network_core::buffer_writer::w<unsigned char>(
    &player_id,
    v10,
    time_offset,
    ".\\fingers_to_weapon_corrector.cpp",
    (const char *)0x123,
    "vostok::animation::fingers_to_weapon_corrector::serialize",
    "(u8)m_hands[right].locator_set_id");
  player_id = writer[246].serialization_operations_descriptors.m_size;
  vostok::network_core::buffer_writer::w<unsigned char>(
    &player_id,
    v11,
    time_offset,
    ".\\fingers_to_weapon_corrector.cpp",
    (const char *)0x124,
    "vostok::animation::fingers_to_weapon_corrector::serialize",
    "(u8)m_hands[right].previous_locator_set_id");
}
