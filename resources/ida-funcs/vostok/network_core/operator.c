int __cdecl vostok::network_core::operator-<unsigned short>(
        const vostok::network_core::sequence_number<unsigned short> *left,
        vostok::network_core::sequence_number<unsigned short> *right)
{
  if ( vostok::network_core::sequence_number<unsigned short>::operator<=(right, left) )
    return ((int)&_sbh_sizeHeaderList + left->m_number - right->m_number) % 0x10000;
  else
    return -vostok::network_core::operator-<unsigned short>(right, left);
}


vostok::network_core::udp_match_stats *__usercall vostok::network_core::operator-@<eax>(
        const vostok::network_core::udp_match_stats *left@<edi>,
        const vostok::network_core::udp_match_stats *right@<esi>,
        vostok::network_core::udp_match_stats *a3@<ecx>,
        int a4)
{
  unsigned int v4; // ecx
  unsigned int v5; // eax
  unsigned int v6; // ecx
  unsigned int v7; // eax
  unsigned int v8; // ecx
  unsigned int v9; // eax
  unsigned int v10; // ecx
  unsigned int v11; // eax
  unsigned int v12; // ecx
  unsigned int v13; // eax
  unsigned int v14; // ecx
  unsigned int v15; // eax
  vostok::network_core::udp_match_stats *result; // eax
  __int64 v17; // [esp+4h] [ebp-14h]
  __int64 v18; // [esp+Ch] [ebp-Ch]

  vostok::network_core::udp_match_stats::udp_match_stats(a3, (_DWORD *)a4);
  LODWORD(v17) = left->sent.packets.count - right->sent.packets.count;
  HIDWORD(v17) = left->sent.packets.bytes - right->sent.packets.bytes;
  v4 = left->sent.messages.bytes - right->sent.messages.bytes;
  LODWORD(v18) = left->sent.messages.count - right->sent.messages.count;
  v5 = left->sent.data_bytes - right->sent.data_bytes;
  *(_QWORD *)a4 = v17;
  HIDWORD(v18) = v4;
  *(_QWORD *)(a4 + 8) = v18;
  *(_DWORD *)(a4 + 16) = v5;
  LODWORD(v17) = left->resent.packets.count - right->resent.packets.count;
  HIDWORD(v17) = left->resent.packets.bytes - right->resent.packets.bytes;
  v6 = left->resent.messages.bytes - right->resent.messages.bytes;
  LODWORD(v18) = left->resent.messages.count - right->resent.messages.count;
  v7 = left->resent.data_bytes - right->resent.data_bytes;
  *(_QWORD *)(a4 + 40) = v17;
  HIDWORD(v18) = v6;
  *(_QWORD *)(a4 + 48) = v18;
  *(_DWORD *)(a4 + 56) = v7;
  LODWORD(v17) = left->received.packets.count - right->received.packets.count;
  HIDWORD(v17) = left->received.packets.bytes - right->received.packets.bytes;
  v8 = left->received.messages.bytes - right->received.messages.bytes;
  LODWORD(v18) = left->received.messages.count - right->received.messages.count;
  v9 = left->received.data_bytes - right->received.data_bytes;
  *(_QWORD *)(a4 + 60) = v17;
  HIDWORD(v18) = v8;
  *(_QWORD *)(a4 + 68) = v18;
  *(_DWORD *)(a4 + 76) = v9;
  LODWORD(v17) = left->received_duplicated.packets.count - right->received_duplicated.packets.count;
  HIDWORD(v17) = left->received_duplicated.packets.bytes - right->received_duplicated.packets.bytes;
  v10 = left->received_duplicated.messages.bytes - right->received_duplicated.messages.bytes;
  LODWORD(v18) = left->received_duplicated.messages.count - right->received_duplicated.messages.count;
  v11 = left->received_duplicated.data_bytes - right->received_duplicated.data_bytes;
  *(_QWORD *)(a4 + 100) = v17;
  HIDWORD(v18) = v10;
  *(_QWORD *)(a4 + 108) = v18;
  *(_DWORD *)(a4 + 116) = v11;
  LODWORD(v17) = left->sent_low_level.packets.count - right->sent_low_level.packets.count;
  HIDWORD(v17) = left->sent_low_level.packets.bytes - right->sent_low_level.packets.bytes;
  v12 = left->sent_low_level.messages.bytes - right->sent_low_level.messages.bytes;
  LODWORD(v18) = left->sent_low_level.messages.count - right->sent_low_level.messages.count;
  v13 = left->sent_low_level.data_bytes - right->sent_low_level.data_bytes;
  *(_QWORD *)(a4 + 20) = v17;
  HIDWORD(v18) = v12;
  *(_QWORD *)(a4 + 28) = v18;
  *(_DWORD *)(a4 + 36) = v13;
  LODWORD(v17) = left->received_low_level.packets.count - right->received_low_level.packets.count;
  HIDWORD(v17) = left->received_low_level.packets.bytes - right->received_low_level.packets.bytes;
  v14 = left->received_low_level.messages.bytes - right->received_low_level.messages.bytes;
  LODWORD(v18) = left->received_low_level.messages.count - right->received_low_level.messages.count;
  v15 = left->received_low_level.data_bytes - right->received_low_level.data_bytes;
  *(_QWORD *)(a4 + 80) = v17;
  HIDWORD(v18) = v14;
  *(_QWORD *)(a4 + 88) = v18;
  *(_DWORD *)(a4 + 96) = v15;
  *(_DWORD *)(a4 + 120) = vostok::math::max(left->max_local_sequence_difference, right->max_local_sequence_difference);
  result = (vostok::network_core::udp_match_stats *)a4;
  *(_DWORD *)(a4 + 124) = left->unacknowledged_packets - right->unacknowledged_packets;
  return result;
}


bool __cdecl vostok::network_core::operator>=(
        const vostok::network_core::udp_match_stats *left,
        const vostok::network_core::udp_match_stats *right)
{
  return vostok::network_core::operator>=(&left->sent, &right->sent)
      && vostok::network_core::operator>=(&left->resent, &right->resent)
      && vostok::network_core::operator>=(&left->received, &right->received)
      && vostok::network_core::operator>=(&left->received_duplicated, &right->received_duplicated)
      && vostok::network_core::operator>=(&left->sent_low_level, &right->sent_low_level)
      && vostok::network_core::operator>=(&left->received_low_level, &right->received_low_level);
}


char __cdecl vostok::network_core::operator>=(
        const vostok::network_core::udp_match_stream_stats *left,
        const vostok::network_core::udp_match_stream_stats *right)
{
  char v3; // [esp+0h] [ebp-14h]
  bool v4; // [esp+4h] [ebp-10h]
  bool v5; // [esp+8h] [ebp-Ch]

  v5 = left->packets.count >= right->packets.count && left->packets.bytes >= right->packets.bytes;
  v3 = 0;
  if ( v5 )
  {
    v4 = left->messages.count >= right->messages.count && left->messages.bytes >= right->messages.bytes;
    if ( v4 && left->data_bytes >= right->data_bytes )
      return 1;
  }
  return v3;
}
