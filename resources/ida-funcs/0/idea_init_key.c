int __cdecl idea_init_key(evp_cipher_ctx_st *ctx, unsigned __int8 *key, const unsigned __int8 *iv, int enc)
{
  idea_key_st ks; // [esp+4h] [ebp-D8h] BYREF

  if ( enc || (EVP_CIPHER_CTX_flags(ctx) & 0xF0007) == 4 || (EVP_CIPHER_CTX_flags(ctx) & 0xF0007) == 3 )
  {
    idea_set_encrypt_key(key, (idea_key_st *)ctx->cipher_data);
    return 1;
  }
  else
  {
    idea_set_encrypt_key(key, &ks);
    idea_set_decrypt_key(&ks, (idea_key_st *)ctx->cipher_data);
    OPENSSL_cleanse(&ks, 216);
    return 1;
  }
}
