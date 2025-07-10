void __thiscall vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>(
        vostok::intrusive_ptr<vostok::render::culling::portal_sector_structure,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *this,
        const vostok::intrusive_ptr<vostok::render::culling::portal_sector_structure,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *other)
{
  vostok::render::culling::portal_sector_structure *m_object; // edx

  this->m_object = 0;
  m_object = other->m_object;
  if ( other->m_object )
  {
    this->m_object = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
}
