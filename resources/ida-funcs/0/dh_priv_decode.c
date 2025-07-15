int __usercall dh_priv_decode@<eax>(
        asn1_string_st *a1@<edi>,
        int a2@<ebx>,
        evp_pkey_st *pkey,
        pkcs8_priv_key_info_st *p8)
{
  dh_st *v4; // esi
  int result; // eax
  bignum_st *v6; // eax
  X509_algor_st *pa; // [esp+4h] [ebp-18h] BYREF
  int v8; // [esp+8h] [ebp-14h] BYREF
  int ppklen; // [esp+Ch] [ebp-10h] BYREF
  unsigned __int8 *pk; // [esp+10h] [ebp-Ch] BYREF
  char *v11; // [esp+14h] [ebp-8h] BYREF
  unsigned __int8 *in; // [esp+18h] [ebp-4h] BYREF

  v4 = 0;
  result = PKCS8_pkey_get0(0, (const unsigned __int8 **)&pk, &ppklen, &pa, p8);
  if ( result )
  {
    X509_ALGOR_get0(0, &v8, &v11, pa);
    if ( v8 == 16
      && (a1 = d2i_ASN1_INTEGER(0, &pk, (const unsigned __int8 *)ppklen)) != 0
      && (in = (unsigned __int8 *)*((_DWORD *)v11 + 2), (v4 = d2i_DHparams(0, &in, *(const unsigned __int8 **)v11)) != 0) )
    {
      v6 = ASN1_INTEGER_to_BN(a2, a1, 0);
      v4->priv_key = v6;
      if ( v6 )
      {
        if ( DH_generate_key(v4) )
        {
          EVP_PKEY_assign(pkey, (void *)0x1C, (char *)v4);
          ASN1_INTEGER_free(a1);
          return 1;
        }
        else
        {
          DH_free((int)a1, a2, v4);
          return 0;
        }
      }
      else
      {
        ERR_put_error(a2, 5u, 110, 106, ".\\crypto\\dh\\dh_ameth.c", 216);
        DH_free((int)a1, a2, v4);
        return 0;
      }
    }
    else
    {
      ERR_put_error(a2, 5u, 110, 114, ".\\crypto\\dh\\dh_ameth.c", 230);
      DH_free((int)a1, a2, v4);
      return 0;
    }
  }
  return result;
}
