void __usercall expand(lhash_st *lh@<esi>)
{
  unsigned int pmax; // ecx
  unsigned int p; // ebx
  lhash_node_st **v3; // ebp
  lhash_node_st **p_next; // edi
  lhash_node_st *v5; // ecx
  unsigned int v6; // ebx
  lhash_node_st **v7; // edx
  unsigned int num_alloc_nodes; // eax
  unsigned int v9; // ecx
  unsigned int i; // [esp+Ch] [ebp-4h]

  pmax = lh->pmax;
  p = lh->p;
  ++lh->num_nodes;
  ++lh->num_expands;
  lh->p = p + 1;
  v3 = &lh->b[p] + pmax;
  p_next = &lh->b[p];
  *v3 = 0;
  v5 = *p_next;
  for ( i = lh->num_alloc_nodes; *p_next; v5 = *p_next )
  {
    if ( v5->hash % i == p )
    {
      p_next = &(*p_next)->next;
    }
    else
    {
      *p_next = (*p_next)->next;
      v5->next = *v3;
      *v3 = v5;
    }
  }
  if ( lh->p >= lh->pmax )
  {
    v6 = 2 * lh->num_alloc_nodes;
    v7 = (lhash_node_st **)CRYPTO_realloc(lh->b, 8 * lh->num_alloc_nodes, ".\\crypto\\lhash\\lhash.c", 347);
    if ( v7 )
    {
      num_alloc_nodes = lh->num_alloc_nodes;
      if ( num_alloc_nodes < v6 )
        memset(&v7[num_alloc_nodes], 0, 4 * (v6 - num_alloc_nodes));
      v9 = lh->num_alloc_nodes;
      ++lh->num_expand_reallocs;
      lh->pmax = v9;
      lh->num_alloc_nodes = v6;
      lh->b = v7;
      lh->p = 0;
    }
    else
    {
      ++lh->error;
      lh->p = 0;
    }
  }
}
