void __thiscall vostok::ai::planning::pddl_domain::add_action(
        vostok::ai::planning::pddl_domain *this,
        survarium::game_camera *action_to_be_added)
{
  vostok::intrusive_list<vostok::ai::planning::generalized_action,vostok::ai::planning::generalized_action *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
    &this->m_actions,
    action_to_be_added,
    0);
}
