void __usercall int_dh_free(unsigned int a1@<edi>, evp_pkey_st *pkey)
{
  DH_free(a1, pkey->pkey.dh);
}
