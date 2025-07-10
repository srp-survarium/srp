void __cdecl stlp_std::sort<vostok::network_core::udp_match_packet * *,packets_predicate>(
        vostok::network_core::udp_match_packet **__first,
        vostok::network_core::udp_match_packet **__last,
        packets_predicate __comp)
{
  int v3; // eax

  if ( __first != __last )
  {
    v3 = stlp_std::priv::__lg<int>(__last - __first);
    stlp_std::priv::__introsort_loop<vostok::network_core::udp_match_packet * *,vostok::network_core::udp_match_packet *,int,packets_predicate>(
      __first,
      __last,
      0,
      2 * v3,
      __comp);
    stlp_std::priv::__final_insertion_sort<vostok::network_core::udp_match_packet * *,packets_predicate>(
      __first,
      __last,
      __comp);
  }
}
