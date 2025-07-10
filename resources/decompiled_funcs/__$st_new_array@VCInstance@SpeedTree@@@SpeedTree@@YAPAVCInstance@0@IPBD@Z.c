SpeedTree::CInstance *__cdecl SpeedTree::st_new_array<SpeedTree::CInstance>(unsigned int siNumElements)
{
  unsigned int v1; // esi
  _DWORD *v2; // eax
  _DWORD *v3; // ebx
  SpeedTree::CInstance *v4; // edi

  v1 = siNumElements;
  if ( !SpeedTree::g_pAllocator )
    return 0;
  v2 = SpeedTree::g_pAllocator->Alloc(SpeedTree::g_pAllocator, 36 * siNumElements + 4);
  if ( !v2 )
    return 0;
  v3 = v2 + 1;
  *v2 = siNumElements;
  if ( siNumElements )
  {
    v4 = (SpeedTree::CInstance *)(v2 + 1);
    do
    {
      if ( v4 )
        SpeedTree::CInstance::CInstance(v4);
      ++v4;
      --v1;
    }
    while ( v1 );
  }
  SpeedTree::g_siHeapMemoryUsed += 36 * siNumElements + 4;
  ++SpeedTree::g_siNumHeapAllocs;
  return (SpeedTree::CInstance *)v3;
}
