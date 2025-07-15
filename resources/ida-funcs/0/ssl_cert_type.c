int __cdecl ssl_cert_type(x509_st *x, evp_pkey_st *pkey)
{
  int v2; // esi
  evp_pkey_st *pubkey; // eax
  int type; // ecx

  v2 = -1;
  if ( pkey )
    pubkey = pkey;
  else
    pubkey = X509_get_pubkey(x);
  if ( pubkey )
  {
    type = pubkey->type;
    if ( pubkey->type == 6 )
    {
      v2 = 0;
    }
    else
    {
      switch ( type )
      {
        case 116:
          v2 = 2;
          break;
        case 408:
          v2 = 5;
          break;
        case 812:
        case 850:
          v2 = 6;
          break;
        case 811:
        case 851:
          v2 = 7;
          break;
      }
    }
  }
  if ( !pkey )
    EVP_PKEY_free(pubkey);
  return v2;
}
