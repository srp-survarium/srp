vostok::math::float4x4 *__thiscall survarium::collision_geometry::get_transform(
        survarium::collision_geometry *this,
        vostok::math::float4x4 *result)
{
  vostok::physics::bt_ghost_object::get_transform((vostok::physics::bt_ghost_object *)result, (int)this->m_ghost_object);
  return result;
}
