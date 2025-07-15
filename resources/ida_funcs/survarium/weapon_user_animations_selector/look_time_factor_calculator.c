double __thiscall survarium::weapon_user_animations_selector::look_time_factor_calculator(
        survarium::weapon_user_animations_selector *this,
        float animation_length,
        float animation_time_before_time_scale_starts,
        unsigned int time_scale_start_time_in_ms,
        unsigned int current_time_in_ms,
        survarium::game_camera *target_time_in_ms,
        float time_scale)
{
  _BYTE *v7; // eax

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( *v7 )
    survarium::weapon_user_dead_state::finalize(target_time_in_ms);
  return survarium::weapon_user_animations_selector::look_time_factor(this) * animation_length;
}
