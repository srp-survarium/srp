char __thiscall survarium::player::set_new_active_item(
        survarium::player *this,
        const vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base> *item)
{
  survarium::inventory_item *m_object; // esi
  survarium::inventory_item *v3; // eax
  survarium::interactive_object *v4; // edx
  survarium::interactive_object *v5; // eax

  m_object = 0;
  if ( item->m_object )
  {
    m_object = item->m_object;
    _InterlockedExchangeAdd(&item->m_object->m_reference_count, 1u);
  }
  if ( this->m_target_active_object.m_object != m_object )
    this->m_force_animation_selection = 1;
  v3 = 0;
  if ( m_object )
  {
    v3 = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  v4 = v3;
  v5 = this->m_target_active_object.m_object;
  this->m_target_active_object.m_object = v4;
  if ( v5 && !_InterlockedExchangeAdd(&v5->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v5->vostok::resources::unmanaged_intrusive_base, v5);
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &m_object->vostok::resources::unmanaged_intrusive_base,
      m_object);
  return 1;
}
