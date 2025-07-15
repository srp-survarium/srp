char __userpurge survarium::material_pair::load_from_config@<al>(
        survarium::material_pair *this@<ecx>,
        int a2@<esi>,
        const survarium::game_material_manager *manager,
        const vostok::configs::binary_config_value *val)
{
  survarium::game_material_manager *v5; // ecx
  unsigned __int16 v6; // di
  survarium::game_material_manager *v7; // ecx
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
  unsigned __int16 pointer; // [esp+10h] [ebp+8h]

  pointer = (unsigned __int16)vostok::configs::binary_config_value::operator[](val, "mtrl_1_id")->data.pointer;
  v6 = (unsigned __int16)vostok::configs::binary_config_value::operator[](val, "mtrl_2_id")->data.pointer;
  if ( !manager->m_materials[pointer] || !manager->m_materials[v6] )
    return 0;
  *(_DWORD *)a2 = survarium::game_material_manager::get_material(v5, (int)manager, pointer);
  *(_DWORD *)(a2 + 4) = survarium::game_material_manager::get_material(v7, (int)manager, v6);
  *(_DWORD *)(a2 + 116) = vostok::configs::binary_config_value::operator[](val, "particle_orientation")->data.pointer;
  v8 = vostok::configs::binary_config_value::operator[](val, "decal_in_size");
  if ( v8->type == 2 )
    v9 = *(float *)&v8->data.pointer;
  else
    v9 = (float)(int)v8->data.pointer;
  *(float *)(a2 + 120) = v9;
  if ( v9 <= 0.0099999998 )
    v9 = FLOAT_0_0099999998;
  *(float *)(a2 + 120) = v9;
  v10 = vostok::configs::binary_config_value::operator[](val, "decal_out_size");
  if ( v10->type == 2 )
    v11 = *(float *)&v10->data.pointer;
  else
    v11 = (float)(int)v10->data.pointer;
  *(float *)(a2 + 124) = v11;
  if ( v11 <= 0.0099999998 )
    v11 = FLOAT_0_0099999998;
  *(float *)(a2 + 124) = v11;
  v12 = vostok::configs::binary_config_value::operator[](val, "reflection_decal_size");
  if ( v12->type == 2 )
    v13 = *(float *)&v12->data.pointer;
  else
    v13 = (float)(int)v12->data.pointer;
  *(float *)(a2 + 128) = v13;
  if ( v13 <= 0.0099999998 )
    v13 = FLOAT_0_0099999998;
  *(float *)(a2 + 128) = v13;
  v14 = vostok::configs::binary_config_value::operator[](val, "reflection_decal_ratio");
  if ( v14->type == 2 )
    v15 = *(float *)&v14->data.pointer;
  else
    v15 = (float)(int)v14->data.pointer;
  *(float *)(a2 + 132) = v15;
  v16 = vostok::configs::binary_config_value::operator[](val, "collision_decal_size");
  if ( v16->type == 2 )
    v17 = *(float *)&v16->data.pointer;
  else
    v17 = (float)(int)v16->data.pointer;
  *(float *)(a2 + 136) = v17;
  if ( v17 <= 0.0099999998 )
    v17 = FLOAT_0_0099999998;
  *(float *)(a2 + 136) = v17;
  v18 = vostok::configs::binary_config_value::operator[](val, "decal_scale_delta");
  if ( v18->type == 2 )
    v19 = *(float *)&v18->data.pointer;
  else
    v19 = (float)(int)v18->data.pointer;
  *(float *)(a2 + 140) = v19;
  return 1;
}
