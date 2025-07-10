void __cdecl stlp_std::priv::__partial_sort<char const * *,char const *,vostok::render::shader_macros_dort_predicate>(
        const char **__first,
        const char **__middle,
        const char **__last,
        const char **__formal)
{
  const char **v4; // esi
  const char *v5; // edi

  v4 = __middle;
  if ( __middle - __first >= 2 )
    stlp_std::__make_heap<char const * *,vostok::render::shader_macros_dort_predicate,char const *,int>(
      __first,
      __middle);
  if ( __middle < __last )
  {
    do
    {
      v5 = *v4;
      if ( strcmp(*v4, *__first) < 0 )
      {
        *v4 = *__first;
        stlp_std::__adjust_heap<char const * *,int,char const *,vostok::render::shader_macros_dort_predicate>(
          __first,
          0,
          __middle - __first,
          v5,
          (vostok::render::shader_macros_dort_predicate)__formal);
      }
      ++v4;
    }
    while ( v4 < __last );
    v4 = __middle;
  }
  stlp_std::sort_heap<char const * *,vostok::render::shader_macros_dort_predicate>(
    __first,
    v4,
    (vostok::render::shader_macros_dort_predicate)__formal);
}
