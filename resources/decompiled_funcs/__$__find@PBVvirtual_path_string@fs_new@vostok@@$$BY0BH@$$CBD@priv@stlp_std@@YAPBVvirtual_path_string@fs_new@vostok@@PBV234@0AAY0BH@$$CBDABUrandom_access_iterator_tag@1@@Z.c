const vostok::fs_new::virtual_path_string *__usercall stlp_std::priv::__find<vostok::fs_new::virtual_path_string const *,char const [23]>@<eax>(
        vostok::fs_new::virtual_path_string *__first@<eax>,
        const vostok::fs_new::virtual_path_string *__last)
{
  vostok::fs_new::virtual_path_string *v2; // esi
  int v3; // edi
  bool v4; // zf
  const vostok::fs_new::virtual_path_string *result; // eax

  v2 = __first;
  v3 = (__last - __first) >> 2;
  if ( v3 > 0 )
  {
    while ( !vostok::fs_new::path_string_impl::operator==(v2, "GLOBAL_SHADING_QUALITY") )
    {
      if ( vostok::fs_new::path_string_impl::operator==(++v2, "GLOBAL_SHADING_QUALITY") )
        break;
      if ( vostok::fs_new::path_string_impl::operator==(++v2, "GLOBAL_SHADING_QUALITY") )
        break;
      if ( vostok::fs_new::path_string_impl::operator==(++v2, "GLOBAL_SHADING_QUALITY") )
        break;
      --v3;
      ++v2;
      if ( v3 <= 0 )
        goto LABEL_7;
    }
    return v2;
  }
LABEL_7:
  switch ( __last - v2 )
  {
    case 1:
LABEL_14:
      v4 = !vostok::fs_new::path_string_impl::operator==(v2, "GLOBAL_SHADING_QUALITY");
      result = v2;
      if ( !v4 )
        return result;
      return __last;
    case 2:
      goto LABEL_12;
    case 3:
      if ( vostok::fs_new::path_string_impl::operator==(v2, "GLOBAL_SHADING_QUALITY") )
        return v2;
      ++v2;
LABEL_12:
      if ( !vostok::fs_new::path_string_impl::operator==(v2, "GLOBAL_SHADING_QUALITY") )
      {
        ++v2;
        goto LABEL_14;
      }
      return v2;
  }
  return __last;
}
