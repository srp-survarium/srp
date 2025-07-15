int __usercall obj_name_cmp@<eax>(const void *a_void@<esi>, const void *b_void@<ebx>)
{
  int result; // eax
  int v3; // edi
  char *v4; // eax

  result = *(_DWORD *)a_void - *(_DWORD *)b_void;
  if ( *(_DWORD *)a_void == *(_DWORD *)b_void )
  {
    if ( name_funcs_stack && (v3 = *(_DWORD *)a_void, sk_num(&name_funcs_stack->stack) > v3) )
    {
      v4 = sk_value(&name_funcs_stack->stack, v3);
      return (*((int (__cdecl **)(_DWORD, _DWORD))v4 + 1))(*((_DWORD *)a_void + 2), *((_DWORD *)b_void + 2));
    }
    else
    {
      return strcmp(*((const char **)a_void + 2), *((const char **)b_void + 2));
    }
  }
  return result;
}
