int __cdecl PKCS8_pkey_get0(
        asn1_object_st **ppkalg,
        const unsigned __int8 **pk,
        int *ppklen,
        X509_algor_st **pa,
        pkcs8_priv_key_info_st *p8)
{
  asn1_type_st *pkey; // ecx

  if ( ppkalg )
    *ppkalg = p8->pkeyalg->algorithm;
  pkey = p8->pkey;
  if ( pkey->type == 4 )
  {
    p8->broken = 0;
  }
  else
  {
    if ( pkey->type != 16 )
      return 0;
    p8->broken = 1;
  }
  if ( pk )
  {
    *pk = *(const unsigned __int8 **)(pkey->value.boolean + 8);
    *ppklen = *(_DWORD *)p8->pkey->value.ptr;
  }
  if ( pa )
    *pa = p8->pkeyalg;
  return 1;
}
