bn_mont_ctx_st *__cdecl BN_MONT_CTX_copy(bn_mont_ctx_st *to, bn_mont_ctx_st *from)
{
  if ( to != from )
  {
    if ( !BN_copy(&to->RR, &from->RR) || !BN_copy(&to->N, &from->N) || !BN_copy(&to->Ni, &from->Ni) )
      return 0;
    to->ri = from->ri;
    *(_QWORD *)to->n0 = *(_QWORD *)from->n0;
  }
  return to;
}
