void __usercall stlp_std::sort_heap<char const * *,bool (__cdecl *)(char const *,char const *)>(
        const char **__first@<ecx>,
        const char **__last@<eax>,
        bool (__cdecl *__comp)(const char *, const char *))
{
  int v4; // eax
  const char *v5; // ecx
  int v6; // esi

  v4 = (char *)__last - (char *)__first;
  if ( (int)(v4 & 0xFFFFFFFC) > 4 )
  {
    do
    {
      v5 = *(const char **)((char *)__first + v4 - 4);
      v6 = v4 - 4;
      *(const char **)((char *)__first + v4 - 4) = *__first;
      stlp_std::__adjust_heap<char const * *,int,char const *,bool (__cdecl *)(char const *,char const *)>(
        __first,
        0,
        (v4 - 4) >> 2,
        v5,
        __comp);
      v4 = v6;
    }
    while ( (int)(v6 & 0xFFFFFFFC) > 4 );
  }
}
