void __userpurge survarium::weapon_recoil_params::weapon_recoil_params(
        survarium::weapon_recoil_params *this@<ecx>,
        float *a2@<esi>,
        const vostok::configs::binary_config_value *cfg)
{
  const vostok::configs::binary_config_value *v4; // eax
  float pointer; // xmm1_4
  const vostok::configs::binary_config_value *v6; // eax
  vostok::configs::binary_config_value *v7; // ecx
  float v8; // xmm1_4
  float value_if; // xmm0_4
  vostok::configs::binary_config_value *v10; // ecx
  float v11; // xmm0_4
  vostok::configs::binary_config_value *v12; // ecx
  float v13; // xmm0_4
  vostok::configs::binary_config_value *v14; // ecx
  float v15; // xmm0_4
  vostok::configs::binary_config_value *v16; // ecx
  float v17; // xmm0_4
  vostok::configs::binary_config_value *v18; // ecx
  float v19; // xmm0_4
  vostok::configs::binary_config_value *v20; // ecx
  float v21; // xmm0_4
  vostok::configs::binary_config_value *v22; // ecx
  vostok::configs::binary_config_value *v23; // ecx
  float v24; // xmm0_4
  vostok::configs::binary_config_value *v25; // ecx
  float v26; // xmm0_4
  vostok::configs::binary_config_value *v27; // ecx
  float v28; // xmm0_4
  vostok::configs::binary_config_value *v29; // ecx
  float v30; // xmm0_4
  vostok::configs::binary_config_value *v31; // ecx
  float v32; // xmm0_4
  vostok::configs::binary_config_value *v33; // ecx
  float v34; // xmm0_4
  vostok::configs::binary_config_value *v35; // ecx
  float v36; // xmm0_4
  vostok::configs::binary_config_value *v37; // ecx
  vostok::configs::binary_config_value *v38; // ecx
  vostok::configs::binary_config_value *v39; // ecx
  vostok::configs::binary_config_value *v40; // ecx
  vostok::configs::binary_config_value *v41; // ecx
  vostok::configs::binary_config_value *v42; // ecx
  vostok::configs::binary_config_value *v43; // ecx
  float v44; // [esp+Ch] [ebp-4h]
  float cfga; // [esp+18h] [ebp+8h]

  *a2 = 0.0;
  a2[1] = 0.0;
  a2[2] = 0.0;
  a2[3] = 0.0;
  a2[4] = 0.0;
  a2[5] = 0.0;
  a2[6] = 0.0;
  a2[7] = 0.0;
  a2[8] = 0.0;
  a2[9] = 0.0;
  a2[10] = 0.0;
  a2[11] = 0.0;
  a2[12] = 0.0;
  a2[13] = 0.0;
  a2[14] = 0.0;
  a2[15] = 0.0;
  a2[21] = 0.0;
  a2[16] = 0.0;
  a2[17] = 0.0;
  a2[18] = 0.0;
  a2[19] = 0.0;
  a2[20] = 0.0;
  v4 = vostok::configs::binary_config_value::operator[](cfg, "horizontal_recoil_anim_range");
  if ( v4->type == 2 )
    pointer = *(float *)&v4->data.pointer;
  else
    pointer = (float)(int)v4->data.pointer;
  cfga = s_bm_current_air_resistance / pointer;
  v6 = vostok::configs::binary_config_value::operator[](cfg, "vertical_recoil_anim_range");
  if ( v6->type == 2 )
    v8 = *(float *)&v6->data.pointer;
  else
    v8 = (float)(int)v6->data.pointer;
  v44 = s_bm_current_air_resistance / v8;
  value_if = survarium::read_value_if_exists<float>("max_first_shoot_left_recoil", v7, cfg, 0.0);
  *a2 = value_if;
  v11 = survarium::read_value_if_exists<float>("min_first_shoot_left_recoil", v10, cfg, value_if * 0.25);
  *a2 = *a2 * cfga;
  a2[1] = v11 * cfga;
  v13 = survarium::read_value_if_exists<float>("max_first_shoot_right_recoil", v12, cfg, 0.0);
  a2[2] = v13;
  v15 = survarium::read_value_if_exists<float>("min_first_shoot_right_recoil", v14, cfg, v13 * 0.25);
  a2[2] = a2[2] * cfga;
  a2[3] = v15 * cfga;
  v17 = survarium::read_value_if_exists<float>("max_first_shoot_top_recoil", v16, cfg, 0.0);
  a2[4] = v17;
  v19 = survarium::read_value_if_exists<float>("min_first_shoot_top_recoil", v18, cfg, v17 * 0.25);
  a2[4] = a2[4] * v44;
  a2[5] = v19 * v44;
  v21 = survarium::read_value_if_exists<float>("max_first_shoot_back_recoil", v20, cfg, 0.0);
  a2[6] = v21;
  a2[7] = survarium::read_value_if_exists<float>("min_first_shoot_back_recoil", v22, cfg, v21 * 0.25);
  v24 = survarium::read_value_if_exists<float>("max_queue_shoot_left_recoil", v23, cfg, 0.0);
  a2[8] = v24;
  v26 = survarium::read_value_if_exists<float>("min_queue_shoot_left_recoil", v25, cfg, v24 * 0.25);
  a2[8] = a2[8] * cfga;
  a2[9] = v26 * cfga;
  v28 = survarium::read_value_if_exists<float>("max_queue_shoot_right_recoil", v27, cfg, 0.0);
  a2[10] = v28;
  v30 = survarium::read_value_if_exists<float>("min_queue_shoot_right_recoil", v29, cfg, v28 * 0.25);
  a2[10] = cfga * a2[10];
  a2[11] = v30 * cfga;
  v32 = survarium::read_value_if_exists<float>("max_queue_shoot_top_recoil", v31, cfg, 0.0);
  a2[12] = v32;
  v34 = survarium::read_value_if_exists<float>("min_queue_shoot_top_recoil", v33, cfg, v32 * 0.25);
  a2[12] = a2[12] * v44;
  a2[13] = v34 * v44;
  v36 = survarium::read_value_if_exists<float>("max_queue_shoot_back_recoil", v35, cfg, 0.0);
  a2[14] = v36;
  a2[15] = survarium::read_value_if_exists<float>("min_queue_shoot_back_recoil", v37, cfg, v36 * 0.25);
  a2[16] = survarium::read_value_if_exists<float>("side_compensation_speed", v38, cfg, 0.0) * v44;
  a2[17] = survarium::read_value_if_exists<float>("side_increase_speed", v39, cfg, 0.0) * v44;
  a2[18] = survarium::read_value_if_exists<float>("back_recoil_max_limit", v40, cfg, 0.0);
  a2[19] = survarium::read_value_if_exists<float>("back_compensation_speed", v41, cfg, 0.0);
  a2[20] = survarium::read_value_if_exists<float>("back_increase_speed", v42, cfg, 0.0);
  *((_DWORD *)a2 + 21) = (unsigned __int64)(survarium::read_value_if_exists<float>(
                                              "side_compensation_delay",
                                              v43,
                                              cfg,
                                              0.0)
                                          * 1000.0);
}
