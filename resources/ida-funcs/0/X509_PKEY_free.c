void __usercall X509_PKEY_free(int a1@<edi>, private_key_st *x)
{
  if ( x && CRYPTO_add_lock(&x->references, -1, 5, ".\\crypto\\asn1\\x_pkey.c", 133) <= 0 )
  {
    if ( x->enc_algor )
      X509_ALGOR_free(x->enc_algor);
    if ( x->enc_pkey )
      ASN1_STRING_free(x->enc_pkey);
    if ( x->dec_pkey )
      EVP_PKEY_free(a1, x->dec_pkey);
    if ( x->key_data )
    {
      if ( x->key_free )
        CRYPTO_free(x->key_data);
    }
    CRYPTO_free(x);
  }
}
