int __cdecl ssl3_generate_master_secret(ssl_st *s, unsigned __int8 *out)
{
  const unsigned __int8 **v3; // edi
  const char *v4; // eax
  unsigned int size; // [esp+10h] [ebp-68h] BYREF
  int v7; // [esp+14h] [ebp-64h]
  int v8; // [esp+18h] [ebp-60h]
  env_md_ctx_st ctx; // [esp+1Ch] [ebp-5Ch] BYREF
  unsigned __int8 md[64]; // [esp+34h] [ebp-44h] BYREF

  v7 = 0;
  EVP_MD_CTX_init(&ctx);
  v3 = salt;
  do
  {
    EVP_DigestInit_ex(&ctx, s->ctx->sha1, 0);
    v4 = (const char *)*v3;
    v8 = (int)(*v3 + 1);
    strlen(v4);
    EVP_DigestUpdate(&ctx);
    EVP_DigestUpdate(&ctx);
    EVP_DigestUpdate(&ctx);
    EVP_DigestUpdate(&ctx);
    EVP_DigestFinal_ex((unsigned int)v3, &ctx, md, &size);
    EVP_DigestInit_ex(&ctx, s->ctx->md5, 0);
    EVP_DigestUpdate(&ctx);
    EVP_DigestUpdate(&ctx);
    EVP_DigestFinal_ex((unsigned int)v3, &ctx, out, &size);
    v7 += size;
    ++v3;
    out += size;
  }
  while ( (int)v3 < (int)&DTLSv1_enc_data );
  EVP_MD_CTX_cleanup((unsigned int)v3, &ctx);
  return v7;
}
