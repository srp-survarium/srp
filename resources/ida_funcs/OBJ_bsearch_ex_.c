char *__cdecl OBJ_bsearch_ex_(
        const void *key,
        char *base_,
        int num,
        int size,
        int (__cdecl *cmp)(const void *, const void *),
        char flags)
{
  int v6; // ebp
  int v7; // esi
  char *v8; // edi
  int v10; // ebx
  int v11; // eax
  char *v12; // edi

  v6 = num;
  v7 = 0;
  v8 = 0;
  if ( !num )
    return 0;
  v10 = 0;
  if ( num <= 0 )
    goto LABEL_12;
  do
  {
    v7 = (v10 + v6) / 2;
    v8 = &base_[size * v7];
    v11 = cmp(key, v8);
    if ( v11 >= 0 )
    {
      if ( v11 <= 0 )
        break;
      v10 = v7 + 1;
    }
    else
    {
      v6 = (v10 + v6) / 2;
    }
  }
  while ( v10 < v6 );
  if ( v11 )
  {
    if ( (flags & 1) == 0 )
      return 0;
  }
  else
  {
LABEL_12:
    if ( (flags & 2) != 0 )
    {
      if ( v7 > 0 )
      {
        v12 = &base_[size * (v7 - 1)];
        do
        {
          if ( cmp(key, v12) )
            break;
          --v7;
          v12 -= size;
        }
        while ( v7 > 0 );
      }
      return &base_[size * v7];
    }
  }
  return v8;
}
