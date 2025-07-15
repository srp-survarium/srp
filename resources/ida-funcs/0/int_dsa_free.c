void __usercall int_dsa_free(int a1@<edi>, evp_pkey_st *pkey)
{
  DSA_free(a1, pkey->pkey.dsa);
}
