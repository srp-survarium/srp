int __usercall nc_dns@<eax>(int *a1@<ecx>, int a2@<ebx>, int a3@<edi>, asn1_string_st *dns)
{
  unsigned __int8 *data; // edx
  char *v5; // esi
  int v7; // ecx

  data = dns->data;
  v5 = (char *)a1[2];
  if ( !*v5 )
    return 0;
  v7 = *a1;
  if ( dns->length <= v7 )
    return _stricmp(a2, a3, v5, (char *)data) != 0 ? 0x2F : 0;
  data += dns->length - v7;
  if ( *(data - 1) == 46 )
    return _stricmp(a2, a3, v5, (char *)data) != 0 ? 0x2F : 0;
  else
    return 47;
}
