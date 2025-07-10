int __cdecl EVP_PKEY_size(evp_pkey_st *pkey)
{
  const evp_pkey_asn1_method_st *ameth; // eax
  int (*pkey_size)(void); // eax

  if ( pkey && (ameth = pkey->ameth) != 0 && (pkey_size = (int (*)(void))ameth->pkey_size) != 0 )
    return pkey_size();
  else
    return 0;
}
