vostok::render::shader_constant_binding *__usercall stlp_std::priv::__find<vostok::render::shader_constant_binding *,vostok::render::shader_constant_binding>@<eax>(
        vostok::render::shader_constant_binding *__first@<ecx>,
        vostok::render::shader_constant_binding *__last@<esi>,
        const vostok::render::shader_constant_binding *__val@<edi>)
{
  int v3; // eax
  vostok::strings::shared::profile *m_object; // edx
  vostok::render::shader_constant_binding *result; // eax

  v3 = (__last - __first) >> 2;
  if ( v3 > 0 )
  {
    m_object = __val->m_name.m_pointer.m_object;
    while ( __first->m_name.m_pointer.m_object != m_object )
    {
      ++__first;
      if ( __first->m_name.m_pointer.m_object == m_object )
        break;
      ++__first;
      if ( __first->m_name.m_pointer.m_object == m_object )
        break;
      ++__first;
      if ( __first->m_name.m_pointer.m_object == m_object )
        break;
      --v3;
      ++__first;
      if ( v3 <= 0 )
        goto LABEL_8;
    }
    return __first;
  }
LABEL_8:
  switch ( __last - __first )
  {
    case 1:
LABEL_15:
      result = __first;
      if ( __first->m_name.m_pointer.m_object == __val->m_name.m_pointer.m_object )
        return result;
      return __last;
    case 2:
      goto LABEL_13;
    case 3:
      if ( __first->m_name.m_pointer.m_object == __val->m_name.m_pointer.m_object )
        return __first;
      ++__first;
LABEL_13:
      if ( __first->m_name.m_pointer.m_object != __val->m_name.m_pointer.m_object )
      {
        ++__first;
        goto LABEL_15;
      }
      return __first;
  }
  return __last;
}
