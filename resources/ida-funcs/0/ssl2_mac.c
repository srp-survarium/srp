void __cdecl ssl2_mac(ssl_st *s, unsigned __int8 *md, int send)
{
  ssl2_state_st *s2; // ecx
  int write_key; // edi
  int wact_data_length; // ebx
  env_md_ctx_st ctx; // [esp+10h] [ebp-18h] BYREF

  s2 = s->s2;
  if ( send )
  {
    write_key = (int)s2->write_key;
    wact_data_length = s2->wact_data_length;
  }
  else
  {
    write_key = (int)s2->read_key;
    wact_data_length = s2->ract_data_length;
  }
  EVP_MD_CTX_init(&ctx);
  EVP_MD_CTX_copy(&ctx, s->read_hash);
  EVP_CIPHER_CTX_key_length(s->enc_read_ctx);
  EVP_DigestUpdate(&ctx);
  EVP_DigestUpdate(&ctx);
  EVP_DigestUpdate(&ctx);
  EVP_DigestFinal_ex(write_key, wact_data_length, &ctx, md, 0);
  EVP_MD_CTX_cleanup(write_key, wact_data_length, &ctx);
}
