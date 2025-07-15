BOOL __usercall OBJ_NAME_add@<eax>(int a1@<edi>, int a2@<ebx>, const char *name, int type, char *data)
{
  lhash_node_st *v6; // eax
  lhash_st *v7; // edx
  lhash_node_st *v8; // esi
  int v9; // edi
  char *v10; // eax

  if ( !names_lh )
  {
    CRYPTO_mem_ctrl(a1, a2, 3);
    names_lh = (lhash_st_OBJ_NAME *)lh_new(
                                      (unsigned int (__cdecl *)(const char *))obj_name_LHASH_HASH,
                                      (void (__cdecl *)(unsigned __int8 *, unsigned __int8 *))obj_name_LHASH_COMP);
    CRYPTO_mem_ctrl(a1, a2, 2);
    if ( !names_lh )
      return 0;
  }
  v6 = (lhash_node_st *)CRYPTO_malloc(16, ".\\crypto\\objects\\o_names.c", 195);
  if ( !v6 )
    return 0;
  v6->hash = (unsigned int)name;
  v6->next = (lhash_node_st *)(type & 0x8000);
  v7 = (lhash_st *)names_lh;
  v6->data = (void *)(type & 0xFFFF7FFF);
  v6[1].data = data;
  v8 = lh_insert(v7, v6);
  if ( v8 )
  {
    if ( name_funcs_stack )
    {
      v9 = (int)v8->data;
      if ( sk_num(&name_funcs_stack->stack) > v9 )
      {
        v10 = sk_value(&name_funcs_stack->stack, v9);
        (*((void (__cdecl **)(unsigned int, void *, void *))v10 + 2))(v8->hash, v8->data, v8[1].data);
      }
    }
    CRYPTO_free(v8);
    return 1;
  }
  return !names_lh[23].dummy;
}
