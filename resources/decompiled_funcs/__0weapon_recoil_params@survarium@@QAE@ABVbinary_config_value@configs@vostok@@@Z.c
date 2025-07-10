void __thiscall survarium::weapon_recoil_params::weapon_recoil_params(
        survarium::weapon_recoil_params *this,
        vostok::configs::binary_config_value *cfg)
{
  float v2; // xmm0_4
  vostok::configs::binary_config_value *v3; // ecx
  vostok::configs::binary_config_value *v4; // ecx
  vostok::configs::binary_config_value *v5; // ecx
  vostok::configs::binary_config_value *v6; // ecx
  vostok::configs::binary_config_value *v7; // ecx
  vostok::configs::binary_config_value *v8; // ecx
  vostok::configs::binary_config_value *v9; // ecx
  vostok::configs::binary_config_value *v10; // ecx
  vostok::configs::binary_config_value *v11; // ecx
  vostok::configs::binary_config_value *v12; // ecx
  vostok::configs::binary_config_value *v13; // ecx
  vostok::configs::binary_config_value *v14; // ecx
  vostok::configs::binary_config_value *v15; // ecx

  this->first_shoot_side_recoil = *(float *)&FLOAT_0_0;
  this->shoot_side_recoil = *(float *)&FLOAT_0_0;
  this->shoot_recoil_min_angle = *(float *)&FLOAT_0_0;
  this->shoot_recoil_angle_range = *(float *)&FLOAT_0_0;
  this->additive_recoil_time = epsilon_3_6;
  this->additive_side_recoil = *(float *)&FLOAT_0_0;
  this->additive_recoil_min_angle = *(float *)&FLOAT_0_0;
  this->additive_recoil_angle_range = *(float *)&FLOAT_0_0;
  v2 = *(float *)&FLOAT_0_0;
  this->side_compensation_speed = *(float *)&FLOAT_0_0;
  if ( vostok::configs::binary_config_value::value_exists(cfg, "first_shoot_side_recoil") )
  {
    vostok::configs::binary_config_value::operator[](cfg, "first_shoot_side_recoil");
    vostok::configs::binary_config_value::operator float(v3);
    this->first_shoot_side_recoil = *(float *)&FLOAT_0_0;
  }
  if ( vostok::configs::binary_config_value::value_exists(cfg, "shoot_side_recoil") )
  {
    vostok::configs::binary_config_value::operator[](cfg, "shoot_side_recoil");
    vostok::configs::binary_config_value::operator float(v4);
    this->shoot_side_recoil = *(float *)&FLOAT_0_0;
  }
  if ( vostok::configs::binary_config_value::value_exists(cfg, "first_shoot_back_recoil") )
  {
    vostok::configs::binary_config_value::operator[](cfg, "first_shoot_back_recoil");
    vostok::configs::binary_config_value::operator float(v5);
    this->first_shoot_back_recoil = *(float *)&FLOAT_0_0;
  }
  if ( vostok::configs::binary_config_value::value_exists(cfg, "shoot_back_recoil") )
  {
    vostok::configs::binary_config_value::operator[](cfg, "shoot_back_recoil");
    vostok::configs::binary_config_value::operator float(v6);
    this->shoot_back_recoil = *(float *)&FLOAT_0_0;
  }
  if ( vostok::configs::binary_config_value::value_exists(cfg, "shoot_recoil_min_angle")
    && vostok::configs::binary_config_value::value_exists(cfg, "shoot_recoil_max_angle") )
  {
    vostok::configs::binary_config_value::operator[](cfg, "shoot_recoil_min_angle");
    vostok::configs::binary_config_value::operator float(v7);
    this->shoot_recoil_min_angle = *(float *)&FLOAT_0_0;
    vostok::configs::binary_config_value::operator[](cfg, "shoot_recoil_max_angle");
    vostok::configs::binary_config_value::operator float(v8);
    v2 = 0.0 - this->shoot_recoil_min_angle;
    this->shoot_recoil_angle_range = v2;
  }
  if ( vostok::configs::binary_config_value::value_exists(cfg, "additive_recoil_time") )
  {
    vostok::configs::binary_config_value::operator[](cfg, "additive_recoil_time");
    vostok::configs::binary_config_value::operator float(v9);
    this->additive_recoil_time = v2;
  }
  if ( vostok::configs::binary_config_value::value_exists(cfg, "additive_side_recoil") )
  {
    vostok::configs::binary_config_value::operator[](cfg, "additive_side_recoil");
    vostok::configs::binary_config_value::operator float(v10);
    this->additive_side_recoil = v2;
  }
  if ( vostok::configs::binary_config_value::value_exists(cfg, "additive_back_recoil") )
  {
    vostok::configs::binary_config_value::operator[](cfg, "additive_back_recoil");
    vostok::configs::binary_config_value::operator float(v11);
    this->additive_back_recoil = v2;
  }
  if ( vostok::configs::binary_config_value::value_exists(cfg, "additive_recoil_min_angle")
    && vostok::configs::binary_config_value::value_exists(cfg, "additive_recoil_max_angle") )
  {
    vostok::configs::binary_config_value::operator[](cfg, "additive_recoil_min_angle");
    vostok::configs::binary_config_value::operator float(v12);
    this->additive_recoil_min_angle = v2;
    vostok::configs::binary_config_value::operator[](cfg, "additive_recoil_max_angle");
    vostok::configs::binary_config_value::operator float(v13);
    v2 = v2 - this->additive_recoil_min_angle;
    this->additive_recoil_angle_range = v2;
  }
  if ( vostok::configs::binary_config_value::value_exists(cfg, "side_compensation_speed") )
  {
    vostok::configs::binary_config_value::operator[](cfg, "side_compensation_speed");
    vostok::configs::binary_config_value::operator float(v14);
    this->side_compensation_speed = v2;
  }
  if ( vostok::configs::binary_config_value::value_exists(cfg, "back_compensation_speed") )
  {
    vostok::configs::binary_config_value::operator[](cfg, "back_compensation_speed");
    vostok::configs::binary_config_value::operator float(v15);
    this->back_compensation_speed = v2;
  }
}
