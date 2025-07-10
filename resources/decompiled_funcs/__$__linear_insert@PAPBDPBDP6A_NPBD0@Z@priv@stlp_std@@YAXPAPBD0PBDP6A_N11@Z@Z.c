void __usercall stlp_std::priv::__linear_insert<char const * *,char const *,bool (__cdecl *)(char const *,char const *)>(
        const char **__first@<edi>,
        const char **__last@<eax>,
        const char *__val)
{
  bool (__cdecl *v4)(const char *, const char *); // [esp+0h] [ebp-8h]

  if ( strcmp(__val, *__first) == -1 )
  {
    if ( (char *)__last - (char *)__first > 0 )
      memmove((unsigned __int8 *)__first + 4, (unsigned __int8 *)__first, (char *)__last - (char *)__first);
    *__first = __val;
  }
  else
  {
    stlp_std::priv::__unguarded_linear_insert<char const * *,char const *,bool (__cdecl *)(char const *,char const *)>(
      __last,
      __val,
      v4);
  }
}
