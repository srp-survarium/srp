BOOL __thiscall vostok::network_core::packet_reader::eof(vostok::network_core::packet_reader *this)
{
  return this->m_pointer == &this->m_packet->m_buffer[this->m_packet->m_buffer_size];
}
