vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base> *__userpurge survarium::booby_trap_set::pick_ghost_model@<eax>(
        survarium::booby_trap_set *this@<ecx>,
        vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base> *a2@<eax>,
        vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base> *result,
        bool is_placing_allowed)
{
  vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base> *p_m_model_ghost_allowed; // ecx
  vostok::render::static_model_instance *m_object; // ecx

  if ( (_BYTE)result )
    p_m_model_ghost_allowed = &this->m_model_ghost_allowed;
  else
    p_m_model_ghost_allowed = &this->m_model_ghost_denied;
  m_object = p_m_model_ghost_allowed->m_object;
  a2->m_object = 0;
  if ( m_object )
  {
    a2->m_object = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  return a2;
}
