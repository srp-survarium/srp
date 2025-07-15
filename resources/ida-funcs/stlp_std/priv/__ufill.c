void __cdecl stlp_std::priv::__ufill<char *,char,int>(char *__first, char *__last, char *__x)
{
  char *v3; // ecx
  int i; // eax

  v3 = __first;
  for ( i = __last - __first; i > 0; --i )
    *v3++ = *__x;
}


void __cdecl stlp_std::priv::__ufill<wchar_t *,wchar_t,int>(wchar_t *__first, wchar_t *__last, wchar_t *__x)
{
  wchar_t *v3; // ecx
  int i; // eax

  v3 = __first;
  for ( i = __last - __first; i > 0; ++v3 )
  {
    *v3 = *__x;
    --i;
  }
}
