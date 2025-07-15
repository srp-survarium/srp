void __thiscall survarium::jump_logic_base_state::deserialize(
        survarium::jump_logic_base_state *this,
        vostok::network_core::buffer_reader *reader,
        vostok::network_core::buffer_reader *client_reader)
{
  const unsigned __int8 *m_pointer; // esi
  unsigned __int8 v6; // [esp+17h] [ebp+Bh]

  m_pointer = reader->m_pointer;
  v6 = *m_pointer;
  reader->m_pointer = m_pointer + 1;
  this->m_interval_id_to_wait_for = v6;
  this->m_is_jump_finished = vostok::network_core::buffer_reader::r<bool>(reader);
}
