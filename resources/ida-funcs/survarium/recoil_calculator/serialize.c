void __thiscall survarium::recoil_calculator::serialize(
        survarium::recoil_calculator *this,
        const vostok::network_core::buffer_writer *writer,
        vostok::network_core::buffer_writer *time_offset,
        int a4)
{
  vostok::network_core::buffer_writer *v4; // ecx
  vostok::network_core::buffer_writer *v5; // ecx
  vostok::network_core::buffer_writer *v6; // ecx

  survarium::weapon_recoil_calculator::serialize(&this->m_weapon_calculator, (unsigned int)writer, time_offset, a4);
  vostok::network_core::buffer_writer::w<float>(
    (float *)&writer[2].serialization_operations_descriptors.m_first,
    v4,
    time_offset,
    ".\\character_recoil_calculator.cpp",
    (const char *)0x48,
    "survarium::character_recoil_calculator::serialize",
    "m_current_value");
  vostok::network_core::buffer_writer::w<float>(
    (float *)&writer[2].serialization_operations_descriptors.gap4,
    v5,
    time_offset,
    ".\\character_recoil_calculator.cpp",
    (const char *)0x49,
    "survarium::character_recoil_calculator::serialize",
    "m_target_value");
  a4 += (int)writer[2].m_buffer;
  vostok::network_core::buffer_writer::w<unsigned int>(
    (unsigned __int8 *)&a4,
    v6,
    time_offset,
    ".\\character_recoil_calculator.cpp",
    (const char *)0x4B,
    "survarium::character_recoil_calculator::serialize",
    "m_current_time_in_ms + time_offset");
}
