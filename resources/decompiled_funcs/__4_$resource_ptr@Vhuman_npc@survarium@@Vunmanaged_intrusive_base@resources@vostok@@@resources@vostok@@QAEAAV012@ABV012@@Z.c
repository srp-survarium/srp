vostok::resources::resource_ptr<survarium::human_npc,vostok::resources::unmanaged_intrusive_base> *__userpurge vostok::resources::resource_ptr<survarium::human_npc,vostok::resources::unmanaged_intrusive_base>::operator=@<eax>(
        const vostok::resources::resource_ptr<survarium::human_npc,vostok::resources::unmanaged_intrusive_base> *object@<edi>,
        vostok::resources::resource_ptr<survarium::human_npc,vostok::resources::unmanaged_intrusive_base> *this)
{
  vostok::resources::resource_ptr<survarium::human_npc,vostok::resources::unmanaged_intrusive_base> *v2; // ebx
  survarium::human_npc *m_object; // eax

  v2 = this;
  this = 0;
  vostok::intrusive_ptr<survarium::human_npc,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<survarium::human_npc,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this,
    object);
  m_object = v2->m_object;
  v2->m_object = (survarium::human_npc *)this;
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &m_object->vostok::resources::unmanaged_intrusive_base,
      &m_object->survarium::game_object_);
  return v2;
}
