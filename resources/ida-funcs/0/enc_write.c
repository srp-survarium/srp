int __cdecl enc_write(bio_st *b, char *in, int inl)
{
  int v3; // ebx
  char *ptr; // esi
  int v6; // edi
  int v7; // eax
  int v8; // edi
  int v9; // edi
  int v10; // eax
  int v14; // [esp+1Ch] [ebp+Ch]

  v3 = inl;
  ptr = (char *)b->ptr;
  BIO_clear_flags(b, 15);
  v6 = *(_DWORD *)ptr - *((_DWORD *)ptr + 1);
  if ( v6 > 0 )
  {
    while ( 1 )
    {
      v7 = BIO_write(v3, b->next_bio, &ptr[*((_DWORD *)ptr + 1) + 160], v6);
      v3 = v7;
      if ( v7 <= 0 )
        break;
      *((_DWORD *)ptr + 1) += v7;
      v6 -= v7;
      if ( v6 <= 0 )
      {
        v3 = inl;
        goto LABEL_5;
      }
    }
    BIO_copy_next_retry(b);
    return v3;
  }
LABEL_5:
  if ( !in || v3 <= 0 )
    return 0;
  *((_DWORD *)ptr + 1) = 0;
  while ( 1 )
  {
    v8 = 4096;
    if ( v3 <= 4096 )
      v8 = v3;
    EVP_CipherUpdate(
      (evp_cipher_ctx_st *)(ptr + 20),
      (unsigned __int8 *)ptr + 160,
      (int *)ptr,
      (unsigned __int8 *)in,
      v8);
    in += v8;
    v3 -= v8;
    v9 = *(_DWORD *)ptr;
    v14 = v3;
    *((_DWORD *)ptr + 1) = 0;
    if ( v9 > 0 )
      break;
LABEL_14:
    *(_DWORD *)ptr = 0;
    *((_DWORD *)ptr + 1) = 0;
    if ( v3 <= 0 )
    {
      BIO_copy_next_retry(b);
      return inl;
    }
  }
  while ( 1 )
  {
    v10 = BIO_write(v3, b->next_bio, &ptr[*((_DWORD *)ptr + 1) + 160], v9);
    v3 = v10;
    if ( v10 <= 0 )
      break;
    *((_DWORD *)ptr + 1) += v10;
    v9 -= v10;
    if ( v9 <= 0 )
    {
      v3 = v14;
      goto LABEL_14;
    }
  }
  BIO_copy_next_retry(b);
  if ( inl == v14 )
    return v3;
  return inl - v14;
}
