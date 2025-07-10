vostok::network_core::udp_match_packet **__cdecl stlp_std::remove_if<vostok::network_core::udp_match_packet * *,packets_in_list_predicate>(
        vostok::network_core::udp_match_packet **__first,
        vostok::network_core::udp_match_packet **__last,
        packets_in_list_predicate __pred)
{
  int v4; // [esp-4h] [ebp-2Ch] BYREF
  vostok::network_core::udp_match_packet **matched; // [esp+4h] [ebp-24h]
  vostok::network_core::udp_match_packet **v6; // [esp+8h] [ebp-20h]
  vostok::network_core::udp_match_packet **i; // [esp+Ch] [ebp-1Ch]
  unsigned __int16 m_number; // [esp+12h] [ebp-16h] BYREF
  unsigned __int16 *v9; // [esp+14h] [ebp-14h]
  int *v10; // [esp+18h] [ebp-10h]
  vostok::network_core::udp_match_packet **__next; // [esp+24h] [ebp-4h]

  v10 = &v4;
  matched = stlp_std::find_if<vostok::network_core::udp_match_packet * *,packets_in_list_predicate>(
              __first,
              __last,
              __pred);
  if ( matched == __last )
    return matched;
  __next = matched + 1;
  v9 = &m_number;
  m_number = __pred.m_sequence_id.m_number;
  v6 = matched;
  for ( i = matched + 1; i != __last; ++i )
  {
    if ( (*i)->sequence_id.m_number != m_number )
      *v6++ = *i;
  }
  return v6;
}
