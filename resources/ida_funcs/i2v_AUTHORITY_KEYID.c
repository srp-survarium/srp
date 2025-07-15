stack_st_CONF_VALUE *__cdecl i2v_AUTHORITY_KEYID(
        v3_ext_method *method,
        AUTHORITY_KEYID_st *akeyid,
        stack_st_CONF_VALUE *extlist)
{
  char *v3; // esi
  stack_st_GENERAL_NAME *issuer; // eax
  asn1_string_st *serial; // eax
  char *v6; // esi

  if ( akeyid->keyid )
  {
    v3 = hex_to_string(akeyid->keyid->data, akeyid->keyid->length);
    X509V3_add_value("keyid", v3, &extlist);
    CRYPTO_free(v3);
  }
  issuer = akeyid->issuer;
  if ( issuer )
    extlist = i2v_GENERAL_NAMES(0, issuer, extlist);
  serial = akeyid->serial;
  if ( serial )
  {
    v6 = hex_to_string(serial->data, serial->length);
    X509V3_add_value("serial", v6, &extlist);
    CRYPTO_free(v6);
  }
  return extlist;
}
