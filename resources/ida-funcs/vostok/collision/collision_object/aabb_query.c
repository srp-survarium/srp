int __thiscall vostok::collision::collision_object::aabb_query(
        vostok::collision::collision_object *this,
        const vostok::math::aabb *aabb,
        vostok::vectora<vostok::collision::triangle_result> *results)
{
  return ((int (__thiscall *)(vostok::collision::geometry_instance *const, vostok::collision::collision_object *, const vostok::math::aabb *, vostok::vectora<vostok::collision::triangle_result> *))this->m_geometry_instance->aabb_query)(
           this->m_geometry_instance,
           this,
           aabb,
           results);
}
