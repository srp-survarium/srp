bool __usercall vostok::strings::compare_with_wildcards@<al>(char *wild@<eax>, const char *string@<ecx>)
{
  const char *v2; // esi
  char v3; // cl
  const char *v4; // edi
  const char *v5; // ebx
  char v6; // dl
  char i; // dl
  char v9; // cl

  v2 = string;
  v3 = *string;
  v4 = 0;
  v5 = 0;
  if ( v3 )
  {
    while ( 1 )
    {
      v6 = *wild;
      if ( *wild == 42 )
        break;
      if ( v6 != v3 && v6 != 63 )
        return 0;
      v3 = *++v2;
      ++wild;
      if ( !v3 )
        goto LABEL_6;
    }
    for ( i = *v2; *v2; i = *v2 )
    {
      v9 = *wild;
      if ( *wild == 42 )
      {
        if ( !*++wild )
          return 1;
        v5 = wild;
        v4 = v2 + 1;
      }
      else if ( v9 == i || v9 == 63 )
      {
        ++wild;
        ++v2;
      }
      else
      {
        v2 = v4;
        wild = (char *)v5;
        ++v4;
      }
    }
  }
LABEL_6:
  while ( *wild == 42 )
    ++wild;
  return *wild == 0;
}
