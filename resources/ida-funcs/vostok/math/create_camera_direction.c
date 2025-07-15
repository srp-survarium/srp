vostok::math::float4x4 *__usercall vostok::math::create_camera_direction@<eax>(
        const vostok::math::float3 *view@<edi>,
        const vostok::math::float3 *local_up_in_world_space@<eax>,
        _QWORD *a3@<esi>,
        const vostok::math::float3 *from)
{
  float y; // xmm3_4
  float z; // xmm1_4
  float v6; // xmm0_4
  long double v7; // st7
  float v8; // xmm4_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  unsigned int v11; // xmm3_4
  unsigned int v12; // xmm0_4
  float v13; // xmm5_4
  __int64 v14; // xmm5_8
  float v15; // xmm4_4
  float v16; // xmm0_4
  float x; // [esp+8h] [ebp-34h]
  float v19; // [esp+Ch] [ebp-30h]
  float v20; // [esp+Ch] [ebp-30h]
  float v21; // [esp+10h] [ebp-2Ch]
  float v22; // [esp+14h] [ebp-28h]
  float v23; // [esp+18h] [ebp-24h]
  unsigned int v24; // [esp+18h] [ebp-24h]
  float v25; // [esp+1Ch] [ebp-20h]
  unsigned int v26; // [esp+1Ch] [ebp-20h]
  float right_8; // [esp+28h] [ebp-14h]
  __int64 v28; // [esp+2Ch] [ebp-10h]
  __int64 v29; // [esp+34h] [ebp-8h]

  y = view->y;
  z = view->z;
  v6 = -(float)((float)((float)(local_up_in_world_space->x * view->x) + (float)(local_up_in_world_space->y * y))
              + (float)(local_up_in_world_space->z * z));
  x = view->x;
  v22 = local_up_in_world_space->x + (float)(view->x * v6);
  v23 = local_up_in_world_space->y + (float)(y * v6);
  v25 = local_up_in_world_space->z + (float)(z * v6);
  v7 = sqrtf((float)((float)(v23 * v23) + (float)(v25 * v25)) + (float)(v22 * v22));
  v8 = view->z;
  *(float *)&v29 = x;
  v19 = 1.0 / v7;
  v9 = v19 * v22;
  v10 = (float)(v8 * (float)(v23 * v19)) - (float)(view->y * (float)(v25 * v19));
  *(float *)&v11 = (float)(x * (float)(v25 * v19)) - (float)(v8 * (float)(v19 * v22));
  *(float *)&v12 = (float)(view->y * (float)(v19 * v22)) - (float)(x * (float)(v23 * v19));
  *(float *)&v28 = v10;
  *((float *)&v28 + 1) = v19 * v22;
  *a3 = v28;
  *(float *)&v24 = v23 * v19;
  HIDWORD(v29) = 0;
  v13 = view->y;
  *(float *)&v26 = v25 * v19;
  right_8 = *(float *)&v12;
  a3[1] = (unsigned int)v29;
  v21 = v13;
  v29 = LODWORD(v13);
  v20 = view->z;
  a3[2] = __PAIR64__(v24, v11);
  v14 = v29;
  *(float *)&v29 = v20;
  a3[4] = __PAIR64__(v26, v12);
  HIDWORD(v29) = 0;
  v15 = from->y;
  a3[5] = (unsigned int)v29;
  v16 = from->z;
  a3[3] = v14;
  *(float *)&v14 = from->x;
  *(float *)&v28 = -(float)((float)((float)(v16 * right_8) + (float)(v15 * *(float *)&v11)) + (float)(from->x * v10));
  *(float *)&v29 = -(float)((float)((float)(v16 * v20) + (float)(v15 * v21)) + (float)(from->x * x));
  HIDWORD(v29) = clear_value;
  *((float *)&v28 + 1) = -(float)((float)((float)(v16 * *(float *)&v26) + (float)(*(float *)&v14 * v9))
                                + (float)(v15 * *(float *)&v24));
  a3[6] = v28;
  a3[7] = v29;
  return (vostok::math::float4x4 *)a3;
}
