void __fastcall vostok::circular_buffer<vostok::network_core::sequence_number<unsigned short>,8>::push_back(
        vostok::circular_buffer<vostok::network_core::sequence_number<unsigned short>,8> *this,
        const vostok::network_core::sequence_number<unsigned short> *item)
{
  vostok::network_core::sequence_number<unsigned short> *v2; // eax
  unsigned int m_tail; // eax
  unsigned int v4; // esi

  v2 = (vostok::network_core::sequence_number<unsigned short> *)this->m_buffer[this->m_head];
  if ( v2 )
    v2->m_number = item->m_number;
  m_tail = this->m_tail;
  v4 = (this->m_head + 1) % 9;
  if ( v4 == m_tail )
    this->m_tail = (m_tail + 1) % 9;
  this->m_head = v4;
}
