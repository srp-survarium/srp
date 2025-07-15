int __cdecl eckey_pub_decode(evp_pkey_st *pkey, X509_pubkey_st *pubkey)
{
  ec_key_st *a; // [esp+0h] [ebp-18h] BYREF
  unsigned __int8 *pk; // [esp+4h] [ebp-14h] BYREF
  X509_algor_st *pa; // [esp+8h] [ebp-10h] BYREF
  int pptype; // [esp+Ch] [ebp-Ch] BYREF
  void *ppval; // [esp+10h] [ebp-8h] BYREF
  int ppklen; // [esp+14h] [ebp-4h] BYREF

  pk = 0;
  a = 0;
  if ( !X509_PUBKEY_get0_param(0, &pk, &ppklen, &pa, pubkey) )
    return 0;
  X509_ALGOR_get0(0, &pptype, &ppval, pa);
  a = eckey_type2param((const unsigned __int8 *)pptype);
  if ( !a )
  {
    ERR_put_error(0x10u, 215, 16, ".\\crypto\\ec\\ec_ameth.c", 206);
    return 0;
  }
  if ( o2i_ECPublicKey(&a, (const unsigned __int8 **)&pk, ppklen) )
  {
    EVP_PKEY_assign(pkey, 408, (char *)a);
    return 1;
  }
  else
  {
    ERR_put_error(0x10u, 215, 142, ".\\crypto\\ec\\ec_ameth.c", 213);
    if ( a )
      EC_KEY_free(a);
    return 0;
  }
}
