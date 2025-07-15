vostok::render::hw_buffer_pool_range *__usercall stlp_std::priv::__find<vostok::render::hw_buffer_pool_range *,vostok::render::hw_buffer_pool_range>@<eax>(
        vostok::render::hw_buffer_pool_range *__first@<eax>,
        vostok::render::hw_buffer_pool_range *__last,
        const vostok::render::hw_buffer_pool_range *__val)
{
  vostok::render::hw_buffer_pool_range *v3; // esi
  int i; // edi
  bool v5; // zf
  vostok::render::hw_buffer_pool_range *result; // eax

  v3 = __first;
  for ( i = (__last - __first) >> 2; i > 0; --i )
  {
    if ( vostok::render::operator==(v3, __val) )
      return v3;
    if ( vostok::render::operator==(++v3, __val) )
      return v3;
    if ( vostok::render::operator==(++v3, __val) )
      return v3;
    if ( vostok::render::operator==(++v3, __val) )
      return v3;
    ++v3;
  }
  if ( __last - v3 == 1 )
    goto LABEL_15;
  if ( __last - v3 != 2 )
  {
    if ( __last - v3 != 3 )
      return __last;
    if ( vostok::render::operator==(v3, __val) )
      return v3;
    ++v3;
  }
  if ( !vostok::render::operator==(v3, __val) )
  {
    ++v3;
LABEL_15:
    v5 = !vostok::render::operator==(v3, __val);
    result = v3;
    if ( !v5 )
      return result;
    return __last;
  }
  return v3;
}


vostok::fs_new::virtual_path_string *__usercall stlp_std::priv::__find<vostok::fs_new::virtual_path_string *,vostok::fs_new::virtual_path_string>@<eax>(
        vostok::fs_new::virtual_path_string *__first@<eax>,
        vostok::fs_new::virtual_path_string *__last,
        const vostok::fs_new::virtual_path_string *__val)
{
  vostok::fs_new::virtual_path_string *v3; // edi
  int i; // ebx
  bool v5; // zf
  vostok::fs_new::virtual_path_string *result; // eax

  v3 = __first;
  for ( i = (__last - __first) >> 2; i > 0; --i )
  {
    if ( !vostok::detail::strcmp_s(v3->m_string.m_begin, __val->m_string.m_begin) )
      return v3;
    ++v3;
    if ( !vostok::detail::strcmp_s(v3->m_string.m_begin, __val->m_string.m_begin) )
      return v3;
    ++v3;
    if ( !vostok::detail::strcmp_s(v3->m_string.m_begin, __val->m_string.m_begin) )
      return v3;
    ++v3;
    if ( !vostok::detail::strcmp_s(v3->m_string.m_begin, __val->m_string.m_begin) )
      return v3;
    ++v3;
  }
  if ( __last - v3 == 1 )
    goto LABEL_15;
  if ( __last - v3 != 2 )
  {
    if ( __last - v3 != 3 )
      return __last;
    if ( !vostok::detail::strcmp_s(v3->m_string.m_begin, __val->m_string.m_begin) )
      return v3;
    ++v3;
  }
  if ( vostok::detail::strcmp_s(v3->m_string.m_begin, __val->m_string.m_begin) )
  {
    ++v3;
LABEL_15:
    v5 = vostok::detail::strcmp_s(v3->m_string.m_begin, __val->m_string.m_begin) == 0;
    result = v3;
    if ( v5 )
      return result;
    return __last;
  }
  return v3;
}


vostok::fixed_string<260> *__usercall stlp_std::priv::__find<vostok::fixed_string<260> *,char const *>@<eax>(
        vostok::fixed_string<260> *__first@<eax>,
        vostok::fixed_string<260> *__last,
        const char **__val)
{
  vostok::fixed_string<260> *v3; // edi
  int i; // ebx
  bool v5; // zf
  vostok::fixed_string<260> *result; // eax

  v3 = __first;
  for ( i = (__last - __first) >> 2; i > 0; --i )
  {
    if ( !vostok::detail::strcmp_s(v3->m_begin, *__val) )
      return v3;
    ++v3;
    if ( !vostok::detail::strcmp_s(v3->m_begin, *__val) )
      return v3;
    ++v3;
    if ( !vostok::detail::strcmp_s(v3->m_begin, *__val) )
      return v3;
    ++v3;
    if ( !vostok::detail::strcmp_s(v3->m_begin, *__val) )
      return v3;
    ++v3;
  }
  if ( __last - v3 == 1 )
    goto LABEL_15;
  if ( __last - v3 != 2 )
  {
    if ( __last - v3 != 3 )
      return __last;
    if ( !vostok::detail::strcmp_s(v3->m_begin, *__val) )
      return v3;
    ++v3;
  }
  if ( vostok::detail::strcmp_s(v3->m_begin, *__val) )
  {
    ++v3;
LABEL_15:
    v5 = vostok::detail::strcmp_s(v3->m_begin, *__val) == 0;
    result = v3;
    if ( v5 )
      return result;
    return __last;
  }
  return v3;
}


const vostok::messaging::send_message_params *__usercall stlp_std::priv::__find<vostok::messaging::send_message_params const *,unsigned int>@<eax>(
        const vostok::messaging::send_message_params *__first@<eax>,
        const unsigned int *__val@<edi>,
        const vostok::messaging::send_message_params *__last)
{
  const vostok::messaging::send_message_params *v3; // esi
  int v4; // eax
  int v5; // edx
  const vostok::messaging::send_message_params *result; // eax

  v3 = __first;
  v4 = (__last - __first) >> 2;
  if ( v4 > 0 )
  {
    v5 = *__val;
    while ( v3->message_id != v5 )
    {
      ++v3;
      if ( v3->message_id == v5 )
        break;
      ++v3;
      if ( v3->message_id == v5 )
        break;
      ++v3;
      if ( v3->message_id == v5 )
        break;
      ++v3;
      if ( --v4 <= 0 )
        goto LABEL_8;
    }
    return v3;
  }
LABEL_8:
  switch ( __last - v3 )
  {
    case 1:
LABEL_15:
      result = v3;
      if ( v3->message_id == *__val )
        return result;
      return __last;
    case 2:
      goto LABEL_13;
    case 3:
      if ( v3->message_id == *__val )
        return v3;
      ++v3;
LABEL_13:
      if ( v3->message_id != *__val )
      {
        ++v3;
        goto LABEL_15;
      }
      return v3;
  }
  return __last;
}


const wchar_t *__cdecl stlp_std::priv::__find<wchar_t const *,wchar_t>(
        const wchar_t *__first,
        const wchar_t *__last,
        const wchar_t *__val)
{
  const wchar_t *result; // eax
  int v4; // ecx
  __int16 v5; // dx

  result = __first;
  v4 = ((char *)__last - (char *)__first) >> 3;
  if ( v4 <= 0 )
  {
LABEL_8:
    if ( __last - result != 1 )
    {
      if ( __last - result != 2 )
      {
        if ( __last - result != 3 )
          return __last;
        if ( *result == *__val )
          return result;
        ++result;
      }
      if ( *result == *__val )
        return result;
      ++result;
    }
    if ( *result == *__val )
      return result;
    return __last;
  }
  v5 = *__val;
  while ( *result != v5 )
  {
    if ( *++result == v5 )
      break;
    if ( *++result == v5 )
      break;
    if ( *++result == v5 )
      break;
    --v4;
    ++result;
    if ( v4 <= 0 )
      goto LABEL_8;
  }
  return result;
}
