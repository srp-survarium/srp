vostok::math::float4x4 *__fastcall vostok::math::create_camera_direction(
        const vostok::math::float3 *view,
        const vostok::math::float3 *local_up_in_world_space,
        vostok::math::float4x4 *from,
        float *a4)
{
  float y; // xmm4_4
  float z; // xmm2_4
  float v6; // xmm0_4
  float v7; // xmm5_4
  float v8; // xmm3_4
  vostok::math::float4x4 *result; // eax
  float v11; // xmm6_4
  float v12; // xmm2_4
  float v13; // xmm5_4
  float v14; // xmm3_4
  float v15; // xmm2_4
  float v16; // xmm6_4
  float v17; // xmm7_4
  float v18; // xmm3_4
  float v19; // xmm4_4
  float v20; // xmm5_4
  float v21; // xmm6_4
  float v22; // xmm0_4
  float v23; // xmm5_4
  float v24; // [esp+4h] [ebp-28h]
  _BYTE v25[12]; // [esp+8h] [ebp-24h]
  float v26; // [esp+Ch] [ebp-20h]
  float v27; // [esp+1Ch] [ebp-10h]
  float v28; // [esp+24h] [ebp-8h]
  float x; // [esp+38h] [ebp+Ch]

  y = view->y;
  z = view->z;
  LODWORD(v6) = COERCE_UNSIGNED_INT(
                  (float)((float)(local_up_in_world_space->x * view->x) + (float)(local_up_in_world_space->y * y))
                + (float)(local_up_in_world_space->z * z))
              ^ _mask__NegFloat_;
  v7 = local_up_in_world_space->y + (float)(y * v6);
  v8 = local_up_in_world_space->z + (float)(z * v6);
  result = from;
  x = view->x;
  v11 = local_up_in_world_space->x + (float)(view->x * v6);
  v12 = fsqrt((float)((float)(v7 * v7) + (float)(v8 * v8)) + (float)(v11 * v11));
  v13 = v7 * (float)(s_bm_current_air_resistance / v12);
  v14 = v8 * (float)(s_bm_current_air_resistance / v12);
  v15 = (float)(s_bm_current_air_resistance / v12) * v11;
  v16 = v13;
  v17 = v14;
  v18 = (float)(view->z * v13) - (float)(y * v14);
  v19 = (float)(view->x * v17) - (float)(view->z * v15);
  v20 = (float)(view->y * v15) - (float)(view->x * v13);
  v26 = view->x;
  from->i.x = v18;
  from->i.y = v15;
  *(_QWORD *)&from->lines[0].elements[2] = LODWORD(v26);
  v28 = v16;
  *(float *)v25 = v16;
  v27 = v20;
  *(float *)&v25[4] = view->y;
  v21 = *a4;
  from->j.x = v19;
  *(_QWORD *)&from->lines[1].elements[1] = *(_QWORD *)v25;
  from->j.w = 0.0;
  v22 = a4[2];
  v24 = v20;
  *(float *)&v25[4] = view->z;
  v23 = a4[1];
  from->k.x = v24;
  from->k.y = v17;
  *(_QWORD *)&from->lines[2].elements[2] = *(unsigned int *)&v25[4];
  *(_DWORD *)&v25[4] = COERCE_UNSIGNED_INT((float)((float)(v22 * view->z) + (float)(v23 * view->y)) + (float)(v21 * x))
                     ^ _mask__NegFloat_;
  *(float *)&v25[8] = s_bm_current_air_resistance;
  LODWORD(from->c.x) = COERCE_UNSIGNED_INT((float)((float)(v22 * v27) + (float)(v23 * v19)) + (float)(v21 * v18))
                     ^ _mask__NegFloat_;
  LODWORD(from->c.y) = COERCE_UNSIGNED_INT((float)((float)(v22 * v17) + (float)(v21 * v15)) + (float)(v23 * v28))
                     ^ _mask__NegFloat_;
  *(_QWORD *)&from->lines[3].elements[2] = *(_QWORD *)&v25[4];
  return result;
}
