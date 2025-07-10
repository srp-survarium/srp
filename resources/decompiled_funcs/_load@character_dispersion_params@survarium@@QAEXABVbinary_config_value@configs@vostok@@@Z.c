void __userpurge survarium::character_dispersion_params::load(
        survarium::character_dispersion_params *this@<ecx>,
        float a2@<xmm0>,
        vostok::configs::binary_config_value *cfg)
{
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
  vostok::configs::binary_config_value *v16; // ecx

  if ( vostok::configs::binary_config_value::value_exists(cfg, "idle_multiplier") )
  {
    vostok::configs::binary_config_value::operator[](cfg, "idle_multiplier");
    vostok::configs::binary_config_value::operator float(v3);
    this->idle_multiplier = a2;
  }
  if ( vostok::configs::binary_config_value::value_exists(cfg, "idle_aim_multiplier") )
  {
    vostok::configs::binary_config_value::operator[](cfg, "idle_aim_multiplier");
    vostok::configs::binary_config_value::operator float(v4);
    this->idle_aim_multiplier = a2;
  }
  if ( vostok::configs::binary_config_value::value_exists(cfg, "walk_multiplier") )
  {
    vostok::configs::binary_config_value::operator[](cfg, "walk_multiplier");
    vostok::configs::binary_config_value::operator float(v5);
    this->walk_multiplier = a2;
  }
  if ( vostok::configs::binary_config_value::value_exists(cfg, "walk_aim_multiplier") )
  {
    vostok::configs::binary_config_value::operator[](cfg, "walk_aim_multiplier");
    vostok::configs::binary_config_value::operator float(v6);
    this->walk_aim_multiplier = a2;
  }
  if ( vostok::configs::binary_config_value::value_exists(cfg, "run_multiplier") )
  {
    vostok::configs::binary_config_value::operator[](cfg, "run_multiplier");
    vostok::configs::binary_config_value::operator float(v7);
    this->run_multiplier = a2;
  }
  if ( vostok::configs::binary_config_value::value_exists(cfg, "jump_multiplier") )
  {
    vostok::configs::binary_config_value::operator[](cfg, "jump_multiplier");
    vostok::configs::binary_config_value::operator float(v8);
    this->jump_multiplier = a2;
  }
  if ( vostok::configs::binary_config_value::value_exists(cfg, "crouch_multiplier") )
  {
    vostok::configs::binary_config_value::operator[](cfg, "crouch_multiplier");
    vostok::configs::binary_config_value::operator float(v9);
    this->crouch_multiplier = a2;
  }
  if ( vostok::configs::binary_config_value::value_exists(cfg, "crouch_aim_multiplier") )
  {
    vostok::configs::binary_config_value::operator[](cfg, "crouch_aim_multiplier");
    vostok::configs::binary_config_value::operator float(v10);
    this->crouch_aim_multiplier = a2;
  }
  if ( vostok::configs::binary_config_value::value_exists(cfg, "crouch_walk_multiplier") )
  {
    vostok::configs::binary_config_value::operator[](cfg, "crouch_walk_multiplier");
    vostok::configs::binary_config_value::operator float(v11);
    this->crouch_walk_multiplier = a2;
  }
  if ( vostok::configs::binary_config_value::value_exists(cfg, "crouch_walk_aim_multiplier") )
  {
    vostok::configs::binary_config_value::operator[](cfg, "crouch_walk_aim_multiplier");
    vostok::configs::binary_config_value::operator float(v12);
    this->crouch_walk_aim_multiplier = a2;
  }
  if ( vostok::configs::binary_config_value::value_exists(cfg, "prone_multiplier") )
  {
    vostok::configs::binary_config_value::operator[](cfg, "prone_multiplier");
    vostok::configs::binary_config_value::operator float(v13);
    this->prone_multiplier = a2;
  }
  if ( vostok::configs::binary_config_value::value_exists(cfg, "prone_aim_multiplier") )
  {
    vostok::configs::binary_config_value::operator[](cfg, "prone_aim_multiplier");
    vostok::configs::binary_config_value::operator float(v14);
    this->prone_aim_multiplier = a2;
  }
  if ( vostok::configs::binary_config_value::value_exists(cfg, "injury_penalty_for_double_handed") )
  {
    vostok::configs::binary_config_value::operator[](cfg, "injury_penalty_for_double_handed");
    vostok::configs::binary_config_value::operator float(v15);
    this->injury_penalty_for_double_handed = a2;
  }
  if ( vostok::configs::binary_config_value::value_exists(cfg, "injury_penalty_for_one_handed") )
  {
    vostok::configs::binary_config_value::operator[](cfg, "injury_penalty_for_one_handed");
    vostok::configs::binary_config_value::operator float(v16);
    this->injury_penalty_for_one_handed = a2;
  }
}
