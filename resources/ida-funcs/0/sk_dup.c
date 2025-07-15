stack_st *__cdecl sk_dup(stack_st *sk)
{
  stack_st *v1; // eax
  stack_st *v2; // esi
  char **v3; // eax

  v1 = sk_new(sk->comp);
  v2 = v1;
  if ( !v1 )
    return 0;
  v3 = (char **)CRYPTO_realloc(v1->data, 4 * sk->num_alloc, ".\\crypto\\stack\\stack.c", 99);
  if ( !v3 )
  {
    if ( v2->data )
      CRYPTO_free(v2->data);
    CRYPTO_free(v2);
    return 0;
  }
  v2->data = v3;
  v2->num = sk->num;
  memcpy((int)v3, (const __m128i *)sk->data, 4 * sk->num);
  v2->sorted = sk->sorted;
  v2->num_alloc = sk->num_alloc;
  v2->comp = sk->comp;
  return v2;
}
