asn1_string_st *__usercall s2i_ASN1_OCTET_STRING@<eax>(char a1@<bl>, v3_ext_method *method, v3_ext_ctx *ctx, char *str)
{
  asn1_string_st *v4; // esi
  unsigned __int8 *v6; // eax
  int len; // [esp+4h] [ebp-4h] BYREF

  v4 = ASN1_STRING_type_new(a1, 4);
  if ( v4 )
  {
    v6 = string_to_hex(a1, str, &len);
    v4->data = v6;
    if ( v6 )
    {
      v4->length = len;
      return v4;
    }
    else
    {
      ASN1_STRING_free(v4);
      return 0;
    }
  }
  else
  {
    ERR_put_error(a1, 0x22u, 112, 65, ".\\crypto\\x509v3\\v3_skey.c", 86);
    return 0;
  }
}
