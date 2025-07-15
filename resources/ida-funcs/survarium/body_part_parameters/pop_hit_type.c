vostok::ai::planning::generalized_action *__thiscall survarium::body_part_parameters::pop_hit_type(
        survarium::body_part_parameters *this)
{
  if ( this->m_hit_types.m_first )
    return vostok::intrusive_list<survarium::landing_point,survarium::landing_point *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::pop_front((vostok::intrusive_list<vostok::ai::planning::generalized_action,vostok::ai::planning::generalized_action *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)&this->m_hit_types);
  else
    return 0;
}
