void __userpurge survarium::player_speed_parameters::player_speed_parameters(
        survarium::player_speed_parameters *this@<ecx>,
        const float *a2@<edi>,
        const vostok::configs::binary_config_value *cfg,
        vostok::configs::binary_config_value *a4)
{
  const vostok::configs::binary_config_value *v4; // xmm0_4
  const vostok::configs::binary_config_value *v5; // ebx
  char *v6; // eax
  const vostok::configs::binary_config_value *v7; // eax
  char *v8; // edi
  const vostok::configs::binary_config_value *v9; // eax
  float pointer; // xmm0_4
  const vostok::configs::binary_config_value *v11; // eax
  float v12; // xmm0_4
  vostok::configs::binary_config_value *v13; // ecx
  int v14; // eax
  bool v15; // zf
  const vostok::configs::binary_config_value *v16; // eax
  float v17; // xmm0_4
  vostok::configs::binary_config_value *v18; // eax
  const vostok::configs::binary_config_value *v19; // eax
  float v20; // xmm0_4
  int i; // esi
  const vostok::configs::binary_config_value *v22; // eax
  float v23; // xmm0_4
  const float *v24; // [esp-Ch] [ebp-48h]
  _DWORD v25[4]; // [esp+0h] [ebp-3Ch]
  const char *v26; // [esp+10h] [ebp-2Ch]
  const char *v27; // [esp+14h] [ebp-28h]
  const char *v28; // [esp+18h] [ebp-24h]
  const char *v29; // [esp+1Ch] [ebp-20h]
  const char *v30; // [esp+20h] [ebp-1Ch]
  const char *v31; // [esp+24h] [ebp-18h]
  const char *v32; // [esp+28h] [ebp-14h]
  const char *v33; // [esp+2Ch] [ebp-10h]
  const char *v34; // [esp+30h] [ebp-Ch]
  vostok::configs::binary_config_value *v35; // [esp+34h] [ebp-8h]
  float v36; // [esp+38h] [ebp-4h]

  v4 = (const vostok::configs::binary_config_value *)LODWORD(s_bm_current_air_resistance);
  v5 = cfg;
  v6 = (char *)&cfg->id.max_storage + 4;
  cfg->data.pointer = (char *)&cfg->id.max_storage + 4;
  HIDWORD(v5->data.max_storage) = v6;
  v5->id.pointer = v6 + 52;
  v5[2].id_crc = (unsigned int)&v5[3].data.max_storage + 4;
  *(_DWORD *)&v5[2].type = (char *)v5 + 76;
  v5[3].data.pointer = &v5[4].id_crc;
  cfg = v4;
  vostok::buffer_vector<float>::resize((vostok::buffer_vector<float> *)0xD, (int *)v5, (float *)&cfg, a2);
  v25[0] = "walk_fwd";
  v25[1] = "walk_side";
  v25[2] = "walk_back";
  v25[3] = "walk_aim_fwd";
  v26 = "walk_aim_side";
  v27 = "walk_aim_back";
  v28 = "crouch_fwd";
  v29 = "crouch_side";
  v30 = "crouch_back";
  v31 = "crouch_aim_fwd";
  v32 = "crouch_aim_side";
  v33 = "crouch_aim_back";
  v34 = "sprint_fwd";
  v35 = vostok::configs::binary_config_value::operator[](a4, "default");
  v7 = vostok::configs::binary_config_value::operator[](a4, "desired");
  a4 = 0;
  cfg = v7;
  do
  {
    v8 = *(char **)((char *)v25 + (_DWORD)a4);
    v9 = vostok::configs::binary_config_value::operator[](v35, v8);
    if ( v9->type == 2 )
      pointer = *(float *)&v9->data.pointer;
    else
      pointer = (float)(int)v9->data.pointer;
    v36 = pointer;
    v11 = vostok::configs::binary_config_value::operator[](cfg, v8);
    if ( v11->type == 2 )
      v12 = *(float *)&v11->data.pointer;
    else
      v12 = (float)(int)v11->data.pointer;
    v13 = a4;
    v14 = (int)v5->data.pointer;
    a4 = (vostok::configs::binary_config_value *)((char *)a4 + 4);
    v15 = a4 == (vostok::configs::binary_config_value *)52;
    *(float *)((char *)&v13->data.pointer + v14) = v12 / v36;
  }
  while ( !v15 );
  v16 = vostok::configs::binary_config_value::operator[](cfg, "walk_fwd");
  if ( v16->type == 2 )
    v17 = *(float *)&v16->data.pointer;
  else
    v17 = (float)(int)v16->data.pointer;
  v18 = cfg;
  *(float *)&v5[4].id_crc = v17;
  v19 = vostok::configs::binary_config_value::operator[](v18, "sprint_fwd");
  if ( v19->type == 2 )
    v20 = *(float *)&v19->data.pointer;
  else
    v20 = (float)(int)v19->data.pointer;
  *(float *)&v5[4].type = v20;
  v26 = "jump_on_site_landing(unused)";
  v27 = "jump_on_site_landing_fwd";
  v28 = "jump_on_site_landing_fwd_left";
  v29 = "jump_on_site_landing_fwd_right";
  v30 = "jump_on_site_landing_left";
  v31 = "jump_on_site_landing_right";
  v32 = "jump_on_site_landing_back";
  v33 = "jump_on_site_landing_back_left";
  v34 = "jump_on_site_landing_back_right";
  a4 = 0;
  vostok::buffer_vector<float>::resize((vostok::buffer_vector<float> *)9, (int *)&v5[2].id_crc, (float *)&a4, v24);
  for ( i = 1; i != 9; ++i )
  {
    v22 = vostok::configs::binary_config_value::operator[](v35, (char *)(&v26)[i]);
    if ( v22->type == 2 )
      v23 = *(float *)&v22->data.pointer;
    else
      v23 = (float)(int)v22->data.pointer;
    *(float *)(i * 4 + v5[2].id_crc) = v23;
  }
}
