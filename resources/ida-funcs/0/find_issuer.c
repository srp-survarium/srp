x509_st *__usercall find_issuer@<eax>(stack_st_X509 *sk@<ebx>, x509_store_ctx_st *ctx, x509_st *x)
{
  int v3; // esi
  char *v4; // edi
  const stack_st *v6; // [esp+0h] [ebp-10h]

  v3 = 0;
  if ( sk_num(v6) <= 0 )
    return 0;
  while ( 1 )
  {
    v4 = sk_value(&sk->stack, v3);
    if ( ctx->check_issued(ctx, x, (x509_st *)v4) )
      break;
    if ( ++v3 >= sk_num(&sk->stack) )
      return 0;
  }
  return (x509_st *)v4;
}
