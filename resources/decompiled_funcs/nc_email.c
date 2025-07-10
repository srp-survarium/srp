int __cdecl nc_email(asn1_string_st *eml, asn1_string_st *base)
{
  unsigned __int8 *data; // esi
  unsigned __int8 *v3; // edi
  unsigned __int8 *v4; // eax
  unsigned __int8 *v5; // ebp
  int v6; // eax
  int v7; // ebx
  int result; // eax
  unsigned int v9; // eax

  data = base->data;
  v3 = eml->data;
  strchr((char *)data, 0x40u);
  v5 = v4;
  strchr((char *)v3, 0x40u);
  v7 = v6;
  if ( !v6 )
    return 53;
  if ( v5 )
  {
    if ( v5 != data )
    {
      v9 = v6 - (_DWORD)v3;
      if ( v5 - data != v9 || strncmp((const char *)data, (const char *)v3, v9) )
        return 47;
    }
    data = v5 + 1;
    return _stricmp((const char *)data, (const char *)(v7 + 1)) != 0 ? 0x2F : 0;
  }
  if ( *data != 46 )
    return _stricmp((const char *)data, (const char *)(v7 + 1)) != 0 ? 0x2F : 0;
  if ( eml->length <= base->length )
    return 47;
  result = _stricmp((const char *)data, (const char *)&v3[eml->length - base->length]);
  if ( result )
    return 47;
  return result;
}
