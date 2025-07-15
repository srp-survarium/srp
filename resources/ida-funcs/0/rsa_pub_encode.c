int __usercall rsa_pub_encode@<eax>(int a1@<ebx>, X509_pubkey_st *pk, const evp_pkey_st *pkey)
{
  char *ptr; // edx
  int v4; // eax
  asn1_object_st *v5; // eax
  unsigned __int8 *v7; // [esp-8h] [ebp-Ch]
  int v8; // [esp-4h] [ebp-8h]
  unsigned __int8 *out; // [esp+0h] [ebp-4h] BYREF

  ptr = pkey->pkey.ptr;
  out = 0;
  v4 = i2d_RSAPublicKey((rsa_st *)ptr, &out);
  if ( v4 > 0 )
  {
    v8 = v4;
    v7 = out;
    v5 = OBJ_nid2obj(a1, 6u);
    if ( X509_PUBKEY_set0_param(pk, v5, 5, 0, v7, v8) )
      return 1;
    CRYPTO_free(out);
  }
  return 0;
}
