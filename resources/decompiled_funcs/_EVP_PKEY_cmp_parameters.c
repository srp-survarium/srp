int __cdecl EVP_PKEY_cmp_parameters(const evp_pkey_st *a, const evp_pkey_st *b)
{
  const evp_pkey_asn1_method_st *ameth; // eax
  int (*param_cmp)(void); // eax

  if ( a->type != b->type )
    return -1;
  ameth = a->ameth;
  if ( ameth && (param_cmp = (int (*)(void))ameth->param_cmp) != 0 )
    return param_cmp();
  else
    return -2;
}
