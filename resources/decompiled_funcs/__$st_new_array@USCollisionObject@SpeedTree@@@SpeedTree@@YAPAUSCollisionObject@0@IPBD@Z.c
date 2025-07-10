unsigned int *__cdecl SpeedTree::st_new_array<SpeedTree::SCollisionObject>(unsigned int a1)
{
  unsigned int *v2; // [esp+8h] [ebp-2Ch]
  SpeedTree::SCollisionObject *v3; // [esp+Ch] [ebp-28h]
  unsigned int i; // [esp+14h] [ebp-20h]
  int size; // [esp+24h] [ebp-10h]

  size = 292 * a1 + 4;
  if ( SpeedTree::g_pAllocator )
    v2 = (unsigned int *)SpeedTree::g_pAllocator->Alloc(SpeedTree::g_pAllocator, size);
  else
    v2 = (unsigned int *)malloc(size);
  if ( !v2 )
    return 0;
  *v2 = a1;
  for ( i = 0; i < a1; ++i )
  {
    v3 = (SpeedTree::SCollisionObject *)&v2[73 * i + 1];
    if ( v3 )
      SpeedTree::SCollisionObject::SCollisionObject(v3);
  }
  SpeedTree::g_siHeapMemoryUsed += size;
  ++SpeedTree::g_siNumHeapAllocs;
  return v2 + 1;
}
