vostok::math::float4x4 *__usercall vostok::math::create_rotation_z@<eax>(
        long double a1@<esi:edi>,
        __m128i a2@<xmm0>,
        vostok::math::float4x4 *result,
        float angle)
{
  float v4; // xmm1_4

  *(double *)a2.m128i_i64 = angle;
  __libm_sse2_sin(a2);
  __libm_sse2_cos(a1);
  result->i.x = angle;
  *(_QWORD *)&result->e01 = LODWORD(angle) ^ (unsigned int)_mask__NegFloat_;
  result->i.w = 0.0;
  v4 = s_bm_current_air_resistance;
  result->j.x = angle;
  *(_QWORD *)&result->lines[1].elements[1] = LODWORD(angle);
  *(_QWORD *)&result->lines[1].elements[3] = 0;
  result->k.y = 0.0;
  *(_QWORD *)&result->lines[2].elements[2] = LODWORD(v4);
  *(_QWORD *)&result->lines[3].x = 0;
  result->c.z = 0.0;
  result->c.w = v4;
  return result;
}
