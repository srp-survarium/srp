void __thiscall survarium::damage_model::add_body_part(
        survarium::damage_model *this,
        survarium::game_camera *new_body_part)
{
  vostok::intrusive_list<vostok::ai::planning::generalized_action,vostok::ai::planning::generalized_action *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
    (vostok::intrusive_list<vostok::ai::planning::generalized_action,vostok::ai::planning::generalized_action *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)&this->m_body_parts,
    new_body_part,
    0);
}
