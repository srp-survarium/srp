int __cdecl dh_pub_encode(X509_pubkey_st *pk, const evp_pkey_st *pkey)
{
  const dh_st *dh; // edi
  asn1_string_st *v3; // ebx
  asn1_string_st *v4; // esi
  int v5; // eax
  asn1_string_st *v7; // edi
  int v8; // ebp
  asn1_object_st *v9; // eax
  unsigned __int8 *v10; // [esp-8h] [ebp-1Ch]
  void *str; // [esp+10h] [ebp-4h] BYREF

  dh = pkey->pkey.dh;
  v3 = 0;
  str = 0;
  v4 = ASN1_STRING_new();
  v5 = i2d_DHparams(dh, &v4->data);
  v4->length = v5;
  if ( v5 > 0 )
  {
    v3 = v4;
    v7 = BN_to_ASN1_INTEGER(dh->pub_key, 0);
    if ( v7 )
    {
      v8 = i2d_ASN1_INTEGER(v7, (unsigned __int8 **)&str);
      ASN1_INTEGER_free(v7);
      if ( v8 > 0 )
      {
        v10 = (unsigned __int8 *)str;
        v9 = OBJ_nid2obj(0x1Cu);
        if ( X509_PUBKEY_set0_param(pk, v9, 16, v4, v10, v8) )
          return 1;
      }
      else
      {
        ERR_put_error(5u, 109, 65, ".\\crypto\\dh\\dh_ameth.c", 161);
      }
    }
  }
  else
  {
    ERR_put_error(5u, 109, 65, ".\\crypto\\dh\\dh_ameth.c", 145);
  }
  if ( str )
    CRYPTO_free(str);
  if ( v3 )
    ASN1_STRING_free(v3);
  return 0;
}
