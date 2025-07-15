int __cdecl rsa_priv_encode(pkcs8_priv_key_info_st *p8, const evp_pkey_st *pkey)
{
  char *ptr; // edx
  int v3; // eax
  asn1_object_st *v5; // eax
  unsigned __int8 *v6; // [esp-8h] [ebp-Ch]
  int v7; // [esp-4h] [ebp-8h]
  unsigned __int8 *out; // [esp+0h] [ebp-4h] BYREF

  ptr = pkey->pkey.ptr;
  out = 0;
  v3 = i2d_RSAPrivateKey((rsa_st *)ptr, &out);
  if ( v3 <= 0 )
  {
    ERR_put_error(4u, 138, 65, ".\\crypto\\rsa\\rsa_ameth.c", 135);
    return 0;
  }
  v7 = v3;
  v6 = out;
  v5 = OBJ_nid2obj(6u);
  if ( !PKCS8_pkey_set0(p8, v5, 0, 5, 0, v6, v7) )
  {
    ERR_put_error(4u, 138, 65, ".\\crypto\\rsa\\rsa_ameth.c", 142);
    return 0;
  }
  return 1;
}
