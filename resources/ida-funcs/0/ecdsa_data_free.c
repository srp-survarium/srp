void __usercall ecdsa_data_free(int a1@<ebx>, int a2@<edi>, engine_st **str)
{
  if ( str[1] )
    ENGINE_finish(a2, a1, str[1]);
  CRYPTO_free_ex_data(a2, a1);
  OPENSSL_cleanse(str, 24);
  CRYPTO_free(str);
}
