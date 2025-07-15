void __thiscall vostok::collision::collision_object::destroy(
        vostok::collision::collision_object *this,
        vostok::memory::base_allocator *allocator)
{
  vostok::collision::geometry_instance *m_geometry_instance; // esi

  m_geometry_instance = this->m_geometry_instance;
  if ( m_geometry_instance->m_delete_by_collision_object )
    vostok::collision::delete_geometry_instance(allocator, m_geometry_instance);
}
