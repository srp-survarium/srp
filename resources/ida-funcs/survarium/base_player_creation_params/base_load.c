void __thiscall survarium::base_player_creation_params::base_load(
        survarium::base_player_creation_params *this,
        const vostok::configs::binary_config_value *root,
        vostok::configs::binary_config_value *a3)
{
  vostok::configs::binary_config_value *v4; // eax
  survarium::player_speed_parameters *v5; // ecx
  vostok::buffer_vector<float> *v6; // eax
  vostok::buffer_vector<float> *v7; // esi
  const vostok::configs::binary_config_value *v8; // eax
  const vostok::configs::binary_config_value *v9; // eax
  const vostok::configs::binary_config_value *v10; // eax
  const vostok::configs::binary_config_value *v11; // eax
  survarium::character_dispersion_skill_influence *v12; // ecx
  const vostok::configs::binary_config_value *v13; // eax
  survarium::stamina_base_parameters *v14; // ecx
  const vostok::configs::binary_config_value *v15; // eax
  survarium::player_stealth *v16; // ecx
  const vostok::configs::binary_config_value *v17; // eax
  float pointer; // xmm0_4
  const vostok::configs::binary_config_value *v19; // eax
  float v20; // xmm0_4
  const vostok::configs::binary_config_value *v21; // eax
  float v22; // xmm0_4
  const vostok::configs::binary_config_value *v23; // eax
  float v24; // xmm0_4
  const vostok::configs::binary_config_value *v25; // eax
  float v26; // xmm0_4
  const vostok::configs::binary_config_value *v27; // eax
  float v28; // xmm0_4
  const vostok::configs::binary_config_value *v29; // eax
  float v30; // xmm0_4
  const vostok::configs::binary_config_value *v31; // eax
  float v32; // xmm0_4
  const vostok::configs::binary_config_value *v33; // eax
  float v34; // xmm0_4
  const vostok::configs::binary_config_value *v35; // eax
  float v36; // xmm0_4
  vostok::configs::binary_config_value v37[5]; // [esp+10h] [ebp-90h] BYREF
  vostok::configs::binary_config_value v38; // [esp+88h] [ebp-18h] BYREF

  v4 = vostok::configs::binary_config_value::operator[](a3, "movement_speed");
  survarium::player_speed_parameters::player_speed_parameters(v5, (const float *)"movement_speed", v37, v4);
  v7 = v6;
  vostok::buffer_vector<float>::operator=(v6, (vostok::buffer_vector<float> *)root);
  vostok::buffer_vector<float>::operator=(
    (vostok::buffer_vector<float> *)((char *)v7 + 64),
    (vostok::buffer_vector<float> *)&root[2].id_crc);
  root[4].id_crc = (unsigned int)v7[9].m_end;
  *(float *)&root[4].type = *(float *)&v7[9].m_max_end;
  v8 = vostok::configs::binary_config_value::operator[](a3, "character_recoil_params");
  survarium::character_recoil_params::load(
    v8,
    (const vostok::configs::binary_config_value *)((char *)root + 140),
    (survarium::character_recoil_params *)&root[5].type);
  v9 = vostok::configs::binary_config_value::operator[](a3, "character_breath_vibration_params");
  survarium::character_breath_vibration_params::load(
    v9,
    (const vostok::configs::binary_config_value *)((char *)root + 268),
    (survarium::character_breath_vibration_params *)((char *)&root[11].data.max_storage + 4));
  v10 = vostok::configs::binary_config_value::operator[](a3, "character_dispersion_params");
  survarium::character_dispersion_params::load(
    v10,
    (const vostok::configs::binary_config_value *)((char *)root + 156),
    (survarium::character_dispersion_params *)((char *)&root[6].id.max_storage + 4));
  v11 = vostok::configs::binary_config_value::operator[](a3, "character_dispersion_skill_influence");
  survarium::character_dispersion_skill_influence::load(v12, (float *)&root[9], v11);
  v13 = vostok::configs::binary_config_value::operator[](a3, "stamina_params");
  survarium::stamina_base_parameters::load(v14, (float *)&root[12].id_crc, v13);
  v15 = vostok::configs::binary_config_value::operator[](a3, "stealth_params");
  survarium::player_stealth::load(v16, (float *)&root[14].id, v15);
  qmemcpy((void *)&v38, vostok::configs::binary_config_value::operator[](a3, "jump_params"), sizeof(v38));
  v17 = vostok::configs::binary_config_value::operator[](&v38, "air_control_speed");
  if ( v17->type == 2 )
    pointer = *(float *)&v17->data.pointer;
  else
    pointer = (float)(int)v17->data.pointer;
  *(float *)&root[16].id_crc = pointer;
  v19 = vostok::configs::binary_config_value::operator[](&v38, "jump_from_site_speed");
  if ( v19->type == 2 )
    v20 = *(float *)&v19->data.pointer;
  else
    v20 = (float)(int)v19->data.pointer;
  *(float *)&root[16].type = v20;
  qmemcpy((void *)&v38, vostok::configs::binary_config_value::operator[](a3, "fall_params"), sizeof(v38));
  v21 = vostok::configs::binary_config_value::operator[](&v38, "fatal_damage");
  if ( v21->type == 2 )
    v22 = *(float *)&v21->data.pointer;
  else
    v22 = (float)(int)v21->data.pointer;
  *(float *)&root[17].id.pointer = v22;
  v23 = vostok::configs::binary_config_value::operator[](&v38, "gravity");
  if ( v23->type == 2 )
    v24 = *(float *)&v23->data.pointer;
  else
    v24 = (float)(int)v23->data.pointer;
  *((float *)&root[17].id.max_storage + 1) = v24;
  v25 = vostok::configs::binary_config_value::operator[](&v38, "fatal_height");
  if ( v25->type == 2 )
    v26 = *(float *)&v25->data.pointer;
  else
    v26 = (float)(int)v25->data.pointer;
  *(float *)&root[17].data.pointer = fsqrt((float)(*((float *)&root[17].id.max_storage + 1) * v26) * 2.0);
  v27 = vostok::configs::binary_config_value::operator[](&v38, "harmless_height");
  if ( v27->type == 2 )
    v28 = *(float *)&v27->data.pointer;
  else
    v28 = (float)(int)v27->data.pointer;
  *((float *)&root[17].data.max_storage + 1) = fsqrt((float)(*((float *)&root[17].id.max_storage + 1) * v28) * 2.0);
  qmemcpy((void *)&v38, vostok::configs::binary_config_value::operator[](a3, "physics_controller"), sizeof(v38));
  v29 = vostok::configs::binary_config_value::operator[](&v38, "stand_capsule_width");
  if ( v29->type == 2 )
    v30 = *(float *)&v29->data.pointer;
  else
    v30 = (float)(int)v29->data.pointer;
  *(float *)&root[17].type = v30;
  v31 = vostok::configs::binary_config_value::operator[](&v38, "stand_capsule_height");
  if ( v31->type == 2 )
    v32 = *(float *)&v31->data.pointer;
  else
    v32 = (float)(int)v31->data.pointer;
  *(float *)&root[18].data.pointer = v32;
  v33 = vostok::configs::binary_config_value::operator[](&v38, "crouch_capsule_width");
  if ( v33->type == 2 )
    v34 = *(float *)&v33->data.pointer;
  else
    v34 = (float)(int)v33->data.pointer;
  *((float *)&root[18].data.max_storage + 1) = v34;
  v35 = vostok::configs::binary_config_value::operator[](&v38, "crouch_capsule_height");
  if ( v35->type == 2 )
    v36 = *(float *)&v35->data.pointer;
  else
    v36 = (float)(int)v35->data.pointer;
  *(float *)&root[18].id.pointer = v36;
}
