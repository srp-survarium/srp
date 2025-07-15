void __thiscall survarium::body_part_parameters::update_affects(
        survarium::body_part_parameters *this,
        stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int> *current_time_in_ms,
        unsigned int a3)
{
  stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int> *v3; // ebx
  vostok::buffer_vector<stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int> > *p_second; // edi
  signed __int32 v5; // esi
  int v6; // eax
  const char *second; // [esp-8h] [ebp-18h]

  v3 = current_time_in_ms;
  p_second = (vostok::buffer_vector<stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int> > *)&current_time_in_ms[4].second;
  v5 = (signed __int32)(current_time_in_ms[5].first - current_time_in_ms[4].second) >> 3;
  while ( --v5 >= 0 )
  {
    v6 = (int)&p_second->m_begin[v5];
    if ( *(_DWORD *)(v6 + 4) <= a3 )
    {
      second = (const char *)v3[14].second;
      current_time_in_ms = &p_second->m_begin[v5];
      survarium::damage_model::notify_on_affect_event(
        a3,
        *(survarium::hit_affects_type_enum *)v6,
        (vostok::intrusive_list<survarium::affect_subscriber,survarium::affect_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)v3[14].first,
        second,
        affect_recalling);
      vostok::buffer_vector<stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int>>::erase(
        p_second,
        &current_time_in_ms);
    }
  }
}
