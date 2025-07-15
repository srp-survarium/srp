unsigned __int16 *__cdecl wcspbrk(const wchar_t *string, const wchar_t *control)
{
  unsigned __int16 *result; // eax
  unsigned __int16 v3; // dx
  const wchar_t *v4; // esi
  wchar_t v5; // cx

  result = (unsigned __int16 *)string;
  v3 = *string;
  if ( !*string )
    return 0;
  while ( 1 )
  {
    v4 = control;
    if ( *control )
      break;
LABEL_6:
    v3 = *++result;
    if ( !*result )
      return 0;
  }
  v5 = *control;
  while ( v5 != v3 )
  {
    v5 = *++v4;
    if ( !*v4 )
      goto LABEL_6;
  }
  return result;
}
