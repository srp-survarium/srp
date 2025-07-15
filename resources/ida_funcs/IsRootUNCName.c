BOOL __usercall IsRootUNCName@<eax>(const char *path@<esi>)
{
  unsigned int v1; // eax
  char v2; // al
  char v3; // al
  const char *v4; // eax
  char v5; // cl
  char *v6; // eax
  char v7; // cl
  unsigned __int8 *v9; // [esp+0h] [ebp-4h]

  strlen(v9);
  if ( v1 < 5 || *path != 92 && *path != 47 )
    return 0;
  v2 = path[1];
  if ( v2 != 92 && v2 != 47 )
    return 0;
  v3 = path[2];
  if ( v3 == 92 )
    return 0;
  if ( v3 == 47 )
    return 0;
  v4 = path + 3;
  v5 = path[3];
  if ( !v5 )
    return 0;
  do
  {
    if ( v5 == 92 )
      break;
    if ( v5 == 47 )
      break;
    v5 = *++v4;
  }
  while ( *v4 );
  if ( !*v4 )
    return 0;
  v6 = (char *)(v4 + 1);
  if ( !*v6 )
    return 0;
  v7 = *v6;
  do
  {
    if ( v7 == 92 )
      break;
    if ( v7 == 47 )
      break;
    v7 = *++v6;
  }
  while ( *v6 );
  return !*v6 || !v6[1];
}
