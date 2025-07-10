const char **__usercall stlp_std::priv::__unguarded_partition<char const * *,char const *,bool (__cdecl *)(char const *,char const *)>@<eax>(
        const char **__first@<ecx>,
        const char **__last@<eax>,
        const char *__pivot,
        bool (__cdecl *__comp)(const char *, const char *))
{
  const char *v6; // ecx
  const char *v7; // edx
  const char *v8; // eax
  const char *v9; // eax

  while ( 1 )
  {
    if ( __comp(*__first, __pivot) )
    {
      do
      {
        v6 = __first[1];
        ++__first;
      }
      while ( __comp(v6, __pivot) );
    }
    v7 = *--__last;
    if ( __comp(__pivot, v7) )
    {
      do
        v8 = *--__last;
      while ( __comp(__pivot, v8) );
    }
    if ( __first >= __last )
      break;
    v9 = *__first;
    *__first = *__last;
    *__last = v9;
    ++__first;
  }
  return __first;
}
