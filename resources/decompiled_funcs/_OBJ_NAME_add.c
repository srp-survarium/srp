BOOL __usercall OBJ_NAME_add@<eax>(unsigned int a1@<edi>, const char *name, int type, const char *data)
{
  unsigned int *v5; // eax
  lhash_st *v6; // edx
  lhash_node_st *v7; // esi
  int v8; // edi
  char *v9; // eax

  if ( !names_lh )
  {
    CRYPTO_mem_ctrl(a1, 3);
    names_lh = (lhash_st_OBJ_NAME *)lh_new(
                                      (int (__cdecl *)(const char *))obj_name_LHASH_HASH,
                                      (void (__cdecl *)(unsigned __int8 *, unsigned __int8 *))obj_name_LHASH_COMP);
    CRYPTO_mem_ctrl(a1, 2);
    if ( !names_lh )
      return 0;
  }
  v5 = (unsigned int *)CRYPTO_malloc(16, ".\\crypto\\objects\\o_names.c", 195);
  if ( !v5 )
    return 0;
  v5[2] = (unsigned int)name;
  v5[1] = type & 0x8000;
  v6 = (lhash_st *)names_lh;
  *v5 = type & 0xFFFF7FFF;
  v5[3] = (unsigned int)data;
  v7 = lh_insert(v6, v5);
  if ( v7 )
  {
    if ( name_funcs_stack )
    {
      v8 = (int)v7->data;
      if ( sk_num(&name_funcs_stack->stack) > v8 )
      {
        v9 = sk_value(&name_funcs_stack->stack, v8);
        (*((void (__cdecl **)(unsigned int, void *, void *))v9 + 2))(v7->hash, v7->data, v7[1].data);
      }
    }
    CRYPTO_free(v7);
    return 1;
  }
  return !names_lh[23].dummy;
}
