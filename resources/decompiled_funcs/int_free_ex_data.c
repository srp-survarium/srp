void __cdecl int_free_ex_data(int class_index, void *obj, crypto_ex_data_st *ad)
{
  _DWORD *v3; // edi
  st_ex_class_item *v4; // ebx
  int v5; // eax
  int v6; // ebp
  int i; // esi
  int j; // esi
  int v9; // eax
  stack_st_void *sk; // eax

  v3 = 0;
  v4 = def_get_class(class_index, 0);
  if ( v4 )
  {
    CRYPTO_lock(0, 5, 2, ".\\crypto\\ex_data.c", 500);
    v5 = sk_num(&v4->meth->stack);
    v6 = v5;
    if ( v5 > 0 )
    {
      v3 = CRYPTO_malloc(4 * v5, ".\\crypto\\ex_data.c", 504);
      if ( v3 )
      {
        for ( i = 0; i < v6; ++i )
          v3[i] = sk_value(&v4->meth->stack, i);
      }
    }
    CRYPTO_lock((unsigned int)v3, 6, 2, ".\\crypto\\ex_data.c", 511);
    if ( v6 <= 0 || v3 )
    {
      for ( j = 0; j < v6; ++j )
      {
        v9 = v3[j];
        if ( v9 && *(_DWORD *)(v9 + 12) )
        {
          sk = ad->sk;
          if ( ad->sk )
          {
            if ( j < sk_num(&ad->sk->stack) )
              sk = (stack_st_void *)sk_value(&ad->sk->stack, j);
            else
              sk = 0;
          }
          (*(void (__cdecl **)(void *, stack_st_void *, crypto_ex_data_st *, int, _DWORD, _DWORD))(v3[j] + 12))(
            obj,
            sk,
            ad,
            j,
            *(_DWORD *)v3[j],
            *(_DWORD *)(v3[j] + 4));
        }
      }
      if ( v3 )
        CRYPTO_free(v3);
      if ( ad->sk )
      {
        sk_free(&ad->sk->stack);
        ad->sk = 0;
      }
    }
    else
    {
      ERR_put_error(0xFu, 107, 65, ".\\crypto\\ex_data.c", 514);
    }
  }
}
