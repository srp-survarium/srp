void __cdecl stlp_std::__push_heap<vostok::network_core::udp_match_packet * *,int,vostok::network_core::udp_match_packet *,packets_predicate>(
        vostok::network_core::udp_match_packet **__first,
        int __holeIndex,
        int __topIndex,
        vostok::network_core::udp_match_packet *__val)
{
  survarium::base_project::resolve_link_object *v4; // esi
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v5; // ecx
  vostok::network_core::udp_match_packet *v6; // [esp+4h] [ebp-8h]
  int __parent; // [esp+8h] [ebp-4h]

  for ( __parent = (__holeIndex - 1) / 2; __holeIndex > __topIndex; __parent = (__parent - 1) / 2 )
  {
    v6 = __first[__parent];
    v4 = stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
           (stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *)__parent,
           (int)__val);
    if ( stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
           v5,
           (int)v6) >= v4 )
      break;
    __first[__holeIndex] = __first[__parent];
    __holeIndex = __parent;
  }
  __first[__holeIndex] = __val;
}
