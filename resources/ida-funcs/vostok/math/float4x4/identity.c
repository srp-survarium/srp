vostok::math::float4x4 *__usercall vostok::math::float4x4::identity@<eax>(
        vostok::math::float4x4 *this@<ecx>,
        vostok::math::float4x4 *result@<eax>)
{
  float v2; // xmm1_4

  v2 = s_bm_current_air_resistance;
  *(_QWORD *)&result->i.x = LODWORD(s_bm_current_air_resistance);
  *(_QWORD *)&result->lines[0].elements[2] = 0;
  result->j.x = 0.0;
  *(_QWORD *)&result->lines[1].elements[1] = LODWORD(v2);
  *(_QWORD *)&result->lines[1].elements[3] = 0;
  result->k.y = 0.0;
  *(_QWORD *)&result->lines[2].elements[2] = LODWORD(v2);
  *(_QWORD *)&result->lines[3].x = 0;
  result->c.z = 0.0;
  result->c.w = v2;
  return result;
}
