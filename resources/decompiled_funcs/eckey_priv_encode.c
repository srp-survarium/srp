BOOL __cdecl eckey_priv_encode(pkcs8_priv_key_info_st *p8, const evp_pkey_st *pkey)
{
  char *ptr; // edi
  unsigned int DH; // esi
  int v5; // eax
  int v6; // ebp
  evp_pkey_st *v7; // ebx
  asn1_object_st *v8; // eax
  int v9; // [esp-18h] [ebp-28h]
  void *v10; // [esp-14h] [ebp-24h]
  void *ppval; // [esp+8h] [ebp-8h] BYREF
  int pptype; // [esp+Ch] [ebp-4h] BYREF

  ptr = pkey->pkey.ptr;
  if ( !eckey_param2type((asn1_object_st **)&ppval, (const env_md_st *)ptr, &pptype) )
  {
    ERR_put_error(0x10u, 214, 142, ".\\crypto\\ec\\ec_ameth.c", 324);
    return 0;
  }
  DH = (unsigned int)ENGINE_get_DH((const engine_st *)ptr);
  EC_KEY_set_enc_flags((ec_key_st *)ptr, DH | 1);
  v5 = i2d_ECPrivateKey((ec_key_st *)ptr, 0);
  v6 = v5;
  if ( !v5 )
  {
    EC_KEY_set_enc_flags((ec_key_st *)ptr, DH);
    ERR_put_error(0x10u, 214, 16, ".\\crypto\\ec\\ec_ameth.c", 339);
    return 0;
  }
  v7 = (evp_pkey_st *)CRYPTO_malloc(v5, ".\\crypto\\ec\\ec_ameth.c", 342);
  if ( !v7 )
  {
    EC_KEY_set_enc_flags((ec_key_st *)ptr, DH);
    ERR_put_error(0x10u, 214, 65, ".\\crypto\\ec\\ec_ameth.c", 346);
    return 0;
  }
  pkey = v7;
  if ( !i2d_ECPrivateKey((ec_key_st *)ptr, (unsigned __int8 **)&pkey) )
  {
    EC_KEY_set_enc_flags((ec_key_st *)ptr, DH);
    CRYPTO_free(v7);
    ERR_put_error(0x10u, 214, 16, ".\\crypto\\ec\\ec_ameth.c", 354);
  }
  EC_KEY_set_enc_flags((ec_key_st *)ptr, DH);
  v10 = ppval;
  v9 = pptype;
  v8 = OBJ_nid2obj(0x198u);
  return PKCS8_pkey_set0(p8, v8, 0, v9, v10, (unsigned __int8 *)v7, v6) != 0;
}
