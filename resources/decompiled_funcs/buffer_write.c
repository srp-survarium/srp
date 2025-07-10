int __cdecl buffer_write(bio_st *b, char *in, int inl)
{
  int v3; // ebx
  _DWORD *ptr; // esi
  signed int v5; // edi
  int v6; // eax
  int v7; // edi
  bool v8; // zf
  bool v9; // cc
  int result; // eax
  int v11; // [esp+4h] [ebp-4h]

  v11 = 0;
  if ( !in )
    return 0;
  v3 = inl;
  if ( inl <= 0 )
    return 0;
  ptr = b->ptr;
  if ( !ptr || !b->next_bio )
    return 0;
  BIO_clear_flags(b, 15);
  v5 = ptr[1] - ptr[7] - ptr[6];
  if ( v5 >= inl )
  {
LABEL_20:
    memcpy((unsigned __int8 *)(ptr[6] + ptr[7] + ptr[5]), (unsigned __int8 *)in, v3);
    ptr[6] += v3;
    return v11 + v3;
  }
  else
  {
    while ( 1 )
    {
      v6 = ptr[6];
      if ( v6 )
      {
        if ( v5 > 0 )
        {
          memcpy((unsigned __int8 *)(v6 + ptr[7] + ptr[5]), (unsigned __int8 *)in, v5);
          in += v5;
          v11 += v5;
          v3 -= v5;
          ptr[6] += v5;
        }
        while ( 1 )
        {
          v7 = BIO_write(b->next_bio, (const char *)(ptr[5] + ptr[7]), ptr[6]);
          if ( v7 <= 0 )
            break;
          ptr[7] += v7;
          v8 = ptr[6] == v7;
          ptr[6] -= v7;
          if ( v8 )
            goto LABEL_13;
        }
        BIO_copy_next_retry(b);
        if ( v7 >= 0 )
          return v11;
        goto LABEL_22;
      }
LABEL_13:
      v9 = v3 < ptr[1];
      ptr[7] = 0;
      if ( !v9 )
        break;
LABEL_19:
      v5 = ptr[1] - ptr[7] - ptr[6];
      if ( v5 >= v3 )
        goto LABEL_20;
    }
    while ( 1 )
    {
      v7 = BIO_write(b->next_bio, in, v3);
      if ( v7 <= 0 )
        break;
      v11 += v7;
      in += v7;
      v3 -= v7;
      if ( !v3 )
        return v11;
      if ( v3 < ptr[1] )
        goto LABEL_19;
    }
    BIO_copy_next_retry(b);
    if ( v7 >= 0 )
      return v11;
LABEL_22:
    result = v11;
    if ( v11 <= 0 )
      return v7;
  }
  return result;
}
