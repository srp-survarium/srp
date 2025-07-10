void __thiscall survarium::collision_geometry::set_transform(
        survarium::collision_geometry *this,
        const vostok::math::float4x4 *transform)
{
  vostok::physics::bt_ghost_object::set_transform(transform, this->m_ghost_object);
}
