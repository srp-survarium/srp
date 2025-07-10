const vostok::animation::event_channel *__usercall stlp_std::priv::__find_if<vostok::animation::event_channel const *,vostok::animation::find_predicate>@<eax>(
        const vostok::animation::event_channel *__first@<eax>,
        const vostok::animation::event_channel *__last,
        vostok::animation::find_predicate __pred)
{
  const vostok::animation::event_channel *v3; // esi
  int v4; // edi
  const vostok::animation::event_channel *result; // eax
  bool v6; // zf

  v3 = __first;
  v4 = (__last - __first) >> 2;
  if ( v4 > 0 )
  {
    while ( strcmp(v3->m_name, __pred.m_name) )
    {
      ++v3;
      if ( !strcmp(v3->m_name, __pred.m_name) )
        break;
      ++v3;
      if ( !strcmp(v3->m_name, __pred.m_name) )
        break;
      ++v3;
      if ( !strcmp(v3->m_name, __pred.m_name) )
        break;
      --v4;
      ++v3;
      if ( v4 <= 0 )
        goto LABEL_7;
    }
    return v3;
  }
LABEL_7:
  switch ( __last - v3 )
  {
    case 1:
LABEL_16:
      v6 = strcmp(v3->m_name, __pred.m_name) == 0;
      result = v3;
      if ( v6 )
        return result;
      return __last;
    case 2:
      goto LABEL_14;
    case 3:
      if ( !strcmp(v3->m_name, __pred.m_name) )
        return v3;
      ++v3;
LABEL_14:
      if ( strcmp(v3->m_name, __pred.m_name) )
      {
        ++v3;
        goto LABEL_16;
      }
      return v3;
  }
  return __last;
}
