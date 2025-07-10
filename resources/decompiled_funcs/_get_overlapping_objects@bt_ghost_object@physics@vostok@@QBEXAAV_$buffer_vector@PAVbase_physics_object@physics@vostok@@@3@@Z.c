void __thiscall vostok::physics::bt_ghost_object::get_overlapping_objects(
        vostok::physics::bt_ghost_object *this,
        const vostok::physics::bt_ghost_object *result,
        vostok::physics::base_physics_object *user_ptr)
{
  vostok::physics::base_physics_object *v3; // ebp
  unsigned int m_size; // edi
  unsigned int i; // esi

  v3 = user_ptr;
  m_size = result->m_bt_object->m_overlappingObjects.m_size;
  for ( i = 0; i < m_size; ++i )
  {
    user_ptr = (vostok::physics::base_physics_object *)result->m_bt_object->m_overlappingObjects.m_data[i]->m_userObjectPointer;
    vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
      (vostok::buffer_vector<void const *> *)v3,
      (const void **)&user_ptr);
  }
}
