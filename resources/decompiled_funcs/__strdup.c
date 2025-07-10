char *__cdecl _strdup(char *string)
{
  int v2; // eax
  unsigned int v3; // esi
  char *v4; // eax
  unsigned int v5; // edi

  if ( !string )
    return 0;
  strlen((unsigned __int8 *)string);
  v3 = v2 + 1;
  v4 = (char *)malloc(v2 + 1);
  v5 = (unsigned int)v4;
  if ( !v4 )
    return 0;
  if ( strcpy_s(v4, v3, string) )
    _invoke_watson(0, v5, v3);
  return (char *)v5;
}
