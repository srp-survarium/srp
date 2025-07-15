void __thiscall vostok::physics::bt_static_rigid_body::set_transform(
        vostok::physics::bt_static_rigid_body *this,
        const vostok::math::float4x4 *transform)
{
  btCollisionObject *v3; // eax
  btMatrix3x3 v4; // [esp+10h] [ebp-40h] BYREF

  v3 = (btCollisionObject *)vostok::physics::from_vostok(transform, &v4);
  btCollisionObject::setWorldTransform(v3, (btVector3 *)this->m_bt_body);
  btCollisionObject::setInterpolationWorldTransform(
    (btCollisionObject *)&this->m_bt_body->m_worldTransform,
    (btVector3 *)this->m_bt_body);
}
