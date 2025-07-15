char *__usercall _vorbis_block_alloc@<eax>(vorbis_block *vb@<esi>, int bytes@<eax>)
{
  unsigned int v2; // edi
  alloc_chain *v3; // eax
  void *v4; // eax
  int localtop; // ecx
  char *result; // eax

  v2 = (bytes + 7) & 0xFFFFFFF8;
  if ( (signed int)(v2 + vb->localtop) > vb->localalloc )
  {
    if ( vb->localstore )
    {
      v3 = (alloc_chain *)ogg_malloc_impl(8u);
      vb->totaluse += vb->localtop;
      v3->next = vb->reap;
      v3->ptr = vb->localstore;
      vb->reap = v3;
    }
    vb->localalloc = v2;
    v4 = ogg_malloc_impl(v2);
    vb->localtop = 0;
    vb->localstore = v4;
  }
  localtop = vb->localtop;
  result = (char *)vb->localstore + localtop;
  vb->localtop = v2 + localtop;
  return result;
}
