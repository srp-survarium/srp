int __usercall EVP_CIPHER_get_asn1_iv@<eax>(int a1@<ebx>, evp_cipher_ctx_st *c, asn1_type_st *type)
{
  int v3; // edi
  unsigned int iv_len; // esi
  int octetstring; // eax

  v3 = 0;
  if ( type )
  {
    iv_len = c->cipher->iv_len;
    if ( iv_len > 0x10 )
      OpenSSLDie(0, iv_len, a1, ".\\crypto\\evp\\evp_lib.c", 94, "l <= sizeof(c->iv)");
    octetstring = ASN1_TYPE_get_octetstring(type, c->oiv, c->cipher->iv_len);
    v3 = octetstring;
    if ( octetstring != iv_len )
      return -1;
    if ( octetstring > 0 )
      memcpy((int)c->iv, (const __m128i *)c->oiv, iv_len);
  }
  return v3;
}
