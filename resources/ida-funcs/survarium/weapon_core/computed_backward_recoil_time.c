double __thiscall survarium::weapon_core::computed_backward_recoil_time(
        survarium::weapon_core *this,
        float animation_length,
        float animation_time_before_time_scale_starts,
        unsigned int time_scale_start_time_in_ms,
        survarium::game_camera *current_time_in_ms,
        unsigned int target_time_in_ms,
        float time_scale)
{
  _BYTE *v7; // eax
  float max; // [esp+Ch] [ebp-20h]
  unsigned int v10; // [esp+10h] [ebp-1Ch]
  const survarium::player_input *v12; // [esp+24h] [ebp-8h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( *v7 )
    survarium::weapon_user_dead_state::finalize(current_time_in_ms);
  survarium::weapon_core::update_recoil(this, target_time_in_ms, time_scale);
  v12 = this->m_user->input(this->m_user);
  if ( (v12->actions_mask & 0x80) != 0 && (v12->actions_mask & 0x8000000) != 0 )
    survarium::weapon_core::update_breath_vibration(this, 1, target_time_in_ms, time_scale);
  else
    survarium::weapon_core::update_breath_vibration(this, 0, target_time_in_ms, time_scale);
  max = *(float *)&clear_value - epsilon;
  *(float *)&v10 = survarium::recoil_calculator::get_back_coeff(&this->m_recoil_calculator);
  return vostok::math::clamp_r<float>((__m128)LODWORD(epsilon), v10, max).m128_f32[0] * animation_length;
}
