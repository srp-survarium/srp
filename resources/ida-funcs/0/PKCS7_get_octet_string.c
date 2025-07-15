asn1_string_st *__usercall PKCS7_get_octet_string@<eax>(pkcs7_st *p7@<esi>)
{
  char *ptr; // eax

  if ( OBJ_obj2nid(p7->type) == (void *)21 )
    return p7->d.data;
  if ( (char *)OBJ_obj2nid(p7->type) - 21 > (char *)5 )
  {
    ptr = p7->d.ptr;
    if ( ptr )
    {
      if ( *(_DWORD *)ptr == 4 )
        return (asn1_string_st *)*((_DWORD *)ptr + 1);
    }
  }
  return 0;
}
