void __usercall ecdsa_data_free(unsigned int a1@<edi>, engine_st **data)
{
  if ( data[1] )
    ENGINE_finish(a1, data[1]);
  CRYPTO_free_ex_data(a1);
  OPENSSL_cleanse(data, 24);
  CRYPTO_free(data);
}
