void __usercall stlp_std::priv::__linear_insert<char const * *,char const *,vostok::tips_sorting_predicate>(
        const char **__last@<eax>,
        const char **__first,
        char *__val,
        vostok::tips_sorting_predicate __comp)
{
  unsigned __int8 *v4; // ebx
  int v6; // eax
  int v7; // esi
  int v8; // eax

  v4 = (unsigned __int8 *)*__first;
  strstr((unsigned __int8 *)__val, (unsigned __int8 *)__comp.editor_str);
  v7 = v6;
  strstr(v4, (unsigned __int8 *)__comp.editor_str);
  if ( v7 - (int)__val >= v8 - (int)v4 )
  {
    stlp_std::priv::__unguarded_linear_insert<char const * *,char const *,vostok::tips_sorting_predicate>(
      __last,
      __val,
      __comp);
  }
  else
  {
    if ( (char *)__last - (char *)__first > 0 )
      memmove((unsigned __int8 *)__first + 4, (unsigned __int8 *)__first, (char *)__last - (char *)__first);
    *__first = __val;
  }
}
