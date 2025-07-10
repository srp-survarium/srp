void __cdecl stlp_std::priv::__partial_sort<char const * *,char const *,vostok::tips_sorting_predicate>(
        const char **__first,
        const char **__middle,
        const char **__last,
        const char **__formal)
{
  unsigned __int8 **v4; // ebx
  const char **v5; // esi
  unsigned __int8 *v6; // ebp
  char *v7; // edi
  int v8; // eax
  int v9; // esi
  int v10; // eax
  unsigned __int8 *v11; // [esp-10h] [ebp-20h]

  v4 = (unsigned __int8 **)__middle;
  v5 = __first;
  if ( __middle - __first >= 2 )
    stlp_std::__make_heap<char const * *,vostok::tips_sorting_predicate,char const *,int>(__first, __middle);
  if ( __middle < __last )
  {
    do
    {
      v6 = *v4;
      v7 = (char *)*v5;
      strstr(*v4, (unsigned __int8 *)__formal);
      v9 = v8;
      strstr((unsigned __int8 *)v7, (unsigned __int8 *)__formal);
      if ( v9 - (int)v6 < v10 - (int)v7 )
      {
        v11 = *v4;
        *v4 = (unsigned __int8 *)*__first;
        stlp_std::__adjust_heap<char const * *,int,char const *,vostok::tips_sorting_predicate>(
          __first,
          0,
          __middle - __first,
          (const char *)v11,
          (vostok::tips_sorting_predicate)__formal);
      }
      v5 = __first;
      ++v4;
    }
    while ( v4 < (unsigned __int8 **)__last );
    v4 = (unsigned __int8 **)__middle;
  }
  stlp_std::sort_heap<char const * *,vostok::tips_sorting_predicate>(
    v5,
    (const char **)v4,
    (vostok::tips_sorting_predicate)__formal);
}
