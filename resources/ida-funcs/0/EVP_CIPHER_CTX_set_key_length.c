int __usercall EVP_CIPHER_CTX_set_key_length@<eax>(int a1@<ebx>, evp_cipher_ctx_st *c, int keylen)
{
  unsigned int flags; // edx

  flags = c->cipher->flags;
  if ( (flags & 0x80u) != 0 )
    return EVP_CIPHER_CTX_ctrl(a1, c, 1, keylen, 0);
  if ( c->key_len == keylen )
    return 1;
  if ( keylen > 0 && (flags & 8) != 0 )
  {
    c->key_len = keylen;
    return 1;
  }
  ERR_put_error(a1, 6u, 122, 130, ".\\crypto\\evp\\evp_enc.c", 529);
  return 0;
}
