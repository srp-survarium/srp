unsigned int __stdcall Scaleform::String::BernsteinHashFunction(char *pdataIn, unsigned int size, unsigned int seed)
{
  unsigned int v3; // ecx
  unsigned int result; // eax
  int v5; // esi

  v3 = size;
  for ( result = seed; v3; result = (33 * result) ^ v5 )
    v5 = (unsigned __int8)pdataIn[--v3];
  return result;
}
