void __thiscall survarium::body_part_parameters::add_hit_type(
        survarium::body_part_parameters *this,
        survarium::game_camera *new_hit_type)
{
  vostok::intrusive_list<vostok::ai::planning::generalized_action,vostok::ai::planning::generalized_action *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
    (vostok::intrusive_list<vostok::ai::planning::generalized_action,vostok::ai::planning::generalized_action *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)&this->m_hit_types,
    new_hit_type,
    0);
}
