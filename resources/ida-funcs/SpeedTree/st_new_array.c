char *__cdecl SpeedTree::st_new_array<char>(unsigned int siNumElements)
{
  _DWORD *v1; // eax

  if ( !SpeedTree::g_pAllocator )
    return 0;
  v1 = SpeedTree::g_pAllocator->Alloc(SpeedTree::g_pAllocator, siNumElements + 4);
  if ( !v1 )
    return 0;
  SpeedTree::g_siHeapMemoryUsed += siNumElements + 4;
  ++SpeedTree::g_siNumHeapAllocs;
  *v1 = siNumElements;
  return (char *)(v1 + 1);
}


unsigned int *__cdecl SpeedTree::st_new_array<unsigned char>(unsigned int a1)
{
  unsigned int *v2; // [esp+0h] [ebp-1Ch]
  unsigned int i; // [esp+8h] [ebp-14h]
  unsigned int size; // [esp+18h] [ebp-4h]

  size = a1 + 4;
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


unsigned int *__cdecl SpeedTree::st_new_array<SpeedTree::SIndexedTriangles>(unsigned int a1)
{
  unsigned int *v2; // [esp+8h] [ebp-2Ch]
  SpeedTree::SIndexedTriangles *v3; // [esp+Ch] [ebp-28h]
  unsigned int i; // [esp+14h] [ebp-20h]
  int size; // [esp+24h] [ebp-10h]

  size = 68 * a1 + 4;
  if ( SpeedTree::g_pAllocator )
    v2 = (unsigned int *)SpeedTree::g_pAllocator->Alloc(SpeedTree::g_pAllocator, size);
  else
    v2 = (unsigned int *)malloc(size);
  if ( !v2 )
    return 0;
  *v2 = a1;
  for ( i = 0; i < a1; ++i )
  {
    v3 = (SpeedTree::SIndexedTriangles *)&v2[17 * i + 1];
    if ( v3 )
      SpeedTree::SIndexedTriangles::SIndexedTriangles(v3);
  }
  SpeedTree::g_siHeapMemoryUsed += size;
  ++SpeedTree::g_siNumHeapAllocs;
  return v2 + 1;
}


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


unsigned int *__cdecl SpeedTree::st_new_array<SpeedTree::SLeafCards>(unsigned int a1)
{
  unsigned int *v2; // [esp+8h] [ebp-2Ch]
  SpeedTree::SLeafCards *v3; // [esp+Ch] [ebp-28h]
  unsigned int i; // [esp+14h] [ebp-20h]
  int size; // [esp+24h] [ebp-10h]

  size = 60 * a1 + 4;
  if ( SpeedTree::g_pAllocator )
    v2 = (unsigned int *)SpeedTree::g_pAllocator->Alloc(SpeedTree::g_pAllocator, size);
  else
    v2 = (unsigned int *)malloc(size);
  if ( !v2 )
    return 0;
  *v2 = a1;
  for ( i = 0; i < a1; ++i )
  {
    v3 = (SpeedTree::SLeafCards *)&v2[15 * i + 1];
    if ( v3 )
      SpeedTree::SLeafCards::SLeafCards(v3);
  }
  SpeedTree::g_siHeapMemoryUsed += size;
  ++SpeedTree::g_siNumHeapAllocs;
  return v2 + 1;
}


unsigned int *__cdecl SpeedTree::st_new_array<SpeedTree::SMaterial>(unsigned int a1)
{
  unsigned int *v2; // [esp+8h] [ebp-2Ch]
  SpeedTree::SMaterial *v3; // [esp+Ch] [ebp-28h]
  unsigned int i; // [esp+14h] [ebp-20h]
  int size; // [esp+24h] [ebp-10h]

  size = 1692 * a1 + 4;
  if ( SpeedTree::g_pAllocator )
    v2 = (unsigned int *)SpeedTree::g_pAllocator->Alloc(SpeedTree::g_pAllocator, size);
  else
    v2 = (unsigned int *)malloc(size);
  if ( !v2 )
    return 0;
  *v2 = a1;
  for ( i = 0; i < a1; ++i )
  {
    v3 = (SpeedTree::SMaterial *)&v2[423 * i + 1];
    if ( v3 )
      SpeedTree::SMaterial::SMaterial(v3);
  }
  SpeedTree::g_siHeapMemoryUsed += size;
  ++SpeedTree::g_siNumHeapAllocs;
  return v2 + 1;
}


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
