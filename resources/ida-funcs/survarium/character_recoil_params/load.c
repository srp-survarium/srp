void __userpurge survarium::character_recoil_params::load(
        const vostok::configs::binary_config_value *cfg@<esi>,
        vostok::configs::binary_config_value *a2@<ecx>,
        survarium::character_recoil_params *this)
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
  const vostok::configs::binary_config_value *v12; // eax
  float v13; // xmm0_4

  if ( vostok::configs::binary_config_value::value_exists(a2, (int)cfg, (unsigned int)"crouch_multiplier") )
  {
    v4 = vostok::configs::binary_config_value::operator[](cfg, "crouch_multiplier");
    if ( v4->type == 2 )
      pointer = *(float *)&v4->data.pointer;
    else
      pointer = (float)(int)v4->data.pointer;
    this->crouch_multiplier = pointer;
  }
  if ( vostok::configs::binary_config_value::value_exists(v3, (int)cfg, (unsigned int)"stand_multiplier") )
  {
    v7 = vostok::configs::binary_config_value::operator[](cfg, "stand_multiplier");
    if ( v7->type == 2 )
      v8 = *(float *)&v7->data.pointer;
    else
      v8 = (float)(int)v7->data.pointer;
    this->stand_multiplier = v8;
  }
  if ( vostok::configs::binary_config_value::value_exists(v6, (int)cfg, (unsigned int)"aimed_crouch_multiplier") )
  {
    v10 = vostok::configs::binary_config_value::operator[](cfg, "aimed_crouch_multiplier");
    if ( v10->type == 2 )
      v11 = *(float *)&v10->data.pointer;
    else
      v11 = (float)(int)v10->data.pointer;
    this->aimed_crouch_multiplier = v11;
  }
  if ( vostok::configs::binary_config_value::value_exists(v9, (int)cfg, (unsigned int)"aimed_stand_multiplier") )
  {
    v12 = vostok::configs::binary_config_value::operator[](cfg, "aimed_stand_multiplier");
    if ( v12->type == 2 )
      v13 = *(float *)&v12->data.pointer;
    else
      v13 = (float)(int)v12->data.pointer;
    this->aimed_stand_multiplier = v13;
  }
}
