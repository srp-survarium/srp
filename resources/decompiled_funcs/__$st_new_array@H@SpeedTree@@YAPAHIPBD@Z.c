unsigned int *__cdecl SpeedTree::st_new_array<int>(unsigned int a1)
{
  unsigned int *v2; // [esp+0h] [ebp-1Ch]
  unsigned int i; // [esp+8h] [ebp-14h]
  int size; // [esp+18h] [ebp-4h]

  size = 4 * a1 + 4;
  if ( SpeedTree::g_pAllocator )
    v2 = (unsigned int *)SpeedTree::g_pAllocator->Alloc(SpeedTree::g_pAllocator, size);
  else
    v2 = (unsigned int *)malloc(size);
  if ( !v2 )
    return 0;
  *v2 = a1;
  for ( i = 0; i < a1; ++i )
    ;
  SpeedTree::g_siHeapMemoryUsed += size;
  ++SpeedTree::g_siNumHeapAllocs;
  return v2 + 1;
}
