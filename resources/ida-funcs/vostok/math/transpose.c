vostok::math::float4x4 *__usercall vostok::math::transpose@<eax>(
        const vostok::math::float4x4 *other@<ecx>,
        vostok::math::float4x4 *result@<eax>)
{
  float y; // xmm0_4
  float z; // xmm0_4
  float w; // xmm0_4
  vostok::math::float4_pod v5; // [esp+0h] [ebp-10h]
  float x; // [esp+Ch] [ebp-4h]

  v5.y = other->j.x;
  v5.z = other->k.x;
  x = other->c.x;
  y = other->i.y;
  result->i.x = other->i.x;
  *(_QWORD *)&result->e01 = *(_QWORD *)&v5.elements[1];
  result->i.w = x;
  v5.x = y;
  v5.y = other->j.y;
  v5.z = other->k.y;
  v5.w = other->c.y;
  z = other->i.z;
  result->j = v5;
  v5.x = z;
  v5.y = other->j.z;
  v5.z = other->k.z;
  v5.w = other->c.z;
  w = other->i.w;
  result->k = v5;
  v5.y = other->j.w;
  v5.z = other->k.w;
  v5.w = other->c.w;
  result->c.x = w;
  *(_QWORD *)&result->lines[3].elements[1] = *(_QWORD *)&v5.elements[1];
  result->c.w = v5.w;
  return result;
}
