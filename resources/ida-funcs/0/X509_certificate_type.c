int __cdecl X509_certificate_type(x509_st *x, evp_pkey_st *pkey)
{
  int v2; // edi
  evp_pkey_st *pubkey; // esi
  int type; // eax
  void *v6; // eax
  const char *v7; // eax

  v2 = 0;
  if ( !x )
    return 0;
  if ( pkey )
    pubkey = pkey;
  else
    pubkey = X509_get_pubkey(x);
  if ( !pubkey )
    return 0;
  type = pubkey->type;
  if ( pubkey->type > 116 )
  {
    if ( type == 408 )
    {
      v2 = 88;
    }
    else if ( (unsigned int)(type - 811) <= 1 )
    {
      v2 = 80;
    }
  }
  else if ( pubkey->type == 116 )
  {
    v2 = 18;
  }
  else if ( type == 6 )
  {
    v2 = 49;
  }
  else if ( type == 28 )
  {
    v2 = 68;
  }
  v6 = OBJ_obj2nid(x->sig_alg->algorithm);
  v7 = EVP_PKEY_type(v2, v6);
  if ( v7 == (const char *)6 )
  {
    v2 |= 0x100u;
  }
  else if ( v7 == (const char *)116 )
  {
    v2 |= 0x200u;
  }
  else if ( v7 == (const char *)408 )
  {
    v2 |= 0x400u;
  }
  if ( EVP_PKEY_size(pubkey) <= 128 )
    v2 |= 0x1000u;
  if ( !pkey )
    EVP_PKEY_free(v2, pubkey);
  return v2;
}
