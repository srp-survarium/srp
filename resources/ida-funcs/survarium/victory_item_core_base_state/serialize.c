void __thiscall survarium::victory_item_core_base_state::serialize(
        survarium::victory_item_core_base_state *this,
        vostok::network_core::buffer_writer *writer,
        const vostok::network_core::buffer_writer *client_writer)
{
  vostok::network_core::buffer_writer::w<bool>(
    &this->m_animation_has_been_ended,
    (vostok::network_core::buffer_writer *)this,
    writer,
    ".\\victory_item_core_base_state.cpp",
    (const char *)0x25,
    "survarium::victory_item_core_base_state::serialize",
    "m_animation_has_been_ended");
}
