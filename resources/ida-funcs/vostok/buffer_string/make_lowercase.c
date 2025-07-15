vostok::buffer_string *__usercall vostok::buffer_string::make_lowercase@<eax>(
        vostok::buffer_string *this@<ecx>,
        int a2@<esi>)
{
  int v2; // ecx

  v2 = *(_DWORD *)(a2 + 4) - *(_DWORD *)a2;
  if ( v2 )
    _strlwr_s(*(char **)a2, v2 + 1);
  return (vostok::buffer_string *)a2;
}
