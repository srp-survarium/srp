vostok::math::float4x4 *__usercall vostok::math::create_scale@<eax>(
        const vostok::math::float3 *scale@<edi>,
        vostok::math::float4x4 *a2@<esi>)
{
  float v2; // xmm0_4
  vostok::math::float4x4 *result; // eax

  memset((int)a2, 0, sizeof(vostok::math::float4x4));
  v2 = s_bm_current_air_resistance;
  a2->i.x = scale->x;
  a2->j.y = scale->y;
  a2->c.w = v2;
  result = a2;
  a2->k.z = scale->z;
  return result;
}
