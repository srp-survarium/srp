void __cdecl lh_free(lhash_st *lh)
{
  unsigned int i; // edi
  lhash_node_st *v2; // eax
  lhash_node_st *next; // esi

  if ( lh )
  {
    for ( i = 0; i < lh->num_nodes; ++i )
    {
      v2 = lh->b[i];
      if ( v2 )
      {
        do
        {
          next = v2->next;
          CRYPTO_free(v2);
          v2 = next;
        }
        while ( next );
      }
    }
    CRYPTO_free(lh->b);
    CRYPTO_free(lh);
  }
}
