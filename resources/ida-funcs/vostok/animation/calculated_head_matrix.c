vostok::math::float4x4 *__usercall vostok::animation::calculated_head_matrix@<eax>(
        int a1@<edi>,
        vostok::math::float4x4 *a2@<esi>,
        vostok::math::float4x4 *result,
        const vostok::math::float4x4 *head_matrix)
{
  vostok::math::float4x4 *v4; // edi
  vostok::math::float4x4 *v5; // eax
  float x; // xmm3_4
  float y; // xmm0_4
  float v8; // xmm4_4
  float v9; // xmm3_4
  float z; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  _BYTE v14[64]; // [esp+4h] [ebp-D8h] BYREF
  vostok::math::float4x4 v15; // [esp+44h] [ebp-98h] BYREF
  vostok::math::float4x4 v16; // [esp+84h] [ebp-58h] BYREF
  vostok::math::float3 v17; // [esp+C4h] [ebp-18h] BYREF
  vostok::math::float3 v18; // [esp+D0h] [ebp-Ch] BYREF

  *(_QWORD *)&v17.x = 0;
  v17.z = pi_d2_11;
  v18.x = 0.0;
  *(_QWORD *)&v18.elements[1] = LODWORD(pi_d2_11);
  v4 = vostok::math::create_rotation(&v17, a1, (int)&v16);
  v5 = vostok::math::create_rotation(&v18, (int)v4, (int)v14);
  vostok::math::mul4x3(v4, v5, &v15);
  vostok::math::mul4x3(result, &v15, &v16);
  vostok::math::mul4x3(head_matrix, &v16, a2);
  x = a2->j.x;
  y = a2->j.y;
  a2->c.z = (float)(a2->j.z * 0.1) + a2->c.z;
  a2->c.y = (float)(y * 0.1) + a2->c.y;
  a2->c.x = a2->c.x + (float)(x * 0.1);
  v8 = a2->c.x + (float)(a2->i.x * 0.0);
  v9 = a2->i.z * 0.0;
  a2->c.y = a2->c.y + (float)(a2->i.y * 0.0);
  z = a2->c.z;
  a2->c.x = v8;
  a2->c.z = z + v9;
  v11 = a2->k.y * 0.0;
  v12 = a2->k.z * 0.0;
  a2->c.x = v8 + (float)(a2->k.x * 0.0);
  a2->c.y = a2->c.y + v11;
  a2->c.z = a2->c.z + v12;
  return a2;
}
