unsigned __int8 *__cdecl Scaleform::HeapPT::ListBin::GetAlignedPtr(unsigned __int8 *start, unsigned int alignMask)
{
  unsigned __int8 *result; // eax
  unsigned int v3; // edx

  result = (unsigned __int8 *)(~alignMask & (unsigned int)&start[alignMask]);
  v3 = result - start;
  if ( result != start )
  {
    do
    {
      if ( v3 >= 0x10 )
        break;
      result += alignMask + 1;
      v3 += alignMask + 1;
    }
    while ( v3 );
  }
  return result;
}
