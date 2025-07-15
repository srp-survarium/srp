int __cdecl buffer_gets(bio_st *b, char *buf, int size)
{
  int *ptr; // esi
  int v4; // ebx
  char *v6; // ecx
  char *v7; // ecx
  int v8; // edi
  int v9; // eax
  int result; // eax
  int v11; // edi
  int v12; // [esp+10h] [ebp-4h]

  ptr = (int *)b->ptr;
  v12 = 0;
  v4 = size - 1;
  BIO_clear_flags(b, 15);
  while ( 1 )
  {
    while ( 1 )
    {
      v6 = (char *)ptr[2];
      if ( ptr[3] <= 0 )
        break;
      v7 = &v6[ptr[4]];
      v8 = 0;
      v9 = 0;
      while ( v9 < v4 )
      {
        *buf++ = v7[v9];
        if ( v7[v9] == 10 )
        {
          v8 = 1;
          ++v9;
          break;
        }
        if ( ++v9 >= ptr[3] )
          break;
      }
      v12 += v9;
      ptr[3] -= v9;
      ptr[4] += v9;
      v4 -= v9;
      if ( v8 || !v4 )
      {
        *buf = 0;
        return v12;
      }
    }
    v11 = BIO_read(v4, b->next_bio, v6, *ptr);
    if ( v11 <= 0 )
      break;
LABEL_17:
    ptr[3] = v11;
    ptr[4] = 0;
  }
  BIO_copy_next_retry(b);
  *buf = 0;
  if ( v11 >= 0 )
  {
    if ( !v11 )
      return v12;
    goto LABEL_17;
  }
  result = v12;
  if ( v12 <= 0 )
    return v11;
  return result;
}
