int __cdecl rc2_get_asn1_type_and_iv(x509_st *c, asn1_type_st *type)
{
  int int_octetstring; // ebp
  X509_name_st *issuer_name; // eax
  X509_name_st *v4; // edi
  int v6; // edi
  int num; // [esp+10h] [ebp-18h] BYREF
  unsigned __int8 data[16]; // [esp+14h] [ebp-14h] BYREF

  int_octetstring = 0;
  num = 0;
  if ( type )
  {
    issuer_name = X509_get_issuer_name(c);
    v4 = issuer_name;
    if ( (unsigned int)issuer_name > 0x10 )
      OpenSSLDie((unsigned int)issuer_name, (unsigned int)c, ".\\crypto\\evp\\e_rc2.c", 179, "l <= sizeof(iv)");
    int_octetstring = ASN1_TYPE_get_int_octetstring(type, &num, data, (int)issuer_name);
    if ( (X509_name_st *)int_octetstring != v4 )
      return -1;
    v6 = rc2_magic_to_meth(num);
    if ( !v6 )
      return -1;
    if ( int_octetstring > 0 )
      EVP_CipherInit_ex((evp_cipher_ctx_st *)c, 0, 0, 0, data, -1);
    EVP_CIPHER_CTX_ctrl((evp_cipher_ctx_st *)c, 3, v6, 0);
    EVP_CIPHER_CTX_set_key_length((evp_cipher_ctx_st *)c, v6 / 8);
  }
  return int_octetstring;
}
