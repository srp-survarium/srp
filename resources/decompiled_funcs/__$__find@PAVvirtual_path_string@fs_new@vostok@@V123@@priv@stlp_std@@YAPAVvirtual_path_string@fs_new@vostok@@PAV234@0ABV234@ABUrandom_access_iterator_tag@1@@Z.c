vostok::fs_new::virtual_path_string *__usercall stlp_std::priv::__find<vostok::fs_new::virtual_path_string *,vostok::fs_new::virtual_path_string>@<eax>(
        vostok::fs_new::virtual_path_string *__first@<eax>,
        vostok::fs_new::virtual_path_string *__last,
        const vostok::fs_new::virtual_path_string *__val)
{
  vostok::fs_new::virtual_path_string *v3; // esi
  int v4; // edi
  bool v5; // zf
  vostok::fs_new::virtual_path_string *result; // eax

  v3 = __first;
  v4 = (__last - __first) >> 2;
  if ( v4 > 0 )
  {
    while ( !vostok::fs_new::path_string_impl::operator==(v3, &__val->vostok::fs_new::path_string_impl) )
    {
      if ( vostok::fs_new::path_string_impl::operator==(++v3, &__val->vostok::fs_new::path_string_impl) )
        break;
      if ( vostok::fs_new::path_string_impl::operator==(++v3, &__val->vostok::fs_new::path_string_impl) )
        break;
      if ( vostok::fs_new::path_string_impl::operator==(++v3, &__val->vostok::fs_new::path_string_impl) )
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
LABEL_14:
      v5 = vostok::fs_new::path_string_impl::operator==(v3, &__val->vostok::fs_new::path_string_impl) == 0;
      result = v3;
      if ( !v5 )
        return result;
      return __last;
    case 2:
      goto LABEL_12;
    case 3:
      if ( vostok::fs_new::path_string_impl::operator==(v3, &__val->vostok::fs_new::path_string_impl) )
        return v3;
      ++v3;
LABEL_12:
      if ( !vostok::fs_new::path_string_impl::operator==(v3, &__val->vostok::fs_new::path_string_impl) )
      {
        ++v3;
        goto LABEL_14;
      }
      return v3;
  }
  return __last;
}
