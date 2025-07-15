vostok::math::float4x4 *__usercall vostok::math::create_translation@<eax>(
        const vostok::math::float3 *position@<ecx>,
        vostok::math::float4x4 *result@<eax>)
{
  float v2; // xmm1_4
  float x; // xmm0_4
  __int64 v4; // [esp+4h] [ebp-Ch]

  v2 = s_bm_current_air_resistance;
  *(_QWORD *)&result->i.x = LODWORD(s_bm_current_air_resistance);
  *(_QWORD *)&result->lines[0].elements[2] = 0;
  result->j.x = 0.0;
  *(_QWORD *)&result->lines[1].elements[1] = LODWORD(v2);
  result->j.w = 0.0;
  x = position->x;
  *(_QWORD *)&result->lines[2].x = 0;
  *(_QWORD *)&result->lines[2].elements[2] = LODWORD(v2);
  v4 = *(_QWORD *)&position->elements[1];
  result->c.x = x;
  *(_QWORD *)&result->lines[3].elements[1] = v4;
  result->c.w = v2;
  return result;
}
