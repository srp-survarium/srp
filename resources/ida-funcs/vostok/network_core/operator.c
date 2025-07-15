int __cdecl vostok::network_core::operator-<unsigned short>(
        vostok::network_core::sequence_number<unsigned short> *left,
        vostok::network_core::sequence_number<unsigned short> *right)
{
  if ( (unsigned __int8)vostok::network_core::sequence_number<unsigned short>::operator<=(left, &right->m_number) )
    return ((int)&_sbh_sizeHeaderList + left->m_number - right->m_number) % 0x10000;
  else
    return -vostok::network_core::operator-<unsigned short>(right, left);
}


BOOL __usercall vostok::network_core::operator>=@<eax>(
        const vostok::network_core::udp_match_stats *left@<edi>,
        const vostok::network_core::udp_match_stats *right@<esi>)
{
  return vostok::network_core::operator>=(&left->sent, &right->sent)
      && vostok::network_core::operator>=(&left->resent, &right->resent)
      && vostok::network_core::operator>=(&left->received, &right->received)
      && vostok::network_core::operator>=(&left->received_duplicated, &right->received_duplicated)
      && vostok::network_core::operator>=(&left->sent_low_level, &right->sent_low_level)
      && vostok::network_core::operator>=(&left->received_low_level, &right->received_low_level);
}


BOOL __usercall vostok::network_core::operator>=@<eax>(
        const vostok::network_core::udp_match_stream_stats *left@<ecx>,
        const vostok::network_core::udp_match_stream_stats *right@<eax>)
{
  return left->packets.count >= right->packets.count
      && left->packets.bytes >= right->packets.bytes
      && left->messages.count >= right->messages.count
      && left->messages.bytes >= right->messages.bytes
      && left->data_bytes >= right->data_bytes;
}
