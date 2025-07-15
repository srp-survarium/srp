void *__cdecl btAlignedAllocInternal(unsigned int size)
{
  ++gNumAlignedAllocs;
  return sAlignedAllocFunc(size, 16);
}
