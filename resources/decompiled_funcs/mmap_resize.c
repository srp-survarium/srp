malloc_chunk *__usercall mmap_resize@<eax>(malloc_chunk *oldp@<eax>, unsigned int nb@<edx>)
{
  unsigned int v2; // ecx

  v2 = oldp->head & 0xFFFFFFF8;
  if ( (nb & 0xFFFFFFF8) < 0x100 || v2 < nb + 4 || v2 - nb > 2 * mparams.granularity )
    return 0;
  return oldp;
}
