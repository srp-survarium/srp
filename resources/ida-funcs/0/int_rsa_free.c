void __usercall int_rsa_free(unsigned int a1@<edi>, evp_pkey_st *pkey)
{
  RSA_free(a1, pkey->pkey.rsa);
}
