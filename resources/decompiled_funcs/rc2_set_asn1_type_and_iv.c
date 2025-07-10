int __cdecl rc2_set_asn1_type_and_iv(evp_cipher_ctx_st *c, asn1_type_st *type)
{
  int result; // eax
  int v3; // edi
  X509_name_st *issuer_name; // eax

  result = 0;
  if ( type )
  {
    v3 = rc2_meth_to_magic(c);
    issuer_name = X509_get_issuer_name((x509_st *)c);
    return ASN1_TYPE_set_int_octetstring(type, v3, c->oiv, (int)issuer_name);
  }
  return result;
}
