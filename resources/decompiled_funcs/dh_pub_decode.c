int __usercall dh_pub_decode@<eax>(asn1_string_st *a1@<edi>, evp_pkey_st *pkey, X509_pubkey_st *pubkey)
{
  int result; // eax
  dh_st *v4; // esi
  const asn1_string_st *v5; // eax
  bignum_st *v6; // eax
  X509_algor_st *pa; // [esp+0h] [ebp-18h] BYREF
  int pptype; // [esp+4h] [ebp-14h] BYREF
  void *ppval; // [esp+8h] [ebp-10h] BYREF
  unsigned __int8 *in; // [esp+Ch] [ebp-Ch] BYREF
  int ppklen; // [esp+10h] [ebp-8h] BYREF
  unsigned __int8 *pk; // [esp+14h] [ebp-4h] BYREF

  result = X509_PUBKEY_get0_param(0, &pk, &ppklen, &pa, pubkey);
  if ( result )
  {
    X509_ALGOR_get0(0, &pptype, &ppval, pa);
    if ( pptype != 16 )
    {
      ERR_put_error(5u, 108, 105, ".\\crypto\\dh\\dh_ameth.c", 89);
      return 0;
    }
    in = (unsigned __int8 *)*((_DWORD *)ppval + 2);
    v4 = d2i_DHparams(0, (const unsigned __int8 **)&in, *(_DWORD *)ppval);
    if ( v4 )
    {
      v5 = d2i_ASN1_INTEGER(0, (const unsigned __int8 **)&pk, ppklen);
      a1 = (asn1_string_st *)v5;
      if ( v5 )
      {
        v6 = ASN1_INTEGER_to_BN(v5, 0);
        v4->pub_key = v6;
        if ( v6 )
        {
          ASN1_INTEGER_free(a1);
          EVP_PKEY_assign(pkey, 28, (char *)v4);
          return 1;
        }
        ERR_put_error(5u, 108, 109, ".\\crypto\\dh\\dh_ameth.c", 112);
      }
      else
      {
        ERR_put_error(5u, 108, 104, ".\\crypto\\dh\\dh_ameth.c", 105);
      }
      if ( a1 )
        ASN1_INTEGER_free(a1);
    }
    else
    {
      ERR_put_error(5u, 108, 104, ".\\crypto\\dh\\dh_ameth.c", 99);
    }
    if ( v4 )
      DH_free((unsigned int)a1, v4);
    return 0;
  }
  return result;
}
