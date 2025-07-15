const vostok::ai::planning::pddl_world_state_property_impl *__thiscall vostok::ai::planning::goal::get_target_state_property(
        vostok::ai::planning::goal *this,
        unsigned int index)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  return &this->m_target_state._M_impl._M_start[index];
}
