void __thiscall survarium::weapon_dispersion_params::weapon_dispersion_params(
        survarium::weapon_dispersion_params *this)
{
  this->base_dispersion = *(float *)&FLOAT_0_0;
  LODWORD(this->from_the_hip_multiplier) = clear_value;
  LODWORD(this->aim_multiplier) = clear_value;
  LODWORD(this->speed_of_aiming) = clear_value;
  LODWORD(this->one_shoot_dispersion_amount) = clear_value;
  LODWORD(this->reload_dispersion_amount) = clear_value;
  LODWORD(this->growth_speed) = clear_value;
  this->max_dispersion = retry_to_increase_quality_period_sec;
}
