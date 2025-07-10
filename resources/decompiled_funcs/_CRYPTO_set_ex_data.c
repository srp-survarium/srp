int __cdecl CRYPTO_set_ex_data(crypto_ex_data_st *ad, int idx, void *val)
{
  stack_st_void *v3; // eax
  int v5; // esi

  if ( ad->sk || (v3 = (stack_st_void *)sk_new_null(), (ad->sk = v3) != 0) )
  {
    v5 = sk_num(&ad->sk->stack);
    if ( v5 > idx )
    {
LABEL_7:
      sk_set(&ad->sk->stack, idx, val);
      return 1;
    }
    else
    {
      while ( sk_push(&ad->sk->stack, 0) )
      {
        if ( ++v5 > idx )
          goto LABEL_7;
      }
      ERR_put_error(0xFu, 102, 65, ".\\crypto\\ex_data.c", 615);
      return 0;
    }
  }
  else
  {
    ERR_put_error(0xFu, 102, 65, ".\\crypto\\ex_data.c", 605);
    return 0;
  }
}
