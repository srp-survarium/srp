char *__cdecl stlp_std::priv::__ucopy<char *,char *,int>(const char *__first, const char *__last, char *__result)
{
  char *result; // eax
  const char *v4; // esi
  int i; // ecx
  char v6; // dl

  result = __result;
  v4 = __first;
  for ( i = __last - __first; i > 0; --i )
  {
    v6 = *v4++;
    *result++ = v6;
  }
  return result;
}


char *__cdecl stlp_std::priv::__ucopy<char const *,char *>(const char *__first, const char *__last, char *__result)
{
  char *result; // eax
  int i; // ecx

  result = __result;
  for ( i = __last - __first; i > 0; --i )
  {
    *result = result[__first - __result];
    ++result;
  }
  return result;
}


wchar_t *__cdecl stlp_std::priv::__ucopy<wchar_t const *,wchar_t *,int>(
        wchar_t *__first,
        const wchar_t *__last,
        wchar_t *__result)
{
  wchar_t *v3; // edx
  wchar_t *result; // eax
  int i; // ecx

  v3 = __first;
  result = __result;
  for ( i = __last - __first; i > 0; ++result )
  {
    *result = *v3;
    --i;
    ++v3;
  }
  return result;
}
