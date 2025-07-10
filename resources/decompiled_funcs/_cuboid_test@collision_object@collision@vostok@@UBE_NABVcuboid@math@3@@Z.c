int __thiscall vostok::collision::collision_object::cuboid_test(
        vostok::collision::collision_object *this,
        const vostok::math::cuboid *cuboid)
{
  return ((int (__thiscall *)(vostok::collision::geometry_instance *const, const vostok::math::cuboid *))this->m_geometry_instance->cuboid_test)(
           this->m_geometry_instance,
           cuboid);
}
