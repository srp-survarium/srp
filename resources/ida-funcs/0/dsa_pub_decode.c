int __usercall dsa_pub_decode@<eax>(asn1_string_st *a1@<edi>, evp_pkey_st *pkey, X509_pubkey_st *pubkey)
{
  int result; // eax
  dsa_st *v4; // esi
  const asn1_string_st *v5; // eax
  bignum_st *v6; // eax
  X509_algor_st *pa; // [esp+0h] [ebp-18h] BYREF
  int pptype; // [esp+4h] [ebp-14h] BYREF
  void *ppval; // [esp+8h] [ebp-10h] BYREF
  unsigned __int8 *in; // [esp+Ch] [ebp-Ch] BYREF
  int ppklen; // [esp+10h] [ebp-8h] BYREF
  unsigned __int8 *pk; // [esp+14h] [ebp-4h] BYREF

  result = X509_PUBKEY_get0_param(0, &pk, &ppklen, &pa, pubkey);
  if ( !result )
    return result;
  X509_ALGOR_get0(0, &pptype, &ppval, pa);
  if ( pptype != 16 )
  {
    if ( pptype != 5 && pptype != -1 )
    {
      ERR_put_error(0xAu, 117, 105, ".\\crypto\\dsa\\dsa_ameth.c", 109);
      return 0;
    }
    v4 = DSA_new();
    if ( !v4 )
    {
      ERR_put_error(0xAu, 117, 65, ".\\crypto\\dsa\\dsa_ameth.c", 103);
      goto LABEL_16;
    }
LABEL_10:
    v5 = d2i_ASN1_INTEGER(0, (const unsigned __int8 **)&pk, ppklen);
    a1 = (asn1_string_st *)v5;
    if ( v5 )
    {
      v6 = ASN1_INTEGER_to_BN(v5, 0);
      v4->pub_key = v6;
      if ( v6 )
      {
        ASN1_INTEGER_free(a1);
        EVP_PKEY_assign(pkey, 116, (char *)v4);
        return 1;
      }
      ERR_put_error(0xAu, 117, 108, ".\\crypto\\dsa\\dsa_ameth.c", 121);
    }
    else
    {
      ERR_put_error(0xAu, 117, 104, ".\\crypto\\dsa\\dsa_ameth.c", 115);
    }
    if ( a1 )
      ASN1_INTEGER_free(a1);
    goto LABEL_16;
  }
  in = (unsigned __int8 *)*((_DWORD *)ppval + 2);
  v4 = d2i_DSAparams(0, &in, *(unsigned __int8 **)ppval);
  if ( v4 )
    goto LABEL_10;
  ERR_put_error(0xAu, 117, 104, ".\\crypto\\dsa\\dsa_ameth.c", 94);
LABEL_16:
  if ( v4 )
    DSA_free((unsigned int)a1, v4);
  return 0;
}
