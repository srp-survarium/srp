void __thiscall survarium::collision_geometry::set_transform(
        survarium::collision_geometry *this,
        const vostok::math::float4x4 *transform)
{
  vostok::physics::bt_ghost_object *m_ghost_object; // esi
  btCollisionObject *v3; // eax
  btMatrix3x3 v4; // [esp+10h] [ebp-40h] BYREF

  m_ghost_object = this->m_ghost_object;
  v3 = (btCollisionObject *)vostok::physics::from_vostok(transform, &v4);
  btCollisionObject::setWorldTransform(v3, (btVector3 *)m_ghost_object->m_bt_object);
  m_ghost_object->m_physics_world->update_single_aabb(m_ghost_object->m_physics_world, m_ghost_object->m_bt_object);
}
