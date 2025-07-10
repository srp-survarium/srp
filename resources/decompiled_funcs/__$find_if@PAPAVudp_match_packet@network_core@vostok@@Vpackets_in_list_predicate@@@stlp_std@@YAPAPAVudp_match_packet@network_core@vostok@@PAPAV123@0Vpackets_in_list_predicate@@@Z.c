vostok::network_core::udp_match_packet **__cdecl stlp_std::find_if<vostok::network_core::udp_match_packet * *,packets_in_list_predicate>(
        vostok::network_core::udp_match_packet **__first,
        vostok::network_core::udp_match_packet **__last,
        packets_in_list_predicate __pred)
{
  _DWORD v4[6]; // [esp-8h] [ebp-1Ch] BYREF
  stlp_std::random_access_iterator_tag __formal; // [esp+13h] [ebp-1h] BYREF

  v4[4] = v4;
  return stlp_std::priv::__find_if<vostok::network_core::udp_match_packet * *,packets_in_list_predicate>(
           __first,
           __last,
           __pred,
           &__formal);
}
