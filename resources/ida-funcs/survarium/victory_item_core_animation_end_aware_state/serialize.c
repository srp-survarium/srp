void __thiscall survarium::victory_item_core_animation_end_aware_state::serialize(
        survarium::victory_item_core_animation_end_aware_state *this,
        vostok::network_core::buffer_writer *writer,
        const vostok::network_core::buffer_writer *client_writer)
{
  vostok::network_core::buffer_writer *v4; // ecx

  survarium::victory_item_core_base_state::serialize(this, writer, client_writer);
  vostok::network_core::buffer_writer::w<unsigned char>(
    &this->m_index_of_animation_to_wait,
    v4,
    writer,
    ".\\victory_item_core_animation_end_aware_state.cpp",
    (const char *)0x48,
    "survarium::victory_item_core_animation_end_aware_state::serialize",
    "m_index_of_animation_to_wait");
}
