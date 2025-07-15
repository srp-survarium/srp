char *__fastcall strip_spaces(char *name)
{
  char *v1; // esi
  char *v3; // edi

  v1 = name;
  if ( !*name )
    return 0;
  while ( isspace((unsigned __int8)*v1) )
  {
    if ( !*++v1 )
      return 0;
  }
  if ( !*v1 )
    return 0;
  v3 = &v1[strlen(v1) - 1];
  if ( v3 != v1 )
  {
    while ( isspace((unsigned __int8)*v3) )
    {
      if ( --v3 == v1 )
        return *v1 != 0 ? v1 : 0;
    }
    if ( v1 != v3 )
      v3[1] = 0;
  }
  return *v1 != 0 ? v1 : 0;
}
