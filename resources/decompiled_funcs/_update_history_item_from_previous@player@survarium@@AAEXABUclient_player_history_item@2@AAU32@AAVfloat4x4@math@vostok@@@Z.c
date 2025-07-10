void __thiscall survarium::player::update_history_item_from_previous(
        survarium::player *this,
        survarium::player *previous_item,
        survarium::client_player_history_item *item_to_update,
        survarium::client_player_history_item *previous_transform,
        vostok::math::float4x4 *previous_transforma)
{
  vostok::math::float3 *angles_xyz; // eax
  __int64 v6; // xmm0_8
  float z; // eax
  vostok::math::float4x4 *v8; // ecx
  vostok::math::float3 *v9; // eax
  float v10; // edx
  float v11; // xmm1_4
  float v12; // xmm2_4
  vostok::math::float4x4 *v13; // ecx
  vostok::math::float3 *v14; // eax
  __int64 v15; // xmm0_8
  float v16; // eax
  int v17; // eax
  float v18; // xmm1_4
  float v19; // xmm2_4
  float v20; // xmm3_4
  float v21; // xmm6_4
  float v22; // xmm5_4
  float v23; // xmm1_4
  float v24; // xmm6_4
  float v25; // xmm7_4
  float v26; // xmm2_4
  float v27; // xmm3_4
  __int64 v28; // xmm0_8
  int v29; // edx
  double look_pitch; // st7
  int **v31; // eax
  int v32; // edx
  int v33; // eax
  void (__stdcall *v34)(int, _DWORD); // edx
  vostok::physics::bullet_character_controller *v35; // ecx
  btTransform *transform; // eax
  vostok::math::quaternion v37; // [esp+A4h] [ebp-FCh] BYREF
  __m128i v38; // [esp+C0h] [ebp-E0h] BYREF
  vostok::math::float3 position; // [esp+DCh] [ebp-C4h] BYREF
  float v40; // [esp+E8h] [ebp-B8h]
  float *p_x; // [esp+ECh] [ebp-B4h]
  vostok::math::quaternion q; // [esp+F0h] [ebp-B0h] BYREF
  char *v43; // [esp+108h] [ebp-98h]
  unsigned int v44; // [esp+10Ch] [ebp-94h]
  _BYTE v45[64]; // [esp+110h] [ebp-90h] BYREF
  float v46[4]; // [esp+150h] [ebp-50h] BYREF
  btTransform v47; // [esp+160h] [ebp-40h] BYREF

  angles_xyz = vostok::math::float4x4::get_angles_xyz(
                 (vostok::math::float4x4 *)this,
                 (vostok::math::float3 *)LODWORD(v37.w));
  v6 = *(_QWORD *)&angles_xyz->x;
  z = angles_xyz->z;
  *(_QWORD *)&v37.x = v6;
  v37.z = z;
  vostok::math::quaternion::quaternion(&v37, (float *)v38.m128i_i32, *(vostok::math::float3 *)&v37.x);
  p_x = &previous_transform->action.state.transform.i.x;
  v9 = vostok::math::float4x4::get_angles_xyz(v8, (vostok::math::float3 *)LODWORD(v37.w));
  v10 = v9->z;
  *(_QWORD *)&v37.x = *(_QWORD *)&v9->x;
  v37.z = v10;
  vostok::math::quaternion::quaternion(&v37, &position.x, *(vostok::math::float3 *)&v37.x);
  q = (vostok::math::quaternion)_mm_load_si128(&v38);
  v11 = -*(float *)v38.m128i_i32;
  v12 = -*(float *)&v38.m128i_i32[1];
  *(float *)&v38.m128i_i32[3] = (float)((float)((float)(q.w * v40)
                                              - (float)(position.x * (float)-*(float *)v38.m128i_i32))
                                      - (float)(position.y * (float)-*(float *)&v38.m128i_i32[1]))
                              - (float)(position.z * (float)-*(float *)&v38.m128i_i32[2]);
  *(float *)v38.m128i_i32 = (float)((float)((float)(position.x * q.w)
                                          + (float)(position.z * (float)-*(float *)&v38.m128i_i32[1]))
                                  + (float)(v40 * (float)-*(float *)v38.m128i_i32))
                          - (float)(position.y * (float)-*(float *)&v38.m128i_i32[2]);
  *(float *)&v38.m128i_i32[1] = (float)((float)((float)(position.y * q.w) - (float)(position.z * v11))
                                      + (float)(position.x * (float)-*(float *)&v38.m128i_i32[2]))
                              + (float)(v40 * (float)-*(float *)&v38.m128i_i32[1]);
  *(float *)&v38.m128i_i32[2] = (float)((float)((float)(position.z * q.w) + (float)(position.y * v11))
                                      - (float)(position.x * v12))
                              + (float)(v40 * (float)-*(float *)&v38.m128i_i32[2]);
  v14 = vostok::math::float4x4::get_angles_xyz(v13, (vostok::math::float3 *)LODWORD(v37.w));
  v15 = *(_QWORD *)&v14->x;
  v16 = v14->z;
  *(_QWORD *)&v37.x = v15;
  v37.z = v16;
  vostok::math::quaternion::quaternion(&v37, v46, *(vostok::math::float3 *)&v37.x);
  v18 = *(float *)(v17 + 12);
  LODWORD(v15) = *(_DWORD *)v17;
  v19 = *(float *)(v17 + 4);
  v20 = *(float *)(v17 + 8);
  q.w = (float)((float)((float)(v18 * *(float *)&v38.m128i_i32[3]) - (float)(*(float *)v17 * *(float *)v38.m128i_i32))
              - (float)(v19 * *(float *)&v38.m128i_i32[1]))
      - (float)(v20 * *(float *)&v38.m128i_i32[2]);
  q.x = (float)((float)((float)(v19 * *(float *)&v38.m128i_i32[2])
                      + (float)(*(float *)&v15 * *(float *)&v38.m128i_i32[3]))
              + (float)(v18 * *(float *)v38.m128i_i32))
      - (float)(v20 * *(float *)&v38.m128i_i32[1]);
  v21 = v18;
  v22 = *(float *)&v15 * *(float *)&v38.m128i_i32[2];
  *(float *)&v15 = (float)(*(float *)&v15 * *(float *)&v38.m128i_i32[1]) + (float)(v18 * *(float *)&v38.m128i_i32[2]);
  v23 = previous_transform->action.state.transform.c.y - previous_transforma->c.y;
  v24 = (float)((float)(v21 * *(float *)&v38.m128i_i32[1]) - v22) + (float)(v19 * *(float *)&v38.m128i_i32[3]);
  v25 = v20;
  *(float *)&v15 = *(float *)&v15 - (float)(v19 * *(float *)v38.m128i_i32);
  v26 = previous_transform->action.state.transform.c.z - previous_transforma->c.z;
  q.z = *(float *)&v15 + (float)(v20 * *(float *)&v38.m128i_i32[3]);
  v27 = item_to_update->action.state.transform.c.x
      + (float)(previous_transform->action.state.transform.c.x - previous_transforma->c.x);
  *(float *)&v15 = item_to_update->action.state.transform.c.y;
  q.y = v24 + (float)(v25 * *(float *)v38.m128i_i32);
  *(float *)v38.m128i_i32 = v27;
  *(float *)&v38.m128i_i32[1] = *(float *)&v15 + v23;
  *(float *)&v15 = item_to_update->action.state.transform.c.z;
  qmemcpy((void *)previous_transforma, p_x, sizeof(vostok::math::float4x4));
  *(float *)&v38.m128i_i32[2] = *(float *)&v15 + v26;
  LODWORD(v37.z) = v45;
  memset(&position, 0, sizeof(position));
  vostok::math::create_matrix(&q, &position);
  v28 = v38.m128i_i64[0];
  v29 = v38.m128i_i32[2];
  v43 = (char *)&unk_10D44 + (_DWORD)previous_item;
  qmemcpy((char *)&unk_10D44 + (_DWORD)previous_item, v45, 0x40u);
  *(_QWORD *)&previous_item->m_target.transform.lines[3].x = v28;
  *(int *)((char *)&dword_10D7C + (_DWORD)previous_item) = v29;
  look_pitch = previous_transform->action.state.look_pitch;
  LODWORD(v37.z) = &previous_item->m_target;
  previous_item->m_target.look_pitch = look_pitch;
  survarium::player::set_physics_controller_walk_vector(0, (survarium::client_player_state *)LODWORD(v37.z));
  v31 = *(int ***)((char *)&dword_10DC8 + (_DWORD)previous_item);
  v32 = **v31;
  v44 = previous_transform->time_in_ms - item_to_update->time_in_ms;
  v33 = v31[1][13];
  v34 = *(void (__stdcall **)(int, _DWORD))(v32 + 4);
  v37.z = (double)v44 * 0.001;
  v34(v33, LODWORD(v37.z));
  transform = vostok::physics::bullet_character_controller::get_transform(
                v35,
                &v47,
                **(_DWORD **)((char *)&dword_10DC8 + (_DWORD)previous_item));
  vostok::physics::from_bullet(transform);
  qmemcpy(v43, v45, 0x40u);
  qmemcpy(p_x, v45, 0x40u);
}
