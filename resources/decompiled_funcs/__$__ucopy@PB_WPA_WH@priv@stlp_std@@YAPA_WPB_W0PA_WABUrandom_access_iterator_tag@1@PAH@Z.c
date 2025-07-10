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
