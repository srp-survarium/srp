unsigned int __usercall has_segment_link@<eax>(malloc_state *m@<eax>, malloc_segment *ss@<edx>)
{
  char *base; // ecx
  unsigned int result; // eax

  base = ss->base;
  result = (unsigned int)&m->seg;
  while ( result < (unsigned int)base || result >= (unsigned int)&base[ss->size] )
  {
    result = *(_DWORD *)(result + 8);
    if ( !result )
      return result;
  }
  return 1;
}
