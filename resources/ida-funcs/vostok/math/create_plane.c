vostok::math::plane *__fastcall vostok::math::create_plane(
        const vostok::math::float3 *first,
        const vostok::math::float3 *third,
        vostok::math::plane *second,
        float *a4)
{
  float y; // xmm1_4
  float z; // xmm7_4
  float x; // xmm4_4
  vostok::math::plane *result; // eax
  float v8; // xmm3_4
  float v9; // xmm6_4
  float v10; // xmm2_4
  float v11; // xmm5_4
  float v12; // xmm1_4
  float v13; // xmm7_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm6_4
  float v17; // xmm7_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm5_4
  float v21; // xmm2_4
  float v22; // xmm0_4
  float v23; // xmm3_4

  y = first->y;
  z = first->z;
  x = first->x;
  result = second;
  v8 = third->y - y;
  v9 = a4[1] - y;
  v10 = third->x - first->x;
  v11 = third->z - z;
  v12 = a4[2] - z;
  v13 = v12 * v8;
  v14 = v12 * v10;
  v15 = v10 * v9;
  v16 = (float)(v9 * v11) - v13;
  v17 = *a4 - first->x;
  v18 = (float)(v17 * v8) - v15;
  v19 = v14 - (float)(v17 * v11);
  v20 = s_bm_current_air_resistance / fsqrt((float)((float)(v18 * v18) + (float)(v19 * v19)) + (float)(v16 * v16));
  v21 = v20 * v18;
  v22 = first->z;
  v23 = (float)(v20 * v19) * first->y;
  second->normal.x = v20 * v16;
  second->normal.y = v20 * v19;
  second->normal.z = v21;
  LODWORD(second->d) = COERCE_UNSIGNED_INT((float)((float)(v22 * v21) + (float)(x * (float)(v20 * v16))) + v23)
                     ^ _mask__NegFloat_;
  return result;
}
