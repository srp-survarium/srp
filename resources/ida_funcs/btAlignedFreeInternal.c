void __usercall btAlignedFreeInternal(void *ptr@<eax>)
{
  if ( ptr )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(ptr);
  }
}
