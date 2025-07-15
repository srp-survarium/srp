int __cdecl enc_write(bio_st *b, char *in, int inl)
{
  int v3; // ebx
  char *ptr; // esi
  int v6; // edi
  int v7; // eax
  int v8; // ebx
  int v9; // edi
  int v10; // edi
  int v11; // eax
  int inla; // [esp+1Ch] [ebp+Ch]

  v3 = inl;
  ptr = (char *)b->ptr;
  BIO_clear_flags(b, 15);
  v6 = *(_DWORD *)ptr - *((_DWORD *)ptr + 1);
  if ( v6 > 0 )
  {
    while ( 1 )
    {
      v7 = BIO_write(b->next_bio, &ptr[*((_DWORD *)ptr + 1) + 160], v6);
      v8 = v7;
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
    return v8;
  }
LABEL_5:
  if ( !in || v3 <= 0 )
    return 0;
  *((_DWORD *)ptr + 1) = 0;
  while ( 1 )
  {
    v9 = 4096;
    if ( v3 <= 4096 )
      v9 = v3;
    EVP_CipherUpdate(
      (evp_cipher_ctx_st *)(ptr + 20),
      (unsigned __int8 *)ptr + 160,
      (int *)ptr,
      (unsigned __int8 *)in,
      v9);
    in += v9;
    v3 -= v9;
    v10 = *(_DWORD *)ptr;
    inla = v3;
    *((_DWORD *)ptr + 1) = 0;
    if ( v10 > 0 )
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
    v11 = BIO_write(b->next_bio, &ptr[*((_DWORD *)ptr + 1) + 160], v10);
    v8 = v11;
    if ( v11 <= 0 )
      break;
    *((_DWORD *)ptr + 1) += v11;
    v10 -= v11;
    if ( v10 <= 0 )
    {
      v3 = inla;
      goto LABEL_14;
    }
  }
  BIO_copy_next_retry(b);
  if ( inl == inla )
    return v8;
  return inl - inla;
}
