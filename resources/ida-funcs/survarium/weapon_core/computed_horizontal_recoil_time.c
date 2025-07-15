double __thiscall survarium::weapon_core::computed_horizontal_recoil_time(
        survarium::weapon_core *this,
        const float animation_length,
        const float animation_time_before_time_scale_starts,
        const unsigned int time_scale_start_time_in_ms,
        const unsigned int current_time_in_ms,
        unsigned int target_time_in_ms,
        const float __formal)
{
  survarium::base_player *m_user; // eax

  m_user = this->m_user;
  if ( !m_user || !m_user->m_is_alive )
    return 0.0;
  survarium::weapon_core::update_recoil(this, target_time_in_ms);
  return survarium::weapon_core::horizontal_recoil_value(this, target_time_in_ms) * animation_length;
}
