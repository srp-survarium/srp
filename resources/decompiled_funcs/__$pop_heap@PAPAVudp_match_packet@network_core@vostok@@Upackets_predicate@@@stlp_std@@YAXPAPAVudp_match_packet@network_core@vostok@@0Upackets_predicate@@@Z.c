void __cdecl stlp_std::pop_heap<vostok::network_core::udp_match_packet * *,packets_predicate>(
        vostok::network_core::udp_match_packet **__first,
        vostok::network_core::udp_match_packet **__last,
        packets_predicate __comp)
{
  vostok::network_core::udp_match_packet *__val; // [esp+0h] [ebp-4h]

  __val = *(__last - 1);
  *(__last - 1) = *__first;
  stlp_std::__adjust_heap<vostok::network_core::udp_match_packet * *,int,vostok::network_core::udp_match_packet *,packets_predicate>(
    __first,
    0,
    __last - 1 - __first,
    __val,
    __comp);
}
