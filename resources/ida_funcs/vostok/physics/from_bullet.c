vostok::math::float4x4 *__usercall vostok::physics::from_bullet@<eax>(
        const btTransform *m@<eax>,
        btMatrix3x3 *a2@<ecx>,
        vostok::math::float4x4 *a3@<edi>)
{
  const vostok::math::float4x4 *v4; // eax
  btQuaternion q; // [esp+150h] [ebp-B0h] BYREF
  vostok::math::float3 position; // [esp+164h] [ebp-9Ch] BYREF
  vostok::math::quaternion v8; // [esp+170h] [ebp-90h] BYREF
  vostok::math::float4x4 left; // [esp+180h] [ebp-80h] BYREF
  vostok::math::float4x4 result; // [esp+1C0h] [ebp-40h] BYREF

  btMatrix3x3::getRotation(a2, (float *)m, &q);
  vostok::physics::from_bullet(&q, (btQuaternion *)&v8, &v8);
  LODWORD(q.m_floats[0]) = m->m_origin.mVec128.m128_i32[0];
  LODWORD(q.m_floats[1]) = m->m_origin.mVec128.m128_i32[1];
  q.m_floats[2] = -m->m_origin.mVec128.m128_f32[2];
  memset(&position, 0, sizeof(position));
  vostok::math::create_matrix(&v8, &position);
  v4 = vostok::math::create_translation(&result, (const vostok::math::float3 *)&q);
  vostok::math::mul4x3(a3, &left, v4);
  return a3;
}


vostok::math::quaternion *__usercall vostok::physics::from_bullet@<eax>(
        const btQuaternion *from@<eax>,
        btQuaternion *a2@<ecx>,
        vostok::math::quaternion *a3)
{
  int v3; // xmm1_4
  float v4; // xmm0_4
  btVector3 *Axis; // eax
  double v6; // st7
  float _X; // [esp+0h] [ebp-34h]
  float v9; // [esp+14h] [ebp-20h]
  vostok::math::float3 direction; // [esp+18h] [ebp-1Ch] BYREF
  btVector3 v11; // [esp+24h] [ebp-10h] BYREF

  v3 = -1082130432;
  v4 = from->m_floats[3];
  v9 = v4;
  if ( v4 < -1.0 || (v3 = (int)clear_value, v4 > *(float *)&clear_value) )
    v9 = *(float *)&v3;
  Axis = btQuaternion::getAxis(a2, from->m_floats, &v11);
  *(_QWORD *)&direction.x = Axis->mVec128.m128_u64[0];
  direction.z = -Axis->mVec128.m128_f32[2];
  v6 = acosf(v9);
  _X = v6 + v6;
  vostok::math::quaternion::quaternion(a3, &direction, _X);
  return a3;
}
