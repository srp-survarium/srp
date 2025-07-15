unsigned int __fastcall vostok::operator-(
        const vostok::circular_buffer<stlp_std::pair<enum survarium::game_action_id,enum survarium::action_state_enum>,64>::const_iterator *left,
        const vostok::circular_buffer<stlp_std::pair<enum survarium::game_action_id,enum survarium::action_state_enum>,64>::const_iterator *right)
{
  unsigned int m_index; // eax
  unsigned int v3; // edx
  unsigned int m_head; // ecx

  m_index = left->m_index;
  v3 = right->m_index;
  m_head = left->m_container->m_head;
  if ( m_index < v3 )
  {
    if ( m_head >= m_index && v3 > m_head )
      return m_index - v3 + 65;
  }
  else if ( m_head >= v3 && m_index > m_head )
  {
    return m_index - v3 - 65;
  }
  return m_index - v3;
}


unsigned int __fastcall vostok::operator-(
        const vostok::circular_buffer<survarium::fx_history_item,10>::iterator *left,
        const vostok::circular_buffer<survarium::fx_history_item,10>::iterator *right)
{
  unsigned int m_index; // eax
  unsigned int v3; // edx
  unsigned int m_head; // ecx

  m_index = left->m_index;
  v3 = right->m_index;
  m_head = left->m_container->m_head;
  if ( m_index < v3 )
  {
    if ( m_head >= m_index && v3 > m_head )
      return m_index - v3 + 11;
  }
  else if ( m_head >= v3 && m_index > m_head )
  {
    return m_index - v3 - 11;
  }
  return m_index - v3;
}


unsigned int __fastcall vostok::operator-(
        const vostok::circular_buffer<vostok::network_core::sequence_number<unsigned short>,8>::iterator *left,
        const vostok::circular_buffer<vostok::network_core::sequence_number<unsigned short>,8>::iterator *right)
{
  unsigned int m_index; // eax
  unsigned int v3; // edx
  unsigned int m_head; // ecx

  m_index = left->m_index;
  v3 = right->m_index;
  m_head = left->m_container->m_head;
  if ( m_index < v3 )
  {
    if ( m_head >= m_index && v3 > m_head )
      return m_index - v3 + 9;
  }
  else if ( m_head >= v3 && m_index > m_head )
  {
    return m_index - v3 - 9;
  }
  return m_index - v3;
}
