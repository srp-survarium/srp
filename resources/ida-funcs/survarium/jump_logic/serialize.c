void __userpurge survarium::jump_logic::serialize(
        survarium::jump_logic *this@<ecx>,
        int a2@<eax>,
        vostok::network_core::buffer_writer *writer,
        const vostok::network_core::buffer_writer *client_writer)
{
  vostok::network_core::buffer_writer *v5; // ecx
  vostok::network_core::buffer_writer *v6; // ecx
  vostok::ai::fsm *v7; // ecx
  unsigned __int8 v8; // [esp+Fh] [ebp-1h] BYREF

  v8 = *(_BYTE *)(a2 + 320);
  vostok::network_core::buffer_writer::w<unsigned char>(
    &v8,
    (vostok::network_core::buffer_writer *)this,
    writer,
    ".\\jump_logic.cpp",
    (const char *)0x19C,
    "survarium::jump_logic::serialize",
    "static_cast< u8 >( m_jump_type )");
  vostok::network_core::buffer_writer::w<float>(
    (float *)(a2 + 324),
    v5,
    writer,
    ".\\jump_logic.cpp",
    (const char *)0x19D,
    "survarium::jump_logic::serialize",
    "m_move_animation_weight");
  vostok::network_core::buffer_writer::w<bool>(
    (const bool *)(a2 + 328),
    v6,
    writer,
    ".\\jump_logic.cpp",
    (const char *)0x19E,
    "survarium::jump_logic::serialize",
    "m_is_jump_from_right_leg");
  vostok::ai::fsm::serialize(v7, a2, writer, client_writer);
}
