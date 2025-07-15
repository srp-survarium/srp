void __thiscall vostok::physics::bt_dynamic_rigid_body::apply_impulse(
        vostok::physics::bt_dynamic_rigid_body *this,
        const vostok::math::float3 *impulse,
        btCollisionObject *point_in_world)
{
  btRigidBody *m_bt_body; // eax
  unsigned int v4; // xmm1_4
  unsigned int v5; // xmm2_4
  int v6; // edx
  btRigidBody *v7; // edx
  btVector3 v8; // [esp+Ch] [ebp-20h] BYREF
  btVector3 v9; // [esp+1Ch] [ebp-10h] BYREF

  m_bt_body = this->m_bt_body;
  *(float *)&v4 = *(float *)&point_in_world->__vftable - m_bt_body->m_worldTransform.m_origin.mVec128.m128_f32[0];
  *(float *)&v5 = *((float *)&point_in_world->__vftable + 1) - m_bt_body->m_worldTransform.m_origin.mVec128.m128_f32[1];
  v8.mVec128.m128_f32[2] = COERCE_FLOAT(*((_DWORD *)&point_in_world->__vftable + 2) ^ _mask__NegFloat_)
                         - m_bt_body->m_worldTransform.m_origin.mVec128.m128_f32[2];
  v8.mVec128.m128_u64[0] = __PAIR64__(v5, v4);
  v8.mVec128.m128_i32[3] = 0;
  btCollisionObject::setActivationState(point_in_world, (int)m_bt_body, 1);
  v7 = *(btRigidBody **)(v6 + 20);
  v9.mVec128.m128_u64[0] = *(_QWORD *)&impulse->x;
  v9.mVec128.m128_u64[1] = LODWORD(impulse->z) ^ (unsigned __int64)(unsigned int)_mask__NegFloat_;
  btRigidBody::applyImpulse(v7, &v9, &v8);
}
