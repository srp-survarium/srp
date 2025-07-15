void __thiscall vostok::physics::bullet_character_controller::serialize(
        vostok::physics::bullet_character_controller *this,
        const vostok::network_core::buffer_writer *writer,
        vostok::network_core::buffer_writer *current_time_in_ms)
{
  vostok::network_core::buffer_writer *v3; // ecx
  vostok::network_core::buffer_writer *v4; // ecx
  vostok::network_core::buffer_writer *v5; // ecx
  vostok::network_core::buffer_writer *v6; // ecx
  vostok::network_core::buffer_writer *v7; // ecx
  vostok::network_core::buffer_writer *v8; // ecx
  vostok::network_core::buffer_writer *v9; // ecx
  vostok::math::float3 v10; // [esp+Ch] [ebp-Ch] BYREF

  vostok::network_core::buffer_writer::w<bool>(
    (const bool *)&writer[48].serialization_operations_descriptors.m_last,
    (vostok::network_core::buffer_writer *)this,
    current_time_in_ms,
    ".\\bullet_character_controller.cpp",
    (const char *)0x438,
    "vostok::physics::bullet_character_controller::serialize",
    "m_jumping");
  vostok::network_core::buffer_writer::w<bool>(
    (const bool *)&writer[20].player_id,
    v3,
    current_time_in_ms,
    ".\\bullet_character_controller.cpp",
    (const char *)0x439,
    "vostok::physics::bullet_character_controller::serialize",
    "m_input_is_in_crouch");
  vostok::network_core::buffer_writer::w<bool>(
    (const bool *)&writer[20].player_id + 1,
    v4,
    current_time_in_ms,
    ".\\bullet_character_controller.cpp",
    (const char *)0x43A,
    "vostok::physics::bullet_character_controller::serialize",
    "m_logic_is_in_crouch");
  vostok::network_core::buffer_writer::w<bool>(
    (const bool *)&writer[20].player_id + 3,
    v5,
    current_time_in_ms,
    ".\\bullet_character_controller.cpp",
    (const char *)0x43B,
    "vostok::physics::bullet_character_controller::serialize",
    "m_capsule_is_in_crouch");
  vostok::network_core::buffer_writer::w<bool>(
    (const bool *)&writer[20].player_id + 2,
    v6,
    current_time_in_ms,
    ".\\bullet_character_controller.cpp",
    (const char *)0x43C,
    "vostok::physics::bullet_character_controller::serialize",
    "m_can_stand");
  *(_QWORD *)&v10.x = *(_QWORD *)&writer[51].serialization_operations_descriptors.m_first;
  LODWORD(v10.z) = *(_DWORD *)&writer[51].player_id ^ _mask__NegFloat_;
  vostok::network_core::buffer_writer::w<vostok::math::float3>(
    &v10,
    v7,
    current_time_in_ms,
    ".\\bullet_character_controller.cpp",
    (const char *)0x43D,
    "vostok::physics::bullet_character_controller::serialize",
    "from_bullet( m_fall_and_slide_velocity )");
  *(_QWORD *)&v10.x = *(_QWORD *)&writer[48].player_id;
  LODWORD(v10.z) = writer[49].serialization_operations_descriptors.m_size ^ _mask__NegFloat_;
  vostok::network_core::buffer_writer::w<vostok::math::float3>(
    &v10,
    v8,
    current_time_in_ms,
    ".\\bullet_character_controller.cpp",
    (const char *)0x43E,
    "vostok::physics::bullet_character_controller::serialize",
    "from_bullet( m_supporting_surface_normal )");
  vostok::network_core::buffer_writer::w<bool>(
    (const bool *)&writer[20].m_buffer,
    v9,
    current_time_in_ms,
    ".\\bullet_character_controller.cpp",
    (const char *)0x43F,
    "vostok::physics::bullet_character_controller::serialize",
    "m_is_sprinting");
}
