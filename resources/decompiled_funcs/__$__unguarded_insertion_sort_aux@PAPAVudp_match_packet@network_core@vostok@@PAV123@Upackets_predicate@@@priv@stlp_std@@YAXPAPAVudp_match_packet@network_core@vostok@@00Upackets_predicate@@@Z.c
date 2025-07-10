void __cdecl stlp_std::priv::__unguarded_insertion_sort_aux<vostok::network_core::udp_match_packet * *,vostok::network_core::udp_match_packet *,packets_predicate>(
        vostok::network_core::udp_match_packet **__first,
        vostok::network_core::udp_match_packet **__last,
        vostok::network_core::udp_match_packet **__formal,
        packets_predicate __comp)
{
  while ( __first != __last )
  {
    stlp_std::priv::__unguarded_linear_insert<vostok::network_core::udp_match_packet * *,vostok::network_core::udp_match_packet *,packets_predicate>(
      __first,
      *__first,
      __comp);
    ++__first;
  }
}
