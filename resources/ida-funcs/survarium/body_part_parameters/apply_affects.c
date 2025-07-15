void __thiscall survarium::body_part_parameters::apply_affects(
        survarium::body_part_parameters *this,
        const survarium::affects_threshold *threshold_reached,
        unsigned int current_time_in_ms)
{
  vostok::intrusive_list<survarium::affects_threshold,survarium::affects_threshold *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *p_m_thresholds; // eax
  vostok::intrusive_list<survarium::damage_protector,survarium::damage_protector *,104,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *v5; // ecx
  survarium::hit_affects_type_enum *v6; // esi
  survarium::hit_affects_type_enum v7; // edi
  survarium::hit_affects_type_enum v8; // esi
  unsigned int v9; // eax
  _DWORD v10[2]; // [esp+Ch] [ebp-1Ch] BYREF
  char v11; // [esp+14h] [ebp-14h]
  stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int> value; // [esp+18h] [ebp-10h] BYREF
  survarium::hit_affects_type_enum *v13; // [esp+20h] [ebp-8h]
  vostok::intrusive_list<survarium::damage_protector,survarium::damage_protector *,104,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::void_predicate_ref<survarium::protect_affect_predicate> pred; // [esp+24h] [ebp-4h] BYREF
  survarium::hit_affects_type_enum *v15; // [esp+30h] [ebp+8h]

  p_m_thresholds = &this->m_thresholds;
  v5 = (vostok::intrusive_list<survarium::damage_protector,survarium::damage_protector *,104,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)(&this->m_thresholds.m_size + *(_DWORD *)&this->m_hit_types.gap4);
  v13 = (survarium::hit_affects_type_enum *)v5;
  v6 = (survarium::hit_affects_type_enum *)p_m_thresholds;
  v15 = (survarium::hit_affects_type_enum *)p_m_thresholds;
  if ( p_m_thresholds != (vostok::intrusive_list<survarium::affects_threshold,survarium::affects_threshold *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)v5 )
  {
    do
    {
      v7 = *v6;
      if ( !survarium::body_part_parameters::is_affect_applied(
              (survarium::body_part_parameters *)v5,
              (int)threshold_reached,
              *v6) )
      {
        v10[0] = threshold_reached[5].m_effect.m_object;
        pred.m_predicate_ref = (survarium::protect_affect_predicate *)v10;
        v10[1] = v7;
        v11 = 0;
        vostok::intrusive_list<survarium::damage_protector,survarium::damage_protector *,104,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::for_each<vostok::intrusive_list<survarium::damage_protector,survarium::damage_protector *,104,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::void_predicate_ref<survarium::protect_affect_predicate>>(
          v5,
          (int)&threshold_reached[8].m_effect,
          &pred);
        if ( !v11 )
        {
          survarium::damage_model::notify_on_affect_event(
            current_time_in_ms,
            *v6,
            (vostok::intrusive_list<survarium::affect_subscriber,survarium::affect_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)threshold_reached[5].m_effect_emitter.m_object,
            (const char *)threshold_reached[5].m_effect.m_object,
            affect_applying);
          v8 = *v6;
          v9 = current_time_in_ms
             + 1000
             * *((_DWORD *)&threshold_reached[5].m_effect_emitter.m_object[6].m_parent_resources.m_thread_id + v8);
          value.first = v8;
          value.second = v9;
          vostok::buffer_vector<stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int>>::push_back(
            (vostok::buffer_vector<stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int> > *)&threshold_reached[1].m_effect,
            &value);
          v6 = v15;
        }
      }
      v15 = ++v6;
    }
    while ( v6 != v13 );
  }
}
