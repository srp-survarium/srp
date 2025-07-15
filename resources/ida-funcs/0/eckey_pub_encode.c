int __cdecl eckey_pub_encode(X509_pubkey_st *pk, asn1_object_st *pkey)
{
  ec_key_st *flags; // edi
  unsigned __int8 *v3; // esi
  int v5; // eax
  asn1_object_st *v6; // ebx
  int v7; // ebp
  unsigned __int8 *v8; // eax
  int v9; // eax
  asn1_object_st *v10; // eax
  int v11; // [esp-8h] [ebp-1Ch]
  int ptype; // [esp+Ch] [ebp-8h] BYREF
  unsigned __int8 *v13; // [esp+10h] [ebp-4h] BYREF

  flags = (ec_key_st *)pkey->flags;
  v3 = 0;
  pkey = 0;
  if ( eckey_param2type(&pkey, (const env_md_st *)flags, &ptype) )
  {
    v5 = i2o_ECPublicKey((int)&pkey, flags, 0);
    v6 = pkey;
    v7 = ptype;
    if ( v5 > 0
      && (v8 = (unsigned __int8 *)CRYPTO_malloc(v5, ".\\crypto\\ec\\ec_ameth.c", 119), (v3 = v8) != 0)
      && (v13 = v8, v9 = i2o_ECPublicKey((int)v6, flags, &v13), v9 > 0)
      && (v11 = v9, v10 = OBJ_nid2obj((int)v6, 0x198u), X509_PUBKEY_set0_param(pk, v10, v7, v6, v3, v11)) )
    {
      return 1;
    }
    else
    {
      if ( v7 == 6 )
        ASN1_OBJECT_free(v6);
      else
        ASN1_STRING_free((asn1_string_st *)v6);
      if ( v3 )
        CRYPTO_free(v3);
      return 0;
    }
  }
  else
  {
    ERR_put_error((int)&pkey, 0x10u, 216, 16, ".\\crypto\\ec\\ec_ameth.c", 113);
    return 0;
  }
}
