void *__usercall btAlignedAllocInternal@<eax>(unsigned int size@<eax>)
{
  ++gNumAlignedAllocs;
  return sAlignedAllocFunc(size, 16);
}
