int __cdecl EVP_PKEY_get_default_digest_nid(evp_pkey_st *pkey, int *pnid)
{
  const evp_pkey_asn1_method_st *ameth; // eax
  int (__cdecl *pkey_ctrl)(evp_pkey_st *, int, int, void *); // eax

  ameth = pkey->ameth;
  if ( ameth && (pkey_ctrl = ameth->pkey_ctrl) != 0 )
    return pkey_ctrl(pkey, 3, 0, pnid);
  else
    return -2;
}
