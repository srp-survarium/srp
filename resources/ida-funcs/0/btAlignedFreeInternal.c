void __cdecl btAlignedFreeInternal(void *ptr)
{
  if ( ptr )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(ptr);
  }
}
