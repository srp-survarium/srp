void __usercall stlp_std::priv::__final_insertion_sort<vostok::resources::resource_base * *,vostok::resources::sorting_predicate>(
        vostok::resources::resource_base **__first@<eax>,
        vostok::resources::sorting_predicate a2@<sil>,
        vostok::resources::resource_base **__last,
        vostok::resources::sorting_predicate __comp)
{
  vostok::resources::resource_base **v4; // ebx
  vostok::resources::resource_base **v5; // esi
  vostok::resources::sorting_predicate v6; // bp
  vostok::resources::sorting_predicate v8; // [esp+0h] [ebp-4h]

  v4 = __last;
  if ( (int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) <= 64 )
  {
    LOBYTE(__last) = __comp;
    if ( __first != v4 )
      stlp_std::priv::__insertion_sort<vostok::resources::resource_base * *,vostok::resources::resource_base *,vostok::resources::sorting_predicate>(
        __first,
        v4,
        (vostok::resources::resource_base **)&__last,
        v8);
  }
  else
  {
    v5 = __first + 16;
    stlp_std::priv::__insertion_sort<vostok::resources::resource_base * *,vostok::resources::resource_base *,vostok::resources::sorting_predicate>(
      __first,
      __first + 16,
      (vostok::resources::resource_base **)&__comp,
      a2);
    LOBYTE(__last) = __comp;
    if ( v5 != v4 )
    {
      v6 = (vostok::resources::sorting_predicate)__last;
      do
      {
        stlp_std::priv::__unguarded_linear_insert<vostok::resources::resource_base * *,vostok::resources::resource_base *,vostok::resources::sorting_predicate>(
          v5,
          *v5,
          v6);
        ++v5;
      }
      while ( v5 != v4 );
    }
  }
}
