int __usercall int_dup_ex_data@<eax>(int a1@<edi>, void *class_index, crypto_ex_data_st *to, crypto_ex_data_st *from)
{
  _DWORD *v4; // ebp
  int result; // eax
  int v6; // ebx
  int v7; // edi
  int v8; // eax
  int i; // esi
  int j; // esi
  void *sk; // eax
  int v12; // eax
  void *val; // [esp+8h] [ebp-4h] BYREF

  v4 = 0;
  if ( !from->sk )
    return 1;
  result = (int)def_get_class(class_index, a1);
  v6 = result;
  if ( result )
  {
    CRYPTO_lock(a1, result, 5, 2, ".\\crypto\\ex_data.c", 457);
    v7 = sk_num(*(const stack_st **)(v6 + 4));
    v8 = sk_num(&from->sk->stack);
    if ( v8 < v7 )
      v7 = v8;
    if ( v7 > 0 )
    {
      v4 = CRYPTO_malloc(4 * v7, ".\\crypto\\ex_data.c", 464);
      if ( v4 )
      {
        for ( i = 0; i < v7; ++i )
          v4[i] = sk_value(*(const stack_st **)(v6 + 4), i);
      }
    }
    CRYPTO_lock(v7, v6, 6, 2, ".\\crypto\\ex_data.c", 471);
    if ( v7 <= 0 || v4 )
    {
      for ( j = 0; j < v7; ++j )
      {
        sk = from->sk;
        if ( from->sk )
        {
          if ( j < sk_num(&from->sk->stack) )
            sk = sk_value(&from->sk->stack, j);
          else
            sk = 0;
        }
        val = sk;
        v12 = v4[j];
        if ( v12 && *(_DWORD *)(v12 + 16) )
          (*(void (__cdecl **)(crypto_ex_data_st *, crypto_ex_data_st *, void **, int, _DWORD, _DWORD))(v12 + 16))(
            to,
            from,
            &val,
            j,
            *(_DWORD *)v12,
            *(_DWORD *)(v12 + 4));
        CRYPTO_set_ex_data((int)from, to, j, val);
      }
      if ( v4 )
        CRYPTO_free(v4);
      return 1;
    }
    else
    {
      ERR_put_error(v6, 0xFu, 106, 65, ".\\crypto\\ex_data.c", 474);
      return 0;
    }
  }
  return result;
}
