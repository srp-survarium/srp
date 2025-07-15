void __thiscall survarium::player_input::serialize(
        survarium::player_input *this,
        vostok::math::float2 *writer,
        vostok::network_core::buffer_writer *a3)
{
  vostok::network_core::buffer_writer *v3; // ecx

  vostok::network_core::buffer_writer::w<vostok::math::float2>(
    writer,
    (vostok::network_core::buffer_writer *)this,
    a3,
    ".\\player_input.cpp",
    (const char *)0x17,
    "survarium::player_input::serialize",
    "rotation_delta");
  vostok::network_core::buffer_writer::w<unsigned int>(
    (unsigned __int8 *)&writer[1],
    v3,
    a3,
    ".\\player_input.cpp",
    (const char *)0x18,
    "survarium::player_input::serialize",
    "actions_mask");
}
