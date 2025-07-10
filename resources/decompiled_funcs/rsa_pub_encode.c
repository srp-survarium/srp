int __cdecl rsa_pub_encode(X509_pubkey_st *pk, const evp_pkey_st *pkey)
{
  char *ptr; // edx
  int v3; // eax
  asn1_object_st *v4; // eax
  unsigned __int8 *v6; // [esp-8h] [ebp-Ch]
  int v7; // [esp-4h] [ebp-8h]
  unsigned __int8 *out; // [esp+0h] [ebp-4h] BYREF

  ptr = pkey->pkey.ptr;
  out = 0;
  v3 = i2d_RSAPublicKey((rsa_st *)ptr, &out);
  if ( v3 > 0 )
  {
    v7 = v3;
    v6 = out;
    v4 = OBJ_nid2obj(6u);
    if ( X509_PUBKEY_set0_param(pk, v4, 5, 0, v6, v7) )
      return 1;
    CRYPTO_free(out);
  }
  return 0;
}
