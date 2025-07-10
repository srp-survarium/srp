void __cdecl stlp_std::priv::__partial_sort<vostok::network_core::udp_match_packet * *,vostok::network_core::udp_match_packet *,packets_predicate>(
        vostok::network_core::udp_match_packet **__first,
        vostok::network_core::udp_match_packet **__middle,
        vostok::network_core::udp_match_packet **__last,
        vostok::network_core::udp_match_packet **__formal,
        packets_predicate __comp)
{
  survarium::base_project::resolve_link_object *v5; // esi
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v6; // ecx
  vostok::network_core::udp_match_packet **i; // [esp+Ch] [ebp-18h]
  vostok::network_core::udp_match_packet *__val; // [esp+14h] [ebp-10h]
  int v9; // [esp+1Ch] [ebp-8h]
  vostok::network_core::udp_match_packet **__i; // [esp+20h] [ebp-4h]

  stlp_std::make_heap<vostok::network_core::udp_match_packet * *,packets_predicate>(__first, __middle, __comp);
  for ( __i = __middle; __i < __last; ++__i )
  {
    v9 = (int)*__i;
    v5 = stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
           (stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *)*__first,
           (int)*__first);
    if ( stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
           v6,
           v9) < v5 )
    {
      __val = *__i;
      *__i = *__first;
      stlp_std::__adjust_heap<vostok::network_core::udp_match_packet * *,int,vostok::network_core::udp_match_packet *,packets_predicate>(
        __first,
        0,
        __middle - __first,
        __val,
        __comp);
    }
  }
  for ( i = __middle; i - __first > 1; --i )
    stlp_std::pop_heap<vostok::network_core::udp_match_packet * *,packets_predicate>(__first, i, __comp);
}
