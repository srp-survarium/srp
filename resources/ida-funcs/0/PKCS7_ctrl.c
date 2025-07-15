int __usercall PKCS7_ctrl@<eax>(int a1@<ebx>, pkcs7_st *p7, int cmd, int larg)
{
  void *v4; // eax
  int result; // eax
  char *ptr; // eax

  v4 = OBJ_obj2nid(p7->type);
  if ( cmd != 1 )
  {
    if ( cmd != 2 )
    {
      ERR_put_error(a1, 0x21u, 104, 110, ".\\crypto\\pkcs7\\pk7_lib.c", 109);
      return 0;
    }
    if ( v4 == (void *)22 )
    {
      ptr = p7->d.ptr;
      if ( ptr && *(_DWORD *)(*((_DWORD *)ptr + 5) + 20) )
      {
        result = 0;
        p7->detached = 0;
      }
      else
      {
        result = 1;
        p7->detached = 1;
      }
      return result;
    }
    ERR_put_error(a1, 0x21u, 104, 104, ".\\crypto\\pkcs7\\pk7_lib.c", 103);
    return 0;
  }
  if ( v4 != (void *)22 )
  {
    ERR_put_error(a1, 0x21u, 104, 104, ".\\crypto\\pkcs7\\pk7_lib.c", 88);
    return 0;
  }
  p7->detached = larg;
  if ( larg && OBJ_obj2nid(*(const asn1_object_st **)(*((_DWORD *)p7->d.ptr + 5) + 16)) == (void *)21 )
  {
    ASN1_OCTET_STRING_free(*(asn1_string_st **)(*((_DWORD *)p7->d.ptr + 5) + 20));
    *(_DWORD *)(*((_DWORD *)p7->d.ptr + 5) + 20) = 0;
  }
  return larg;
}
