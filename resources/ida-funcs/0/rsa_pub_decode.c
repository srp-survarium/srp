int __usercall rsa_pub_decode@<eax>(int a1@<ebx>, evp_pkey_st *pkey, X509_pubkey_st *pubkey)
{
  char *v3; // eax
  const unsigned __int8 **v5; // [esp+0h] [ebp-8h] BYREF
  unsigned __int8 *v6; // [esp+4h] [ebp-4h] BYREF

  if ( !X509_PUBKEY_get0_param(0, &v6, (int *)&v5, 0, pubkey) )
    return 0;
  v3 = (char *)d2i_RSAPublicKey(0, &v6, v5);
  if ( !v3 )
  {
    ERR_put_error(a1, 4u, 139, 4, ".\\crypto\\rsa\\rsa_ameth.c", 94);
    return 0;
  }
  EVP_PKEY_assign(pkey, (void *)6, v3);
  return 1;
}
