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
