int __usercall enc_free@<eax>(int a1@<edi>, int a2@<ebx>, bio_st *a)
{
  if ( !a )
    return 0;
  EVP_CIPHER_CTX_cleanup(a1, a2, (evp_cipher_ctx_st *)((char *)a->ptr + 20));
  OPENSSL_cleanse(a->ptr, 4324);
  CRYPTO_free(a->ptr);
  a->ptr = 0;
  a->init = 0;
  a->flags = 0;
  return 1;
}
