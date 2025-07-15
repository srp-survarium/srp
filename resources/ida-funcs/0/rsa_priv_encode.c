int __usercall rsa_priv_encode@<eax>(int a1@<ebx>, pkcs8_priv_key_info_st *p8, const evp_pkey_st *pkey)
{
  char *ptr; // edx
  int v4; // eax
  asn1_object_st *v6; // eax
  unsigned __int8 *v7; // [esp-8h] [ebp-Ch]
  int v8; // [esp-4h] [ebp-8h]
  unsigned __int8 *out; // [esp+0h] [ebp-4h] BYREF

  ptr = pkey->pkey.ptr;
  out = 0;
  v4 = i2d_RSAPrivateKey((rsa_st *)ptr, &out);
  if ( v4 <= 0 )
  {
    ERR_put_error(a1, 4u, 138, 65, ".\\crypto\\rsa\\rsa_ameth.c", 135);
    return 0;
  }
  v8 = v4;
  v7 = out;
  v6 = OBJ_nid2obj(a1, 6u);
  if ( !PKCS8_pkey_set0(a1, p8, v6, 0, 5, 0, v7, v8) )
  {
    ERR_put_error(a1, 4u, 138, 65, ".\\crypto\\rsa\\rsa_ameth.c", 142);
    return 0;
  }
  return 1;
}
