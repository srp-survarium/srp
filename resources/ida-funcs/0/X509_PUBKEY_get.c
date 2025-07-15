evp_pkey_st *__usercall X509_PUBKEY_get@<eax>(int a1@<ebx>, X509_pubkey_st *key)
{
  evp_pkey_st *pkey; // eax
  evp_pkey_st *v4; // esi
  void *v5; // eax
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
      v4 = EVP_PKEY_new(a1);
      if ( v4 )
      {
        v5 = OBJ_obj2nid(key->algor->algorithm);
        if ( EVP_PKEY_set_type(v4, v5) )
        {
          pub_decode = v4->ameth->pub_decode;
          if ( pub_decode )
          {
            if ( pub_decode(v4, key) )
            {
              key->pkey = v4;
              CRYPTO_add_lock(&v4->references, 1, 10, ".\\crypto\\asn1\\x_pubkey.c", 175);
              return v4;
            }
            ERR_put_error(a1, 0xBu, 119, 125, ".\\crypto\\asn1\\x_pubkey.c", 164);
          }
          else
          {
            ERR_put_error(a1, 0xBu, 119, 124, ".\\crypto\\asn1\\x_pubkey.c", 170);
          }
        }
        else
        {
          ERR_put_error(a1, 0xBu, 119, 111, ".\\crypto\\asn1\\x_pubkey.c", 155);
        }
      }
      else
      {
        ERR_put_error(a1, 0xBu, 119, 65, ".\\crypto\\asn1\\x_pubkey.c", 149);
      }
      if ( v4 )
        EVP_PKEY_free((int)key, v4);
    }
  }
  return 0;
}
