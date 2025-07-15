void __userpurge survarium::player::smooth(
        survarium::player *this@<ecx>,
        vostok::math::float3 *a2@<edi>,
        float time_delta,
        float time_deltaa)
{
  float *v4; // ebp
  vostok::math::float4x4 *v5; // ecx
  const vostok::math::float4x4 *v6; // xmm7_4
  vostok::math::quaternion *v7; // ecx
  char *v8; // esi
  bool v9; // zf
  float v10; // xmm6_4
  float v11; // xmm4_4
  float v12; // eax
  float v13; // xmm1_4
  float v14; // xmm3_4
  __int64 v15; // xmm0_8
  float v16; // xmm0_4
  vostok::math::float3 v17; // [esp-8h] [ebp-D8h]
  vostok::math::float3 v18; // [esp-8h] [ebp-D8h]
  vostok::math::float3 *v19; // [esp+4h] [ebp-CCh]
  vostok::math::quaternion right_rotation; // [esp+18h] [ebp-B8h] BYREF
  float t; // [esp+28h] [ebp-A8h]
  vostok::math::quaternion left_rotation; // [esp+2Ch] [ebp-A4h] BYREF
  vostok::math::quaternion q; // [esp+3Ch] [ebp-94h] BYREF
  vostok::math::float4x4 result; // [esp+4Ch] [ebp-84h] BYREF
  char v25; // [esp+8Ch] [ebp-44h] BYREF

  if ( time_deltaa > 0.0 )
  {
    v4 = (float *)((char *)&unk_10D44 + LODWORD(time_delta));
    vostok::math::float4x4::get_angles_xyz((vostok::math::float4x4 *)this, a2);
    vostok::math::float4x4::get_angles_xyz(v5, v19);
    v6 = clear_value;
    if ( left_rotation.x == right_rotation.x
      && left_rotation.y == right_rotation.y
      && left_rotation.z == right_rotation.z )
    {
      v8 = (char *)(LODWORD(time_delta) + 34672);
    }
    else
    {
      *(_QWORD *)&v17.x = *(_QWORD *)&left_rotation.x;
      v17.z = left_rotation.z;
      vostok::math::quaternion::quaternion((vostok::math::quaternion *)LODWORD(left_rotation.z), &left_rotation.x, v17);
      *(_QWORD *)&v18.x = *(_QWORD *)&right_rotation.x;
      v18.z = right_rotation.z;
      vostok::math::quaternion::quaternion(v7, &right_rotation.x, v18);
      if ( (float)((float)((float)(s_smooth_angular_speed * 0.0055555557) * 3.1415927) * time_deltaa) <= *(float *)&clear_value )
        t = (float)((float)(s_smooth_angular_speed * 0.0055555557) * 3.1415927) * time_deltaa;
      else
        t = *(float *)&clear_value;
      slerp_optimized(&left_rotation, &right_rotation, t);
      memset(&right_rotation, 0, 12);
      vostok::math::create_matrix(&q, (const vostok::math::float3 *)&right_rotation);
      v6 = clear_value;
      v8 = &v25;
    }
    v9 = *(float *)(LODWORD(time_delta) + 34720) == v4[12];
    qmemcpy((void *)&result, v8, sizeof(result));
    if ( v9 && *(float *)(LODWORD(time_delta) + 34724) == v4[13] && *(float *)(LODWORD(time_delta) + 34728) == v4[14] )
    {
      v12 = time_delta;
      v15 = *(_QWORD *)(LODWORD(time_delta) + 34720);
      result.c.z = *(float *)(LODWORD(time_delta) + 34728);
    }
    else
    {
      v10 = s_smooth_linear_speed * time_deltaa;
      if ( (float)(s_smooth_linear_speed * time_deltaa) > *(float *)&v6 )
        v10 = *(float *)&v6;
      v11 = *(float *)(LODWORD(time_delta) + 34724);
      v12 = time_delta;
      v13 = (float)(v4[13] - v11) * v10;
      v14 = *(float *)(LODWORD(time_delta) + 34720)
          + (float)((float)(v4[12] - *(float *)(LODWORD(time_delta) + 34720)) * v10);
      right_rotation.z = *(float *)(LODWORD(time_delta) + 34728)
                       + (float)((float)(v4[14] - *(float *)(LODWORD(time_delta) + 34728)) * v10);
      right_rotation.x = v14;
      right_rotation.y = v11 + v13;
      v15 = *(_QWORD *)&right_rotation.x;
      result.c.z = right_rotation.z;
    }
    *(_QWORD *)&result.lines[3].x = v15;
    qmemcpy((void *)(LODWORD(time_delta) + 34672), &result, 0x40u);
    v16 = s_smooth_pitch_speed * time_deltaa;
    if ( (float)(s_smooth_pitch_speed * time_deltaa) > *(float *)&v6 )
      v16 = *(float *)&v6;
    *(float *)(LODWORD(v12) + 34808) = (float)((float)(*(float *)((char *)&dword_10DCC + LODWORD(v12))
                                                     - *(float *)(LODWORD(v12) + 34808))
                                             * v16)
                                     + *(float *)(LODWORD(v12) + 34808);
  }
}
