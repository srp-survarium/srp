int __cdecl btAlignedAllocDefault(unsigned int size, int alignment)
{
  char *v2; // eax
  int v3; // ecx

  v2 = (char *)sAllocFunc(size + alignment + 3);
  if ( !v2 )
    return 0;
  v3 = (int)&v2[((alignment - 1) & (alignment - (_DWORD)v2 - 4)) + 4];
  *(_DWORD *)&v2[(alignment - 1) & (alignment - (_DWORD)v2 - 4)] = v2;
  return v3;
}
