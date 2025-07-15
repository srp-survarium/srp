void __userpurge vostok::physics::bt_ghost_object::set_transform(
        const vostok::math::float4x4 *transform@<esi>,
        vostok::physics::bt_ghost_object *this)
{
  const btTransform *v2; // eax

  v2 = vostok::physics::from_vostok(transform);
  btCollisionObject::setWorldTransform(this->m_bt_object, v2);
}
