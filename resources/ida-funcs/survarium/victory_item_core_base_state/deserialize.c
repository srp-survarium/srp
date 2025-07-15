void __thiscall survarium::victory_item_core_base_state::deserialize(
        survarium::victory_item_core_base_state *this,
        vostok::network_core::buffer_reader *reader,
        vostok::network_core::buffer_reader *client_reader)
{
  this->m_animation_has_been_ended = vostok::network_core::buffer_reader::r<bool>(reader);
}
