int *__usercall vostok_mspace_memalign@<eax>(malloc_state *msp@<ecx>, unsigned int alignment@<eax>, unsigned int bytes)
{
  return internal_memalign(bytes, msp, alignment);
}
