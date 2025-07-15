void *__cdecl lh_delete(lhash_st *lh, void *data)
{
  lhash_st *v2; // esi
  lhash_node_st **v3; // eax
  lhash_node_st *v4; // ecx
  void *v6; // edi
  unsigned int num_nodes; // ecx
  const void *v8; // [esp-8h] [ebp-Ch]

  v2 = lh;
  v8 = data;
  lh->error = 0;
  v3 = getrn(v2, v8, (unsigned int *)&lh);
  v4 = *v3;
  if ( *v3 )
  {
    *v3 = v4->next;
    v6 = v4->data;
    CRYPTO_free(v4);
    --v2->num_items;
    num_nodes = v2->num_nodes;
    ++v2->num_delete;
    if ( num_nodes > 0x10 && v2->down_load >= (v2->num_items << 8) / num_nodes )
      contract(v2);
    return v6;
  }
  else
  {
    ++v2->num_no_delete;
    return 0;
  }
}
