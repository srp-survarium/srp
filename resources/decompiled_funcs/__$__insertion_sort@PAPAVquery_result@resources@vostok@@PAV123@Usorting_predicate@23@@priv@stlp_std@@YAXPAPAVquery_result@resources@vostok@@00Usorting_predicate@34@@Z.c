void __cdecl stlp_std::priv::__insertion_sort<vostok::resources::query_result * *,vostok::resources::query_result *,vostok::resources::sorting_predicate>(
        vostok::resources::query_result **__first,
        vostok::resources::query_result **__last)
{
  unsigned __int8 *v2; // ebp
  vostok::resources::query_result **v3; // esi
  signed int v4; // edi
  vostok::resources::query_result *v5; // ebx
  vostok::resources::query_result **v6; // ecx
  int i; // eax

  v2 = (unsigned __int8 *)__first;
  v3 = __first + 1;
  if ( __first + 1 != __last )
  {
    v4 = 4;
    do
    {
      v5 = *v3;
      if ( (*v3)->m_quality_index < *(_DWORD *)(*(_DWORD *)v2 + 680) )
      {
        v6 = v3;
        for ( i = (int)&v2[v4 - 4]; v5->m_quality_index >= *(_DWORD *)(*(_DWORD *)i + 680); i -= 4 )
        {
          *v6 = *(vostok::resources::query_result **)i;
          v6 = (vostok::resources::query_result **)i;
        }
        v2 = (unsigned __int8 *)__first;
        *v6 = v5;
      }
      else
      {
        if ( v4 > 0 )
          memmove((unsigned __int8 *)&v3[v4 / 0xFFFFFFFC + 1], v2, v4);
        *(_DWORD *)v2 = v5;
      }
      ++v3;
      v4 += 4;
    }
    while ( v3 != __last );
  }
}
