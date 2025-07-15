unsigned __int8 *__usercall vostok_mspace_realloc@<eax>(
        malloc_state *msp@<eax>,
        unsigned __int8 *oldmem,
        unsigned int bytes)
{
  if ( oldmem )
    return internal_realloc(msp, oldmem, bytes);
  else
    return (unsigned __int8 *)vostok_mspace_malloc(msp, bytes);
}
