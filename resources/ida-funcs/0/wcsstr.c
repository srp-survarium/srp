unsigned __int16 *__cdecl wcsstr(const wchar_t *wcs1, const wchar_t *wcs2)
{
  unsigned __int16 *result; // eax
  const wchar_t *v3; // edi
  unsigned __int16 v4; // dx
  int i; // eax
  const wchar_t *v6; // ecx

  result = (unsigned __int16 *)wcs1;
  v3 = wcs1;
  if ( *wcs2 )
  {
    if ( *wcs1 )
    {
      v4 = *wcs1;
      for ( i = (char *)wcs1 - (char *)wcs2; ; i += 2 )
      {
        v6 = wcs2;
        if ( v4 )
          break;
LABEL_8:
        if ( !*v6 )
          return (unsigned __int16 *)v3;
        v4 = *++v3;
        if ( !*v3 )
          return 0;
      }
      while ( *v6 )
      {
        if ( *(const wchar_t *)((char *)v6 + i) == *v6 )
        {
          if ( *(const wchar_t *)((char *)++v6 + i) )
            continue;
        }
        goto LABEL_8;
      }
      return (unsigned __int16 *)v3;
    }
    else
    {
      return 0;
    }
  }
  return result;
}
