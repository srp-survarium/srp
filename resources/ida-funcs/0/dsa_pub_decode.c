int __usercall dsa_pub_decode@<eax>(asn1_string_st *a1@<edi>, int a2@<ebx>, evp_pkey_st *pkey, X509_pubkey_st *pubkey)
{
  int result; // eax
  dsa_st *v5; // esi
  asn1_string_st *v6; // eax
  bignum_st *v7; // eax
  X509_algor_st *v8; // [esp+0h] [ebp-18h] BYREF
  int v9; // [esp+4h] [ebp-14h] BYREF
  char *v10; // [esp+8h] [ebp-10h] BYREF
  unsigned __int8 *v11; // [esp+Ch] [ebp-Ch] BYREF
  const unsigned __int8 *v12; // [esp+10h] [ebp-8h] BYREF
  unsigned __int8 *v13; // [esp+14h] [ebp-4h] BYREF

  result = X509_PUBKEY_get0_param(0, &v13, (int *)&v12, &v8, pubkey);
  if ( !result )
    return result;
  X509_ALGOR_get0(0, &v9, &v10, v8);
  if ( v9 != 16 )
  {
    if ( v9 != 5 && v9 != -1 )
    {
      ERR_put_error(a2, 0xAu, 117, 105, ".\\crypto\\dsa\\dsa_ameth.c", 109);
      return 0;
    }
    v5 = DSA_new(a2);
    if ( !v5 )
    {
      ERR_put_error(a2, 0xAu, 117, 65, ".\\crypto\\dsa\\dsa_ameth.c", 103);
      goto LABEL_16;
    }
LABEL_10:
    v6 = d2i_ASN1_INTEGER(0, &v13, v12);
    a1 = v6;
    if ( v6 )
    {
      v7 = ASN1_INTEGER_to_BN(a2, v6, 0);
      v5->pub_key = v7;
      if ( v7 )
      {
        ASN1_INTEGER_free(a1);
        EVP_PKEY_assign(pkey, (void *)0x74, (char *)v5);
        return 1;
      }
      ERR_put_error(a2, 0xAu, 117, 108, ".\\crypto\\dsa\\dsa_ameth.c", 121);
    }
    else
    {
      ERR_put_error(a2, 0xAu, 117, 104, ".\\crypto\\dsa\\dsa_ameth.c", 115);
    }
    if ( a1 )
      ASN1_INTEGER_free(a1);
    goto LABEL_16;
  }
  v11 = (unsigned __int8 *)*((_DWORD *)v10 + 2);
  v5 = d2i_DSAparams(0, &v11, *(const unsigned __int8 ***)v10);
  if ( v5 )
    goto LABEL_10;
  ERR_put_error(a2, 0xAu, 117, 104, ".\\crypto\\dsa\\dsa_ameth.c", 94);
LABEL_16:
  if ( v5 )
    DSA_free((int)a1, a2, v5);
  return 0;
}
