void __userpurge survarium::player_stealth::load(
        survarium::player_stealth *this@<ecx>,
        float *a2@<esi>,
        const vostok::configs::binary_config_value *config)
{
  const vostok::configs::binary_config_value *v3; // eax
  float pointer; // xmm0_4
  const vostok::configs::binary_config_value *v5; // eax
  float v6; // xmm0_4
  const vostok::configs::binary_config_value *v7; // eax
  float v8; // xmm0_4
  const vostok::configs::binary_config_value *v9; // eax
  float v10; // xmm0_4
  const vostok::configs::binary_config_value *v11; // eax
  float v12; // xmm0_4
  const vostok::configs::binary_config_value *v13; // eax
  float v14; // xmm0_4
  const vostok::configs::binary_config_value *v15; // eax
  float v16; // xmm0_4
  const vostok::configs::binary_config_value *v17; // eax
  float v18; // xmm0_4
  const vostok::configs::binary_config_value *v19; // eax
  float v20; // xmm0_4
  const vostok::configs::binary_config_value *v21; // eax
  float v22; // xmm0_4
  const vostok::configs::binary_config_value *v23; // eax
  float v24; // xmm0_4

  v3 = vostok::configs::binary_config_value::operator[](config, "default_value");
  if ( v3->type == 2 )
    pointer = *(float *)&v3->data.pointer;
  else
    pointer = (float)(int)v3->data.pointer;
  *a2 = pointer;
  v5 = vostok::configs::binary_config_value::operator[](config, "default_sound_value");
  if ( v5->type == 2 )
    v6 = *(float *)&v5->data.pointer;
  else
    v6 = (float)(int)v5->data.pointer;
  a2[1] = v6;
  v7 = vostok::configs::binary_config_value::operator[](config, "stand_factor");
  if ( v7->type == 2 )
    v8 = *(float *)&v7->data.pointer;
  else
    v8 = (float)(int)v7->data.pointer;
  a2[2] = v8;
  v9 = vostok::configs::binary_config_value::operator[](config, "crouch_factor");
  if ( v9->type == 2 )
    v10 = *(float *)&v9->data.pointer;
  else
    v10 = (float)(int)v9->data.pointer;
  a2[3] = v10;
  v11 = vostok::configs::binary_config_value::operator[](config, "crouch_sound_factor");
  if ( v11->type == 2 )
    v12 = *(float *)&v11->data.pointer;
  else
    v12 = (float)(int)v11->data.pointer;
  a2[4] = v12;
  v13 = vostok::configs::binary_config_value::operator[](config, "walk_factor");
  if ( v13->type == 2 )
    v14 = *(float *)&v13->data.pointer;
  else
    v14 = (float)(int)v13->data.pointer;
  a2[5] = v14;
  v15 = vostok::configs::binary_config_value::operator[](config, "walk_sound_factor");
  if ( v15->type == 2 )
    v16 = *(float *)&v15->data.pointer;
  else
    v16 = (float)(int)v15->data.pointer;
  a2[6] = v16;
  v17 = vostok::configs::binary_config_value::operator[](config, "sprint_factor");
  if ( v17->type == 2 )
    v18 = *(float *)&v17->data.pointer;
  else
    v18 = (float)(int)v17->data.pointer;
  a2[7] = v18;
  v19 = vostok::configs::binary_config_value::operator[](config, "sprint_sound_factor");
  if ( v19->type == 2 )
    v20 = *(float *)&v19->data.pointer;
  else
    v20 = (float)(int)v19->data.pointer;
  a2[8] = v20;
  v21 = vostok::configs::binary_config_value::operator[](config, "detection_level");
  if ( v21->type == 2 )
    v22 = *(float *)&v21->data.pointer;
  else
    v22 = (float)(int)v21->data.pointer;
  a2[9] = v22;
  v23 = vostok::configs::binary_config_value::operator[](config, "always_visible_distance");
  if ( v23->type == 2 )
    v24 = *(float *)&v23->data.pointer;
  else
    v24 = (float)(int)v23->data.pointer;
  a2[10] = v24;
}
