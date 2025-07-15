vostok::ai::planning::generalized_action *__thiscall survarium::damage_model::pop_body_part(
        survarium::damage_model *this)
{
  if ( this->m_body_parts.m_first )
    return vostok::intrusive_list<survarium::landing_point,survarium::landing_point *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::pop_front((vostok::intrusive_list<vostok::ai::planning::generalized_action,vostok::ai::planning::generalized_action *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)&this->m_body_parts);
  else
    return 0;
}
