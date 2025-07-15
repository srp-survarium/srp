void __usercall vostok::network_core::udp_match_connection::fill_packet_header(
        vostok::network_core::udp_match_connection *this@<ecx>,
        vostok::network_core::udp_match_packet *packet@<eax>)
{
  unsigned __int8 *m_buffer; // ecx
  __int64 v4; // rax
  int v5; // [esp+Ch] [ebp-4h]

  m_buffer = packet->m_buffer.m_buffer;
  v5 = *m_buffer;
  *(_WORD *)m_buffer = *(_WORD *)&packet->sequence_ids.m_buffer[(packet->sequence_ids.m_head + 8) % 9][0];
  m_buffer += 2;
  *(_WORD *)m_buffer = this->m_remote_sequence_id.m_number;
  LODWORD(v4) = (2 * LODWORD(this->m_remote_acknowledgement_bits)) | (v5 == 1);
  HIDWORD(v4) = this->m_remote_acknowledgement_bits >> 31;
  *(_QWORD *)(m_buffer + 2) = v4;
}
