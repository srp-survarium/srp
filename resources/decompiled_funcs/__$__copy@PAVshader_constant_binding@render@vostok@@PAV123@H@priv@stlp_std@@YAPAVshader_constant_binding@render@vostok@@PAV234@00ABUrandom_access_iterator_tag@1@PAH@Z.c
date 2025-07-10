vostok::render::shader_constant_binding *__usercall stlp_std::priv::__copy<vostok::render::shader_constant_binding *,vostok::render::shader_constant_binding *,int>@<eax>(
        vostok::render::shader_constant_binding *__last@<eax>,
        vostok::render::shader_constant_binding *__result@<ecx>,
        vostok::render::shader_constant_binding *__first)
{
  vostok::render::shader_constant_binding *v3; // edi
  int i; // ebx
  vostok::strings::shared::profile *m_object; // eax
  vostok::strings::shared::profile *v7; // eax

  v3 = __first;
  for ( i = __last - __first; i > 0; ++__result )
  {
    m_object = __result->m_name.m_pointer.m_object;
    if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
    __result->m_source.m_pointer = v3->m_source.m_pointer;
    __result->m_source.m_size = v3->m_source.m_size;
    __result->m_name.m_pointer.m_object = 0;
    v7 = v3->m_name.m_pointer.m_object;
    if ( v7 )
    {
      __result->m_name.m_pointer.m_object = v7;
      _InterlockedExchangeAdd(&v7->m_reference_count, 1u);
    }
    __result->m_type = v3->m_type;
    __result->m_class_id = v3->m_class_id;
    --i;
    ++v3;
  }
  return __result;
}
