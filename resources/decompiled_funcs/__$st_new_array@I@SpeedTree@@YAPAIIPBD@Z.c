unsigned int *__cdecl SpeedTree::st_new_array<unsigned int>(unsigned int siNumElements)
{
  _DWORD *v1; // eax

  if ( !SpeedTree::g_pAllocator )
    return 0;
  v1 = SpeedTree::g_pAllocator->Alloc(SpeedTree::g_pAllocator, 4 * siNumElements + 4);
  if ( !v1 )
    return 0;
  SpeedTree::g_siHeapMemoryUsed += 4 * siNumElements + 4;
  ++SpeedTree::g_siNumHeapAllocs;
  *v1 = siNumElements;
  return v1 + 1;
}
