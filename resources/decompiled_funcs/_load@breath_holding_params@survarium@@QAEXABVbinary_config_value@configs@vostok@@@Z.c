void __userpurge survarium::breath_holding_params::load(
        vostok::configs::binary_config_value *cfg@<esi>,
        survarium::breath_holding_params *this)
{
  const vostok::configs::binary_config_value *v2; // eax
  float pointer; // xmm0_4
  const vostok::configs::binary_config_value *v4; // eax
  float v5; // xmm0_4
  const vostok::configs::binary_config_value *v6; // eax
  float v7; // xmm0_4
  const vostok::configs::binary_config_value *v8; // eax
  float v9; // xmm0_4
  const vostok::configs::binary_config_value *v10; // eax
  float v11; // xmm0_4
  const vostok::configs::binary_config_value *v12; // eax
  float v13; // xmm0_4
  const vostok::configs::binary_config_value *v14; // eax
  float v15; // xmm0_4
  const vostok::configs::binary_config_value *v16; // eax
  float v17; // xmm0_4
  const vostok::configs::binary_config_value *v18; // eax
  float v19; // xmm0_4
  const vostok::configs::binary_config_value *v20; // eax

  if ( vostok::configs::binary_config_value::value_exists(cfg, "max_breath_holding_time") )
  {
    v2 = vostok::configs::binary_config_value::operator[](cfg, "max_breath_holding_time");
    if ( v2->type == 2 )
      pointer = *(float *)&v2->data.pointer;
    else
      pointer = (float)(int)v2->data.pointer;
    this->max_breath_holding_time = pointer;
  }
  if ( vostok::configs::binary_config_value::value_exists(cfg, "shortbreathing_repair_time") )
  {
    v4 = vostok::configs::binary_config_value::operator[](cfg, "shortbreathing_repair_time");
    if ( v4->type == 2 )
      v5 = *(float *)&v4->data.pointer;
    else
      v5 = (float)(int)v4->data.pointer;
    this->shortbreathing_repair_time = v5;
  }
  if ( vostok::configs::binary_config_value::value_exists(cfg, "breath_holding_multiplier") )
  {
    v6 = vostok::configs::binary_config_value::operator[](cfg, "breath_holding_multiplier");
    if ( v6->type == 2 )
      v7 = *(float *)&v6->data.pointer;
    else
      v7 = (float)(int)v6->data.pointer;
    this->breath_holding_multiplier = v7;
  }
  if ( vostok::configs::binary_config_value::value_exists(cfg, "shortbreathing_multiplier") )
  {
    v8 = vostok::configs::binary_config_value::operator[](cfg, "shortbreathing_multiplier");
    if ( v8->type == 2 )
      v9 = *(float *)&v8->data.pointer;
    else
      v9 = (float)(int)v8->data.pointer;
    this->shortbreathing_multiplier = v9;
  }
  if ( vostok::configs::binary_config_value::value_exists(cfg, "multiplier_increase_speed") )
  {
    v10 = vostok::configs::binary_config_value::operator[](cfg, "multiplier_increase_speed");
    if ( v10->type == 2 )
      v11 = *(float *)&v10->data.pointer;
    else
      v11 = (float)(int)v10->data.pointer;
    this->multiplier_increase_speed = v11;
  }
  if ( vostok::configs::binary_config_value::value_exists(cfg, "multiplier_decrease_speed") )
  {
    v12 = vostok::configs::binary_config_value::operator[](cfg, "multiplier_decrease_speed");
    if ( v12->type == 2 )
      v13 = *(float *)&v12->data.pointer;
    else
      v13 = (float)(int)v12->data.pointer;
    this->multiplier_decrease_speed = v13;
  }
  if ( vostok::configs::binary_config_value::value_exists(cfg, "horizontal_amplitude") )
  {
    v14 = vostok::configs::binary_config_value::operator[](cfg, "horizontal_amplitude");
    if ( v14->type == 2 )
      v15 = *(float *)&v14->data.pointer;
    else
      v15 = (float)(int)v14->data.pointer;
    this->horizontal_amplitude = v15;
  }
  if ( vostok::configs::binary_config_value::value_exists(cfg, "vertical_amplitude") )
  {
    v16 = vostok::configs::binary_config_value::operator[](cfg, "vertical_amplitude");
    if ( v16->type == 2 )
      v17 = *(float *)&v16->data.pointer;
    else
      v17 = (float)(int)v16->data.pointer;
    this->vertical_amplitude = v17;
  }
  if ( vostok::configs::binary_config_value::value_exists(cfg, "horizontal_peroid") )
  {
    v18 = vostok::configs::binary_config_value::operator[](cfg, "horizontal_peroid");
    if ( v18->type == 2 )
      v19 = *(float *)&v18->data.pointer;
    else
      v19 = (float)(int)v18->data.pointer;
    this->horizontal_peroid = v19;
  }
  if ( vostok::configs::binary_config_value::value_exists(cfg, "vertical_peroid") )
  {
    v20 = vostok::configs::binary_config_value::operator[](cfg, "vertical_peroid");
    if ( v20->type == 2 )
      LODWORD(this->vertical_peroid) = v20->data.pointer;
    else
      this->vertical_peroid = (float)(int)v20->data.pointer;
  }
}
