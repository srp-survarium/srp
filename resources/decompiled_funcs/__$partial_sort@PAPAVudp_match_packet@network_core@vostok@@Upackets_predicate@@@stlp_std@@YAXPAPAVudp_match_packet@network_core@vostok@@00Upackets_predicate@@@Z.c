void __cdecl stlp_std::partial_sort<vostok::network_core::udp_match_packet * *,packets_predicate>(
        vostok::network_core::udp_match_packet **__first,
        vostok::network_core::udp_match_packet **__middle,
        vostok::network_core::udp_match_packet **__last,
        packets_predicate __comp)
{
  stlp_std::priv::__partial_sort<vostok::network_core::udp_match_packet * *,vostok::network_core::udp_match_packet *,packets_predicate>(
    __first,
    __middle,
    __last,
    0,
    __comp);
}
