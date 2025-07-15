unsigned int __fastcall vostok::resources::queries_result::calculate_fs_iterator_requests_count(
        vostok::resources::queries_result *this,
        int a2)
{
  int v2; // ecx
  unsigned int result; // eax
  _DWORD *v4; // edx
  int v5; // esi

  v2 = *(_DWORD *)(a2 + 56);
  result = 0;
  if ( v2 )
  {
    v4 = (_DWORD *)(a2 + 212);
    v5 = v2;
    do
    {
      if ( *v4 == 1 || *v4 == 2 )
        ++result;
      v4 += 180;
      --v5;
    }
    while ( v5 );
  }
  return result;
}
