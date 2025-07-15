vostok::math::float4x4 *__usercall vostok::math::create_rotation_x@<eax>(
        long double a1@<esi:edi>,
        __m128i a2@<xmm0>,
        vostok::math::float4x4 *result,
        float angle)
{
  float v4; // xmm1_4

  *(double *)a2.m128i_i64 = angle;
  __libm_sse2_sin(a2);
  __libm_sse2_cos(a1);
  v4 = s_bm_current_air_resistance;
  *(_QWORD *)&result->i.x = LODWORD(s_bm_current_air_resistance);
  *(_QWORD *)&result->lines[0].elements[2] = 0;
  result->j.x = 0.0;
  result->j.y = angle;
  *(_QWORD *)&result->lines[1].elements[2] = LODWORD(angle) ^ (unsigned int)_mask__NegFloat_;
  result->k.x = 0.0;
  result->k.y = angle;
  *(_QWORD *)&result->lines[2].elements[2] = LODWORD(angle);
  *(_QWORD *)&result->lines[3].x = 0;
  result->c.z = 0.0;
  result->c.w = v4;
  return result;
}
