void __userpurge survarium::game_material::load_from_config(
        survarium::game_material *this@<ecx>,
        int a2@<esi>,
        const vostok::configs::binary_config_value *val)
{
  char *pointer; // edx
  _BYTE *v4; // eax
  vostok::configs::binary_config_value *v5; // eax
  const vostok::configs::binary_config_value *v6; // eax
  float v7; // xmm0_4
  vostok::configs::binary_config_value *v8; // eax
  const vostok::configs::binary_config_value *v9; // eax
  float v10; // xmm0_4
  vostok::configs::binary_config_value *v11; // eax
  const vostok::configs::binary_config_value *v12; // eax
  float v13; // xmm0_4
  vostok::configs::binary_config_value *v14; // eax
  const vostok::configs::binary_config_value *v15; // eax
  float v16; // xmm0_4
  vostok::configs::binary_config_value *v17; // eax
  const vostok::configs::binary_config_value *v18; // eax
  float v19; // xmm0_4
  vostok::configs::binary_config_value *v20; // eax
  const vostok::configs::binary_config_value *v21; // eax
  float v22; // xmm0_4
  vostok::configs::binary_config_value *v23; // eax
  vostok::configs::binary_config_value *v24; // eax
  const vostok::configs::binary_config_value *v25; // eax
  vostok::configs::binary_config_value *v26; // ecx
  vostok::configs::binary_config_value *v27; // eax

  *(_WORD *)(a2 + 100) = vostok::configs::binary_config_value::operator[](val, "id")->data.pointer;
  pointer = (char *)vostok::configs::binary_config_value::operator[](val, "name")->data.pointer;
  v4 = *(_BYTE **)a2;
  *(_DWORD *)(a2 + 4) = *(_DWORD *)a2;
  *v4 = 0;
  vostok::buffer_string::operator+=((vostok::buffer_string *)a2, pointer);
  v5 = vostok::configs::binary_config_value::operator[](val, "physic");
  v6 = vostok::configs::binary_config_value::operator[](v5, "armor");
  if ( v6->type == 2 )
    v7 = *(float *)&v6->data.pointer;
  else
    v7 = (float)(int)v6->data.pointer;
  *(float *)(a2 + 76) = v7;
  v8 = vostok::configs::binary_config_value::operator[](val, "physic");
  v9 = vostok::configs::binary_config_value::operator[](v8, "reflection_speed_down");
  if ( v9->type == 2 )
    v10 = *(float *)&v9->data.pointer;
  else
    v10 = (float)(int)v9->data.pointer;
  *(float *)(a2 + 80) = v10;
  v11 = vostok::configs::binary_config_value::operator[](val, "physic");
  v12 = vostok::configs::binary_config_value::operator[](v11, "k_ricochet");
  if ( v12->type == 2 )
    v13 = *(float *)&v12->data.pointer;
  else
    v13 = (float)(int)v12->data.pointer;
  *(float *)(a2 + 84) = v13;
  v14 = vostok::configs::binary_config_value::operator[](val, "physic");
  v15 = vostok::configs::binary_config_value::operator[](v14, "k_ricochet_dispersion");
  if ( v15->type == 2 )
    v16 = *(float *)&v15->data.pointer;
  else
    v16 = (float)(int)v15->data.pointer;
  *(float *)(a2 + 88) = v16;
  v17 = vostok::configs::binary_config_value::operator[](val, "physic");
  v18 = vostok::configs::binary_config_value::operator[](v17, "k_pierce_dispersion");
  if ( v18->type == 2 )
    v19 = *(float *)&v18->data.pointer;
  else
    v19 = (float)(int)v18->data.pointer;
  *(float *)(a2 + 92) = v19;
  v20 = vostok::configs::binary_config_value::operator[](val, "physic");
  v21 = vostok::configs::binary_config_value::operator[](v20, "k_ricochet_chance");
  if ( v21->type == 2 )
    v22 = *(float *)&v21->data.pointer;
  else
    v22 = (float)(int)v21->data.pointer;
  *(float *)(a2 + 96) = v22;
  v23 = vostok::configs::binary_config_value::operator[](val, "mine");
  *(_BYTE *)(a2 + 105) = vostok::configs::binary_config_value::operator[](v23, "can_place")->data.pointer != 0;
  v24 = vostok::configs::binary_config_value::operator[](val, "mine");
  *(_BYTE *)(a2 + 106) = vostok::configs::binary_config_value::operator[](v24, "can_stick")->data.pointer != 0;
  v25 = vostok::configs::binary_config_value::operator[](val, "physic");
  if ( vostok::configs::binary_config_value::value_exists(v26, (int)v25, (unsigned int)"walker_behaviour") )
  {
    v27 = vostok::configs::binary_config_value::operator[](val, "physic");
    *(_BYTE *)(a2 + 104) = vostok::configs::binary_config_value::operator[](v27, "walker_behaviour")->data.pointer;
  }
}
