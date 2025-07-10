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
