X509_name_entry_st *__usercall X509_NAME_ENTRY_create_by_txt@<eax>(
        int a1@<ebx>,
        X509_name_entry_st **ne,
        char *field,
        int type,
        __m128i *bytes,
        int len)
{
  asn1_object_st *v6; // esi
  X509_name_entry_st *v8; // edi

  v6 = OBJ_txt2obj(a1, field, 0);
  if ( v6 )
  {
    v8 = X509_NAME_ENTRY_create_by_OBJ(a1, ne, v6, type, bytes, len);
    ASN1_OBJECT_free(v6);
    return v8;
  }
  else
  {
    ERR_put_error(a1, 0xBu, 131, 119, ".\\crypto\\x509\\x509name.c", 285);
    ERR_add_error_data(2, "name=", field);
    return 0;
  }
}
