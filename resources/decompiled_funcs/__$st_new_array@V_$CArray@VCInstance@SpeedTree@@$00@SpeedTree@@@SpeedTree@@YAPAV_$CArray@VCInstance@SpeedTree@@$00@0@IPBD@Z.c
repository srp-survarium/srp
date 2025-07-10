SpeedTree::CArray<SpeedTree::CInstance,1> *__usercall SpeedTree::st_new_array<SpeedTree::CArray<SpeedTree::CInstance,1>>@<eax>(
        unsigned int siNumElements@<eax>)
{
  unsigned int v1; // esi
  unsigned int v2; // edi
  unsigned int *v3; // eax
  _DWORD *v4; // ecx

  v1 = siNumElements;
  v2 = 20 * siNumElements + 4;
  if ( !SpeedTree::g_pAllocator )
    return 0;
  v3 = (unsigned int *)SpeedTree::g_pAllocator->Alloc(SpeedTree::g_pAllocator, v2);
  if ( !v3 )
    return 0;
  *v3 = v1;
  if ( v1 )
  {
    v4 = v3 + 3;
    do
    {
      if ( v4 != (_DWORD *)8 )
      {
        *(v4 - 2) = &SpeedTree::CArray<SpeedTree::CInstance,1>::`vftable';
        *(v4 - 1) = 0;
        *v4 = 0;
        v4[1] = 0;
        *((_BYTE *)v4 + 8) = 0;
      }
      v4 += 5;
      --v1;
    }
    while ( v1 );
  }
  SpeedTree::g_siHeapMemoryUsed += v2;
  ++SpeedTree::g_siNumHeapAllocs;
  return (SpeedTree::CArray<SpeedTree::CInstance,1> *)(v3 + 1);
}
