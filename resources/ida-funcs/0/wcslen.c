int __cdecl wcslen(const wchar_t *wcs)
{
  const wchar_t *v1; // eax

  v1 = wcs;
  while ( *v1++ )
    ;
  return v1 - wcs - 1;
}
