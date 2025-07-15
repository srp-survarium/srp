void __usercall vostok::render::render_target::set_name(vostok::render::render_target *this@<edi>)
{
  vostok::strings::shared::profile *v2; // eax
  volatile signed __int32 *p_m_reference_count; // esi
  vostok::strings::shared::profile *v4; // ecx
  vostok::strings::shared::profile *m_object; // eax

  v2 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  p_m_reference_count = 0;
  if ( v2 )
  {
    p_m_reference_count = &v2->m_reference_count;
    _InterlockedExchangeAdd(&v2->m_reference_count, 1u);
  }
  v4 = 0;
  if ( p_m_reference_count )
  {
    v4 = (vostok::strings::shared::profile *)p_m_reference_count;
    _InterlockedExchangeAdd(p_m_reference_count, 1u);
  }
  m_object = this->m_name.m_pointer.m_object;
  this->m_name.m_pointer.m_object = v4;
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(
      (vostok::strings::shared::manager *)m_object,
      (vostok::strings::shared::profile *)s_manager.m_variable);
  if ( p_m_reference_count )
  {
    if ( !_InterlockedExchangeAdd(p_m_reference_count, 0xFFFFFFFF) )
      vostok::strings::shared::manager::remove(
        (vostok::strings::shared::manager *)p_m_reference_count,
        (vostok::strings::shared::profile *)s_manager.m_variable);
  }
}
