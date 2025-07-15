void __userpurge survarium::character_breath_vibration_params::load(
        const vostok::configs::binary_config_value *cfg@<esi>,
        vostok::configs::binary_config_value *a2@<ecx>,
        survarium::character_breath_vibration_params *this)
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
  const vostok::configs::binary_config_value *v27; // eax
  float v28; // xmm0_4

  if ( vostok::configs::binary_config_value::value_exists(a2, (int)cfg, (unsigned int)"max_breath_holding_time") )
  {
    v4 = vostok::configs::binary_config_value::operator[](cfg, "max_breath_holding_time");
    if ( v4->type == 2 )
      pointer = *(float *)&v4->data.pointer;
    else
      pointer = (float)(int)v4->data.pointer;
    this->max_breath_holding_time = pointer;
  }
  if ( vostok::configs::binary_config_value::value_exists(v3, (int)cfg, (unsigned int)"base_time_to_hold_breath") )
  {
    v7 = vostok::configs::binary_config_value::operator[](cfg, "base_time_to_hold_breath");
    if ( v7->type == 2 )
      v8 = *(float *)&v7->data.pointer;
    else
      v8 = (float)(int)v7->data.pointer;
    this->base_time_to_hold_breath = v8;
  }
  if ( vostok::configs::binary_config_value::value_exists(
         v6,
         (int)cfg,
         (unsigned int)"time_to_speed_up_after_breath_holding") )
  {
    v10 = vostok::configs::binary_config_value::operator[](cfg, "time_to_speed_up_after_breath_holding");
    if ( v10->type == 2 )
      v11 = *(float *)&v10->data.pointer;
    else
      v11 = (float)(int)v10->data.pointer;
    this->time_to_speed_up_after_breath_holding = v11;
  }
  if ( vostok::configs::binary_config_value::value_exists(v9, (int)cfg, (unsigned int)"penalty_for_shortbreathing") )
  {
    v13 = vostok::configs::binary_config_value::operator[](cfg, "penalty_for_shortbreathing");
    if ( v13->type == 2 )
      v14 = *(float *)&v13->data.pointer;
    else
      v14 = (float)(int)v13->data.pointer;
    this->penalty_for_shortbreathing = v14;
  }
  if ( vostok::configs::binary_config_value::value_exists(
         v12,
         (int)cfg,
         (unsigned int)"time_to_get_penalty_for_shortbreathing") )
  {
    v16 = vostok::configs::binary_config_value::operator[](cfg, "time_to_get_penalty_for_shortbreathing");
    if ( v16->type == 2 )
      v17 = *(float *)&v16->data.pointer;
    else
      v17 = (float)(int)v16->data.pointer;
    this->time_to_get_penalty_for_shortbreathing = v17;
  }
  if ( vostok::configs::binary_config_value::value_exists(
         v15,
         (int)cfg,
         (unsigned int)"time_to_recover_after_shortbreathing") )
  {
    v19 = vostok::configs::binary_config_value::operator[](cfg, "time_to_recover_after_shortbreathing");
    if ( v19->type == 2 )
      v20 = *(float *)&v19->data.pointer;
    else
      v20 = (float)(int)v19->data.pointer;
    this->time_to_recover_after_shortbreathing = v20;
  }
  if ( vostok::configs::binary_config_value::value_exists(v18, (int)cfg, (unsigned int)"dispersion_to_amplitude_ratio") )
  {
    v22 = vostok::configs::binary_config_value::operator[](cfg, "dispersion_to_amplitude_ratio");
    if ( v22->type == 2 )
      v23 = *(float *)&v22->data.pointer;
    else
      v23 = (float)(int)v22->data.pointer;
    this->dispersion_to_amplitude_ratio = v23;
  }
  if ( vostok::configs::binary_config_value::value_exists(v21, (int)cfg, (unsigned int)"dispersion_to_speed_ratio") )
  {
    v25 = vostok::configs::binary_config_value::operator[](cfg, "dispersion_to_speed_ratio");
    if ( v25->type == 2 )
      v26 = *(float *)&v25->data.pointer;
    else
      v26 = (float)(int)v25->data.pointer;
    this->dispersion_to_speed_ratio = v26;
  }
  if ( vostok::configs::binary_config_value::value_exists(
         v24,
         (int)cfg,
         (unsigned int)"dispersion_to_time_to_hold_breath_ratio") )
  {
    v27 = vostok::configs::binary_config_value::operator[](cfg, "dispersion_to_time_to_hold_breath_ratio");
    if ( v27->type == 2 )
      v28 = *(float *)&v27->data.pointer;
    else
      v28 = (float)(int)v27->data.pointer;
    this->dispersion_to_time_to_hold_breath_ratio = v28;
  }
}
