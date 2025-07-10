int __cdecl btAlignedAllocDefault(unsigned int size, int alignment)
{
  char *v2; // eax
  int v3; // edx

  v2 = (char *)sAllocFunc(size + alignment + 3);
  if ( !v2 )
    return 0;
  v3 = (alignment - 1) & (alignment - (_DWORD)v2 - 4);
  *(_DWORD *)&v2[v3] = v2;
  return (int)&v2[v3 + 4];
}
