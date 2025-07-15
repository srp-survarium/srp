int __usercall b64_read@<eax>(int a1@<edi>, int a2@<ebx>, bio_st *b, char *out, int outl)
{
  int result; // eax
  char *ptr; // esi
  int v7; // edi
  int v8; // ebx
  int v9; // edi
  const unsigned __int8 *v10; // edi
  const unsigned __int8 *v11; // ebp
  char v12; // al
  int i; // eax
  int v14; // ebp
  int j; // eax
  unsigned int v16; // edi
  int v17; // eax
  unsigned int v18; // ebx
  unsigned int v19; // edi
  int v20; // [esp+4h] [ebp-10h]
  int v21; // [esp+8h] [ebp-Ch]
  int v22; // [esp+8h] [ebp-Ch]
  int v23; // [esp+Ch] [ebp-8h]
  int outla; // [esp+10h] [ebp-4h] BYREF

  v20 = 0;
  if ( !out )
    return 0;
  ptr = (char *)b->ptr;
  if ( !ptr || !b->next_bio )
    return 0;
  BIO_clear_flags(b, 15);
  if ( *((_DWORD *)ptr + 4) != 2 )
  {
    *((_DWORD *)ptr + 4) = 2;
    *(_DWORD *)ptr = 0;
    *((_DWORD *)ptr + 1) = 0;
    *((_DWORD *)ptr + 2) = 0;
    EVP_DecodeInit((evp_Encode_Ctx_st *)(ptr + 28));
  }
  if ( *(int *)ptr <= 0 )
  {
    v8 = outl;
  }
  else
  {
    if ( *(_DWORD *)ptr < *((_DWORD *)ptr + 1) )
      OpenSSLDie(a1, (int)ptr, a2, ".\\crypto\\evp\\bio_b64.c", 169, "ctx->buf_len >= ctx->buf_off");
    v7 = *(_DWORD *)ptr - *((_DWORD *)ptr + 1);
    if ( v7 > outl )
      v7 = outl;
    if ( v7 + *((_DWORD *)ptr + 1) >= 1502 )
      OpenSSLDie(v7, (int)ptr, outl, ".\\crypto\\evp\\bio_b64.c", 172, "ctx->buf_off+i < (int)sizeof(ctx->buf)");
    memcpy((int)out, (const __m128i *)&ptr[*((_DWORD *)ptr + 1) + 124], v7);
    *((_DWORD *)ptr + 1) += v7;
    out += v7;
    v8 = outl - v7;
    v20 = v7;
    outl -= v7;
    if ( *(_DWORD *)ptr == *((_DWORD *)ptr + 1) )
    {
      *(_DWORD *)ptr = 0;
      *((_DWORD *)ptr + 1) = 0;
    }
  }
  v23 = 0;
  if ( v8 <= 0 )
    goto LABEL_73;
  while ( 2 )
  {
    if ( *((int *)ptr + 6) <= 0 )
      goto LABEL_73;
    v9 = BIO_read(v8, b->next_bio, &ptr[*((_DWORD *)ptr + 2) + 1626], 1024 - *((_DWORD *)ptr + 2));
    if ( v9 <= 0 )
    {
      v23 = v9;
      if ( BIO_test_flags(b->next_bio, 8) )
        goto LABEL_73;
      *((_DWORD *)ptr + 6) = v9;
      if ( !*((_DWORD *)ptr + 2) )
        goto LABEL_73;
      v9 = 0;
    }
    *((_DWORD *)ptr + 2) += v9;
    v8 = *((_DWORD *)ptr + 2);
    if ( !*((_DWORD *)ptr + 5) )
      goto LABEL_54;
    if ( (BIO_test_flags(b, -1) & 0x100) != 0 )
    {
      *((_DWORD *)ptr + 2) = 0;
      goto LABEL_55;
    }
    if ( !*((_DWORD *)ptr + 5) )
    {
LABEL_54:
      if ( v8 < 1024 && *((int *)ptr + 6) > 0 )
        goto LABEL_46;
      goto LABEL_55;
    }
    v10 = (const unsigned __int8 *)(ptr + 1626);
    v11 = (const unsigned __int8 *)(ptr + 1626);
    v21 = 0;
    if ( v8 <= 0 )
      goto LABEL_42;
    while ( 1 )
    {
      v12 = *v11++;
      if ( v12 == 10 )
        break;
LABEL_36:
      if ( ++v21 >= v8 )
        goto LABEL_42;
    }
    if ( *((_DWORD *)ptr + 3) )
    {
      *((_DWORD *)ptr + 3) = 0;
LABEL_35:
      v10 = v11;
      goto LABEL_36;
    }
    if ( EVP_DecodeUpdate((evp_Encode_Ctx_st *)(ptr + 28), (unsigned __int8 *)ptr + 124, &outla, v10, v11 - v10) <= 0
      && !outla
      && *((_DWORD *)ptr + 5) )
    {
      EVP_DecodeInit((evp_Encode_Ctx_st *)(ptr + 28));
      goto LABEL_35;
    }
    if ( v10 != (const unsigned __int8 *)(ptr + 1626) )
    {
      v8 += ptr - (char *)v10 + 1626;
      for ( i = 0; i < v8; ++i )
        ptr[i + 1626] = v10[i];
    }
    EVP_DecodeInit((evp_Encode_Ctx_st *)(ptr + 28));
    *((_DWORD *)ptr + 5) = 0;
LABEL_42:
    if ( v21 == v8 )
    {
      if ( v10 == (const unsigned __int8 *)(ptr + 1626) )
      {
        if ( v8 == 1024 )
        {
          *((_DWORD *)ptr + 3) = 1;
          *((_DWORD *)ptr + 2) = 0;
        }
      }
      else if ( v10 != v11 )
      {
        v14 = v11 - v10;
        for ( j = 0; j < v14; ++j )
          ptr[j + 1626] = v10[j];
        *((_DWORD *)ptr + 2) = v14;
      }
LABEL_46:
      if ( outl <= 0 )
        goto LABEL_73;
      continue;
    }
    break;
  }
  *((_DWORD *)ptr + 2) = 0;
LABEL_55:
  if ( (BIO_test_flags(b, -1) & 0x100) != 0 )
  {
    v16 = v8 & 0xFFFFFFFC;
    v17 = EVP_DecodeBlock((unsigned __int8 *)ptr + 124, (const unsigned __int8 *)ptr + 1626, v8 & 0xFFFFFFFC);
    v22 = v17;
    if ( (int)(v8 & 0xFFFFFFFC) > 2 && ptr[v16 + 1625] == 61 )
    {
      v22 = --v17;
      if ( ptr[v16 + 1624] == 61 )
        v22 = --v17;
    }
    if ( v16 != v8 )
    {
      v18 = v8 - v16;
      memmove((int)(ptr + 1626), (const __m128i *)&ptr[v16 + 1626], v18);
      v17 = v22;
      *((_DWORD *)ptr + 2) = v18;
    }
    *(_DWORD *)ptr = 0;
    if ( v17 > 0 )
      *(_DWORD *)ptr = v17;
  }
  else
  {
    v17 = EVP_DecodeUpdate(
            (evp_Encode_Ctx_st *)(ptr + 28),
            (unsigned __int8 *)ptr + 124,
            (int *)ptr,
            (const unsigned __int8 *)ptr + 1626,
            v8);
    *((_DWORD *)ptr + 2) = 0;
  }
  *((_DWORD *)ptr + 1) = 0;
  if ( v17 >= 0 )
  {
    v19 = *(_DWORD *)ptr;
    if ( *(_DWORD *)ptr > outl )
      v19 = outl;
    memcpy((int)out, (const __m128i *)(ptr + 124), v19);
    v20 += v19;
    *((_DWORD *)ptr + 1) = v19;
    if ( v19 == *(_DWORD *)ptr )
    {
      *(_DWORD *)ptr = 0;
      *((_DWORD *)ptr + 1) = 0;
    }
    v8 = outl - v19;
    out += v19;
    outl -= v19;
    goto LABEL_46;
  }
  v23 = 0;
  *(_DWORD *)ptr = 0;
LABEL_73:
  BIO_copy_next_retry(b);
  result = v20;
  if ( !v20 )
    return v23;
  return result;
}
