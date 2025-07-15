vostok::math::float4x4 *__usercall vostok::physics::from_bullet@<eax>(
        long double m@<esi:edi>,
        vostok::math::float4x4 *a2)
{
  btQuaternion *v2; // ecx
  vostok::math::float4x4 *v3; // eax
  btQuaternion q; // [esp+0h] [ebp-B0h] BYREF
  vostok::math::float3 position; // [esp+14h] [ebp-9Ch] BYREF
  vostok::math::quaternion v7; // [esp+20h] [ebp-90h] BYREF
  vostok::math::float4x4 left; // [esp+30h] [ebp-80h] BYREF
  vostok::math::float4x4 v9; // [esp+70h] [ebp-40h] BYREF

  btMatrix3x3::getRotation((btMatrix3x3 *)HIDWORD(m), &q);
  vostok::physics::from_bullet(&q, v2, m, (const struct vostok::math::float3 *)&v7);
  *(_QWORD *)q.m_floats = *(_QWORD *)(HIDWORD(m) + 48);
  LODWORD(q.m_floats[2]) = *(_DWORD *)(HIDWORD(m) + 56) ^ _mask__NegFloat_;
  memset(&position, 0, sizeof(position));
  vostok::math::create_matrix(&v7, &position, &left);
  v3 = vostok::math::create_translation((const vostok::math::float3 *)&q, &v9);
  vostok::math::mul4x3(v3, &left, a2);
  return a2;
}


vostok::math::quaternion *__usercall vostok::physics::from_bullet@<eax>(
        const btQuaternion *from@<eax>,
        btQuaternion *a2@<ecx>,
        long double a3@<esi:edi>,
        const struct vostok::math::float3 *a4)
{
  float v4; // xmm1_4
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm3_4
  float v8; // xmm4_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  vostok::math::quaternion *v11; // ecx
  float v13; // [esp-4h] [ebp-10h]
  float v14[3]; // [esp+0h] [ebp-Ch] BYREF

  v4 = s_bm_current_air_resistance - (float)(from->m_floats[3] * from->m_floats[3]);
  if ( v4 >= 0.0000011920929 )
  {
    v8 = s_bm_current_air_resistance / fsqrt(v4);
    v6 = from->m_floats[0] * v8;
    v7 = from->m_floats[1] * v8;
    v5 = from->m_floats[2] * v8;
  }
  else
  {
    v5 = 0.0;
    v6 = s_bm_current_air_resistance;
    v7 = 0.0;
  }
  LODWORD(v9) = LODWORD(v5) ^ _mask__NegFloat_;
  v10 = s_bm_current_air_resistance / fsqrt((float)((float)(v9 * v9) + (float)(v6 * v6)) + (float)(v7 * v7));
  v14[0] = v10 * v6;
  v14[1] = v10 * v7;
  v14[2] = v9 * v10;
  btQuaternion::getAngle(a2);
  vostok::math::quaternion::quaternion(v11, v14, a3, v10, a4, v13);
  return (vostok::math::quaternion *)a4;
}
