vostok::math::float4x4 *__usercall vostok::animation::calculated_head_matrix@<eax>(
        vostok::math::float4x4 *a1@<esi>,
        vostok::math::float4x4 *result,
        const vostok::math::float4x4 *head_matrix)
{
  const vostok::math::float4x4 *v3; // edi
  const vostok::math::float4x4 *v4; // eax
  float x; // xmm2_4
  float y; // xmm0_4
  float z; // xmm3_4
  float v8; // xmm4_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm3_4
  vostok::math::float3 v13; // [esp+4h] [ebp-D8h] BYREF
  vostok::math::float3 angles; // [esp+10h] [ebp-CCh] BYREF
  vostok::math::float4x4 resulta; // [esp+1Ch] [ebp-C0h] BYREF
  vostok::math::float4x4 left; // [esp+5Ch] [ebp-80h] BYREF
  vostok::math::float4x4 v17; // [esp+9Ch] [ebp-40h] BYREF

  *(_QWORD *)&angles.x = 0;
  angles.z = pi_d2_8;
  v13.x = 0.0;
  *(_QWORD *)&v13.elements[1] = LODWORD(pi_d2_8);
  v3 = vostok::math::create_rotation(&resulta, &angles);
  v4 = vostok::math::create_rotation(&v17, &v13);
  vostok::math::mul4x3(&left, v4, v3);
  vostok::math::mul4x3(&resulta, &left, result);
  vostok::math::mul4x3(a1, &resulta, head_matrix);
  x = a1->j.x;
  y = a1->j.y;
  a1->c.z = (float)(a1->j.z * 0.1) + a1->c.z;
  a1->c.y = (float)(y * 0.1) + a1->c.y;
  a1->c.x = a1->c.x + (float)(x * 0.1);
  z = a1->i.z;
  v8 = a1->c.x + (float)(a1->i.x * 0.0);
  a1->c.y = a1->c.y + (float)(a1->i.y * 0.0);
  v9 = a1->c.z;
  a1->c.x = v8;
  a1->c.z = v9 + (float)(z * 0.0);
  v10 = a1->k.y * 0.0;
  v11 = a1->k.z * 0.0;
  a1->c.x = v8 + (float)(a1->k.x * 0.0);
  a1->c.y = a1->c.y + v10;
  a1->c.z = a1->c.z + v11;
  return a1;
}
