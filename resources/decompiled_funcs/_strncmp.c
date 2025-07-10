int __cdecl strncmp(const char *first, const char *last, unsigned int count)
{
  const char *v4; // ecx
  const char *v5; // eax
  char v6; // dl
  char v7; // dl
  char v8; // dl
  char v9; // dl
  int v10; // eax
  int v11; // ecx
  unsigned int n; // [esp+4h] [ebp-4h]

  n = 0;
  if ( !count )
    return 0;
  if ( count <= 4 )
  {
    v4 = last;
    v5 = first;
    goto LABEL_23;
  }
  v4 = last;
  v5 = first;
  do
  {
    v6 = *v5;
    v5 += 4;
    v4 += 4;
    if ( !v6 || v6 != *(v4 - 4) )
    {
      v10 = *((unsigned __int8 *)v5 - 4);
      v11 = *((unsigned __int8 *)v4 - 4);
      return v10 - v11;
    }
    v7 = *(v5 - 3);
    if ( !v7 || v7 != *(v4 - 3) )
    {
      v10 = *((unsigned __int8 *)v5 - 3);
      v11 = *((unsigned __int8 *)v4 - 3);
      return v10 - v11;
    }
    v8 = *(v5 - 2);
    if ( !v8 || v8 != *(v4 - 2) )
    {
      v10 = *((unsigned __int8 *)v5 - 2);
      v11 = *((unsigned __int8 *)v4 - 2);
      return v10 - v11;
    }
    v9 = *(v5 - 1);
    if ( !v9 || v9 != *(v4 - 1) )
    {
      v10 = *((unsigned __int8 *)v5 - 1);
      v11 = *((unsigned __int8 *)v4 - 1);
      return v10 - v11;
    }
    n += 4;
  }
  while ( n < count - 4 );
  while ( 1 )
  {
LABEL_23:
    if ( n >= count )
      return 0;
    if ( !*v5 || *v5 != *v4 )
      break;
    ++v5;
    ++v4;
    ++n;
  }
  v10 = *(unsigned __int8 *)v5;
  v11 = *(unsigned __int8 *)v4;
  return v10 - v11;
}
