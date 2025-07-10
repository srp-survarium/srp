void __usercall stlp_std::__destroy_range_aux<vostok::render::shader_constant_binding *,vostok::render::shader_constant_binding>(
        vostok::render::shader_constant_binding *__first@<eax>,
        vostok::render::shader_constant_binding *__last@<edi>)
{
  vostok::render::shader_constant_binding *i; // esi
  volatile signed __int32 *p_m_reference_count; // eax

  for ( i = __first; i != __last; ++i )
  {
    p_m_reference_count = &i->m_name.m_pointer.m_object->m_reference_count;
    if ( p_m_reference_count )
    {
      if ( !_InterlockedExchangeAdd(p_m_reference_count, 0xFFFFFFFF) )
        vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
    }
  }
}
