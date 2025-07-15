const vostok::fs_new::virtual_path_string *__userpurge vostok::fs_new::virtual_path_string::append_path@<eax>(
        vostok::fs_new::virtual_path_string *this@<ecx>,
        int a2@<esi>,
        const vostok::fs_new::virtual_path_string *s)
{
  vostok::fs_new::path_string_impl *v3; // ecx

  if ( *(_DWORD *)(a2 + 4) != *(_DWORD *)a2 )
  {
    *(_BYTE *)(*(_DWORD *)(a2 + 4))++ = *(_BYTE *)(a2 + 272);
    **(_BYTE **)(a2 + 4) = 0;
  }
  vostok::fs_new::path_string_impl::append<vostok::fixed_string<260>>(
    &s->vostok::fs_new::path_string_impl,
    (const vostok::fixed_string<260> *)a2);
  vostok::fs_new::path_string_impl::rtrim(v3, (_DWORD *)a2, *(_BYTE *)(a2 + 272));
  return (const vostok::fs_new::virtual_path_string *)a2;
}
