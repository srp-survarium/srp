void __userpurge survarium::character_recoil_params::load(
        survarium::character_recoil_params *this@<ecx>,
        float a2@<xmm0>,
        vostok::configs::binary_config_value *cfg)
{
  vostok::configs::binary_config_value *v3; // ecx
  vostok::configs::binary_config_value *v4; // ecx
  vostok::configs::binary_config_value *v5; // ecx
  vostok::configs::binary_config_value *v6; // ecx

  if ( vostok::configs::binary_config_value::value_exists(cfg, "crouch_multiplier") )
  {
    vostok::configs::binary_config_value::operator[](cfg, "crouch_multiplier");
    vostok::configs::binary_config_value::operator float(v3);
    this->crouch_multiplier = a2;
  }
  if ( vostok::configs::binary_config_value::value_exists(cfg, "stand_multiplier") )
  {
    vostok::configs::binary_config_value::operator[](cfg, "stand_multiplier");
    vostok::configs::binary_config_value::operator float(v4);
    this->stand_multiplier = a2;
  }
  if ( vostok::configs::binary_config_value::value_exists(cfg, "aimed_crouch_multiplier") )
  {
    vostok::configs::binary_config_value::operator[](cfg, "aimed_crouch_multiplier");
    vostok::configs::binary_config_value::operator float(v5);
    this->aimed_crouch_multiplier = a2;
  }
  if ( vostok::configs::binary_config_value::value_exists(cfg, "aimed_stand_multiplier") )
  {
    vostok::configs::binary_config_value::operator[](cfg, "aimed_stand_multiplier");
    vostok::configs::binary_config_value::operator float(v6);
    this->aimed_stand_multiplier = a2;
  }
}
