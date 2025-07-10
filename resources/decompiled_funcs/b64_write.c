int __usercall b64_write@<eax>(unsigned int a1@<edi>, bio_st *b, char *in, int inl)
{
  bio_st *v4; // ebp
  char *ptr; // esi
  int v6; // edi
  unsigned __int8 *v7; // ebp
  int v8; // ebx
  int result; // eax
  int v10; // eax
  int v11; // ebx
  int v12; // edi
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // ebx
  signed int v18; // eax
  signed int v19; // edi
  int v20; // [esp+10h] [ebp-4h]
  int v21; // [esp+20h] [ebp+Ch]

  v4 = b;
  ptr = (char *)b->ptr;
  v20 = 0;
  BIO_clear_flags(b, 15);
  if ( *((_DWORD *)ptr + 4) != 1 )
  {
    *((_DWORD *)ptr + 4) = 1;
    *(_DWORD *)ptr = 0;
    *((_DWORD *)ptr + 1) = 0;
    *((_DWORD *)ptr + 2) = 0;
    EVP_EncodeInit((evp_Encode_Ctx_st *)(ptr + 28));
  }
  if ( *((int *)ptr + 1) >= 1502 )
    OpenSSLDie(a1, (unsigned int)ptr, ".\\crypto\\evp\\bio_b64.c", 392, "ctx->buf_off < (int)sizeof(ctx->buf)");
  if ( *(int *)ptr > 1502 )
    OpenSSLDie(a1, (unsigned int)ptr, ".\\crypto\\evp\\bio_b64.c", 393, "ctx->buf_len <= (int)sizeof(ctx->buf)");
  if ( *(_DWORD *)ptr < *((_DWORD *)ptr + 1) )
    OpenSSLDie(a1, (unsigned int)ptr, ".\\crypto\\evp\\bio_b64.c", 394, "ctx->buf_len >= ctx->buf_off");
  v6 = *(_DWORD *)ptr - *((_DWORD *)ptr + 1);
  if ( v6 > 0 )
  {
    while ( 1 )
    {
      v10 = BIO_write(v4->next_bio, &ptr[*((_DWORD *)ptr + 1) + 124], v6);
      v11 = v10;
      if ( v10 <= 0 )
      {
        BIO_copy_next_retry(b);
        return v11;
      }
      if ( v10 > v6 )
        OpenSSLDie(v6, (unsigned int)ptr, ".\\crypto\\evp\\bio_b64.c", 404, "i <= n");
      *((_DWORD *)ptr + 1) += v10;
      if ( *((int *)ptr + 1) > 1502 )
        OpenSSLDie(v6, (unsigned int)ptr, ".\\crypto\\evp\\bio_b64.c", 406, "ctx->buf_off <= (int)sizeof(ctx->buf)");
      if ( *(_DWORD *)ptr < *((_DWORD *)ptr + 1) )
        OpenSSLDie(v6, (unsigned int)ptr, ".\\crypto\\evp\\bio_b64.c", 407, "ctx->buf_len >= ctx->buf_off");
      v6 -= v10;
      if ( v6 <= 0 )
        break;
      v4 = b;
    }
  }
  v7 = (unsigned __int8 *)in;
  *((_DWORD *)ptr + 1) = 0;
  *(_DWORD *)ptr = 0;
  if ( !in )
    return 0;
  v8 = inl;
  if ( inl <= 0 )
    return 0;
  while ( 1 )
  {
    v12 = 1024;
    if ( v8 <= 1024 )
      v12 = v8;
    if ( (BIO_test_flags(b, -1) & 0x100) == 0 )
    {
      EVP_EncodeUpdate(
        (unsigned int)ptr,
        (evp_Encode_Ctx_st *)(ptr + 28),
        (unsigned __int8 *)ptr + 124,
        (int *)ptr,
        v7,
        v12);
      if ( *(int *)ptr > 1502 )
        OpenSSLDie(v12, (unsigned int)ptr, ".\\crypto\\evp\\bio_b64.c", 462, "ctx->buf_len <= (int)sizeof(ctx->buf)");
      if ( *(_DWORD *)ptr < *((_DWORD *)ptr + 1) )
        OpenSSLDie(v12, (unsigned int)ptr, ".\\crypto\\evp\\bio_b64.c", 463, "ctx->buf_len >= ctx->buf_off");
LABEL_49:
      v20 += v12;
      goto LABEL_50;
    }
    v13 = *((_DWORD *)ptr + 2);
    if ( v13 <= 0 )
    {
      if ( v12 < 3 )
      {
        memcpy((unsigned __int8 *)ptr + 1626, v7, v12);
        result = v12 + v20;
        *((_DWORD *)ptr + 2) = v12;
        return result;
      }
      v12 = 3 * (v12 / 3);
      v16 = EVP_EncodeBlock((unsigned __int8 *)ptr + 124, v7, v12);
      *(_DWORD *)ptr = v16;
      if ( v16 > 1502 )
        OpenSSLDie(v12, (unsigned int)ptr, ".\\crypto\\evp\\bio_b64.c", 452, "ctx->buf_len <= (int)sizeof(ctx->buf)");
      if ( *(_DWORD *)ptr < *((_DWORD *)ptr + 1) )
        OpenSSLDie(v12, (unsigned int)ptr, ".\\crypto\\evp\\bio_b64.c", 453, "ctx->buf_len >= ctx->buf_off");
      goto LABEL_49;
    }
    if ( v13 > 3 )
      OpenSSLDie(v12, (unsigned int)ptr, ".\\crypto\\evp\\bio_b64.c", 424, "ctx->tmp_len <= 3");
    v12 = 3 - *((_DWORD *)ptr + 2);
    if ( v12 > v8 )
      v12 = v8;
    memcpy((unsigned __int8 *)&ptr[*((_DWORD *)ptr + 2) + 1626], v7, v12);
    *((_DWORD *)ptr + 2) += v12;
    v14 = *((_DWORD *)ptr + 2);
    v20 += v12;
    if ( v14 < 3 )
      return v20;
    v15 = EVP_EncodeBlock((unsigned __int8 *)ptr + 124, (const unsigned __int8 *)ptr + 1626, v14);
    *(_DWORD *)ptr = v15;
    if ( v15 > 1502 )
      OpenSSLDie(v12, (unsigned int)ptr, ".\\crypto\\evp\\bio_b64.c", 435, "ctx->buf_len <= (int)sizeof(ctx->buf)");
    if ( *(_DWORD *)ptr < *((_DWORD *)ptr + 1) )
      OpenSSLDie(v12, (unsigned int)ptr, ".\\crypto\\evp\\bio_b64.c", 436, "ctx->buf_len >= ctx->buf_off");
    *((_DWORD *)ptr + 2) = 0;
LABEL_50:
    v21 = v8 - v12;
    v17 = *(_DWORD *)ptr;
    v7 += v12;
    *((_DWORD *)ptr + 1) = 0;
    if ( v17 > 0 )
      break;
LABEL_59:
    *(_DWORD *)ptr = 0;
    *((_DWORD *)ptr + 1) = 0;
    if ( v21 <= 0 )
      return v20;
    v8 = v21;
  }
  while ( 1 )
  {
    v18 = BIO_write(b->next_bio, &ptr[*((_DWORD *)ptr + 1) + 124], v17);
    v19 = v18;
    if ( v18 <= 0 )
      break;
    if ( v18 > v17 )
      OpenSSLDie(v18, (unsigned int)ptr, ".\\crypto\\evp\\bio_b64.c", 479, "i <= n");
    *((_DWORD *)ptr + 1) += v18;
    v17 -= v18;
    if ( *((int *)ptr + 1) > 1502 )
      OpenSSLDie(v18, (unsigned int)ptr, ".\\crypto\\evp\\bio_b64.c", 482, "ctx->buf_off <= (int)sizeof(ctx->buf)");
    if ( *(_DWORD *)ptr < *((_DWORD *)ptr + 1) )
      OpenSSLDie(v18, (unsigned int)ptr, ".\\crypto\\evp\\bio_b64.c", 483, "ctx->buf_len >= ctx->buf_off");
    if ( v17 <= 0 )
      goto LABEL_59;
  }
  BIO_copy_next_retry(b);
  result = v20;
  if ( !v20 )
    return v19;
  return result;
}
