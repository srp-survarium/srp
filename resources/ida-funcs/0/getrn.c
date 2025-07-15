lhash_node_st **__usercall getrn@<eax>(lhash_st *lh@<esi>, const void *data, unsigned int *rhash)
{
  unsigned int v3; // ebp
  unsigned int v4; // edx
  lhash_node_st *v5; // edi
  lhash_node_st **i; // ebx
  lhash_node_st **p_next; // eax
  int (__cdecl *comp)(const void *, const void *); // [esp+14h] [ebp+8h]

  v3 = lh->hash(data);
  ++lh->num_hash_calls;
  *rhash = v3;
  v4 = v3 % lh->pmax;
  if ( v4 < lh->p )
    v4 = v3 % lh->num_alloc_nodes;
  comp = lh->comp;
  v5 = lh->b[v4];
  for ( i = &lh->b[v4]; v5; i = p_next )
  {
    ++lh->num_hash_comps;
    if ( v5->hash == v3 )
    {
      ++lh->num_comp_calls;
      if ( !comp(v5->data, data) )
        break;
    }
    p_next = &v5->next;
    v5 = v5->next;
  }
  return i;
}
