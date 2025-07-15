int __cdecl EVP_PKEY_asn1_get0_info(
        int *ppkey_id,
        int *ppkey_base_id,
        unsigned int *ppkey_flags,
        char **pinfo,
        char **ppem_str,
        const evp_pkey_asn1_method_st *ameth)
{
  int result; // eax

  result = (int)ameth;
  if ( ameth )
  {
    if ( ppkey_id )
      *ppkey_id = ameth->pkey_id;
    if ( ppkey_base_id )
      *ppkey_base_id = ameth->pkey_base_id;
    if ( ppkey_flags )
      *ppkey_flags = ameth->pkey_flags;
    if ( pinfo )
      *pinfo = ameth->info;
    if ( ppem_str )
      *ppem_str = ameth->pem_str;
    return 1;
  }
  return result;
}
