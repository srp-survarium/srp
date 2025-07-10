stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > **__cdecl stlp_std::priv::__median<vostok::network_core::udp_match_packet *,packets_predicate>(
        vostok::network_core::udp_match_packet *const *__a,
        stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > **__b,
        stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > **__c)
{
  survarium::base_project::resolve_link_object *v3; // esi
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v4; // ecx
  survarium::base_project::resolve_link_object *v5; // esi
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v6; // ecx
  survarium::base_project::resolve_link_object *v8; // esi
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v9; // ecx
  survarium::base_project::resolve_link_object *v10; // esi
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v11; // ecx
  survarium::base_project::resolve_link_object *v12; // esi
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v13; // ecx
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v14; // [esp+8h] [ebp-24h]
  int v15; // [esp+10h] [ebp-1Ch]
  int v16; // [esp+18h] [ebp-14h]
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v17; // [esp+20h] [ebp-Ch]
  int v18; // [esp+28h] [ebp-4h]

  v18 = (int)*__a;
  v3 = stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
         *__b,
         (int)*__b);
  if ( stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
         v4,
         v18) >= v3 )
  {
    v15 = (int)*__a;
    v10 = stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
            *__c,
            (int)*__c);
    if ( stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
           v11,
           v15) >= v10 )
    {
      v14 = *__b;
      v12 = stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
              *__c,
              (int)*__c);
      if ( stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
             v13,
             (int)v14) >= v12 )
        return __b;
      else
        return __c;
    }
    else
    {
      return (stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > **)__a;
    }
  }
  else
  {
    v17 = *__b;
    v5 = stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
           *__c,
           (int)*__c);
    if ( stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
           v6,
           (int)v17) >= v5 )
    {
      v16 = (int)*__a;
      v8 = stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
             *__c,
             (int)*__c);
      if ( stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
             v9,
             v16) >= v8 )
        return (stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > **)__a;
      else
        return __c;
    }
    else
    {
      return __b;
    }
  }
}
