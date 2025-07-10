void __usercall vostok::intrusive_ptr<survarium::human_npc,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
        vostok::intrusive_ptr<survarium::human_npc,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *this@<esi>,
        const vostok::intrusive_ptr<survarium::human_npc,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *object@<edi>)
{
  survarium::human_npc *m_object; // eax
  survarium::human_npc *v3; // eax
  vostok::resources::unmanaged_resource *v4; // ecx
  survarium::human_npc *v5; // eax

  m_object = this->m_object;
  if ( this->m_object != object->m_object )
  {
    if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    {
      v3 = this->m_object;
      if ( this->m_object )
        v4 = &v3->survarium::game_object_;
      else
        v4 = 0;
      vostok::resources::unmanaged_intrusive_base::destroy(&v3->vostok::resources::unmanaged_intrusive_base, v4);
    }
    v5 = object->m_object;
    this->m_object = object->m_object;
    if ( v5 )
      _InterlockedExchangeAdd(&v5->m_reference_count, 1u);
  }
}
