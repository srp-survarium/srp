void __thiscall survarium::body_part_parameters::add_threshold(
        survarium::body_part_parameters *this,
        survarium::game_camera *new_threshold)
{
  vostok::intrusive_list<vostok::ai::planning::generalized_action,vostok::ai::planning::generalized_action *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
    (vostok::intrusive_list<vostok::ai::planning::generalized_action,vostok::ai::planning::generalized_action *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)&this->m_thresholds,
    new_threshold,
    0);
}
