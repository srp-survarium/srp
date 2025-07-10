vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base> *__thiscall vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
        vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base> *this,
        const vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base> *object)
{
  vostok::physics::bt_collision_shape *m_object; // eax
  vostok::physics::bt_collision_shape *v4; // ecx
  vostok::physics::bt_collision_shape *v5; // eax

  m_object = 0;
  if ( object->m_object )
  {
    m_object = object->m_object;
    _InterlockedExchangeAdd(&object->m_object->m_reference_count, 1u);
  }
  v4 = m_object;
  v5 = this->m_object;
  this->m_object = v4;
  if ( v5 && !_InterlockedExchangeAdd(&v5->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v5->vostok::resources::unmanaged_intrusive_base, v5);
  return this;
}
