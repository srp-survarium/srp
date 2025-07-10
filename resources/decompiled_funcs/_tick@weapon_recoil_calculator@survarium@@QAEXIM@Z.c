void __thiscall survarium::weapon_recoil_calculator::tick(
        survarium::weapon_recoil_calculator *this,
        unsigned int current_time_in_ms,
        float time_scale)
{
  survarium::weapon_core *m_weapon; // ecx
  double random_angle; // st7
  float v5; // xmm0_4
  long double v6; // st7
  long double v7; // st7
  float v8; // [esp+8h] [ebp-64h]
  float v10; // [esp+28h] [ebp-44h] BYREF
  float v11; // [esp+2Ch] [ebp-40h] BYREF
  float __a; // [esp+30h] [ebp-3Ch] BYREF
  float v13; // [esp+34h] [ebp-38h] BYREF
  float __b; // [esp+38h] [ebp-34h] BYREF
  float total_amount; // [esp+3Ch] [ebp-30h]
  float additive_dispersion_angle_rad; // [esp+40h] [ebp-2Ch]
  float additive_recoil_amount; // [esp+44h] [ebp-28h]
  const survarium::weapon_recoil_params *weapon_params; // [esp+48h] [ebp-24h]
  float total_square_amount; // [esp+4Ch] [ebp-20h]
  float additive_dispersion_amount; // [esp+50h] [ebp-1Ch]
  float additive_dispersion_angle_deg; // [esp+54h] [ebp-18h]
  float force_koef; // [esp+58h] [ebp-14h]
  unsigned int time_delta_in_ms; // [esp+5Ch] [ebp-10h]
  float interpolated_value; // [esp+60h] [ebp-Ch]
  float one_minus_interpolated_value; // [esp+64h] [ebp-8h]
  float dt_sec; // [esp+68h] [ebp-4h]

  if ( this->m_last_time_in_ms )
  {
    if ( this->m_last_time_in_ms < current_time_in_ms && this->m_weapon )
    {
      time_delta_in_ms = current_time_in_ms - this->m_last_time_in_ms;
      this->m_last_time_in_ms = current_time_in_ms;
      dt_sec = (double)time_delta_in_ms * 0.001 * time_scale;
      this->m_time_since_shoot = this->m_time_since_shoot + dt_sec;
      this->m_time_since_last_dispersion_change = this->m_time_since_last_dispersion_change + dt_sec;
      __b = this->m_interpolator.transition_time(&this->m_interpolator);
      this->m_time_since_last_dispersion_change = *stlp_std::min<float>(
                                                     &this->m_time_since_last_dispersion_change,
                                                     &__b);
      if ( this->m_additive_recoil_timer != 0.0 )
      {
        if ( this->m_additive_recoil_timer <= dt_sec )
        {
          m_weapon = this->m_weapon;
          weapon_params = &m_weapon->m_recoil_params;
          random_angle = survarium::weapon_recoil_calculator::get_random_angle(
                           this,
                           m_weapon->m_recoil_params.additive_recoil_angle_range);
          additive_dispersion_angle_deg = random_angle + weapon_params->additive_recoil_min_angle;
          v5 = additive_dispersion_angle_deg;
          vostok::math::deg2rad();
          additive_dispersion_angle_rad = v5;
          force_koef = survarium::weapon_recoil_calculator::get_random_amount(this, 1.0);
          additive_dispersion_amount = (float)(weapon_params->additive_side_recoil * force_koef)
                                     * this->m_player_recoil_multiplier;
          v6 = vostok::math::cos(additive_dispersion_angle_rad);
          this->m_target_vertical_koef = v6 * additive_dispersion_amount + this->m_vertical_koef;
          v7 = vostok::math::sin(additive_dispersion_angle_rad);
          this->m_target_horizontal_koef = v7 * additive_dispersion_amount + this->m_horizontal_koef;
          v8 = vostok::math::sqr<float>(&this->m_target_vertical_koef);
          total_square_amount = v8 + vostok::math::sqr<float>(&this->m_target_horizontal_koef);
          if ( total_square_amount > *(float *)&clear_value )
          {
            total_amount = vostok::math::sqrt(total_square_amount);
            this->m_target_vertical_koef = this->m_target_vertical_koef / total_amount;
            this->m_target_horizontal_koef = this->m_target_horizontal_koef / total_amount;
          }
          additive_recoil_amount = weapon_params->additive_back_recoil * force_koef;
          v13 = *(float *)&FLOAT_0_0;
          __a = this->m_target_recoil_koef - additive_recoil_amount;
          this->m_target_recoil_koef = *stlp_std::max<float>(&__a, &v13);
          this->m_additive_recoil_timer = *(float *)&FLOAT_0_0;
          v11 = *(float *)&FLOAT_0_0;
          v10 = this->m_back_koef - additive_dispersion_amount;
          this->m_back_koef = *stlp_std::max<float>(&v10, &v11);
        }
        else
        {
          this->m_additive_recoil_timer = this->m_additive_recoil_timer - dt_sec;
        }
      }
      interpolated_value = ((double (__thiscall *)(_DWORD, _DWORD))this->m_interpolator.interpolated_value)(
                             &this->m_interpolator,
                             this->m_time_since_last_dispersion_change);
      one_minus_interpolated_value = *(float *)&clear_value - interpolated_value;
      this->m_vertical_koef = (float)(this->m_vertical_koef * (float)(*(float *)&clear_value - interpolated_value))
                            + (float)(this->m_target_vertical_koef * interpolated_value);
      this->m_horizontal_koef = (float)(this->m_horizontal_koef * one_minus_interpolated_value)
                              + (float)(this->m_target_horizontal_koef * interpolated_value);
      this->m_back_koef = (float)(this->m_back_koef * one_minus_interpolated_value)
                        + (float)(this->m_target_recoil_koef * interpolated_value);
      survarium::weapon_recoil_calculator::process_compensation(this, dt_sec);
    }
  }
  else
  {
    this->m_last_time_in_ms = current_time_in_ms;
  }
}
