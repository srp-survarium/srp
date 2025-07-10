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
