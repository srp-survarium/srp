int __usercall ASN1_TYPE_get_octetstring@<eax>(int a1@<ebx>, asn1_type_st *a, unsigned __int8 *data, int max_len)
{
  char *ptr; // eax
  const __m128i *v5; // ecx
  int v6; // esi
  unsigned int v7; // eax

  if ( a->type == 4 && a->value.boolean )
  {
    ptr = a->value.ptr;
    v5 = (const __m128i *)*((_DWORD *)ptr + 2);
    v6 = *(_DWORD *)ptr;
    v7 = max_len;
    if ( v6 < max_len )
      v7 = v6;
    memcpy((int)data, v5, v7);
    return v6;
  }
  else
  {
    ERR_put_error(a1, 0xDu, 135, 109, ".\\crypto\\asn1\\evp_asn1.c", 83);
    return -1;
  }
}
