int __cdecl dh_priv_encode(pkcs8_priv_key_info_st *p8, const evp_pkey_st *pkey)
{
  asn1_string_st *v2; // edi
  asn1_string_st *v3; // esi
  int v4; // eax
  asn1_string_st *v5; // eax
  int v6; // ebx
  asn1_object_st *v7; // eax
  unsigned __int8 *v9; // [esp-8h] [ebp-18h]
  unsigned __int8 *out; // [esp+Ch] [ebp-4h] BYREF

  v2 = 0;
  out = 0;
  v3 = ASN1_STRING_new();
  if ( v3 )
  {
    v4 = i2d_DHparams(pkey->pkey.dh, &v3->data);
    v3->length = v4;
    if ( v4 > 0 )
    {
      v3->type = 16;
      v5 = BN_to_ASN1_INTEGER(*((const bignum_st **)pkey->pkey.ptr + 6), 0);
      v2 = v5;
      if ( v5 )
      {
        v6 = i2d_ASN1_INTEGER(v5, &out);
        ASN1_INTEGER_free(v2);
        v9 = out;
        v7 = OBJ_nid2obj(0x1Cu);
        if ( PKCS8_pkey_set0(p8, v7, 0, 16, v3, v9, v6) )
          return 1;
      }
      else
      {
        ERR_put_error(5u, 111, 106, ".\\crypto\\dh\\dh_ameth.c", 264);
      }
    }
    else
    {
      ERR_put_error(5u, 111, 65, ".\\crypto\\dh\\dh_ameth.c", 254);
    }
  }
  else
  {
    ERR_put_error(5u, 111, 65, ".\\crypto\\dh\\dh_ameth.c", 247);
  }
  if ( out )
    CRYPTO_free(out);
  if ( v3 )
    ASN1_STRING_free(v3);
  if ( v2 )
    ASN1_INTEGER_free(v2);
  return 0;
}
