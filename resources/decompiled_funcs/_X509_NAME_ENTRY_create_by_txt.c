X509_name_entry_st *__cdecl X509_NAME_ENTRY_create_by_txt(
        X509_name_entry_st **ne,
        char *field,
        int type,
        unsigned __int8 *bytes,
        int len)
{
  asn1_object_st *v5; // esi
  X509_name_entry_st *v7; // edi

  v5 = OBJ_txt2obj(field, 0);
  if ( v5 )
  {
    v7 = X509_NAME_ENTRY_create_by_OBJ(ne, v5, type, bytes, len);
    ASN1_OBJECT_free(v5);
    return v7;
  }
  else
  {
    ERR_put_error(0xBu, 131, 119, ".\\crypto\\x509\\x509name.c", 285);
    ERR_add_error_data(2, "name=", field);
    return 0;
  }
}
