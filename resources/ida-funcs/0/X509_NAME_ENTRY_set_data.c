int __cdecl X509_NAME_ENTRY_set_data(X509_name_entry_st *ne, int type, unsigned __int8 *bytes, int len)
{
  int v4; // esi
  int v5; // eax
  int result; // eax

  if ( !ne )
    return 0;
  v4 = len;
  if ( !bytes )
  {
    if ( len )
      return 0;
  }
  if ( type > 0 && (type & 0x1000) != 0 )
  {
    v5 = OBJ_obj2nid(ne->object);
    return ASN1_STRING_set_by_NID(&ne->value, bytes, len, type, v5) != 0;
  }
  if ( len < 0 )
    v4 = strlen((const char *)bytes);
  result = ASN1_STRING_set(ne->value, (char *)bytes, v4);
  if ( result )
  {
    if ( type != -1 )
    {
      if ( type == -2 )
      {
        ne->value->type = ASN1_PRINTABLE_type(bytes, v4);
        return 1;
      }
      ne->value->type = type;
    }
    return 1;
  }
  return result;
}
