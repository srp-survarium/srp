int __usercall PKCS7_stream@<eax>(int a1@<ebx>, unsigned __int8 ***boundary, pkcs7_st *p7)
{
  char *ptr; // eax

  switch ( (unsigned int)OBJ_obj2nid(p7->type) )
  {
    case 0x15u:
      ptr = p7->d.ptr;
      break;
    case 0x16u:
      ptr = *(char **)(*((_DWORD *)p7->d.ptr + 5) + 20);
      break;
    case 0x17u:
      ptr = *(char **)(*((_DWORD *)p7->d.ptr + 2) + 8);
      if ( ptr )
        goto LABEL_10;
      ptr = (char *)ASN1_STRING_type_new(a1, 4);
      *(_DWORD *)(*((_DWORD *)p7->d.ptr + 2) + 8) = ptr;
      break;
    case 0x18u:
      ptr = *(char **)(*((_DWORD *)p7->d.ptr + 5) + 8);
      if ( ptr )
        goto LABEL_10;
      ptr = (char *)ASN1_STRING_type_new(a1, 4);
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
