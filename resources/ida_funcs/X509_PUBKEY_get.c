evp_pkey_st *__cdecl X509_PUBKEY_get(X509_pubkey_st *key)
{
  evp_pkey_st *pkey; // eax
  evp_pkey_st *v3; // esi
  int v4; // eax
  int (__cdecl *pub_decode)(evp_pkey_st *, X509_pubkey_st *); // eax

  if ( key )
  {
    pkey = key->pkey;
    if ( pkey )
    {
      CRYPTO_add_lock(&pkey->references, 1, 10, ".\\crypto\\asn1\\x_pubkey.c", 141);
      return key->pkey;
    }
    if ( key->public_key )
    {
      v3 = EVP_PKEY_new();
      if ( v3 )
      {
        v4 = OBJ_obj2nid(key->algor->algorithm);
        if ( EVP_PKEY_set_type(v3, v4) )
        {
          pub_decode = v3->ameth->pub_decode;
          if ( pub_decode )
          {
            if ( pub_decode(v3, key) )
            {
              key->pkey = v3;
              CRYPTO_add_lock(&v3->references, 1, 10, ".\\crypto\\asn1\\x_pubkey.c", 175);
              return v3;
            }
            ERR_put_error(0xBu, 119, 125, ".\\crypto\\asn1\\x_pubkey.c", 164);
          }
          else
          {
            ERR_put_error(0xBu, 119, 124, ".\\crypto\\asn1\\x_pubkey.c", 170);
          }
        }
        else
        {
          ERR_put_error(0xBu, 119, 111, ".\\crypto\\asn1\\x_pubkey.c", 155);
        }
      }
      else
      {
        ERR_put_error(0xBu, 119, 65, ".\\crypto\\asn1\\x_pubkey.c", 149);
      }
      if ( v3 )
        EVP_PKEY_free(v3);
    }
  }
  return 0;
}
