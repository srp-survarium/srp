int __fastcall tls_decrypt_ticket(
        ssl_session_st **psess,
        const __m128i *etick,
        ssl_st *s,
        int eticklen,
        unsigned __int8 *sess_id,
        unsigned int sesslen)
{
  ssl_ctx_st *initial_ctx; // ebx
  int (__cdecl *tlsext_ticket_key_cb)(ssl_st *, unsigned __int8 *, unsigned __int8 *, evp_cipher_ctx_st *, hmac_ctx_st *, int); // eax
  int v9; // eax
  unsigned __int8 *tlsext_tick_key_name; // eax
  unsigned int v11; // ecx
  const env_md_st *v12; // eax
  const evp_cipher_st *v13; // eax
  int v14; // eax
  int v16; // esi
  unsigned int v17; // eax
  unsigned __int8 *v18; // ecx
  unsigned __int8 *v19; // ebp
  int v20; // esi
  unsigned __int8 *v21; // edi
  ssl_session_st *v22; // esi
  ssl_session_st **v23; // eax
  BOOL v24; // ecx
  ssl_st *v25; // edx
  int length; // [esp+10h] [ebp-1BCh] BYREF
  int outl; // [esp+14h] [ebp-1B8h] BYREF
  unsigned __int8 *pp; // [esp+18h] [ebp-1B4h] BYREF
  ssl_st *v29; // [esp+1Ch] [ebp-1B0h]
  BOOL v30; // [esp+20h] [ebp-1ACh]
  ssl_session_st **v31; // [esp+24h] [ebp-1A8h]
  unsigned __int8 *src; // [esp+28h] [ebp-1A4h]
  evp_cipher_ctx_st v33; // [esp+2Ch] [ebp-1A0h] BYREF
  hmac_ctx_st ctx; // [esp+B8h] [ebp-114h] BYREF
  unsigned __int8 v35[64]; // [esp+188h] [ebp-44h] BYREF

  initial_ctx = s->initial_ctx;
  v29 = s;
  src = sess_id;
  v31 = psess;
  v30 = 0;
  if ( eticklen < 48 )
  {
tickerr:
    v29->tlsext_ticket_expected = 1;
    return 0;
  }
  HMAC_CTX_init(&ctx);
  EVP_CIPHER_CTX_init(&v33);
  tlsext_ticket_key_cb = initial_ctx->tlsext_ticket_key_cb;
  if ( !tlsext_ticket_key_cb )
  {
    tlsext_tick_key_name = initial_ctx->tlsext_tick_key_name;
    v11 = 16;
    while ( *(_DWORD *)&tlsext_tick_key_name[(char *)etick - (char *)initial_ctx->tlsext_tick_key_name] == *(_DWORD *)tlsext_tick_key_name )
    {
      v11 -= 4;
      tlsext_tick_key_name += 4;
      if ( v11 < 4 )
      {
        v12 = EVP_sha256();
        HMAC_Init_ex(
          (int)etick,
          (env_md_ctx_st *)initial_ctx,
          &ctx,
          (const __m128i *)initial_ctx->tlsext_tick_hmac_key,
          16,
          v12,
          0);
        initial_ctx = (ssl_ctx_st *)((char *)initial_ctx + 296);
        v13 = EVP_aes_128_cbc();
        EVP_DecryptInit_ex(&v33, v13, 0, (const unsigned __int8 *)initial_ctx, etick + 1);
        goto LABEL_10;
      }
    }
    goto tickerr;
  }
  v9 = tlsext_ticket_key_cb(s, (unsigned __int8 *)etick, (unsigned __int8 *)&etick[1], &v33, &ctx, 0);
  if ( v9 < 0 )
    return -1;
  if ( !v9 )
    goto tickerr;
  v30 = v9 == 2;
LABEL_10:
  v14 = EVP_MD_size((int)initial_ctx, ctx.md);
  outl = v14;
  if ( v14 < 0 )
  {
    EVP_CIPHER_CTX_cleanup((int)etick, (int)initial_ctx, &v33);
    return -1;
  }
  v16 = eticklen - v14;
  HMAC_Update(&ctx);
  HMAC_Final(&ctx, v35, 0);
  HMAC_CTX_cleanup((int)etick, (int)initial_ctx, &ctx);
  v17 = outl;
  v18 = &etick->m128i_u8[v16];
  v19 = v35;
  if ( (unsigned int)outl >= 4 )
  {
    while ( *(_DWORD *)v19 == *(_DWORD *)v18 )
    {
      v17 -= 4;
      v18 += 4;
      v19 += 4;
      if ( v17 < 4 )
        goto LABEL_16;
    }
    goto tickerr;
  }
LABEL_16:
  if ( v17 && (*v18 != *v19 || v17 > 1 && (v18[1] != v19[1] || v17 > 2 && v18[2] != v19[2])) )
    goto tickerr;
  pp = &etick[1].m128i_u8[(_DWORD)X509_get_issuer_name((x509_st *)&v33)];
  v20 = -16 - (_DWORD)X509_get_issuer_name((x509_st *)&v33) + v16;
  v21 = (unsigned __int8 *)CRYPTO_malloc(v20, ".\\ssl\\t1_lib.c", 1716);
  if ( !v21 )
  {
    EVP_CIPHER_CTX_cleanup(0, (int)initial_ctx, &v33);
    return -1;
  }
  EVP_DecryptUpdate(&v33, v21, &length, (const __m128i *)pp, v20);
  if ( EVP_DecryptFinal(&v33, &v21[length], &outl) <= 0 )
    goto tickerr;
  length += outl;
  EVP_CIPHER_CTX_cleanup((int)v21, (int)initial_ctx, &v33);
  pp = v21;
  v22 = d2i_SSL_SESSION((int)v21, 0, (const unsigned __int8 **)&pp, length);
  CRYPTO_free(v21);
  if ( !v22 )
    goto tickerr;
  if ( sesslen )
    memcpy((int)v22->session_id, (const __m128i *)src, sesslen);
  v23 = v31;
  v24 = v30;
  v25 = v29;
  v22->session_id_length = sesslen;
  *v23 = v22;
  v25->tlsext_ticket_expected = v24;
  return 1;
}
