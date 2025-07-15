void __thiscall survarium::player_logic_jump_state::deserialize(
        survarium::player_logic_jump_state *this,
        vostok::network_core::buffer_reader *reader,
        vostok::network_core::buffer_reader *client_reader)
{
  const unsigned __int8 *m_pointer; // esi
  const unsigned __int8 *v5; // esi
  vostok::network_core::buffer_reader *readera; // [esp+18h] [ebp+8h]
  unsigned __int8 reader_3; // [esp+1Bh] [ebp+Bh]

  m_pointer = reader->m_pointer;
  reader_3 = *m_pointer;
  reader->m_pointer = m_pointer + 1;
  this->m_logic.m_jump_type = reader_3;
  v5 = reader->m_pointer;
  readera = *(vostok::network_core::buffer_reader **)v5;
  reader->m_pointer = v5 + 4;
  LODWORD(this->m_logic.m_move_animation_weight) = readera;
  this->m_logic.m_is_jump_from_right_leg = vostok::network_core::buffer_reader::r<bool>(reader);
  vostok::ai::fsm::deserialize(&this->m_logic.m_logic, reader, client_reader);
  this->m_is_sprinting = vostok::network_core::buffer_reader::r<bool>(reader);
}
