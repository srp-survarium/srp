void __thiscall survarium::weapon_recoil_calculator::fire(survarium::weapon_recoil_calculator *this)
{
  survarium::weapon_core *m_weapon; // ecx
  float first_shoot_back_recoil; // [esp+4h] [ebp-48h]
  float v3; // [esp+8h] [ebp-44h]
  float first_shoot_side_recoil; // [esp+Ch] [ebp-40h]
  bool v5; // [esp+13h] [ebp-39h]
  float __a; // [esp+20h] [ebp-2Ch] BYREF
  const vostok::math::float4x4 *__b; // [esp+24h] [ebp-28h] BYREF
  float total_amount; // [esp+28h] [ebp-24h]
  bool first_shoot; // [esp+2Fh] [ebp-1Dh]
  float recoil_angle_rad; // [esp+30h] [ebp-1Ch]
  const survarium::weapon_recoil_params *weapon_params; // [esp+34h] [ebp-18h]
  float total_square_amount; // [esp+38h] [ebp-14h]
  float force_koef; // [esp+3Ch] [ebp-10h]
  float recoil; // [esp+40h] [ebp-Ch]
  float recoil_angle_deg; // [esp+44h] [ebp-8h]
  float recoil_amount; // [esp+48h] [ebp-4h]

  m_weapon = this->m_weapon;
  weapon_params = &m_weapon->m_recoil_params;
  recoil_angle_deg = survarium::weapon_recoil_calculator::get_random_angle(
                       this,
                       m_weapon->m_recoil_params.shoot_recoil_angle_range)
                   + m_weapon->m_recoil_params.shoot_recoil_min_angle;
  force_koef = survarium::weapon_recoil_calculator::get_random_amount(this, 1.0);
  v5 = this->m_target_vertical_koef == 0.0 && this->m_target_horizontal_koef == 0.0;
  first_shoot = v5;
  if ( v5 )
    first_shoot_side_recoil = weapon_params->first_shoot_side_recoil;
  else
    first_shoot_side_recoil = weapon_params->shoot_side_recoil;
  recoil = (float)(first_shoot_side_recoil * force_koef) * this->m_player_recoil_multiplier;
  vostok::math::deg2rad();
  recoil_angle_rad = recoil_angle_deg;
  this->m_target_vertical_koef = vostok::math::cos(recoil_angle_deg) * recoil + this->m_vertical_koef;
  this->m_target_horizontal_koef = vostok::math::sin(recoil_angle_rad) * recoil + this->m_horizontal_koef;
  v3 = vostok::math::sqr<float>(&this->m_target_vertical_koef);
  total_square_amount = v3 + vostok::math::sqr<float>(&this->m_target_horizontal_koef);
  if ( total_square_amount > *(float *)&clear_value )
  {
    total_amount = vostok::math::sqrt(total_square_amount);
    this->m_target_vertical_koef = this->m_target_vertical_koef / total_amount;
    this->m_target_horizontal_koef = this->m_target_horizontal_koef / total_amount;
  }
  if ( first_shoot )
    first_shoot_back_recoil = weapon_params->first_shoot_back_recoil;
  else
    first_shoot_back_recoil = weapon_params->shoot_back_recoil;
  recoil_amount = (float)(first_shoot_back_recoil * force_koef) * this->m_player_recoil_multiplier;
  __b = clear_value;
  __a = this->m_target_recoil_koef + recoil_amount;
  this->m_target_recoil_koef = *stlp_std::min<float>(&__a, (const float *)&__b);
  this->m_time_since_last_dispersion_change = *(float *)&FLOAT_0_0;
  this->m_time_since_shoot = *(float *)&FLOAT_0_0;
  this->m_additive_recoil_timer = weapon_params->additive_recoil_time;
}
