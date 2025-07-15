asn1_string_st *__usercall s2i_ASN1_INTEGER@<eax>(int a1@<ebx>, v3_ext_method *method, char *value)
{
  char *v3; // esi
  bignum_st *v5; // eax
  bool v6; // zf
  int v7; // edi
  char v8; // al
  int v9; // eax
  asn1_string_st *v10; // esi
  bignum_st *bn; // [esp+4h] [ebp-4h] BYREF

  v3 = value;
  bn = 0;
  if ( value )
  {
    v5 = BN_new(a1);
    v6 = *value == 45;
    bn = v5;
    if ( v6 )
    {
      v3 = value + 1;
      v7 = 1;
    }
    else
    {
      v7 = 0;
    }
    if ( *v3 == 48 && ((v8 = v3[1], v8 == 120) || v8 == 88) )
    {
      v3 += 2;
      v9 = BN_hex2bn(&bn, v3);
    }
    else
    {
      v9 = BN_dec2bn(&bn, v3);
    }
    if ( !v9 || v3[v9] )
    {
      BN_free(bn);
      ERR_put_error(a1, 0x22u, 108, 100, ".\\crypto\\x509v3\\v3_utl.c", 185);
      return 0;
    }
    else
    {
      if ( v7 && !bn->top )
        v7 = 0;
      v10 = BN_to_ASN1_INTEGER(bn, 0);
      BN_free(bn);
      if ( v10 )
      {
        if ( v7 )
          v10->type |= 0x100u;
        return v10;
      }
      else
      {
        ERR_put_error(a1, 0x22u, 108, 101, ".\\crypto\\x509v3\\v3_utl.c", 194);
        return 0;
      }
    }
  }
  else
  {
    ERR_put_error(a1, 0x22u, 108, 109, ".\\crypto\\x509v3\\v3_utl.c", 166);
    return 0;
  }
}
