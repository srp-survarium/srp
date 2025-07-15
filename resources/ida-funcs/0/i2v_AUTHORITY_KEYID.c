stack_st_CONF_VALUE *__usercall i2v_AUTHORITY_KEYID@<eax>(
        stack_st_CONF_VALUE **a1@<ebx>,
        v3_ext_method *method,
        AUTHORITY_KEYID_st *akeyid,
        stack_st_CONF_VALUE *extlist)
{
  char *v4; // esi
  stack_st_GENERAL_NAME *issuer; // eax
  asn1_string_st *serial; // eax
  char *v7; // esi

  if ( akeyid->keyid )
  {
    v4 = hex_to_string(akeyid->keyid->data, akeyid->keyid->length);
    X509V3_add_value(a1, "keyid", v4, &extlist);
    CRYPTO_free(v4);
  }
  issuer = akeyid->issuer;
  if ( issuer )
    extlist = i2v_GENERAL_NAMES(0, issuer, extlist);
  serial = akeyid->serial;
  if ( serial )
  {
    v7 = hex_to_string(serial->data, serial->length);
    X509V3_add_value(a1, "serial", v7, &extlist);
    CRYPTO_free(v7);
  }
  return extlist;
}
