void __cdecl stlp_std::__adjust_heap<vostok::network_core::udp_match_packet * *,int,vostok::network_core::udp_match_packet *,packets_predicate>(
        vostok::network_core::udp_match_packet **__first,
        int __holeIndex,
        int __len,
        vostok::network_core::udp_match_packet *__val,
        packets_predicate __comp)
{
  survarium::base_project::resolve_link_object *v5; // esi
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v6; // ecx
  vostok::network_core::udp_match_packet *v7; // [esp+10h] [ebp-Ch]
  int __secondChild; // [esp+14h] [ebp-8h]
  int __topIndex; // [esp+18h] [ebp-4h]

  __topIndex = __holeIndex;
  for ( __secondChild = 2 * __holeIndex + 2; __secondChild < __len; __secondChild = 2 * __secondChild + 2 )
  {
    v7 = __first[__secondChild];
    v5 = stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
           (stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *)__secondChild,
           (int)__first[__secondChild - 1]);
    if ( stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
           v6,
           (int)v7) < v5 )
      --__secondChild;
    __first[__holeIndex] = __first[__secondChild];
    __holeIndex = __secondChild;
  }
  if ( __secondChild == __len )
  {
    __first[__holeIndex] = __first[__secondChild - 1];
    __holeIndex = __secondChild - 1;
  }
  stlp_std::__push_heap<vostok::network_core::udp_match_packet * *,int,vostok::network_core::udp_match_packet *,packets_predicate>(
    __first,
    __holeIndex,
    __topIndex,
    __val,
    __comp);
}
