const char **__usercall stlp_std::priv::__unguarded_partition<char const * *,char const *,vostok::render::shader_macros_dort_predicate>@<eax>(
        const char **__first@<eax>,
        const char **__last@<ecx>,
        const char *__pivot@<edi>)
{
  const char *v4; // ecx
  const char *v5; // edx
  const char *v6; // edx
  const char *v7; // ecx

  while ( 1 )
  {
    if ( strcmp(*__first, __pivot) < 0 )
    {
      do
      {
        v4 = __first[1];
        ++__first;
      }
      while ( strcmp(v4, __pivot) < 0 );
    }
    v5 = *--__last;
    if ( strcmp(__pivot, v5) < 0 )
    {
      do
        v6 = *--__last;
      while ( strcmp(__pivot, v6) < 0 );
    }
    if ( __first >= __last )
      break;
    v7 = *__first;
    *__first = *__last;
    *__last = v7;
    ++__first;
  }
  return __first;
}
