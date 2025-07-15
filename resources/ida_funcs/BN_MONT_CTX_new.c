bn_mont_ctx_st *__cdecl BN_MONT_CTX_new()
{
  bn_mont_ctx_st *result; // eax
  bn_mont_ctx_st *v1; // esi

  result = (bn_mont_ctx_st *)CRYPTO_malloc(76, ".\\crypto\\bn\\bn_mont.c", 383);
  v1 = result;
  if ( result )
  {
    result->ri = 0;
    BN_init(&result->RR);
    BN_init(&v1->N);
    BN_init(&v1->Ni);
    v1->n0[1] = 0;
    v1->n0[0] = 0;
    v1->flags = 1;
    return v1;
  }
  return result;
}
