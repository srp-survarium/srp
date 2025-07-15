int __usercall dh_pub_decode@<eax>(asn1_string_st *a1@<edi>, int a2@<ebx>, evp_pkey_st *pkey, X509_pubkey_st *pubkey)
{
  int result; // eax
  dh_st *v5; // esi
  asn1_string_st *v6; // eax
  bignum_st *v7; // eax
  X509_algor_st *v8; // [esp+0h] [ebp-18h] BYREF
  int v9; // [esp+4h] [ebp-14h] BYREF
  char *v10; // [esp+8h] [ebp-10h] BYREF
  unsigned __int8 *in; // [esp+Ch] [ebp-Ch] BYREF
  const unsigned __int8 *v12; // [esp+10h] [ebp-8h] BYREF
  unsigned __int8 *v13; // [esp+14h] [ebp-4h] BYREF

  result = X509_PUBKEY_get0_param(0, &v13, (int *)&v12, &v8, pubkey);
  if ( result )
  {
    X509_ALGOR_get0(0, &v9, &v10, v8);
    if ( v9 != 16 )
    {
      ERR_put_error(a2, 5u, 108, 105, ".\\crypto\\dh\\dh_ameth.c", 89);
      return 0;
    }
    in = (unsigned __int8 *)*((_DWORD *)v10 + 2);
    v5 = d2i_DHparams(0, &in, *(const unsigned __int8 **)v10);
    if ( v5 )
    {
      v6 = d2i_ASN1_INTEGER(0, &v13, v12);
      a1 = v6;
      if ( v6 )
      {
        v7 = ASN1_INTEGER_to_BN(a2, v6, 0);
        v5->pub_key = v7;
        if ( v7 )
        {
          ASN1_INTEGER_free(a1);
          EVP_PKEY_assign(pkey, (void *)0x1C, (char *)v5);
          return 1;
        }
        ERR_put_error(a2, 5u, 108, 109, ".\\crypto\\dh\\dh_ameth.c", 112);
      }
      else
      {
        ERR_put_error(a2, 5u, 108, 104, ".\\crypto\\dh\\dh_ameth.c", 105);
      }
      if ( a1 )
        ASN1_INTEGER_free(a1);
    }
    else
    {
      ERR_put_error(a2, 5u, 108, 104, ".\\crypto\\dh\\dh_ameth.c", 99);
    }
    if ( v5 )
      DH_free((int)a1, a2, v5);
    return 0;
  }
  return result;
}
