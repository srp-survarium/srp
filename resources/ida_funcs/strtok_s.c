char *__usercall strtok_s@<eax>(unsigned int a1@<ebx>, char *_String, const char *_Control, char **_Context)
{
  const char *v4; // esi
  char v6; // dl
  char *v7; // edx
  char *v8; // ebx
  unsigned __int8 map[32]; // [esp+10h] [ebp-24h] BYREF

  v4 = _Control;
  if ( _Context && _Control && (_String || *_Context) )
  {
    memset(map, 0, sizeof(map));
    do
    {
      v6 = *v4;
      map[*(unsigned __int8 *)v4 >> 3] |= 1 << (*v4 & 7);
      ++v4;
    }
    while ( v6 );
    v7 = _String;
    if ( !_String )
      v7 = *_Context;
    while ( ((unsigned __int8)(1 << (*v7 & 7)) & map[(unsigned __int8)*v7 >> 3]) != 0 && *v7 )
      ++v7;
    v8 = v7;
    while ( *v7 )
    {
      if ( ((unsigned __int8)(1 << (*v7 & 7)) & map[(unsigned __int8)*v7 >> 3]) != 0 )
      {
        *v7++ = 0;
        break;
      }
      ++v7;
    }
    *_Context = v7;
    return v7 != v8 ? v8 : 0;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(a1, 0, (unsigned int)_Control);
    return 0;
  }
}
