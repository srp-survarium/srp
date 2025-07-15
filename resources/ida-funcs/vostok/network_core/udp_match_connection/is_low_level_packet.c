bool __usercall vostok::network_core::udp_match_connection::is_low_level_packet@<al>(
        const vostok::network_core::udp_match_packet *packet@<eax>)
{
  unsigned __int8 *m_buffer; // edx

  m_buffer = packet->m_buffer.m_buffer;
  return (*(_QWORD *)(m_buffer + 4) & 1) != 0 && &m_buffer[m_buffer[12] + 13] == &m_buffer[packet->m_buffer.m_size];
}
