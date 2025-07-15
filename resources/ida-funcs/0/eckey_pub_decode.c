int __usercall eckey_pub_decode@<eax>(int a1@<ebx>, evp_pkey_st *pkey, X509_pubkey_st *pubkey)
{
  ec_key_st *r; // [esp+0h] [ebp-18h] BYREF
  unsigned __int8 *v5; // [esp+4h] [ebp-14h] BYREF
  X509_algor_st *v6; // [esp+8h] [ebp-10h] BYREF
  int v7; // [esp+Ch] [ebp-Ch] BYREF
  const asn1_object_st *v8; // [esp+10h] [ebp-8h] BYREF
  unsigned int v9; // [esp+14h] [ebp-4h] BYREF

  v5 = 0;
  r = 0;
  if ( !X509_PUBKEY_get0_param(0, &v5, (int *)&v9, &v6, pubkey) )
    return 0;
  X509_ALGOR_get0(0, &v7, (char **)&v8, v6);
  r = eckey_type2param(v8, a1, v7);
  if ( !r )
  {
    ERR_put_error(a1, 0x10u, 215, 16, ".\\crypto\\ec\\ec_ameth.c", 206);
    return 0;
  }
  if ( o2i_ECPublicKey(a1, &r, (const unsigned __int8 **)&v5, v9) )
  {
    EVP_PKEY_assign(pkey, (void *)0x198, (char *)r);
    return 1;
  }
  else
  {
    ERR_put_error(a1, 0x10u, 215, 142, ".\\crypto\\ec\\ec_ameth.c", 213);
    if ( r )
      EC_KEY_free(r);
    return 0;
  }
}
