void __thiscall survarium::bullet::serialize(
        survarium::bullet *this,
        vostok::network_core::buffer_writer *writer,
        vostok::network_core::buffer_writer *offset,
        int a4)
{
  vostok::network_core::buffer_writer *v4; // ebx
  vostok::network_core::buffer_writer *v5; // ecx
  vostok::network_core::buffer_writer *v6; // ecx
  vostok::network_core::buffer_writer *v7; // ecx
  vostok::network_core::buffer_writer *v8; // ecx
  vostok::network_core::buffer_writer *v9; // ecx
  vostok::network_core::buffer_writer *v10; // ecx
  vostok::network_core::buffer_writer *v11; // ecx
  vostok::network_core::buffer_writer *v12; // ecx
  vostok::network_core::buffer_writer *v13; // ecx
  vostok::network_core::buffer_writer *v14; // ecx
  vostok::network_core::buffer_writer *v15; // ecx
  vostok::network_core::buffer_writer *v16; // ecx
  vostok::network_core::buffer_writer *v17; // ecx
  vostok::network_core::buffer_writer *v18; // ecx
  vostok::network_core::buffer_writer *v19; // ecx
  vostok::network_core::buffer_writer *v20; // ecx
  int v21; // eax
  vostok::network_core::buffer_writer *v22; // ecx
  vostok::network_core::buffer_writer *v23; // ecx
  vostok::network_core::buffer_writer *v24; // ecx
  vostok::network_core::buffer_writer *v25; // ecx
  vostok::network_core::mutable_buffer *m_buffer; // eax
  vostok::network_core::buffer_writer *v27; // ecx
  const char *v28; // [esp+0h] [ebp-Ch]
  int v29; // [esp+4h] [ebp-8h]
  const char *v30; // [esp+8h] [ebp-4h]
  const char *savedregs; // [esp+Ch] [ebp+0h]

  v4 = writer;
  vostok::network_core::buffer_writer::w<unsigned int>(
    (unsigned __int8 *)writer,
    (vostok::network_core::buffer_writer *)this,
    offset,
    ".\\bullet.cpp",
    (const char *)0x93,
    "survarium::bullet::serialize",
    "m_id");
  vostok::network_core::buffer_writer::w<vostok::math::float3>(
    (vostok::math::float3 *)&v4[1].serialization_operations_descriptors.gap4,
    v5,
    offset,
    ".\\bullet.cpp",
    (const char *)0x94,
    "survarium::bullet::serialize",
    "m_start_position");
  vostok::network_core::buffer_writer::w<vostok::math::float3>(
    (vostok::math::float3 *)&v4[1].player_id,
    v6,
    offset,
    ".\\bullet.cpp",
    (const char *)0x95,
    "survarium::bullet::serialize",
    "m_start_velocity");
  vostok::network_core::buffer_writer::w<float>(
    (float *)&v4[5].serialization_operations_descriptors.m_size,
    v7,
    offset,
    ".\\bullet.cpp",
    (const char *)0x96,
    "survarium::bullet::serialize",
    "m_max_damage_speed");
  vostok::network_core::buffer_writer::w<float>(
    (float *)&v4[5].serialization_operations_descriptors.gap4,
    v8,
    offset,
    ".\\bullet.cpp",
    (const char *)0x97,
    "survarium::bullet::serialize",
    "m_min_damage_speed");
  writer = (vostok::network_core::buffer_writer *)((char *)v4[3].m_buffer + a4);
  vostok::network_core::buffer_writer::w<unsigned int>(
    (unsigned __int8 *)&writer,
    v9,
    offset,
    ".\\bullet.cpp",
    (const char *)0x98,
    "survarium::bullet::serialize",
    "m_born_time_in_ms + offset");
  vostok::network_core::buffer_writer::w<float>(
    (float *)&v4[4].serialization_operations_descriptors.gap4,
    v10,
    offset,
    ".\\bullet.cpp",
    (const char *)0x99,
    "survarium::bullet::serialize",
    "m_life_time");
  vostok::network_core::buffer_writer::w<float>(
    (float *)&v4[4].serialization_operations_descriptors.m_first,
    v11,
    offset,
    ".\\bullet.cpp",
    (const char *)0x9A,
    "survarium::bullet::serialize",
    "m_flown_distance");
  vostok::network_core::buffer_writer::w<float>(
    (float *)&v4[4].player_id,
    v12,
    offset,
    ".\\bullet.cpp",
    (const char *)0x9B,
    "survarium::bullet::serialize",
    "m_damage");
  vostok::network_core::buffer_writer::w<float>(
    (float *)&v4[4].m_buffer,
    v13,
    offset,
    ".\\bullet.cpp",
    (const char *)0x9C,
    "survarium::bullet::serialize",
    "m_pierce");
  vostok::network_core::buffer_writer::w<unsigned char>(
    &v4[5].player_id,
    v14,
    offset,
    ".\\bullet.cpp",
    (const char *)0x9D,
    "survarium::bullet::serialize",
    "m_ricochet_count");
  HIBYTE(writer) = v4[5].serialization_operations_descriptors.m_last;
  vostok::network_core::buffer_writer::w<unsigned char>(
    (unsigned __int8 *)&writer + 3,
    v15,
    offset,
    ".\\bullet.cpp",
    (const char *)0x9E,
    "survarium::bullet::serialize",
    "static_cast< u8 >( m_change_trajectory_count )");
  vostok::network_core::buffer_writer::w<unsigned char>(
    (unsigned __int8 *)&v4[3].serialization_operations_descriptors.m_first,
    v16,
    offset,
    ".\\bullet.cpp",
    (const char *)0x9F,
    "survarium::bullet::serialize",
    "m_last_hitted_player");
  vostok::network_core::buffer_writer::w<unsigned char>(
    (unsigned __int8 *)&v4[3].serialization_operations_descriptors.m_first + 1,
    v17,
    offset,
    ".\\bullet.cpp",
    (const char *)0xA0,
    "survarium::bullet::serialize",
    "m_last_hitted_body_part");
  vostok::network_core::buffer_writer::w<float>(
    (float *)&v4[3].serialization_operations_descriptors.m_last,
    v18,
    offset,
    ".\\bullet.cpp",
    (const char *)0xA1,
    "survarium::bullet::serialize",
    "m_max_damage_dealt");
  HIBYTE(writer) = v4[3].player_id;
  vostok::network_core::buffer_writer::w<signed char>((char *)&writer + 3, v19, offset, v28, v29, v30, savedregs);
  vostok::network_core::buffer_writer::w<unsigned char>(
    (unsigned __int8 *)(v4[3].serialization_operations_descriptors.m_size + 4),
    v20,
    offset,
    ".\\bullet.cpp",
    (const char *)0xA5,
    "survarium::bullet::serialize",
    "m_initiator->id");
  v21 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)&v4[3].serialization_operations_descriptors.gap4 + 8))(*(_DWORD *)&v4[3].serialization_operations_descriptors.gap4);
  vostok::network_core::buffer_writer::w<unsigned char>(
    (unsigned __int8 *)(v21 + 304),
    v22,
    offset,
    ".\\bullet.cpp",
    (const char *)0xA7,
    "survarium::bullet::serialize",
    "m_ignorable_object->cast_to_base_player()->id");
  HIBYTE(writer) = v4[2].serialization_operations_descriptors.m_first[9].type;
  vostok::network_core::buffer_writer::w<unsigned char>(
    (unsigned __int8 *)&writer + 3,
    v23,
    offset,
    ".\\bullet.cpp",
    (const char *)0xA8,
    "survarium::bullet::serialize",
    "static_cast< u8 >( m_weapon->profile_slot_id() )");
  if ( *(&v4[5].player_id + 1) )
    HIBYTE(writer) = -1;
  else
    HIBYTE(writer) = *(_BYTE *)(*(_DWORD *)&v4[2].serialization_operations_descriptors.gap4 + 276);
  vostok::network_core::buffer_writer::w<unsigned char>(
    (unsigned __int8 *)&writer + 3,
    v24,
    offset,
    ".\\bullet.cpp",
    (const char *)0xA9,
    "survarium::bullet::serialize",
    "static_cast< u8 >( ( !m_is_melee ) ? m_weapon_ammunition->profile_slot_id() : (u8)-1 )");
  m_buffer = v4[2].m_buffer;
  if ( m_buffer )
    HIBYTE(writer) = m_buffer[6].m_buffer;
  else
    HIBYTE(writer) = 0;
  vostok::network_core::buffer_writer::w<unsigned char>(
    (unsigned __int8 *)&writer + 3,
    v25,
    offset,
    ".\\bullet.cpp",
    (const char *)0xAA,
    "survarium::bullet::serialize",
    "m_collided_material ? static_cast< u8 >(m_collided_material->id()) : u8(0)");
  if ( *(_BYTE *)(*(_DWORD *)&v4[2].serialization_operations_descriptors.gap4 + 344) > 1u )
    vostok::network_core::buffer_writer::w<unsigned char>(
      (unsigned __int8 *)&v4[5].serialization_operations_descriptors.m_first,
      v27,
      offset,
      ".\\bullet.cpp",
      (const char *)0xAD,
      "survarium::bullet::serialize",
      "m_buck_shot");
}
