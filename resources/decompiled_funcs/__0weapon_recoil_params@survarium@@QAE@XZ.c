void __thiscall survarium::weapon_recoil_params::weapon_recoil_params(survarium::weapon_recoil_params *this)
{
  this->first_shoot_side_recoil = *(float *)&FLOAT_0_0;
  this->shoot_side_recoil = *(float *)&FLOAT_0_0;
  this->first_shoot_back_recoil = *(float *)&FLOAT_0_0;
  this->shoot_back_recoil = *(float *)&FLOAT_0_0;
  this->shoot_recoil_min_angle = *(float *)&FLOAT_0_0;
  this->shoot_recoil_angle_range = *(float *)&FLOAT_0_0;
  this->additive_recoil_time = epsilon_3_6;
  this->additive_side_recoil = *(float *)&FLOAT_0_0;
  this->additive_recoil_min_angle = *(float *)&FLOAT_0_0;
  this->additive_recoil_angle_range = *(float *)&FLOAT_0_0;
  this->side_compensation_speed = *(float *)&FLOAT_0_0;
  this->back_compensation_speed = *(float *)&FLOAT_0_0;
}
