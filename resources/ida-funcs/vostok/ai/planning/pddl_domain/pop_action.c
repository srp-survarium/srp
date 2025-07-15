vostok::ai::planning::generalized_action *__thiscall vostok::ai::planning::pddl_domain::pop_action(
        vostok::ai::planning::pddl_domain *this)
{
  return vostok::intrusive_list<survarium::landing_point,survarium::landing_point *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::pop_front(&this->m_actions);
}
