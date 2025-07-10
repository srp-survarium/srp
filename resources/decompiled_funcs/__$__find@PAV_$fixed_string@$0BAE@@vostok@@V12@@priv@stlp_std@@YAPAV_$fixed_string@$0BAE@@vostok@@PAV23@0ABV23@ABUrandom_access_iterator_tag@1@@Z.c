vostok::fs_new::path_string_impl *__usercall stlp_std::priv::__find<vostok::fixed_string<260> *,vostok::fixed_string<260>>@<eax>(
        vostok::fs_new::path_string_impl *__first@<eax>,
        vostok::fixed_string<260> *__last,
        vostok::fs_new::path_string_impl *__val)
{
  vostok::fs_new::path_string_impl *v3; // esi
  int v4; // edi
  bool v5; // zf
  vostok::fs_new::path_string_impl *result; // eax

  v3 = __first;
  v4 = (((char *)__last - (char *)__first) / 272) >> 2;
  if ( v4 > 0 )
  {
    while ( !vostok::operator==(v3, __val) )
    {
      v3 = (vostok::fs_new::path_string_impl *)((char *)v3 + 272);
      if ( vostok::operator==(v3, __val) )
        break;
      v3 = (vostok::fs_new::path_string_impl *)((char *)v3 + 272);
      if ( vostok::operator==(v3, __val) )
        break;
      v3 = (vostok::fs_new::path_string_impl *)((char *)v3 + 272);
      if ( vostok::operator==(v3, __val) )
        break;
      --v4;
      v3 = (vostok::fs_new::path_string_impl *)((char *)v3 + 272);
      if ( v4 <= 0 )
        goto LABEL_7;
    }
    return v3;
  }
LABEL_7:
  switch ( ((char *)__last - (char *)v3) / 272 )
  {
    case 1:
LABEL_14:
      v5 = vostok::operator==(v3, __val) == 0;
      result = v3;
      if ( !v5 )
        return result;
      return (vostok::fs_new::path_string_impl *)__last;
    case 2:
      goto LABEL_12;
    case 3:
      if ( vostok::operator==(v3, __val) )
        return v3;
      v3 = (vostok::fs_new::path_string_impl *)((char *)v3 + 272);
LABEL_12:
      if ( !vostok::operator==(v3, __val) )
      {
        v3 = (vostok::fs_new::path_string_impl *)((char *)v3 + 272);
        goto LABEL_14;
      }
      return v3;
  }
  return (vostok::fs_new::path_string_impl *)__last;
}
