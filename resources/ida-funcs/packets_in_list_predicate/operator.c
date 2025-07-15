BOOL __thiscall packets_in_list_predicate::operator()(
        packets_in_list_predicate *this,
        const vostok::network_core::udp_match_packet *const packet)
{
  int v2; // eax

  v2 = *(_DWORD *)&this[46].m_sequence_id.m_number;
  return v2 != *(_DWORD *)&this[48].m_sequence_id.m_number
      && this[(v2 + 8) % 9u + 36].m_sequence_id.m_number == LOWORD(packet->ordered_multipackets_hook.parent_);
}
