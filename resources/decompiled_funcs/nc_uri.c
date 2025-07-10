void __usercall nc_uri(unsigned int a1@<ebx>, asn1_string_st *uri, asn1_string_st *base)
{
  unsigned __int8 *data; // edi
  _BYTE *v4; // eax
  char *v5; // esi
  int v6; // eax
  signed int v7; // eax

  data = base->data;
  strchr((char *)uri->data, 0x3Au);
  if ( v4 && v4[1] == 47 && v4[2] == 47 )
  {
    v5 = v4 + 3;
    strchr(v4 + 3, 0x3Au);
    if ( v6 || (strchr(v5, 0x2Fu), v6) )
      v7 = v6 - (_DWORD)v5;
    else
      v7 = strlen(v5);
    if ( v7 )
    {
      if ( *data == 46 )
      {
        if ( v7 > base->length )
          _strnicmp(a1, (const char *)data, &v5[v7 - base->length], (char *)data, base->length);
      }
      else if ( base->length == v7 )
      {
        _strnicmp(a1, (const char *)data, v5, (char *)data, v7);
      }
    }
  }
}
