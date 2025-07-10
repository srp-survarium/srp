void __usercall vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
        vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *this@<esi>,
        const vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *object@<edi>)
{
  vostok::strings::shared::profile *m_object; // eax
  vostok::strings::shared::profile *v3; // eax

  m_object = this->m_object;
  if ( this->m_object != object->m_object )
  {
    if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
    v3 = object->m_object;
    this->m_object = object->m_object;
    if ( v3 )
      _InterlockedExchangeAdd(&v3->m_reference_count, 1u);
  }
}
