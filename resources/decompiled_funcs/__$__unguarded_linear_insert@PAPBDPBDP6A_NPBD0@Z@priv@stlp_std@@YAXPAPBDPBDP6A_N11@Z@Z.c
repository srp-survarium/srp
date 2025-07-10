void __cdecl stlp_std::priv::__unguarded_linear_insert<char const * *,char const *,bool (__cdecl *)(char const *,char const *)>(
        const char **__last,
        const char *__val)
{
  const char **v2; // ebx
  const char **i; // edi

  v2 = __last;
  for ( i = __last - 1; strcmp(__val, *i) == -1; --i )
  {
    *v2 = *i;
    v2 = i;
  }
  *v2 = __val;
}
