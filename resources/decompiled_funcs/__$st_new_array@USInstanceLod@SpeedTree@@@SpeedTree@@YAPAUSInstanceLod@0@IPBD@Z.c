unsigned int *__cdecl SpeedTree::st_new_array<SpeedTree::SInstanceLod>(unsigned int a1)
{
  unsigned int *v2; // [esp+4h] [ebp-24h]
  unsigned int *v3; // [esp+Ch] [ebp-1Ch]
  unsigned int i; // [esp+14h] [ebp-14h]
  int size; // [esp+24h] [ebp-4h]

  size = 32 * a1 + 4;
  if ( SpeedTree::g_pAllocator )
    v2 = (unsigned int *)SpeedTree::g_pAllocator->Alloc(SpeedTree::g_pAllocator, size);
  else
    v2 = (unsigned int *)malloc(size);
  if ( !v2 )
    return 0;
  *v2 = a1;
  for ( i = 0; i < a1; ++i )
  {
    v3 = &v2[8 * i + 1];
    if ( v3 )
    {
      *((_BYTE *)v3 + 28) = -1;
      *((_BYTE *)v3 + 29) = -1;
      *((_BYTE *)v3 + 30) = -1;
      *((_BYTE *)v3 + 31) = -1;
    }
  }
  SpeedTree::g_siHeapMemoryUsed += size;
  ++SpeedTree::g_siNumHeapAllocs;
  return v2 + 1;
}
