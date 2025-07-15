int __cdecl EVP_BytesToKey(
        const evp_cipher_st *type,
        const env_md_st *md,
        const unsigned __int8 *salt,
        const unsigned __int8 *data,
        int datal,
        unsigned int count,
        unsigned __int8 *key,
        engine_st *iv)
{
  engine_st *v8; // ebx
  int iv_len; // ebp
  int key_len; // edi
  int v13; // esi
  unsigned int v14; // ecx
  int i; // eax
  unsigned __int8 *v16; // esi
  unsigned __int8 v17; // dl
  unsigned int v18; // [esp+10h] [ebp-74h] BYREF
  unsigned __int8 *v19; // [esp+14h] [ebp-70h]
  const env_md_st *typea; // [esp+18h] [ebp-6Ch]
  int v21; // [esp+1Ch] [ebp-68h]
  const unsigned __int8 *v22; // [esp+20h] [ebp-64h]
  const unsigned __int8 *v23; // [esp+24h] [ebp-60h]
  env_md_ctx_st ctx; // [esp+28h] [ebp-5Ch] BYREF
  unsigned __int8 v25[64]; // [esp+40h] [ebp-44h] BYREF

  v8 = iv;
  typea = md;
  v21 = 0;
  v18 = 0;
  iv_len = type->iv_len;
  key_len = type->key_len;
  v22 = salt;
  v23 = data;
  v19 = key;
  if ( key_len > 32 )
    OpenSSLDie(key_len, (int)data, (int)iv, ".\\crypto\\evp\\evp_key.c", 126, "nkey <= EVP_MAX_KEY_LENGTH");
  if ( iv_len > 16 )
    OpenSSLDie(key_len, (int)data, (int)iv, ".\\crypto\\evp\\evp_key.c", 127, "niv <= EVP_MAX_IV_LENGTH");
  if ( !data )
    return key_len;
  EVP_MD_CTX_init(&ctx);
  if ( !EVP_DigestInit_ex(iv, &ctx, typea, 0) )
    return 0;
  while ( 1 )
  {
    if ( v21++ )
      EVP_DigestUpdate(&ctx);
    EVP_DigestUpdate(&ctx);
    if ( v22 )
      EVP_DigestUpdate(&ctx);
    EVP_DigestFinal_ex(key_len, (int)v8, &ctx, v25, &v18);
    if ( count > 1 )
    {
      v13 = count - 1;
      do
      {
        EVP_DigestInit_ex(v8, &ctx, typea, 0);
        EVP_DigestUpdate(&ctx);
        EVP_DigestFinal_ex(key_len, (int)v8, &ctx, v25, &v18);
        --v13;
      }
      while ( v13 );
    }
    v14 = v18;
    for ( i = 0; key_len; ++i )
    {
      if ( i == v14 )
        break;
      if ( v19 )
      {
        v16 = v19;
        v17 = v25[i];
        ++v19;
        *v16 = v17;
      }
      --key_len;
    }
    if ( iv_len && i != v14 )
    {
      do
      {
        if ( i == v14 )
          break;
        if ( v8 )
        {
          LOBYTE(v8->id) = v25[i];
          v8 = (engine_st *)((char *)v8 + 1);
        }
        --iv_len;
        ++i;
      }
      while ( iv_len );
    }
    if ( !key_len && !iv_len )
      break;
    if ( !EVP_DigestInit_ex(v8, &ctx, typea, 0) )
      return 0;
  }
  EVP_MD_CTX_cleanup(0, (int)v8, &ctx);
  OPENSSL_cleanse(v25, 64);
  return type->key_len;
}
