void __thiscall survarium::body_part_parameters::increase_health(
        survarium::body_part_parameters *this,
        unsigned int current_time_in_ms,
        float amount)
{
  float m_health; // xmm0_4
  float m_max_health; // xmm2_4
  float v5; // xmm0_4
  float v6; // xmm1_4
  _DWORD v7[2]; // [esp+0h] [ebp-8h] BYREF

  m_health = this->m_health;
  m_max_health = this->m_max_health;
  if ( m_health != m_max_health )
  {
    v5 = m_health + amount;
    v6 = 0.0;
    if ( v5 > 0.0 )
    {
      if ( m_max_health < v5 )
        v6 = this->m_max_health;
      else
        v6 = v5;
    }
    this->m_health = v6;
    if ( v6 == m_max_health )
    {
      v7[0] = current_time_in_ms;
      v7[1] = this->m_name.m_begin;
      amount = COERCE_FLOAT(v7);
      vostok::intrusive_list<survarium::body_part_events_subscriber,survarium::body_part_events_subscriber *,64,vostok::threading::single_threading_policy,vostok::no_size_policy,vostok::no_debug_policy>::for_each<vostok::intrusive_list<survarium::body_part_events_subscriber,survarium::body_part_events_subscriber *,64,vostok::threading::single_threading_policy,vostok::no_size_policy,vostok::no_debug_policy>::void_predicate_ref<survarium::notify_fully_regenerated_functor>>(
        (vostok::intrusive_list<survarium::body_part_events_subscriber,survarium::body_part_events_subscriber *,64,vostok::threading::single_threading_policy,vostok::no_size_policy,vostok::no_debug_policy> *)this,
        (int)&this->m_events_subscribers,
        (const vostok::intrusive_list<survarium::body_part_events_subscriber,survarium::body_part_events_subscriber *,64,vostok::threading::single_threading_policy,vostok::no_size_policy,vostok::no_debug_policy>::void_predicate_ref<survarium::notify_fully_regenerated_functor> *)&amount);
    }
  }
}
