int __cdecl EVP_BytesToKey(
        const evp_cipher_st *type,
        const env_md_st *md,
        unsigned __int8 *salt,
        const unsigned __int8 *data,
        unsigned int datal,
        unsigned int count,
        unsigned __int8 *key,
        unsigned __int8 *iv)
{
  int iv_len; // ebp
  signed int key_len; // edi
  unsigned int v13; // esi
  unsigned int v14; // ecx
  int i; // eax
  unsigned __int8 *v16; // esi
  unsigned __int8 v17; // dl
  unsigned int counta; // [esp+10h] [ebp-74h] BYREF
  unsigned __int8 *v19; // [esp+14h] [ebp-70h]
  const env_md_st *typea; // [esp+18h] [ebp-6Ch]
  int v21; // [esp+1Ch] [ebp-68h]
  void *v22; // [esp+20h] [ebp-64h]
  const unsigned __int8 *v23; // [esp+24h] [ebp-60h]
  env_md_ctx_st ctx; // [esp+28h] [ebp-5Ch] BYREF
  unsigned __int8 dataa[64]; // [esp+40h] [ebp-44h] BYREF

  typea = md;
  v21 = 0;
  counta = 0;
  iv_len = type->iv_len;
  key_len = type->key_len;
  v22 = salt;
  v23 = data;
  v19 = key;
  if ( key_len > 32 )
    OpenSSLDie(key_len, (unsigned int)data, ".\\crypto\\evp\\evp_key.c", 126, "nkey <= EVP_MAX_KEY_LENGTH");
  if ( iv_len > 16 )
    OpenSSLDie(key_len, (unsigned int)data, ".\\crypto\\evp\\evp_key.c", 127, "niv <= EVP_MAX_IV_LENGTH");
  if ( !data )
    return key_len;
  EVP_MD_CTX_init(&ctx);
  if ( !EVP_DigestInit_ex(&ctx, typea, 0) )
    return 0;
  while ( 1 )
  {
    if ( v21++ )
      EVP_DigestUpdate(&ctx);
    EVP_DigestUpdate(&ctx);
    if ( v22 )
      EVP_DigestUpdate(&ctx);
    EVP_DigestFinal_ex(key_len, &ctx, dataa, &counta);
    if ( count > 1 )
    {
      v13 = count - 1;
      do
      {
        EVP_DigestInit_ex(&ctx, typea, 0);
        EVP_DigestUpdate(&ctx);
        EVP_DigestFinal_ex(key_len, &ctx, dataa, &counta);
        --v13;
      }
      while ( v13 );
    }
    v14 = counta;
    for ( i = 0; key_len; ++i )
    {
      if ( i == v14 )
        break;
      if ( v19 )
      {
        v16 = v19;
        v17 = dataa[i];
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
        if ( iv )
          *iv++ = dataa[i];
        --iv_len;
        ++i;
      }
      while ( iv_len );
    }
    if ( !key_len && !iv_len )
      break;
    if ( !EVP_DigestInit_ex(&ctx, typea, 0) )
      return 0;
  }
  EVP_MD_CTX_cleanup(0, &ctx);
  OPENSSL_cleanse(dataa, 64);
  return type->key_len;
}
