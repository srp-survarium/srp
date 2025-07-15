void __userpurge vostok::fs_new::path_string_impl::rtrim(
        vostok::fs_new::path_string_impl *this@<ecx>,
        _DWORD *a2@<eax>,
        char c)
{
  _BYTE *v3; // ecx

  while ( a2[1] > *a2 )
  {
    v3 = (_BYTE *)(a2[1] - 1);
    if ( *v3 != c )
      break;
    a2[1] = v3;
  }
  *(_BYTE *)a2[1] = 0;
}
