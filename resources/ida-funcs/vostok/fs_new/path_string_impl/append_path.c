vostok::fs_new::path_string_impl *__userpurge vostok::fs_new::path_string_impl::append_path<char const *>@<eax>(
        vostok::fs_new::path_string_impl *this@<ecx>,
        int a2@<eax>,
        char **s)
{
  _BYTE *v4; // eax
  vostok::buffer_string *v5; // ecx
  vostok::fs_new::path_string_impl *v6; // ecx

  v4 = *(_BYTE **)(a2 + 4);
  v5 = (vostok::buffer_string *)&v4[-*(_DWORD *)a2];
  if ( v4 != *(_BYTE **)a2 )
  {
    LOBYTE(v5) = *(_BYTE *)(a2 + 272);
    *v4 = (_BYTE)v5;
    *(_BYTE *)++*(_DWORD *)(a2 + 4) = 0;
  }
  vostok::buffer_string::append(v5, a2, *s);
  vostok::fs_new::path_string_impl::rtrim(v6, (_DWORD *)a2, *(_BYTE *)(a2 + 272));
  return (vostok::fs_new::path_string_impl *)a2;
}
