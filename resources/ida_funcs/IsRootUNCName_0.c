BOOL __usercall IsRootUNCName_0@<eax>(const wchar_t *path@<esi>)
{
  wchar_t v1; // ax
  wchar_t v2; // ax
  const wchar_t *v3; // eax
  wchar_t v4; // cx
  __int16 *v5; // eax
  __int16 v6; // cx
  const wchar_t *v8; // [esp+0h] [ebp-4h]

  if ( (unsigned int)wcslen(v8) < 5 || *path != 92 && *path != 47 )
    return 0;
  v1 = path[1];
  if ( v1 != 92 && v1 != 47 )
    return 0;
  v2 = path[2];
  if ( v2 == 92 )
    return 0;
  if ( v2 == 47 )
    return 0;
  v3 = path + 3;
  v4 = path[3];
  if ( !v4 )
    return 0;
  do
  {
    if ( v4 == 92 )
      break;
    if ( v4 == 47 )
      break;
    v4 = *++v3;
  }
  while ( *v3 );
  if ( !*v3 )
    return 0;
  v5 = (__int16 *)(v3 + 1);
  if ( !*v5 )
    return 0;
  v6 = *v5;
  do
  {
    if ( v6 == 92 )
      break;
    if ( v6 == 47 )
      break;
    v6 = *++v5;
  }
  while ( *v5 );
  return !*v5 || !v5[1];
}
