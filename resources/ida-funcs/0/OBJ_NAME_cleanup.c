void __cdecl OBJ_NAME_cleanup(int type)
{
  int dummy; // edi
  lhash_st *v2; // [esp-10h] [ebp-10h]

  if ( names_lh )
  {
    dummy = names_lh[8].dummy;
    v2 = (lhash_st *)names_lh;
    free_type = type;
    names_lh[8].dummy = 0;
    lh_doall(v2, (void (__cdecl *)(void *))names_lh_free_LHASH_DOALL);
    if ( type >= 0 )
    {
      names_lh[8].dummy = dummy;
    }
    else
    {
      lh_free((lhash_st *)names_lh);
      sk_pop_free(&name_funcs_stack->stack, (void (__cdecl *)(void *))policy_node_free);
      names_lh = 0;
      name_funcs_stack = 0;
    }
  }
}
