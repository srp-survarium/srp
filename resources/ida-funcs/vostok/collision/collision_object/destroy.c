void __thiscall vostok::collision::collision_object::destroy(
        vostok::collision::collision_object *this,
        vostok::memory::base_allocator *allocator)
{
  vostok::collision::geometry_instance *m_geometry_instance; // esi
  _BYTE *v3; // ebx

  m_geometry_instance = this->m_geometry_instance;
  if ( m_geometry_instance->m_delete_by_collision_object )
  {
    if ( m_geometry_instance )
    {
      m_geometry_instance->destroy(m_geometry_instance, allocator);
      v3 = __RTCastToVoid((void **)&m_geometry_instance->__vftable);
      ((void (__thiscall *)(vostok::collision::geometry_instance *, _DWORD))m_geometry_instance->~vostok::collision::geometry_instance)(
        m_geometry_instance,
        0);
      allocator->call_free(allocator, v3);
    }
  }
}
