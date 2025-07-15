const vostok::ai::planning::pddl_world_state_property_impl *__thiscall vostok::ai::vector<vostok::ai::planning::pddl_world_state_property_impl>::operator[](
        vostok::ai::vector<vostok::ai::planning::pddl_world_state_property_impl> *this,
        unsigned int index)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  return &this->_M_impl._M_start[index];
}
