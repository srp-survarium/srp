void __usercall doall_util_fn(
        int use_arg@<ebx>,
        lhash_st *lh,
        void (__cdecl *func)(void *),
        void (__cdecl *func_arg)(void *, void *),
        void *arg)
{
  signed int i; // edi
  lhash_node_st *v6; // eax
  lhash_node_st *next; // esi

  if ( lh )
  {
    for ( i = lh->num_nodes - 1; i >= 0; --i )
    {
      v6 = lh->b[i];
      if ( v6 )
      {
        do
        {
          next = v6->next;
          if ( use_arg )
            func_arg(v6->data, arg);
          else
            func(v6->data);
          v6 = next;
        }
        while ( next );
      }
    }
  }
}
