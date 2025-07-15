int __cdecl EVP_CIPHER_set_asn1_iv(evp_cipher_ctx_st *c, asn1_type_st *type)
{
  int result; // eax
  unsigned int iv_len; // esi

  result = 0;
  if ( type )
  {
    iv_len = c->cipher->iv_len;
    if ( iv_len > 0x10 )
      OpenSSLDie((unsigned int)c, iv_len, ".\\crypto\\evp\\evp_lib.c", 112, "j <= sizeof(c->iv)");
    return ASN1_TYPE_set_octetstring(type, c->oiv, c->cipher->iv_len);
  }
  return result;
}
