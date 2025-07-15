char *__cdecl i2s_ASN1_OCTET_STRING(v3_ext_method *method, asn1_string_st *oct)
{
  return hex_to_string(oct->data, oct->length);
}
