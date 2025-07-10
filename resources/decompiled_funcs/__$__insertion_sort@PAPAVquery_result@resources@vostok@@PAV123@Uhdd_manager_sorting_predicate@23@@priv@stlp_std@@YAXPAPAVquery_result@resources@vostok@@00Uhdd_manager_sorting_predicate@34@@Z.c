void __cdecl stlp_std::priv::__insertion_sort<vostok::resources::query_result * *,vostok::resources::query_result *,vostok::resources::hdd_manager_sorting_predicate>(
        vostok::resources::query_result **__first,
        vostok::resources::query_result **__last,
        vostok::resources::query_result **__formal)
{
  vostok::resources::query_result **v3; // esi
  signed int v4; // edi
  vostok::resources::query_result *v5; // [esp+0h] [ebp-18h]
  vostok::resources::query_result *__val; // [esp+10h] [ebp-8h]

  if ( __first != __last )
  {
    v3 = __first + 1;
    if ( __first + 1 != __last )
    {
      v4 = 4;
      do
      {
        __val = *v3;
        if ( vostok::resources::hdd_manager_sorting_predicate::operator()(
               *v3,
               (vostok::resources::hdd_manager_sorting_predicate *)*__first,
               v5) )
        {
          if ( v4 > 0 )
            memmove((unsigned __int8 *)&v3[v4 / 0xFFFFFFFC + 1], (unsigned __int8 *)__first, v4);
          *__first = __val;
        }
        else
        {
          stlp_std::priv::__unguarded_linear_insert<vostok::resources::query_result * *,vostok::resources::query_result *,vostok::resources::hdd_manager_sorting_predicate>(
            v3,
            __val,
            (vostok::resources::hdd_manager_sorting_predicate)__formal);
        }
        ++v3;
        v4 += 4;
      }
      while ( v3 != __last );
    }
  }
}
