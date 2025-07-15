void __thiscall survarium::weapon_dispersion_params::weapon_dispersion_params(
        survarium::weapon_dispersion_params *this,
        vostok::configs::binary_config_value *cfg)
{
  vostok::configs::binary_config_value *v2; // ecx
  vostok::configs::binary_config_value *v3; // ecx
  vostok::configs::binary_config_value *v4; // ecx
  vostok::configs::binary_config_value *v5; // ecx
  vostok::configs::binary_config_value *v6; // ecx
  vostok::configs::binary_config_value *v7; // ecx
  vostok::configs::binary_config_value *v8; // ecx
  vostok::configs::binary_config_value *v9; // ecx

  this->base_dispersion = *(float *)&FLOAT_0_0;
  LODWORD(this->from_the_hip_multiplier) = clear_value;
  LODWORD(this->aim_multiplier) = clear_value;
  LODWORD(this->speed_of_aiming) = clear_value;
  LODWORD(this->one_shoot_dispersion_amount) = clear_value;
  LODWORD(this->reload_dispersion_amount) = clear_value;
  LODWORD(this->growth_speed) = clear_value;
  this->max_dispersion = retry_to_increase_quality_period_sec;
  if ( vostok::configs::binary_config_value::value_exists(cfg, "base_dispersion") )
  {
    vostok::configs::binary_config_value::operator[](cfg, "base_dispersion");
    vostok::configs::binary_config_value::operator float(v2);
    this->base_dispersion = retry_to_increase_quality_period_sec;
  }
  if ( vostok::configs::binary_config_value::value_exists(cfg, "from_the_hip_multiplier") )
  {
    vostok::configs::binary_config_value::operator[](cfg, "from_the_hip_multiplier");
    vostok::configs::binary_config_value::operator float(v3);
    this->from_the_hip_multiplier = retry_to_increase_quality_period_sec;
  }
  if ( vostok::configs::binary_config_value::value_exists(cfg, "aim_multiplier") )
  {
    vostok::configs::binary_config_value::operator[](cfg, "aim_multiplier");
    vostok::configs::binary_config_value::operator float(v4);
    this->aim_multiplier = retry_to_increase_quality_period_sec;
  }
  if ( vostok::configs::binary_config_value::value_exists(cfg, "speed_of_aiming") )
  {
    vostok::configs::binary_config_value::operator[](cfg, "speed_of_aiming");
    vostok::configs::binary_config_value::operator float(v5);
    this->speed_of_aiming = retry_to_increase_quality_period_sec;
  }
  if ( vostok::configs::binary_config_value::value_exists(cfg, "one_shoot_dispersion_amount") )
  {
    vostok::configs::binary_config_value::operator[](cfg, "one_shoot_dispersion_amount");
    vostok::configs::binary_config_value::operator float(v6);
    this->one_shoot_dispersion_amount = retry_to_increase_quality_period_sec;
  }
  if ( vostok::configs::binary_config_value::value_exists(cfg, "reload_dispersion_amount") )
  {
    vostok::configs::binary_config_value::operator[](cfg, "reload_dispersion_amount");
    vostok::configs::binary_config_value::operator float(v7);
    this->reload_dispersion_amount = retry_to_increase_quality_period_sec;
  }
  if ( vostok::configs::binary_config_value::value_exists(cfg, "growth_speed") )
  {
    vostok::configs::binary_config_value::operator[](cfg, "growth_speed");
    vostok::configs::binary_config_value::operator float(v8);
    this->growth_speed = retry_to_increase_quality_period_sec;
  }
  if ( vostok::configs::binary_config_value::value_exists(cfg, "max_dispersion") )
  {
    vostok::configs::binary_config_value::operator[](cfg, "max_dispersion");
    vostok::configs::binary_config_value::operator float(v9);
    this->max_dispersion = retry_to_increase_quality_period_sec;
  }
  this->one_shoot_dispersion_amount = *(float *)&FLOAT_0_0;
}


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
