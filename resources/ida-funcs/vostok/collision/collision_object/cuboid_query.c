int __thiscall vostok::collision::collision_object::cuboid_query(
        vostok::collision::collision_object *this,
        const vostok::math::cuboid *cuboid,
        vostok::buffer_vector<vostok::collision::triangle_result> *results)
{
  return ((int (__thiscall *)(vostok::collision::geometry_instance *const, vostok::collision::collision_object *, const vostok::math::cuboid *, vostok::buffer_vector<vostok::collision::triangle_result> *))this->m_geometry_instance->cuboid_query)(
           this->m_geometry_instance,
           this,
           cuboid,
           results);
}
