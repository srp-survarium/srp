asn1_string_st *__cdecl s2i_ASN1_OCTET_STRING(v3_ext_method *method, v3_ext_ctx *ctx, char *str)
{
  asn1_string_st *v3; // esi
  unsigned __int8 *v5; // eax
  int len; // [esp+4h] [ebp-4h] BYREF

  v3 = ASN1_STRING_type_new(4);
  if ( v3 )
  {
    v5 = string_to_hex(str, &len);
    v3->data = v5;
    if ( v5 )
    {
      v3->length = len;
      return v3;
    }
    else
    {
      ASN1_STRING_free(v3);
      return 0;
    }
  }
  else
  {
    ERR_put_error(0x22u, 112, 65, ".\\crypto\\x509v3\\v3_skey.c", 86);
    return 0;
  }
}
