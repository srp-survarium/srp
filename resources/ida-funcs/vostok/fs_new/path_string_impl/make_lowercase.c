vostok::fs_new::path_string_impl *__usercall vostok::fs_new::path_string_impl::make_lowercase@<eax>(
        vostok::fs_new::path_string_impl *this@<ecx>,
        int a2@<esi>)
{
  int v2; // eax

  v2 = *(_DWORD *)(a2 + 4) - *(_DWORD *)a2;
  if ( v2 )
    _strlwr_s(*(char **)a2, v2 + 1);
  return (vostok::fs_new::path_string_impl *)a2;
}
