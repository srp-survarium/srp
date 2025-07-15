unsigned int __stdcall Scaleform::String::BernsteinHashFunctionCIS(char *pdataIn, unsigned int size, unsigned int seed)
{
  unsigned int v3; // edx
  unsigned int result; // eax
  int v5; // ecx

  v3 = size;
  for ( result = seed; v3; result = v5 ^ (33 * result) )
  {
    v5 = (unsigned __int8)pdataIn[--v3];
    if ( (unsigned int)(v5 - 65) <= 0x19 )
      v5 += 32;
  }
  return result;
}
