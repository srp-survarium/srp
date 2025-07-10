void __usercall stlp_std::priv::__linear_insert<char const * *,char const *,vostok::render::shader_macros_dort_predicate>(
        const char **__first@<edi>,
        const char **__last@<eax>,
        const char *__val,
        vostok::render::shader_macros_dort_predicate __comp)
{
  if ( strcmp(__val, *__first) >= 0 )
  {
    stlp_std::priv::__unguarded_linear_insert<char const * *,char const *,vostok::render::shader_macros_dort_predicate>(
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
