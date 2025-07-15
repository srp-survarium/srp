unsigned __int16 *__cdecl wcsrchr(const wchar_t *string, wchar_t ch)
{
  unsigned __int16 *result; // eax

  result = (unsigned __int16 *)string;
  while ( *result++ )
    ;
  do
    --result;
  while ( result != string && *result != ch );
  if ( *result != ch )
    return 0;
  return result;
}
