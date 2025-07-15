const vostok::ai::planning::pddl_world_state_property_impl *__thiscall vostok::ai::planning::specified_action::get_precondition(
        vostok::ai::planning::specified_action *this,
        unsigned int index)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  return &this->m_preconditions._M_impl._M_start[index];
}
