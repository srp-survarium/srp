vostok::math::float4x4 *__usercall vostok::math::create_camera_at@<eax>(
        const vostok::math::float3 *from@<eax>,
        const vostok::math::float3 *at@<ecx>,
        vostok::math::float4x4 *up,
        const vostok::math::float3 *a4)
{
  float v4; // xmm1_4
  float v5; // xmm3_4
  float v6; // xmm2_4
  float v7; // xmm0_4
  vostok::math::float3 v9; // [esp+4h] [ebp-Ch] BYREF

  v4 = at->x - from->x;
  v5 = at->z - from->z;
  v6 = at->y - from->y;
  v7 = s_bm_current_air_resistance / fsqrt((float)((float)(v5 * v5) + (float)(v4 * v4)) + (float)(v6 * v6));
  v9.x = v7 * v4;
  v9.y = v7 * v6;
  v9.z = v7 * v5;
  vostok::math::create_camera_direction(&v9, a4, up, &from->x);
  return up;
}
