int *__fastcall vostok_mspace_realloc(unsigned __int8 *oldmem, unsigned int bytes, malloc_state *msp)
{
  if ( oldmem )
    return (int *)internal_realloc(msp, oldmem, bytes);
  else
    return vostok_mspace_malloc(msp, bytes);
}
