void __thiscall vostok::circular_buffer<survarium::fx_history_item,10>::~circular_buffer<survarium::fx_history_item,10>(
        vostok::circular_buffer<survarium::fx_history_item,10> *this)
{
  unsigned int v1; // eax

  if ( this->m_head != this->m_tail )
  {
    do
    {
      v1 = (this->m_head + 10) % 0xB;
      this->m_head = v1;
    }
    while ( v1 != this->m_tail );
  }
}


void __thiscall vostok::circular_buffer<vostok::network_core::sequence_number<unsigned short>,8>::~circular_buffer<vostok::network_core::sequence_number<unsigned short>,8>(
        vostok::circular_buffer<vostok::network_core::sequence_number<unsigned short>,8> *this)
{
  unsigned int v1; // eax

  if ( this->m_head != this->m_tail )
  {
    do
    {
      v1 = (this->m_head + 8) % 9;
      this->m_head = v1;
    }
    while ( v1 != this->m_tail );
  }
}
