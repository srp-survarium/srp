bool __thiscall survarium::weapon_core::must_chamber_a_round_and_animation_ended_predicate(
        survarium::weapon_core *this)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  return survarium::weapon_core::must_chamber_a_round_predicate(this)
      && survarium::weapon_core_base_state::has_animation_ended(
           (survarium::weapon_core_base_state *)this->m_logic->m_current_state,
           (int)this->m_logic->m_current_state);
}
