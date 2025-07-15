int __usercall dsa_priv_encode@<eax>(int a1@<ebx>, pkcs8_priv_key_info_st *p8, const evp_pkey_st *pkey)
{
  asn1_string_st *v3; // edi
  asn1_string_st *v4; // esi
  int v5; // eax
  asn1_string_st *v6; // eax
  int v7; // ebx
  asn1_object_st *v8; // eax
  unsigned __int8 *v10; // [esp-8h] [ebp-18h]
  unsigned __int8 *out; // [esp+Ch] [ebp-4h] BYREF

  v3 = 0;
  out = 0;
  v4 = ASN1_STRING_new(a1);
  if ( v4 )
  {
    v5 = i2d_DSAparams(pkey->pkey.dsa, &v4->data);
    v4->length = v5;
    if ( v5 > 0 )
    {
      v4->type = 16;
      v6 = BN_to_ASN1_INTEGER(*((const bignum_st **)pkey->pkey.ptr + 7), 0);
      v3 = v6;
      if ( v6 )
      {
        v7 = i2d_ASN1_INTEGER(v6, &out);
        ASN1_INTEGER_free(v3);
        v10 = out;
        v8 = OBJ_nid2obj(v7, 0x74u);
        if ( PKCS8_pkey_set0(v7, p8, v8, 0, 16, (int)v4, v10, v7) )
          return 1;
      }
      else
      {
        ERR_put_error((int)pkey, 0xAu, 116, 109, ".\\crypto\\dsa\\dsa_ameth.c", 331);
      }
    }
    else
    {
      ERR_put_error((int)pkey, 0xAu, 116, 65, ".\\crypto\\dsa\\dsa_ameth.c", 321);
    }
  }
  else
  {
    ERR_put_error(a1, 0xAu, 116, 65, ".\\crypto\\dsa\\dsa_ameth.c", 314);
  }
  if ( out )
    CRYPTO_free(out);
  if ( v4 )
    ASN1_STRING_free(v4);
  if ( v3 )
    ASN1_INTEGER_free(v3);
  return 0;
}
