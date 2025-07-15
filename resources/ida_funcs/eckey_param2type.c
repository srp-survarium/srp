int __usercall eckey_param2type@<eax>(asn1_object_st **ppval@<ebx>, const env_md_st *ec_key@<edi>, int *pptype)
{
  const ssl_st *v3; // eax
  const ssl_st *v4; // esi
  unsigned int shutdown; // eax
  asn1_string_st *v7; // esi
  int v8; // eax

  if ( !ec_key || (v3 = (const ssl_st *)EVP_CIPHER_block_size(ec_key), (v4 = v3) == 0) )
  {
    ERR_put_error(0x10u, 223, 124, ".\\crypto\\ec\\ec_ameth.c", 74);
    return 0;
  }
  if ( SSL_state(v3) )
  {
    shutdown = SSL_get_shutdown(v4);
    if ( shutdown )
    {
      *ppval = OBJ_nid2obj(shutdown);
      *pptype = 6;
      return 1;
    }
  }
  v7 = ASN1_STRING_new();
  if ( !v7 )
    return 0;
  v8 = i2d_ECParameters((ec_key_st *)ec_key, &v7->data);
  v7->length = v8;
  if ( v8 >= 0 )
  {
    *ppval = (asn1_object_st *)v7;
    *pptype = 16;
    return 1;
  }
  else
  {
    ASN1_STRING_free(v7);
    ERR_put_error(0x10u, 223, 16, ".\\crypto\\ec\\ec_ameth.c", 94);
    return 0;
  }
}
