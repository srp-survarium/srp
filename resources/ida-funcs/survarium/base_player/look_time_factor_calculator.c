double __thiscall survarium::base_player::look_time_factor_calculator(
        survarium::base_player *this,
        const float animation_length,
        const float animation_time_before_time_scale_starts,
        const unsigned int time_scale_start_time_in_ms,
        const unsigned int current_time_in_ms,
        const unsigned int target_time_in_ms,
        const float time_scale)
{
  float v8; // [esp+0h] [ebp-4h]

  if ( (float)((float)(*(float *)((char *)&dword_10E6C + (_DWORD)this) + s_bm_current_air_resistance) * 0.5) >= 0.99998999 )
    v8 = FLOAT_0_99998999;
  else
    v8 = (float)(*(float *)((char *)&dword_10E6C + (_DWORD)this) + s_bm_current_air_resistance) * 0.5;
  return v8 * animation_length;
}
