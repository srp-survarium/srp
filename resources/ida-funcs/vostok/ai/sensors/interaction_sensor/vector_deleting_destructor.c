vostok::ai::selectors::disturbance_target_selector *__thiscall vostok::ai::sensors::interaction_sensor::`vector deleting destructor'(
        vostok::ai::selectors::disturbance_target_selector *this,
        char a2)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_next);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
