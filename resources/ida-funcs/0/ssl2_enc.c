void __cdecl ssl2_enc(ssl_st *s, int send)
{
  evp_cipher_ctx_st *enc_write_ctx; // ecx

  if ( send )
    enc_write_ctx = s->enc_write_ctx;
  else
    enc_write_ctx = s->enc_read_ctx;
  if ( enc_write_ctx )
    EVP_Cipher(enc_write_ctx);
}
