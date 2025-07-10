int __cdecl EVP_CIPHER_get_asn1_iv(evp_cipher_ctx_st *c, asn1_type_st *type)
{
  int v2; // edi
  unsigned int iv_len; // esi
  int octetstring; // eax

  v2 = 0;
  if ( type )
  {
    iv_len = c->cipher->iv_len;
    if ( iv_len > 0x10 )
      OpenSSLDie(0, iv_len, ".\\crypto\\evp\\evp_lib.c", 94, "l <= sizeof(c->iv)");
    octetstring = ASN1_TYPE_get_octetstring(type, c->oiv, c->cipher->iv_len);
    v2 = octetstring;
    if ( octetstring != iv_len )
      return -1;
    if ( octetstring > 0 )
      memcpy(c->iv, c->oiv, iv_len);
  }
  return v2;
}
