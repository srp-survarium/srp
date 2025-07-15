void __thiscall vostok::physics::bt_static_rigid_body::apply_impulse(
        vostok::physics::bt_static_rigid_body *this,
        const vostok::math::float3 *impulse,
        const vostok::math::float3 *point_in_world)
{
  btRigidBody *m_bt_body; // eax
  int m_activationState1; // ecx
  unsigned int v6; // xmm1_4
  unsigned int v7; // xmm2_4
  btRigidBody *v8; // edx
  btVector3 v9; // [esp+2Ch] [ebp-20h] BYREF
  btVector3 v10; // [esp+3Ch] [ebp-10h] BYREF

  m_bt_body = this->m_bt_body;
  m_activationState1 = m_bt_body->m_activationState1;
  *(float *)&v6 = point_in_world->x - m_bt_body->m_worldTransform.m_origin.mVec128.m128_f32[0];
  *(float *)&v7 = point_in_world->y - m_bt_body->m_worldTransform.m_origin.mVec128.m128_f32[1];
  v9.mVec128.m128_f32[2] = (float)-point_in_world->z - m_bt_body->m_worldTransform.m_origin.mVec128.m128_f32[2];
  v9.mVec128.m128_u64[0] = __PAIR64__(v7, v6);
  v9.mVec128.m128_i32[3] = 0;
  if ( m_activationState1 != 4 && m_activationState1 != 5 )
    m_bt_body->m_activationState1 = 1;
  v8 = this->m_bt_body;
  v10.mVec128.m128_u64[0] = *(_QWORD *)&impulse->x;
  v10.mVec128.m128_f32[2] = -impulse->z;
  v10.mVec128.m128_i32[3] = 0;
  btRigidBody::applyImpulse(v8, &v10, &v9);
}
