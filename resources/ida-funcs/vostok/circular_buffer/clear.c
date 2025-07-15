void __thiscall vostok::circular_buffer<stlp_std::pair<enum survarium::game_action_id,enum survarium::action_state_enum>,64>::clear(
        vostok::circular_buffer<stlp_std::pair<enum survarium::game_action_id,enum survarium::action_state_enum>,64> *this)
{
  unsigned int v1; // eax

  if ( this->m_head != this->m_tail )
  {
    do
    {
      v1 = (this->m_head + 64) % 0x41;
      this->m_head = v1;
    }
    while ( v1 != this->m_tail );
  }
}
