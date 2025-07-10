int __usercall dh_priv_decode@<eax>(asn1_string_st *a1@<edi>, evp_pkey_st *pkey, pkcs8_priv_key_info_st *p8)
{
  dh_st *v3; // esi
  int result; // eax
  bignum_st *v5; // eax
  X509_algor_st *pa; // [esp+4h] [ebp-18h] BYREF
  int pptype; // [esp+8h] [ebp-14h] BYREF
  int ppklen; // [esp+Ch] [ebp-10h] BYREF
  unsigned __int8 *pk; // [esp+10h] [ebp-Ch] BYREF
  void *ppval; // [esp+14h] [ebp-8h] BYREF
  unsigned __int8 *in; // [esp+18h] [ebp-4h] BYREF

  v3 = 0;
  result = PKCS8_pkey_get0(0, (const unsigned __int8 **)&pk, &ppklen, &pa, p8);
  if ( result )
  {
    X509_ALGOR_get0(0, &pptype, &ppval, pa);
    if ( pptype == 16
      && (a1 = d2i_ASN1_INTEGER(0, (const unsigned __int8 **)&pk, ppklen)) != 0
      && (in = (unsigned __int8 *)*((_DWORD *)ppval + 2),
          (v3 = d2i_DHparams(0, (const unsigned __int8 **)&in, *(_DWORD *)ppval)) != 0) )
    {
      v5 = ASN1_INTEGER_to_BN(a1, 0);
      v3->priv_key = v5;
      if ( v5 )
      {
        if ( DH_generate_key(v3) )
        {
          EVP_PKEY_assign(pkey, 28, (char *)v3);
          ASN1_INTEGER_free(a1);
          return 1;
        }
        else
        {
          DH_free((unsigned int)a1, v3);
          return 0;
        }
      }
      else
      {
        ERR_put_error(5u, 110, 106, ".\\crypto\\dh\\dh_ameth.c", 216);
        DH_free((unsigned int)a1, v3);
        return 0;
      }
    }
    else
    {
      ERR_put_error(5u, 110, 114, ".\\crypto\\dh\\dh_ameth.c", 230);
      DH_free((unsigned int)a1, v3);
      return 0;
    }
  }
  return result;
}
