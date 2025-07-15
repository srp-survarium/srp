int __thiscall vostok::collision::collision_object::aabb_test(
        vostok::collision::collision_object *this,
        const vostok::math::aabb *aabb)
{
  return ((int (__thiscall *)(vostok::collision::geometry_instance *const, const vostok::math::aabb *))this->m_geometry_instance->aabb_test)(
           this->m_geometry_instance,
           aabb);
}
