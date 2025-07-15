void __userpurge survarium::weapon_breath_vibration_params::weapon_breath_vibration_params(
        const vostok::configs::binary_config_value *cfg@<esi>,
        vostok::configs::binary_config_value *a2@<ecx>,
        survarium::weapon_breath_vibration_params *this)
{
  vostok::configs::binary_config_value *v3; // ecx
  const vostok::configs::binary_config_value *v4; // eax
  float pointer; // xmm0_4
  vostok::configs::binary_config_value *v6; // ecx
  const vostok::configs::binary_config_value *v7; // eax
  float v8; // xmm0_4
  const vostok::configs::binary_config_value *v9; // eax
  float v10; // xmm0_4

  if ( vostok::configs::binary_config_value::value_exists(a2, (int)cfg, (unsigned int)"base_horizontal_amplitude") )
  {
    v4 = vostok::configs::binary_config_value::operator[](cfg, "base_horizontal_amplitude");
    if ( v4->type == 2 )
      pointer = *(float *)&v4->data.pointer;
    else
      pointer = (float)(int)v4->data.pointer;
    this->base_horizontal_amplitude = pointer;
  }
  if ( vostok::configs::binary_config_value::value_exists(v3, (int)cfg, (unsigned int)"base_vertical_amplitude") )
  {
    v7 = vostok::configs::binary_config_value::operator[](cfg, "base_vertical_amplitude");
    if ( v7->type == 2 )
      v8 = *(float *)&v7->data.pointer;
    else
      v8 = (float)(int)v7->data.pointer;
    this->base_vertical_amplitude = v8;
  }
  if ( vostok::configs::binary_config_value::value_exists(v6, (int)cfg, (unsigned int)"base_period") )
  {
    v9 = vostok::configs::binary_config_value::operator[](cfg, "base_period");
    if ( v9->type == 2 )
      v10 = *(float *)&v9->data.pointer;
    else
      v10 = (float)(int)v9->data.pointer;
    this->base_period = v10;
  }
}
