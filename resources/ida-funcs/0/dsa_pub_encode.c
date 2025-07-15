int __cdecl dsa_pub_encode(X509_pubkey_st *pk, const evp_pkey_st *pkey)
{
  asn1_string_st *v2; // ebx
  dsa_st *dsa; // esi
  asn1_string_st *v4; // edi
  int v5; // eax
  int v7; // edi
  int v8; // eax
  asn1_object_st *v9; // eax
  unsigned __int8 *v10; // [esp-8h] [ebp-18h]
  int v11; // [esp-4h] [ebp-14h]
  void *str; // [esp+Ch] [ebp-4h] BYREF

  v2 = 0;
  dsa = pkey->pkey.dsa;
  str = 0;
  if ( pkey->save_parameters && dsa->p && dsa->q && dsa->g )
  {
    v4 = ASN1_STRING_new(0);
    v5 = i2d_DSAparams(dsa, &v4->data);
    v4->length = v5;
    if ( v5 <= 0 )
    {
      ERR_put_error(0, 0xAu, 118, 65, ".\\crypto\\dsa\\dsa_ameth.c", 154);
      goto err_75;
    }
    v2 = v4;
    v7 = 16;
  }
  else
  {
    v7 = -1;
  }
  dsa->write_params = 0;
  v8 = i2d_DSAPublicKey(dsa, (unsigned __int8 **)&str);
  if ( v8 > 0 )
  {
    v11 = v8;
    v10 = (unsigned __int8 *)str;
    v9 = OBJ_nid2obj((int)v2, 0x74u);
    if ( X509_PUBKEY_set0_param(pk, v9, v7, v2, v10, v11) )
      return 1;
  }
  else
  {
    ERR_put_error((int)v2, 0xAu, 118, 65, ".\\crypto\\dsa\\dsa_ameth.c", 169);
  }
err_75:
  if ( str )
    CRYPTO_free(str);
  if ( v2 )
    ASN1_STRING_free(v2);
  return 0;
}
