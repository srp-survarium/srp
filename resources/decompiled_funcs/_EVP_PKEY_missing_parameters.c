int __cdecl EVP_PKEY_missing_parameters(const evp_pkey_st *pkey)
{
  const evp_pkey_asn1_method_st *ameth; // eax
  int (*param_missing)(void); // eax

  ameth = pkey->ameth;
  if ( ameth && (param_missing = (int (*)(void))ameth->param_missing) != 0 )
    return param_missing();
  else
    return 0;
}
