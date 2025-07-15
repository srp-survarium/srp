int __cdecl OBJ_NAME_remove(const char *name, int type)
{
  int result; // eax
  int *v3; // esi
  int v4; // edi
  char *v5; // eax
  _DWORD data[4]; // [esp+0h] [ebp-10h] BYREF

  result = (int)names_lh;
  if ( names_lh )
  {
    data[2] = name;
    data[0] = type & 0xFFFF7FFF;
    v3 = (int *)lh_delete((lhash_st *)names_lh, data);
    if ( v3 )
    {
      if ( name_funcs_stack )
      {
        v4 = *v3;
        if ( sk_num(&name_funcs_stack->stack) > v4 )
        {
          v5 = sk_value(&name_funcs_stack->stack, v4);
          (*((void (__cdecl **)(int, int, int))v5 + 2))(v3[2], *v3, v3[3]);
        }
      }
      CRYPTO_free(v3);
      return 1;
    }
    else
    {
      return 0;
    }
  }
  return result;
}
