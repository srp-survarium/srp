BOOL __cdecl eckey_priv_encode(pkcs8_priv_key_info_st *p8, const evp_pkey_st *pkey)
{
  char *ptr; // edi
  unsigned int DH; // esi
  int v5; // eax
  int v6; // ebp
  evp_pkey_st *v7; // ebx
  asn1_object_st *v8; // eax
  int v9; // [esp-18h] [ebp-28h]
  asn1_object_st *v10; // [esp-14h] [ebp-24h]
  asn1_object_st *v11; // [esp+8h] [ebp-8h] BYREF
  int v12; // [esp+Ch] [ebp-4h] BYREF

  ptr = pkey->pkey.ptr;
  if ( !eckey_param2type(&v11, (const env_md_st *)ptr, &v12) )
  {
    ERR_put_error((int)&v11, 0x10u, 214, 142, ".\\crypto\\ec\\ec_ameth.c", 324);
    return 0;
  }
  DH = (unsigned int)ENGINE_get_DH((const engine_st *)ptr);
  EC_KEY_set_enc_flags((ec_key_st *)ptr, DH | 1);
  v5 = i2d_ECPrivateKey((int)&v11, (ec_key_st *)ptr, 0);
  v6 = v5;
  if ( !v5 )
  {
    EC_KEY_set_enc_flags((ec_key_st *)ptr, DH);
    ERR_put_error((int)&v11, 0x10u, 214, 16, ".\\crypto\\ec\\ec_ameth.c", 339);
    return 0;
  }
  v7 = (evp_pkey_st *)CRYPTO_malloc(v5, ".\\crypto\\ec\\ec_ameth.c", 342);
  if ( !v7 )
  {
    EC_KEY_set_enc_flags((ec_key_st *)ptr, DH);
    ERR_put_error(0, 0x10u, 214, 65, ".\\crypto\\ec\\ec_ameth.c", 346);
    return 0;
  }
  pkey = v7;
  if ( !i2d_ECPrivateKey((int)v7, (ec_key_st *)ptr, (unsigned __int8 **)&pkey) )
  {
    EC_KEY_set_enc_flags((ec_key_st *)ptr, DH);
    CRYPTO_free(v7);
    ERR_put_error((int)v7, 0x10u, 214, 16, ".\\crypto\\ec\\ec_ameth.c", 354);
  }
  EC_KEY_set_enc_flags((ec_key_st *)ptr, DH);
  v10 = v11;
  v9 = v12;
  v8 = OBJ_nid2obj((int)v7, 0x198u);
  return PKCS8_pkey_set0((int)v7, p8, v8, 0, v9, (int)v10, (unsigned __int8 *)v7, v6) != 0;
}
