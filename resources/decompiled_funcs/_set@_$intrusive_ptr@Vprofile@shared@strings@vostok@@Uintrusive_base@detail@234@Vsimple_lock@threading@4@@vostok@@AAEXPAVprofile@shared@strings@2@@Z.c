void __usercall vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
        vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *this@<edi>,
        vostok::strings::shared::profile *object@<eax>)
{
  vostok::strings::shared::profile *m_object; // eax

  m_object = this->m_object;
  if ( this->m_object != object )
  {
    if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
    this->m_object = object;
    if ( object )
      _InterlockedExchangeAdd(&object->m_reference_count, 1u);
  }
}
