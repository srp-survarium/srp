void __userpurge survarium::character_dispersion_params::load(
        const vostok::configs::binary_config_value *cfg@<esi>,
        vostok::configs::binary_config_value *a2@<ecx>,
        survarium::character_dispersion_params *this)
{
  vostok::configs::binary_config_value *v3; // ecx
  const vostok::configs::binary_config_value *v4; // eax
  float pointer; // xmm0_4
  vostok::configs::binary_config_value *v6; // ecx
  const vostok::configs::binary_config_value *v7; // eax
  float v8; // xmm0_4
  vostok::configs::binary_config_value *v9; // ecx
  const vostok::configs::binary_config_value *v10; // eax
  float v11; // xmm0_4
  vostok::configs::binary_config_value *v12; // ecx
  const vostok::configs::binary_config_value *v13; // eax
  float v14; // xmm0_4
  vostok::configs::binary_config_value *v15; // ecx
  const vostok::configs::binary_config_value *v16; // eax
  float v17; // xmm0_4
  vostok::configs::binary_config_value *v18; // ecx
  const vostok::configs::binary_config_value *v19; // eax
  float v20; // xmm0_4
  vostok::configs::binary_config_value *v21; // ecx
  const vostok::configs::binary_config_value *v22; // eax
  float v23; // xmm0_4
  vostok::configs::binary_config_value *v24; // ecx
  const vostok::configs::binary_config_value *v25; // eax
  float v26; // xmm0_4
  vostok::configs::binary_config_value *v27; // ecx
  const vostok::configs::binary_config_value *v28; // eax
  float v29; // xmm0_4
  vostok::configs::binary_config_value *v30; // ecx
  const vostok::configs::binary_config_value *v31; // eax
  float v32; // xmm0_4
  vostok::configs::binary_config_value *v33; // ecx
  const vostok::configs::binary_config_value *v34; // eax
  float v35; // xmm0_4
  vostok::configs::binary_config_value *v36; // ecx
  const vostok::configs::binary_config_value *v37; // eax
  float v38; // xmm0_4
  vostok::configs::binary_config_value *v39; // ecx
  const vostok::configs::binary_config_value *v40; // eax
  float v41; // xmm0_4
  vostok::configs::binary_config_value *v42; // ecx
  const vostok::configs::binary_config_value *v43; // eax
  float v44; // xmm0_4
  const vostok::configs::binary_config_value *v45; // eax
  float v46; // xmm0_4

  if ( vostok::configs::binary_config_value::value_exists(a2, (int)cfg, (unsigned int)"idle_dispersion") )
  {
    v4 = vostok::configs::binary_config_value::operator[](cfg, "idle_dispersion");
    if ( v4->type == 2 )
      pointer = *(float *)&v4->data.pointer;
    else
      pointer = (float)(int)v4->data.pointer;
    this->idle_dispersion = pointer;
  }
  if ( vostok::configs::binary_config_value::value_exists(v3, (int)cfg, (unsigned int)"idle_aim_dispersion") )
  {
    v7 = vostok::configs::binary_config_value::operator[](cfg, "idle_aim_dispersion");
    if ( v7->type == 2 )
      v8 = *(float *)&v7->data.pointer;
    else
      v8 = (float)(int)v7->data.pointer;
    this->idle_aim_dispersion = v8;
  }
  if ( vostok::configs::binary_config_value::value_exists(v6, (int)cfg, (unsigned int)"walk_dispersion") )
  {
    v10 = vostok::configs::binary_config_value::operator[](cfg, "walk_dispersion");
    if ( v10->type == 2 )
      v11 = *(float *)&v10->data.pointer;
    else
      v11 = (float)(int)v10->data.pointer;
    this->walk_dispersion = v11;
  }
  if ( vostok::configs::binary_config_value::value_exists(v9, (int)cfg, (unsigned int)"walk_aim_dispersion") )
  {
    v13 = vostok::configs::binary_config_value::operator[](cfg, "walk_aim_dispersion");
    if ( v13->type == 2 )
      v14 = *(float *)&v13->data.pointer;
    else
      v14 = (float)(int)v13->data.pointer;
    this->walk_aim_dispersion = v14;
  }
  if ( vostok::configs::binary_config_value::value_exists(v12, (int)cfg, (unsigned int)"run_dispersion") )
  {
    v16 = vostok::configs::binary_config_value::operator[](cfg, "run_dispersion");
    if ( v16->type == 2 )
      v17 = *(float *)&v16->data.pointer;
    else
      v17 = (float)(int)v16->data.pointer;
    this->run_dispersion = v17;
  }
  if ( vostok::configs::binary_config_value::value_exists(v15, (int)cfg, (unsigned int)"jump_dispersion") )
  {
    v19 = vostok::configs::binary_config_value::operator[](cfg, "jump_dispersion");
    if ( v19->type == 2 )
      v20 = *(float *)&v19->data.pointer;
    else
      v20 = (float)(int)v19->data.pointer;
    this->jump_dispersion = v20;
  }
  if ( vostok::configs::binary_config_value::value_exists(v18, (int)cfg, (unsigned int)"crouch_dispersion") )
  {
    v22 = vostok::configs::binary_config_value::operator[](cfg, "crouch_dispersion");
    if ( v22->type == 2 )
      v23 = *(float *)&v22->data.pointer;
    else
      v23 = (float)(int)v22->data.pointer;
    this->crouch_dispersion = v23;
  }
  if ( vostok::configs::binary_config_value::value_exists(v21, (int)cfg, (unsigned int)"crouch_aim_dispersion") )
  {
    v25 = vostok::configs::binary_config_value::operator[](cfg, "crouch_aim_dispersion");
    if ( v25->type == 2 )
      v26 = *(float *)&v25->data.pointer;
    else
      v26 = (float)(int)v25->data.pointer;
    this->crouch_aim_dispersion = v26;
  }
  if ( vostok::configs::binary_config_value::value_exists(v24, (int)cfg, (unsigned int)"crouch_walk_dispersion") )
  {
    v28 = vostok::configs::binary_config_value::operator[](cfg, "crouch_walk_dispersion");
    if ( v28->type == 2 )
      v29 = *(float *)&v28->data.pointer;
    else
      v29 = (float)(int)v28->data.pointer;
    this->crouch_walk_dispersion = v29;
  }
  if ( vostok::configs::binary_config_value::value_exists(v27, (int)cfg, (unsigned int)"crouch_walk_aim_dispersion") )
  {
    v31 = vostok::configs::binary_config_value::operator[](cfg, "crouch_walk_aim_dispersion");
    if ( v31->type == 2 )
      v32 = *(float *)&v31->data.pointer;
    else
      v32 = (float)(int)v31->data.pointer;
    this->crouch_walk_aim_dispersion = v32;
  }
  if ( vostok::configs::binary_config_value::value_exists(v30, (int)cfg, (unsigned int)"prone_dispersion") )
  {
    v34 = vostok::configs::binary_config_value::operator[](cfg, "prone_dispersion");
    if ( v34->type == 2 )
      v35 = *(float *)&v34->data.pointer;
    else
      v35 = (float)(int)v34->data.pointer;
    this->prone_dispersion = v35;
  }
  if ( vostok::configs::binary_config_value::value_exists(v33, (int)cfg, (unsigned int)"prone_aim_multiplier") )
  {
    v37 = vostok::configs::binary_config_value::operator[](cfg, "prone_aim_dispersion");
    if ( v37->type == 2 )
      v38 = *(float *)&v37->data.pointer;
    else
      v38 = (float)(int)v37->data.pointer;
    this->prone_aim_dispersion = v38;
  }
  if ( vostok::configs::binary_config_value::value_exists(v36, (int)cfg, (unsigned int)"low_stamina_dispersion") )
  {
    v40 = vostok::configs::binary_config_value::operator[](cfg, "low_stamina_dispersion");
    if ( v40->type == 2 )
      v41 = *(float *)&v40->data.pointer;
    else
      v41 = (float)(int)v40->data.pointer;
    this->low_stamina_dispersion = v41;
  }
  if ( vostok::configs::binary_config_value::value_exists(
         v39,
         (int)cfg,
         (unsigned int)"injury_penalty_for_double_handed") )
  {
    v43 = vostok::configs::binary_config_value::operator[](cfg, "injury_penalty_for_double_handed");
    if ( v43->type == 2 )
      v44 = *(float *)&v43->data.pointer;
    else
      v44 = (float)(int)v43->data.pointer;
    this->injury_penalty_for_double_handed = v44;
  }
  if ( vostok::configs::binary_config_value::value_exists(v42, (int)cfg, (unsigned int)"injury_penalty_for_one_handed") )
  {
    v45 = vostok::configs::binary_config_value::operator[](cfg, "injury_penalty_for_one_handed");
    if ( v45->type == 2 )
      v46 = *(float *)&v45->data.pointer;
    else
      v46 = (float)(int)v45->data.pointer;
    this->injury_penalty_for_one_handed = v46;
  }
}
