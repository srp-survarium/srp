void *SpeedTree::st_allocate<SpeedTree::CCore>()
{
  void *v1; // [esp+0h] [ebp-10h]

  if ( SpeedTree::g_pAllocator )
    v1 = SpeedTree::g_pAllocator->Alloc(SpeedTree::g_pAllocator, 3620);
  else
    v1 = malloc(0xE24u);
  if ( !v1 )
    return 0;
  SpeedTree::g_siHeapMemoryUsed += 3620;
  ++SpeedTree::g_siNumHeapAllocs;
  return v1;
}
