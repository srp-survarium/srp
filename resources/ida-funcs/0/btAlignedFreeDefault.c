void __cdecl btAlignedFreeDefault(void **ptr)
{
  if ( ptr )
    sFreeFunc(*(ptr - 1));
}
