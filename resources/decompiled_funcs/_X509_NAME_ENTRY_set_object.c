BOOL __cdecl X509_NAME_ENTRY_set_object(X509_name_entry_st *ne, asn1_object_st *obj)
{
  asn1_object_st *v2; // eax

  if ( ne && obj )
  {
    ASN1_OBJECT_free(ne->object);
    v2 = OBJ_dup(obj);
    ne->object = v2;
    return v2 != 0;
  }
  else
  {
    ERR_put_error(0xBu, 115, 67, ".\\crypto\\x509\\x509name.c", 341);
    return 0;
  }
}
