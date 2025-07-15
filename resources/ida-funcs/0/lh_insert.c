lhash_node_st *__cdecl lh_insert(lhash_st *lh, _DWORD *data)
{
  lhash_st *v2; // esi
  unsigned int v3; // eax
  _DWORD *v4; // ebx
  lhash_node_st **v5; // edi
  lhash_node_st *v6; // ecx
  lhash_node_st *result; // eax

  v2 = lh;
  v3 = (lh->num_items << 8) / lh->num_nodes;
  lh->error = 0;
  if ( v2->up_load <= v3 )
    expand(v2);
  v4 = data;
  v5 = getrn(v2, data, (unsigned int *)&lh);
  v6 = *v5;
  if ( *v5 )
  {
    result = (lhash_node_st *)v6->data;
    v6->data = v4;
    ++v2->num_replace;
  }
  else
  {
    result = (lhash_node_st *)CRYPTO_malloc(12, ".\\crypto\\lhash\\lhash.c", 193);
    if ( result )
    {
      result->hash = (unsigned int)lh;
      result->data = v4;
      result->next = 0;
      *v5 = result;
      ++v2->num_insert;
      result = 0;
      ++v2->num_items;
    }
    else
    {
      ++v2->error;
    }
  }
  return result;
}
