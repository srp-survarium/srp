asn1_string_st *__cdecl s2i_ASN1_INTEGER(v3_ext_method *method, char *value)
{
  char *v2; // esi
  bignum_st *v4; // eax
  bool v5; // zf
  int v6; // edi
  char v7; // al
  int v8; // eax
  asn1_string_st *v9; // esi
  bignum_st *bn; // [esp+4h] [ebp-4h] BYREF

  v2 = value;
  bn = 0;
  if ( value )
  {
    v4 = BN_new();
    v5 = *value == 45;
    bn = v4;
    if ( v5 )
    {
      v2 = value + 1;
      v6 = 1;
    }
    else
    {
      v6 = 0;
    }
    if ( *v2 == 48 && ((v7 = v2[1], v7 == 120) || v7 == 88) )
    {
      v2 += 2;
      v8 = BN_hex2bn(&bn, v2);
    }
    else
    {
      v8 = BN_dec2bn(&bn, v2);
    }
    if ( !v8 || v2[v8] )
    {
      BN_free(bn);
      ERR_put_error(0x22u, 108, 100, ".\\crypto\\x509v3\\v3_utl.c", 185);
      return 0;
    }
    else
    {
      if ( v6 && !bn->top )
        v6 = 0;
      v9 = BN_to_ASN1_INTEGER(bn, 0);
      BN_free(bn);
      if ( v9 )
      {
        if ( v6 )
          v9->type |= 0x100u;
        return v9;
      }
      else
      {
        ERR_put_error(0x22u, 108, 101, ".\\crypto\\x509v3\\v3_utl.c", 194);
        return 0;
      }
    }
  }
  else
  {
    ERR_put_error(0x22u, 108, 109, ".\\crypto\\x509v3\\v3_utl.c", 166);
    return 0;
  }
}
