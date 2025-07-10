void __usercall contract(lhash_st *lh@<esi>)
{
  lhash_node_st **v1; // eax
  lhash_node_st *v2; // ebx
  unsigned int p; // eax
  lhash_node_st **v4; // eax
  unsigned int pmax; // ecx
  unsigned int v6; // ecx
  lhash_node_st **b; // edx
  lhash_node_st *v8; // eax
  lhash_node_st **v9; // ecx

  v1 = &lh->b[lh->p - 1] + lh->pmax;
  v2 = *v1;
  *v1 = 0;
  p = lh->p;
  if ( p )
  {
    lh->p = p - 1;
  }
  else
  {
    v4 = (lhash_node_st **)CRYPTO_realloc(lh->b, 4 * lh->pmax, ".\\crypto\\lhash\\lhash.c", 375);
    if ( !v4 )
    {
      ++lh->error;
      return;
    }
    lh->pmax >>= 1;
    pmax = lh->pmax;
    ++lh->num_contract_reallocs;
    lh->num_alloc_nodes >>= 1;
    lh->p = pmax - 1;
    lh->b = v4;
  }
  v6 = lh->p;
  b = lh->b;
  --lh->num_nodes;
  ++lh->num_contracts;
  v8 = b[v6];
  v9 = &b[v6];
  if ( v8 )
  {
    for ( ; v8->next; v8 = v8->next )
      ;
    v8->next = v2;
  }
  else
  {
    *v9 = v2;
  }
}
