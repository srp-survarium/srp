void __usercall _vorbis_block_ripcord(vorbis_block *vb@<esi>)
{
  alloc_chain *reap; // ebx
  alloc_chain *next; // ebp
  int totaluse; // eax

  reap = vb->reap;
  if ( reap )
  {
    do
    {
      next = reap->next;
      ogg_free_impl(reap->ptr);
      reap->ptr = 0;
      reap->next = 0;
      ogg_free_impl(reap);
      reap = next;
    }
    while ( next );
  }
  totaluse = vb->totaluse;
  if ( totaluse )
  {
    vb->localstore = ogg_realloc_impl(vb->localstore, totaluse + vb->localalloc);
    vb->localalloc += vb->totaluse;
    vb->totaluse = 0;
  }
  vb->localtop = 0;
  vb->reap = 0;
}
