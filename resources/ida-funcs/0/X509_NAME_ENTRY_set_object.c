BOOL __usercall X509_NAME_ENTRY_set_object@<eax>(int a1@<ebx>, X509_name_entry_st *ne, asn1_object_st *obj)
{
  asn1_object_st *v3; // eax

  if ( ne && obj )
  {
    ASN1_OBJECT_free(ne->object);
    v3 = OBJ_dup(a1, obj);
    ne->object = v3;
    return v3 != 0;
  }
  else
  {
    ERR_put_error(a1, 0xBu, 115, 67, ".\\crypto\\x509\\x509name.c", 341);
    return 0;
  }
}
