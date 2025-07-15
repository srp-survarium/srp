void __userpurge survarium::base_player::set_physics_controller_walk_vector(
        survarium::base_player *this@<ecx>,
        float a2@<xmm0>,
        const unsigned int delta_time_in_ms,
        unsigned int a4)
{
  survarium::player_params_modifiers_enum v4; // edx
  survarium::player_params_modifiers_container *v5; // ecx
  survarium::player_input *v6; // ecx
  vostok::physics::bt_character_controller *v7; // ecx
  float v8; // xmm0_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  _DWORD *v11; // eax
  vostok::physics::bt_character_controller *v12; // ecx
  vostok::math::float3 *v13; // eax
  unsigned int v14; // xmm2_4
  unsigned int v15; // xmm0_4
  vostok::math::float3 *p_air_control_vector; // esi
  int v17; // edi
  vostok::physics::bt_character_controller *v18; // esi
  float v19; // xmm1_4
  float v20; // xmm0_4
  float v21; // xmm1_4
  unsigned int v22; // [esp+8h] [ebp-90h]
  float v23; // [esp+14h] [ebp-84h]
  float v24; // [esp+14h] [ebp-84h]
  float v25; // [esp+14h] [ebp-84h]
  vostok::math::float3 air_control_speed; // [esp+18h] [ebp-80h] BYREF
  vostok::math::float3 air_control_vector; // [esp+24h] [ebp-74h] BYREF
  survarium::player_input *input; // [esp+30h] [ebp-68h]
  float v29; // [esp+34h] [ebp-64h]
  btVector3 walk_vector; // [esp+38h] [ebp-60h] BYREF
  float *v31; // [esp+48h] [ebp-50h]
  float v32; // [esp+4Ch] [ebp-4Ch] BYREF
  float v33; // [esp+50h] [ebp-48h]
  float v34; // [esp+54h] [ebp-44h]
  vostok::math::float4x4 transform; // [esp+58h] [ebp-40h] BYREF

  v31 = (float *)&byte_10E2C[delta_time_in_ms];
  qmemcpy(&transform, &byte_10E2C[delta_time_in_ms], sizeof(transform));
  air_control_speed = *(vostok::math::float3 *)((char *)&loc_1110F + delta_time_in_ms + 1);
  *(_QWORD *)&transform.lines[3].x = *(_QWORD *)((char *)&loc_1110F + delta_time_in_ms + 1);
  transform.c.z = *(float *)((char *)&loc_1110F + delta_time_in_ms + 9);
  vostok::physics::bt_character_controller::set_transform(
    0,
    *(const btTransform ***)((char *)&dword_10E74 + delta_time_in_ms),
    &transform,
    v22);
  v23 = survarium::player_params_modifiers_container::apply_modifier(
          (survarium::player_params_modifiers_container *)(*(_DWORD *)((char *)&loc_11066 + delta_time_in_ms + 2) + 448),
          movement_speed_modifier,
          a2,
          *(float *)(delta_time_in_ms + 444),
          1.0);
  v29 = survarium::player_params_modifiers_container::apply_modifier(
          v5,
          v4,
          v23,
          *(float *)(delta_time_in_ms + 440),
          1.0);
  input = (survarium::player_input *)(delta_time_in_ms + 744);
  if ( survarium::player_input::is_sprinting(v6, delta_time_in_ms + 744)
    && (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)(delta_time_in_ms + 320) + 80))(*(_DWORD *)(delta_time_in_ms + 320)) )
  {
    v8 = v23;
  }
  else
  {
    v8 = v29;
  }
  v24 = v8;
  v9 = *(float *)&byte_10E5C[delta_time_in_ms] - air_control_speed.x;
  v33 = *(float *)&byte_10E5C[delta_time_in_ms + 4] - air_control_speed.y;
  v25 = (double)a4 * v24 * 0.001;
  v10 = *(float *)&byte_10E5C[delta_time_in_ms + 8] - air_control_speed.z;
  v11 = *(_DWORD **)((char *)&dword_10E74 + delta_time_in_ms);
  v32 = v9;
  v34 = v10;
  *(_QWORD *)&air_control_vector.x = LODWORD(v9);
  air_control_vector.z = v10;
  if ( vostok::physics::bt_character_controller::is_in_jump(v7, v11)
    || (float)(v25 * v25) > (float)((float)(v10 * v10) + (float)(v9 * v9)) )
  {
    p_air_control_vector = (vostok::math::float3 *)&v32;
  }
  else
  {
    memset(&air_control_speed, 0, sizeof(air_control_speed));
    v13 = vostok::math::normalize_safe(&air_control_vector, &air_control_speed, (vostok::math::float3 *)&walk_vector);
    *(float *)&v14 = v13->z * v25;
    *(float *)&v15 = (float)(v13->y * v25) + v33;
    air_control_vector.x = v13->x * v25;
    *(_QWORD *)&air_control_vector.elements[1] = __PAIR64__(v14, v15);
    p_air_control_vector = &air_control_vector;
  }
  air_control_speed = *p_air_control_vector;
  walk_vector.mVec128.m128_u64[0] = *(_QWORD *)&air_control_speed.x;
  walk_vector.mVec128.m128_u64[1] = LODWORD(air_control_speed.z) ^ (unsigned __int64)(unsigned int)_mask__NegFloat_;
  if ( s_cc_use_old_controller_value )
  {
    vostok::physics::old_bullet_character_controller::set_desired_walk_vector(
      *(vostok::physics::old_bullet_character_controller **)(*(int *)((char *)&dword_10E74 + delta_time_in_ms) + 4),
      &walk_vector);
  }
  else
  {
    v17 = **(_DWORD **)((char *)&dword_10E74 + delta_time_in_ms) + 32;
    *(_DWORD *)v17 = walk_vector.mVec128.m128_i32[0];
    v17 += 4;
    *(_DWORD *)v17 = walk_vector.mVec128.m128_i32[1];
    *(_QWORD *)(v17 + 4) = walk_vector.mVec128.m128_u64[1];
  }
  v18 = *(vostok::physics::bt_character_controller **)((char *)&dword_10E74 + delta_time_in_ms);
  if ( vostok::physics::bt_character_controller::is_in_jump(v12, v18) )
  {
    if ( *(_DWORD *)(delta_time_in_ms + 760) )
      survarium::get_air_control_vector(
        &air_control_speed.x,
        *(float *)(delta_time_in_ms + 712),
        *(_DWORD *)(delta_time_in_ms + 760));
    else
      memset(&air_control_speed, 0, sizeof(air_control_speed));
    v19 = v31[5] * air_control_speed.y;
    air_control_vector.x = (float)((float)(v31[8] * air_control_speed.z) + (float)(v31[4] * air_control_speed.y))
                         + (float)(*v31 * air_control_speed.x);
    v20 = (float)((float)(v31[9] * air_control_speed.z) + v19) + (float)(v31[1] * air_control_speed.x);
    v21 = v31[6] * air_control_speed.y;
    air_control_vector.y = v20;
    air_control_vector.z = (float)((float)(v31[10] * air_control_speed.z) + v21) + (float)(v31[2] * air_control_speed.x);
  }
  else
  {
    memset(&air_control_vector, 0, sizeof(air_control_vector));
  }
  vostok::physics::bt_character_controller::set_air_control_vector(v18, &air_control_vector);
}
