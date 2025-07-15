void __userpurge survarium::weapon_dispersion_params::weapon_dispersion_params(
        survarium::weapon_dispersion_params *this@<ecx>,
        int a2@<esi>,
        const vostok::configs::binary_config_value *cfg)
{
  float v3; // xmm0_4
  vostok::configs::binary_config_value *v4; // ecx
  const vostok::configs::binary_config_value *v5; // eax
  float pointer; // xmm0_4
  vostok::configs::binary_config_value *v7; // ecx
  const vostok::configs::binary_config_value *v8; // eax
  float v9; // xmm0_4
  vostok::configs::binary_config_value *v10; // ecx
  const vostok::configs::binary_config_value *v11; // eax
  float v12; // xmm0_4
  vostok::configs::binary_config_value *v13; // ecx
  const vostok::configs::binary_config_value *v14; // eax
  float v15; // xmm0_4
  vostok::configs::binary_config_value *v16; // ecx
  const vostok::configs::binary_config_value *v17; // eax
  float v18; // xmm0_4
  vostok::configs::binary_config_value *v19; // ecx
  const vostok::configs::binary_config_value *v20; // eax
  float v21; // xmm0_4
  vostok::configs::binary_config_value *v22; // ecx
  const vostok::configs::binary_config_value *v23; // eax
  float v24; // xmm0_4
  const vostok::configs::binary_config_value *v25; // eax
  float v26; // xmm0_4

  *(_DWORD *)a2 = 0;
  v3 = s_bm_current_air_resistance;
  *(float *)(a2 + 4) = s_bm_current_air_resistance;
  *(float *)(a2 + 8) = v3;
  *(float *)(a2 + 12) = v3;
  *(float *)(a2 + 16) = v3;
  *(float *)(a2 + 20) = v3;
  *(float *)(a2 + 24) = v3;
  *(float *)(a2 + 28) = retry_to_increase_quality_period_sec;
  if ( vostok::configs::binary_config_value::value_exists(
         (vostok::configs::binary_config_value *)this,
         (int)cfg,
         (unsigned int)"base_dispersion") )
  {
    v5 = vostok::configs::binary_config_value::operator[](cfg, "base_dispersion");
    if ( v5->type == 2 )
      pointer = *(float *)&v5->data.pointer;
    else
      pointer = (float)(int)v5->data.pointer;
    *(float *)a2 = pointer;
  }
  if ( vostok::configs::binary_config_value::value_exists(v4, (int)cfg, (unsigned int)"from_the_hip_multiplier") )
  {
    v8 = vostok::configs::binary_config_value::operator[](cfg, "from_the_hip_multiplier");
    if ( v8->type == 2 )
      v9 = *(float *)&v8->data.pointer;
    else
      v9 = (float)(int)v8->data.pointer;
    *(float *)(a2 + 4) = v9;
  }
  if ( vostok::configs::binary_config_value::value_exists(v7, (int)cfg, (unsigned int)"aim_multiplier") )
  {
    v11 = vostok::configs::binary_config_value::operator[](cfg, "aim_multiplier");
    if ( v11->type == 2 )
      v12 = *(float *)&v11->data.pointer;
    else
      v12 = (float)(int)v11->data.pointer;
    *(float *)(a2 + 8) = v12;
  }
  if ( vostok::configs::binary_config_value::value_exists(v10, (int)cfg, (unsigned int)"speed_of_aiming") )
  {
    v14 = vostok::configs::binary_config_value::operator[](cfg, "speed_of_aiming");
    if ( v14->type == 2 )
      v15 = *(float *)&v14->data.pointer;
    else
      v15 = (float)(int)v14->data.pointer;
    *(float *)(a2 + 12) = v15;
  }
  if ( vostok::configs::binary_config_value::value_exists(v13, (int)cfg, (unsigned int)"one_shoot_dispersion_amount") )
  {
    v17 = vostok::configs::binary_config_value::operator[](cfg, "one_shoot_dispersion_amount");
    if ( v17->type == 2 )
      v18 = *(float *)&v17->data.pointer;
    else
      v18 = (float)(int)v17->data.pointer;
    *(float *)(a2 + 16) = v18;
  }
  if ( vostok::configs::binary_config_value::value_exists(v16, (int)cfg, (unsigned int)"reload_dispersion_amount") )
  {
    v20 = vostok::configs::binary_config_value::operator[](cfg, "reload_dispersion_amount");
    if ( v20->type == 2 )
      v21 = *(float *)&v20->data.pointer;
    else
      v21 = (float)(int)v20->data.pointer;
    *(float *)(a2 + 20) = v21;
  }
  if ( vostok::configs::binary_config_value::value_exists(v19, (int)cfg, (unsigned int)"growth_speed") )
  {
    v23 = vostok::configs::binary_config_value::operator[](cfg, "growth_speed");
    if ( v23->type == 2 )
      v24 = *(float *)&v23->data.pointer;
    else
      v24 = (float)(int)v23->data.pointer;
    *(float *)(a2 + 24) = v24;
  }
  if ( vostok::configs::binary_config_value::value_exists(v22, (int)cfg, (unsigned int)"max_dispersion") )
  {
    v25 = vostok::configs::binary_config_value::operator[](cfg, "max_dispersion");
    if ( v25->type == 2 )
      v26 = *(float *)&v25->data.pointer;
    else
      v26 = (float)(int)v25->data.pointer;
    *(float *)(a2 + 28) = v26;
  }
}
