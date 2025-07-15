void __userpurge survarium::weapon_damage_params::weapon_damage_params(
        const vostok::configs::binary_config_value *cfg@<esi>,
        vostok::configs::binary_config_value *a2@<ecx>,
        survarium::weapon_damage_params *this)
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
  const vostok::configs::binary_config_value *v15; // eax
  float v16; // xmm0_4

  if ( vostok::configs::binary_config_value::value_exists(a2, (int)cfg, (unsigned int)"bullet_damage") )
  {
    v4 = vostok::configs::binary_config_value::operator[](cfg, "bullet_damage");
    if ( v4->type == 2 )
      pointer = *(float *)&v4->data.pointer;
    else
      pointer = (float)(int)v4->data.pointer;
    this->bullet_damage = pointer;
  }
  if ( vostok::configs::binary_config_value::value_exists(v3, (int)cfg, (unsigned int)"bullet_pierce") )
  {
    v7 = vostok::configs::binary_config_value::operator[](cfg, "bullet_pierce");
    if ( v7->type == 2 )
      v8 = *(float *)&v7->data.pointer;
    else
      v8 = (float)(int)v7->data.pointer;
    this->bullet_pierce = v8;
  }
  if ( vostok::configs::binary_config_value::value_exists(v6, (int)cfg, (unsigned int)"max_damage_distance") )
  {
    v10 = vostok::configs::binary_config_value::operator[](cfg, "max_damage_distance");
    if ( v10->type == 2 )
      v11 = *(float *)&v10->data.pointer;
    else
      v11 = (float)(int)v10->data.pointer;
    this->max_damage_distance = v11;
  }
  if ( vostok::configs::binary_config_value::value_exists(v9, (int)cfg, (unsigned int)"min_damage_distance") )
  {
    v13 = vostok::configs::binary_config_value::operator[](cfg, "min_damage_distance");
    if ( v13->type == 2 )
      v14 = *(float *)&v13->data.pointer;
    else
      v14 = (float)(int)v13->data.pointer;
    this->min_damage_distance = v14;
  }
  if ( vostok::configs::binary_config_value::value_exists(v12, (int)cfg, (unsigned int)"min_damage_amount") )
  {
    v15 = vostok::configs::binary_config_value::operator[](cfg, "min_damage_amount");
    if ( v15->type == 2 )
      v16 = *(float *)&v15->data.pointer;
    else
      v16 = (float)(int)v15->data.pointer;
    this->min_damage_amount = v16;
  }
}
