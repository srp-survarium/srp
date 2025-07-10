int __cdecl PKCS7_stream(unsigned __int8 ***boundary, pkcs7_st *p7)
{
  char *ptr; // eax

  switch ( OBJ_obj2nid(p7->type) )
  {
    case 21:
      ptr = p7->d.ptr;
      break;
    case 22:
      ptr = *(char **)(*((_DWORD *)p7->d.ptr + 5) + 20);
      break;
    case 23:
      ptr = *(char **)(*((_DWORD *)p7->d.ptr + 2) + 8);
      if ( ptr )
        goto LABEL_10;
      ptr = (char *)ASN1_STRING_type_new(4);
      *(_DWORD *)(*((_DWORD *)p7->d.ptr + 2) + 8) = ptr;
      break;
    case 24:
      ptr = *(char **)(*((_DWORD *)p7->d.ptr + 5) + 8);
      if ( ptr )
        goto LABEL_10;
      ptr = (char *)ASN1_STRING_type_new(4);
      *(_DWORD *)(*((_DWORD *)p7->d.ptr + 5) + 8) = ptr;
      break;
    default:
      return 0;
  }
  if ( !ptr )
    return 0;
LABEL_10:
  *((_DWORD *)ptr + 3) |= 0x10u;
  *boundary = (unsigned __int8 **)(ptr + 8);
  return 1;
}
