double __thiscall survarium::weapon_core::computed_horizontal_recoil_time(
        survarium::weapon_core *this,
        float animation_length,
        float animation_time_before_time_scale_starts,
        unsigned int time_scale_start_time_in_ms,
        survarium::game_camera *current_time_in_ms,
        unsigned int target_time_in_ms,
        float time_scale)
{
  _BYTE *v7; // eax
  const survarium::player_input *v10; // [esp+28h] [ebp-8h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( *v7 )
    survarium::weapon_user_dead_state::finalize(current_time_in_ms);
  survarium::weapon_core::update_recoil(this, target_time_in_ms, time_scale);
  v10 = this->m_user->input(this->m_user);
  if ( (v10->actions_mask & 0x80) != 0 && (v10->actions_mask & 0x8000000) != 0 )
    survarium::weapon_core::update_breath_vibration(this, 1, target_time_in_ms, time_scale);
  else
    survarium::weapon_core::update_breath_vibration(this, 0, target_time_in_ms, time_scale);
  return survarium::weapon_core::horizontal_recoil_value(this) * animation_length;
}
