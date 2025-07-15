vostok::math::float4_pod *__usercall vostok::math::linear_interpolation<vostok::math::float4_pod>@<eax>(
        vostok::math::float4_pod *result@<eax>,
        float a2@<xmm1>,
        vostok::math::float4_pod a,
        vostok::math::float4_pod b)
{
  float v4; // xmm4_4

  v4 = s_bm_current_air_resistance - a2;
  result->x = (float)(a.x * (float)(s_bm_current_air_resistance - a2)) + (float)(b.x * a2);
  result->y = (float)(a.y * v4) + (float)(b.y * a2);
  result->z = (float)(a.z * v4) + (float)(b.z * a2);
  result->w = (float)(a.w * v4) + (float)(b.w * a2);
  return result;
}
