int __cdecl EVP_PKEY_cmp(const evp_pkey_st *a, const evp_pkey_st *b)
{
  int result; // eax
  const evp_pkey_asn1_method_st *ameth; // eax
  int (__cdecl *param_cmp)(const evp_pkey_st *, const evp_pkey_st *); // eax
  int (__cdecl *pub_cmp)(const evp_pkey_st *, const evp_pkey_st *); // eax

  if ( a->type != b->type )
    return -1;
  ameth = a->ameth;
  if ( !ameth )
    return -2;
  param_cmp = ameth->param_cmp;
  if ( !param_cmp || (result = param_cmp(a, b), result > 0) )
  {
    pub_cmp = a->ameth->pub_cmp;
    if ( pub_cmp )
      return pub_cmp(a, b);
    return -2;
  }
  return result;
}
