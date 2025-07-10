unsigned int __thiscall vostok::ai::planning::specified_action::get_cost(vostok::ai::planning::specified_action *this)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  return this->m_prototype->m_cost;
}
