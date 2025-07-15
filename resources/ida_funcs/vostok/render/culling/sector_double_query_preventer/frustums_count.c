int __usercall vostok::render::culling::sector_double_query_preventer::frustums_count@<eax>(
        vostok::render::culling::sector_double_query_preventer *this@<ecx>,
        int a2@<eax>)
{
  int v2; // eax
  _DWORD *v3; // esi
  _DWORD *v4; // edi
  int v5; // ebx
  unsigned int v6; // edx

  v2 = *(_DWORD *)(a2 + 4);
  v3 = *(_DWORD **)v2;
  v4 = *(_DWORD **)(v2 + 4);
  v5 = 0;
  if ( *(_DWORD **)v2 != v4 )
  {
    do
    {
      v6 = (int)((unsigned __int64)(2290649225LL * (v3[1] - *v3)) >> 32) >> 6;
      v3 += 3;
      v5 += v6 + (v6 >> 31);
    }
    while ( v3 != v4 );
  }
  return v5;
}
