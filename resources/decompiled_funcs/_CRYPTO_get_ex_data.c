void *__cdecl CRYPTO_get_ex_data(const crypto_ex_data_st *ad, int idx)
{
  if ( ad->sk && idx < sk_num(&ad->sk->stack) )
    return sk_value(&ad->sk->stack, idx);
  else
    return 0;
}
