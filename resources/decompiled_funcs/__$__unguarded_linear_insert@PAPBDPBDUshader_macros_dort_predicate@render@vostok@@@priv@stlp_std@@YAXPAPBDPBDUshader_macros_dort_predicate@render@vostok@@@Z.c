void __cdecl stlp_std::priv::__unguarded_linear_insert<char const * *,char const *,vostok::render::shader_macros_dort_predicate>(
        const char **__last,
        const char *__val)
{
  const char **v2; // ebx
  const char **v3; // esi
  const char *i; // edi

  v2 = __last;
  v3 = __last - 1;
  for ( i = *(__last - 1); strcmp(__val, i) < 0; --v3 )
  {
    *v2 = i;
    i = *(v3 - 1);
    v2 = v3;
  }
  *v2 = __val;
}
