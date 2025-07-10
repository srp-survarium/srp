void __thiscall survarium::weapon_recoil_calculator::process_compensation(
        survarium::weapon_recoil_calculator *this,
        float dt_sec)
{
  float v2; // xmm0_4
  float v3; // xmm0_4
  float v4; // xmm0_4
  float v5; // [esp+4h] [ebp-40h]
  float v6; // [esp+8h] [ebp-3Ch]
  float v7; // [esp+Ch] [ebp-38h]
  float v8; // [esp+14h] [ebp-30h]
  survarium::weapon_recoil_params *weapon_params; // [esp+30h] [ebp-14h]
  float additive_compensation_speed; // [esp+34h] [ebp-10h]
  float recoil_compensation_amount; // [esp+3Ch] [ebp-8h]
  float additive_recoil_compensation_speed; // [esp+40h] [ebp-4h]

  weapon_params = &this->m_weapon->m_recoil_params;
  v8 = vostok::math::sqr<float>(&this->m_target_vertical_koef);
  v2 = vostok::math::sqr<float>(&this->m_target_horizontal_koef);
  additive_compensation_speed = vostok::math::sqrt(v8 + v2);
  v3 = (float)((float)(weapon_params->side_compensation_speed + additive_compensation_speed) * dt_sec)
     * this->m_player_compensation_multiplier;
  vostok::math::abs();
  this->m_target_vertical_koef = *(float *)&FLOAT_0_0;
  vostok::math::abs();
  if ( v3 >= 0.0 )
    v7 = *(float *)&FLOAT_0_0;
  else
    v7 = this->m_target_horizontal_koef - (float)((float)vostok::math::sign(this->m_target_horizontal_koef) * v3);
  this->m_target_horizontal_koef = v7;
  v6 = vostok::math::sqr<float>(&this->m_target_recoil_koef);
  v4 = vostok::math::sqr<float>(&this->m_target_recoil_koef);
  additive_recoil_compensation_speed = vostok::math::sqrt(v6 + v4);
  recoil_compensation_amount = (float)((float)(weapon_params->back_compensation_speed
                                             + additive_recoil_compensation_speed)
                                     * dt_sec)
                             * this->m_player_compensation_multiplier;
  if ( this->m_target_recoil_koef <= recoil_compensation_amount )
    v5 = *(float *)&FLOAT_0_0;
  else
    v5 = this->m_target_recoil_koef - recoil_compensation_amount;
  this->m_target_recoil_koef = v5;
}
