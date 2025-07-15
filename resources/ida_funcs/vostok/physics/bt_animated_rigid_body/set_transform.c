void __thiscall vostok::physics::bt_animated_rigid_body::set_transform(
        vostok::physics::bt_animated_rigid_body *this,
        const vostok::math::float4x4 *transform)
{
  vostok::math::quaternion *v3; // eax
  vostok::math::quaternion v4; // [esp+10h] [ebp-40h] BYREF

  v3 = vostok::physics::from_vostok(transform, &v4);
  btCollisionObject::setWorldTransform(this->m_bt_body, (const btTransform *)v3);
}
