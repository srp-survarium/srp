void __usercall vostok::physics::bt_dynamic_rigid_body::set_angular_velocity(
        vostok::physics::bt_dynamic_rigid_body *this@<ecx>,
        const vostok::math::float3 *v@<eax>)
{
  btRigidBody *m_bt_body; // ecx
  btVector3 v3; // [esp+0h] [ebp-10h] BYREF

  m_bt_body = this->m_bt_body;
  v3.mVec128.m128_u64[0] = *(_QWORD *)&v->x;
  v3.mVec128.m128_u64[1] = LODWORD(v->z) ^ (unsigned __int64)(unsigned int)_mask__NegFloat_;
  btRigidBody::setAngularVelocity(m_bt_body, &v3);
}
