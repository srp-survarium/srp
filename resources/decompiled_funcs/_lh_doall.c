void __cdecl lh_doall(lhash_st *lh, void (__cdecl *func)(void *))
{
  signed int i; // edi
  lhash_node_st *v3; // eax
  lhash_node_st *next; // esi

  if ( lh )
  {
    for ( i = lh->num_nodes - 1; i >= 0; --i )
    {
      v3 = lh->b[i];
      if ( v3 )
      {
        do
        {
          next = v3->next;
          func(v3->data);
          v3 = next;
        }
        while ( next );
      }
    }
  }
}
