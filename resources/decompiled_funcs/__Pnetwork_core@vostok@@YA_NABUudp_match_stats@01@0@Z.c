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
