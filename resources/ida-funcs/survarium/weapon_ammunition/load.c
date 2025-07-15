void __userpurge survarium::weapon_ammunition::load(
        survarium::weapon_ammunition *this@<ecx>,
        int a2@<esi>,
        const vostok::configs::binary_config_value *cfg)
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
  float v23; // xmm0_4
  const vostok::configs::binary_config_value *v24; // eax
  float v25; // xmm0_4
  const vostok::configs::binary_config_value *v26; // eax
  float v27; // xmm0_4
  const vostok::configs::binary_config_value *v28; // eax
  float v29; // xmm0_4
  const vostok::configs::binary_config_value *v30; // eax
  float v31; // xmm0_4

  v3 = vostok::configs::binary_config_value::operator[](cfg, "distance");
  if ( v3->type == 2 )
    pointer = *(float *)&v3->data.pointer;
  else
    pointer = (float)(int)v3->data.pointer;
  *(float *)(a2 + 288) = pointer;
  v5 = vostok::configs::binary_config_value::operator[](cfg, "dispersion");
  if ( v5->type == 2 )
    v6 = *(float *)&v5->data.pointer;
  else
    v6 = (float)(int)v5->data.pointer;
  *(float *)(a2 + 292) = v6;
  v7 = vostok::configs::binary_config_value::operator[](cfg, "k_damage");
  if ( v7->type == 2 )
    v8 = *(float *)&v7->data.pointer;
  else
    v8 = (float)(int)v7->data.pointer;
  *(float *)(a2 + 296) = v8;
  v9 = vostok::configs::binary_config_value::operator[](cfg, "k_max_damage_distance");
  if ( v9->type == 2 )
    v10 = *(float *)&v9->data.pointer;
  else
    v10 = (float)(int)v9->data.pointer;
  *(float *)(a2 + 300) = v10;
  v11 = vostok::configs::binary_config_value::operator[](cfg, "k_min_damage_distance");
  if ( v11->type == 2 )
    v12 = *(float *)&v11->data.pointer;
  else
    v12 = (float)(int)v11->data.pointer;
  *(float *)(a2 + 304) = v12;
  v13 = vostok::configs::binary_config_value::operator[](cfg, "k_min_damage_amount");
  if ( v13->type == 2 )
    v14 = *(float *)&v13->data.pointer;
  else
    v14 = (float)(int)v13->data.pointer;
  *(float *)(a2 + 308) = v14;
  v15 = vostok::configs::binary_config_value::operator[](cfg, "k_arp");
  if ( v15->type == 2 )
    v16 = *(float *)&v15->data.pointer;
  else
    v16 = (float)(int)v15->data.pointer;
  *(float *)(a2 + 312) = v16;
  v17 = vostok::configs::binary_config_value::operator[](cfg, "air_resistance");
  if ( v17->type == 2 )
    v18 = *(float *)&v17->data.pointer;
  else
    v18 = (float)(int)v17->data.pointer;
  *(float *)(a2 + 316) = v18;
  *(_BYTE *)(a2 + 344) = vostok::configs::binary_config_value::operator[](cfg, "buck_shot")->data.pointer;
  v19 = vostok::configs::binary_config_value::operator[](cfg, "buck_dispersion");
  if ( v19->type == 2 )
    v20 = *(float *)&v19->data.pointer;
  else
    v20 = (float)(int)v19->data.pointer;
  *(float *)(a2 + 340) = v20;
  *(_WORD *)(a2 + 346) = vostok::configs::binary_config_value::operator[](cfg, "game_material_id")->data.pointer;
  *(_BYTE *)(a2 + 348) = vostok::configs::binary_config_value::operator[](cfg, "tracer")->data.pointer != 0;
  v21 = vostok::configs::binary_config_value::operator[](cfg, "ricochet_angle");
  if ( v21->type == 2 )
    v22 = *(float *)&v21->data.pointer;
  else
    v22 = (float)(int)v21->data.pointer;
  v23 = (float)(v22 * 0.0055555557) * 3.1415927;
  if ( v23 >= 1.5707964 )
    v23 = pi_d2_11;
  *(float *)(a2 + 320) = v23;
  v24 = vostok::configs::binary_config_value::operator[](cfg, "ricochet_dispersion_angle");
  if ( v24->type == 2 )
    v25 = *(float *)&v24->data.pointer;
  else
    v25 = (float)(int)v24->data.pointer;
  *(float *)(a2 + 324) = (float)(v25 * 0.0055555557) * 3.1415927;
  v26 = vostok::configs::binary_config_value::operator[](cfg, "pierce_dispersion_angle");
  if ( v26->type == 2 )
    v27 = *(float *)&v26->data.pointer;
  else
    v27 = (float)(int)v26->data.pointer;
  *(float *)(a2 + 328) = (float)(v27 * 0.0055555557) * 3.1415927;
  v28 = vostok::configs::binary_config_value::operator[](cfg, "ricochet_chance");
  if ( v28->type == 2 )
    v29 = *(float *)&v28->data.pointer;
  else
    v29 = (float)(int)v28->data.pointer;
  *(float *)(a2 + 332) = v29;
  *(_DWORD *)(a2 + 352) = vostok::configs::binary_config_value::operator[](cfg, "ammo_type")->data.pointer;
  v30 = vostok::configs::binary_config_value::operator[](cfg, "muzzle_speed");
  if ( v30->type == 2 )
    v31 = *(float *)&v30->data.pointer;
  else
    v31 = (float)(int)v30->data.pointer;
  *(float *)(a2 + 336) = v31;
}
