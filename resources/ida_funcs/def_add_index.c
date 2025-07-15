int __usercall def_add_index@<eax>(
        st_ex_class_item *item@<edi>,
        int argl,
        void *argp,
        int (__cdecl *new_func)(void *, void *, crypto_ex_data_st *, int, int, void *),
        int (__cdecl *dup_func)(crypto_ex_data_st *, crypto_ex_data_st *, void *, int, int, void *),
        void (__cdecl *free_func)(void *, void *, crypto_ex_data_st *, int, int, void *))
{
  int meth_num; // ebx
  _DWORD *v7; // eax
  void *v8; // esi
  stack_st_CRYPTO_EX_DATA_FUNCS *meth; // [esp-Ch] [ebp-14h]

  meth_num = -1;
  v7 = CRYPTO_malloc(20, ".\\crypto\\ex_data.c", 339);
  v8 = v7;
  if ( v7 )
  {
    *v7 = argl;
    v7[1] = argp;
    v7[2] = new_func;
    v7[4] = dup_func;
    v7[3] = free_func;
    CRYPTO_lock((unsigned int)item, 9, 2, ".\\crypto\\ex_data.c", 350);
    if ( sk_num(&item->meth->stack) > item->meth_num )
    {
LABEL_6:
      meth_num = item->meth_num;
      meth = item->meth;
      item->meth_num = meth_num + 1;
      sk_set(&meth->stack, meth_num, v8);
    }
    else
    {
      while ( sk_push(&item->meth->stack, 0) )
      {
        if ( sk_num(&item->meth->stack) > item->meth_num )
          goto LABEL_6;
      }
      ERR_put_error(0xFu, 104, 65, ".\\crypto\\ex_data.c", 355);
      CRYPTO_free(v8);
    }
    CRYPTO_lock((unsigned int)item, 10, 2, ".\\crypto\\ex_data.c", 363);
    return meth_num;
  }
  else
  {
    ERR_put_error(0xFu, 104, 65, ".\\crypto\\ex_data.c", 342);
    return -1;
  }
}
