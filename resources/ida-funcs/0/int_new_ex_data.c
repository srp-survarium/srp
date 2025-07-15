int __cdecl int_new_ex_data(int class_index, void *obj, crypto_ex_data_st *ad)
{
  _DWORD *v3; // edi
  int result; // eax
  int v5; // ebx
  int v6; // eax
  int v7; // ebp
  int i; // esi
  int j; // esi
  int v10; // eax
  stack_st_void *sk; // eax

  v3 = 0;
  result = (int)def_get_class(class_index, 0);
  v5 = result;
  if ( result )
  {
    ad->sk = 0;
    CRYPTO_lock(0, 5, 2, ".\\crypto\\ex_data.c", 413);
    v6 = sk_num(*(const stack_st **)(v5 + 4));
    v7 = v6;
    if ( v6 > 0 )
    {
      v3 = CRYPTO_malloc(4 * v6, ".\\crypto\\ex_data.c", 417);
      if ( v3 )
      {
        for ( i = 0; i < v7; ++i )
          v3[i] = sk_value(*(const stack_st **)(v5 + 4), i);
      }
    }
    CRYPTO_lock((unsigned int)v3, 6, 2, ".\\crypto\\ex_data.c", 424);
    if ( v7 <= 0 || v3 )
    {
      for ( j = 0; j < v7; ++j )
      {
        v10 = v3[j];
        if ( v10 && *(_DWORD *)(v10 + 8) )
        {
          sk = ad->sk;
          if ( ad->sk )
          {
            if ( j < sk_num(&ad->sk->stack) )
              sk = (stack_st_void *)sk_value(&ad->sk->stack, j);
            else
              sk = 0;
          }
          (*(void (__cdecl **)(void *, stack_st_void *, crypto_ex_data_st *, int, _DWORD, _DWORD))(v3[j] + 8))(
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
      return 1;
    }
    else
    {
      ERR_put_error(0xFu, 108, 65, ".\\crypto\\ex_data.c", 427);
      return 0;
    }
  }
  return result;
}
