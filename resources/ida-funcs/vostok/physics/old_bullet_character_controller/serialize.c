void __thiscall vostok::physics::old_bullet_character_controller::serialize(
        vostok::physics::old_bullet_character_controller *this,
        const vostok::network_core::buffer_writer *writer,
        vostok::network_core::buffer_writer *current_time_in_ms)
{
  vostok::network_core::buffer_writer *v3; // ecx
  vostok::network_core::buffer_writer *v4; // ecx
  vostok::math::float3 v5; // [esp+Ch] [ebp-Ch] BYREF

  vostok::network_core::buffer_writer::w<bool>(
    (const bool *)&writer[23].m_buffer,
    (vostok::network_core::buffer_writer *)this,
    current_time_in_ms,
    ".\\old_bullet_character_controller.cpp",
    (const char *)0x380,
    "vostok::physics::old_bullet_character_controller::serialize",
    "m_jumping");
  vostok::network_core::buffer_writer::w<bool>(
    (const bool *)&writer[23].serialization_operations_descriptors.m_first,
    v3,
    current_time_in_ms,
    ".\\old_bullet_character_controller.cpp",
    (const char *)0x381,
    "vostok::physics::old_bullet_character_controller::serialize",
    "m_in_crouch");
  *(_QWORD *)&v5.x = *(_QWORD *)&writer[26].serialization_operations_descriptors.m_size;
  LODWORD(v5.z) = (__int128)writer[26].serialization_operations_descriptors.m_first ^ _mask__NegFloat_;
  vostok::network_core::buffer_writer::w<vostok::math::float3>(
    &v5,
    v4,
    current_time_in_ms,
    ".\\old_bullet_character_controller.cpp",
    (const char *)0x382,
    "vostok::physics::old_bullet_character_controller::serialize",
    "from_bullet( m_fall_and_slide_velocity )");
}
