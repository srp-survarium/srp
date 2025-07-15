void __thiscall survarium::weapon_core_throw_grenade_base_substate::deserialize(
        survarium::weapon_core_throw_grenade_base_substate *this,
        vostok::network_core::buffer_reader *reader,
        vostok::network_core::buffer_reader *client_reader)
{
  const unsigned __int8 *m_pointer; // esi
  unsigned __int8 v5; // [esp+Fh] [ebp-1h]

  this->m_animation_has_been_ended = vostok::network_core::buffer_reader::r<bool>(reader);
  m_pointer = reader->m_pointer;
  v5 = *m_pointer;
  reader->m_pointer = m_pointer + 1;
  this->m_index_of_animation_to_wait = v5;
  this->subscribe_animation_player(this);
}
