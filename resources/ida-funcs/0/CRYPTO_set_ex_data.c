int __usercall CRYPTO_set_ex_data@<eax>(int a1@<ebx>, crypto_ex_data_st *ad, int idx, void *val)
{
  stack_st_void *v4; // eax
  int v6; // esi

  if ( ad->sk || (v4 = (stack_st_void *)sk_new_null(), (ad->sk = v4) != 0) )
  {
    v6 = sk_num(&ad->sk->stack);
    if ( v6 > idx )
    {
LABEL_7:
      sk_set(&ad->sk->stack, idx, val);
      return 1;
    }
    else
    {
      while ( sk_push(&ad->sk->stack, 0) )
      {
        if ( ++v6 > idx )
          goto LABEL_7;
      }
      ERR_put_error(idx, 0xFu, 102, 65, ".\\crypto\\ex_data.c", 615);
      return 0;
    }
  }
  else
  {
    ERR_put_error(a1, 0xFu, 102, 65, ".\\crypto\\ex_data.c", 605);
    return 0;
  }
}
