unsigned int *__cdecl SpeedTree::st_new_array<SMaterialSerial>(unsigned int a1)
{
  unsigned int *v2; // [esp+8h] [ebp-40h]
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v3; // [esp+20h] [ebp-28h]
  unsigned int i; // [esp+28h] [ebp-20h]
  int size; // [esp+38h] [ebp-10h]

  size = 1648 * a1 + 4;
  if ( SpeedTree::g_pAllocator )
    v2 = (unsigned int *)SpeedTree::g_pAllocator->Alloc(SpeedTree::g_pAllocator, size);
  else
    v2 = (unsigned int *)malloc(size);
  if ( !v2 )
    return 0;
  *v2 = a1;
  for ( i = 0; i < a1; ++i )
  {
    v3 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v2[412 * i + 1];
    if ( v3 )
      SMaterialSerial::SMaterialSerial((SMaterialSerial *)v3);
  }
  SpeedTree::g_siHeapMemoryUsed += size;
  ++SpeedTree::g_siNumHeapAllocs;
  return v2 + 1;
}
