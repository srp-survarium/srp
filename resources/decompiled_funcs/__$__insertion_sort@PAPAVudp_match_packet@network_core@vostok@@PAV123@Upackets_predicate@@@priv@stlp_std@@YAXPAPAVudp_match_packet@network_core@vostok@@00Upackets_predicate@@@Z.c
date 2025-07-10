void __cdecl stlp_std::priv::__insertion_sort<vostok::network_core::udp_match_packet * *,vostok::network_core::udp_match_packet *,packets_predicate>(
        vostok::network_core::udp_match_packet **__first,
        vostok::network_core::udp_match_packet **__last,
        vostok::network_core::udp_match_packet **__formal,
        packets_predicate __comp)
{
  survarium::base_project::resolve_link_object *v4; // esi
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v5; // ecx
  vostok::network_core::udp_match_packet *__val; // [esp+8h] [ebp-18h]
  vostok::network_core::udp_match_packet **__i; // [esp+1Ch] [ebp-4h]

  if ( __first != __last )
  {
    for ( __i = __first + 1; __i != __last; ++__i )
    {
      __val = *__i;
      v4 = stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
             (stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *)__first,
             (int)*__first);
      if ( stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
             v5,
             (int)__val) >= v4 )
      {
        stlp_std::priv::__unguarded_linear_insert<vostok::network_core::udp_match_packet * *,vostok::network_core::udp_match_packet *,packets_predicate>(
          __i,
          __val,
          __comp);
      }
      else
      {
        stlp_std::copy_backward<stlp_std::pair<vostok::ai::weapon const *,unsigned int> *,stlp_std::pair<vostok::ai::weapon const *,unsigned int> *>(
          (vostok::particle::curve_point<vostok::math::float4_pod> *)__first,
          (vostok::particle::curve_point<vostok::math::float4_pod> *)__i,
          (vostok::particle::curve_point<vostok::math::float4_pod> *)(__i + 1));
        *__first = __val;
      }
    }
  }
}
