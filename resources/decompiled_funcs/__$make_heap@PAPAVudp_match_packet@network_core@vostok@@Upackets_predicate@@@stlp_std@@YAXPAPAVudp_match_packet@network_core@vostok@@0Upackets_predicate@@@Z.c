void __cdecl stlp_std::make_heap<vostok::network_core::udp_match_packet * *,packets_predicate>(
        vostok::network_core::udp_match_packet **__first,
        vostok::network_core::udp_match_packet **__last,
        packets_predicate __comp)
{
  int __holeIndex; // [esp+0h] [ebp-8h]

  if ( __last - __first >= 2 )
  {
    for ( __holeIndex = (__last - __first - 2) / 2; ; --__holeIndex )
    {
      stlp_std::__adjust_heap<vostok::network_core::udp_match_packet * *,int,vostok::network_core::udp_match_packet *,packets_predicate>(
        __first,
        __holeIndex,
        __last - __first,
        __first[__holeIndex],
        __comp);
      if ( !__holeIndex )
        break;
    }
  }
}
