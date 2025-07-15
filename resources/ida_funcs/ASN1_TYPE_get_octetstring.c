int __cdecl ASN1_TYPE_get_octetstring(asn1_type_st *a, unsigned __int8 *data, int max_len)
{
  char *ptr; // eax
  unsigned __int8 *v4; // ecx
  int v5; // esi
  unsigned int v6; // eax

  if ( a->type == 4 && a->value.boolean )
  {
    ptr = a->value.ptr;
    v4 = (unsigned __int8 *)*((_DWORD *)ptr + 2);
    v5 = *(_DWORD *)ptr;
    v6 = max_len;
    if ( v5 < max_len )
      v6 = v5;
    memcpy(data, v4, v6);
    return v5;
  }
  else
  {
    ERR_put_error(0xDu, 135, 109, ".\\crypto\\asn1\\evp_asn1.c", 83);
    return -1;
  }
}
