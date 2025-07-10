void __cdecl stlp_std::priv::__introsort_loop<vostok::network_core::udp_match_packet * *,vostok::network_core::udp_match_packet *,int,packets_predicate>(
        vostok::network_core::udp_match_packet **__first,
        vostok::network_core::udp_match_packet **__last,
        vostok::network_core::udp_match_packet **__formal,
        int __depth_limit,
        packets_predicate __comp)
{
  vostok::network_core::udp_match_packet **matched; // eax
  vostok::network_core::udp_match_packet **__cut; // [esp+28h] [ebp-4h]

  while ( __last - __first > 16 )
  {
    if ( !__depth_limit )
    {
      stlp_std::partial_sort<vostok::network_core::udp_match_packet * *,packets_predicate>(
        __first,
        __last,
        __last,
        __comp);
      return;
    }
    --__depth_limit;
    matched = (vostok::network_core::udp_match_packet **)stlp_std::priv::__median<vostok::network_core::udp_match_packet *,packets_predicate>(
                                                           __first,
                                                           &__first[(__last - __first) / 2],
                                                           __last - 1,
                                                           __comp);
    __cut = stlp_std::priv::__unguarded_partition<vostok::network_core::udp_match_packet * *,vostok::network_core::udp_match_packet *,packets_predicate>(
              __first,
              __last,
              *matched,
              __comp);
    stlp_std::priv::__introsort_loop<vostok::network_core::udp_match_packet * *,vostok::network_core::udp_match_packet *,int,packets_predicate>(
      __cut,
      __last,
      0,
      __depth_limit,
      __comp);
    __last = __cut;
  }
}
