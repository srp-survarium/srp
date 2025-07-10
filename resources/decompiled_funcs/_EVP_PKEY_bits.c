int __cdecl EVP_PKEY_bits(evp_pkey_st *pkey)
{
  const evp_pkey_asn1_method_st *ameth; // eax
  int (*pkey_bits)(void); // eax

  if ( pkey && (ameth = pkey->ameth) != 0 && (pkey_bits = (int (*)(void))ameth->pkey_bits) != 0 )
    return pkey_bits();
  else
    return 0;
}
