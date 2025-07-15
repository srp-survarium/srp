btAxisSweep3Internal<unsigned short> *__userpurge btAxisSweep3Internal<unsigned short>::btAxisSweep3Internal<unsigned short>@<eax>(
        btAxisSweep3Internal<unsigned short> *this@<ecx>,
        btAxisSweep3Internal<unsigned short> *worldAabbMin,
        const btVector3 *worldAabbMax,
        const btVector3 *handleMask,
        unsigned __int16 handleSentinel,
        unsigned __int16 userMaxHandles,
        btOverlappingPairCache *pairCache,
        bool disableRaycastAccelerator)
{
  btHashedOverlappingPairCache *v8; // ecx
  btHashedOverlappingPairCache *v9; // eax
  btOverlappingPairCache *v10; // eax
  btDbvtBroadphase *v11; // eax
  int v12; // eax
  unsigned __int64 v13; // xmm0_8
  float m_handleSentinel; // xmm3_4
  char *v15; // eax
  int v16; // esi
  __int16 v17; // ax
  int v18; // ecx
  btAxisSweep3Internal<unsigned short>::Edge **m_pEdges; // esi
  int v20; // edi
  btAxisSweep3Internal<unsigned short>::Edge *v21; // eax
  btAxisSweep3Internal<unsigned short> *result; // eax
  btVector3 v23; // [esp+10h] [ebp-10h]

  ++gNumAlignedAllocs;
  worldAabbMin->__vftable = (btAxisSweep3Internal<unsigned short>_vtbl *)&btAxisSweep3Internal<unsigned short>::`vftable';
  *(float *)&worldAabbMin->m_bpHandleMask = NAN;
  worldAabbMin->m_pairCache = 0;
  worldAabbMin->m_userPairCallback = 0;
  worldAabbMin->m_ownsPairCache = 0;
  worldAabbMin->m_invalidPair = 0;
  worldAabbMin->m_raycastAccelerator = 0;
  if ( sAlignedAllocFunc(0x4Cu, 16) )
    v9 = btHashedOverlappingPairCache::btHashedOverlappingPairCache(v8);
  else
    v9 = 0;
  ++gNumAlignedAllocs;
  worldAabbMin->m_pairCache = v9;
  worldAabbMin->m_ownsPairCache = 1;
  v10 = (btOverlappingPairCache *)sAlignedAllocFunc(0x18u, 16);
  if ( v10 )
  {
    v10->__vftable = (btOverlappingPairCache_vtbl *)&btNullPairCache::`vftable';
    LOBYTE(v10[5].__vftable) = 1;
    v10[4].__vftable = 0;
    v10[2].__vftable = 0;
    v10[3].__vftable = 0;
  }
  else
  {
    v10 = 0;
  }
  ++gNumAlignedAllocs;
  worldAabbMin->m_nullPairCache = v10;
  v11 = (btDbvtBroadphase *)sAlignedAllocFunc(0x9Cu, 16);
  if ( v11 )
    btDbvtBroadphase::btDbvtBroadphase(v11, worldAabbMin->m_nullPairCache);
  else
    v12 = 0;
  worldAabbMin->m_raycastAccelerator = (btDbvtBroadphase *)v12;
  *(_BYTE *)(v12 + 153) = 1;
  v13 = worldAabbMax->mVec128.m128_u64[0];
  ++gNumAlignedAllocs;
  worldAabbMin->m_worldAabbMin.mVec128.m128_u64[0] = v13;
  worldAabbMin->m_worldAabbMin.mVec128.m128_u64[1] = worldAabbMax->mVec128.m128_u64[1];
  worldAabbMin->m_worldAabbMax.mVec128.m128_u64[0] = handleMask->mVec128.m128_u64[0];
  m_handleSentinel = (float)worldAabbMin->m_handleSentinel;
  worldAabbMin->m_worldAabbMax.mVec128.m128_u64[1] = handleMask->mVec128.m128_u64[1];
  v23.mVec128.m128_i32[3] = 0;
  v23.mVec128.m128_f32[0] = m_handleSentinel
                          / (float)(worldAabbMin->m_worldAabbMax.mVec128.m128_f32[0]
                                  - worldAabbMin->m_worldAabbMin.mVec128.m128_f32[0]);
  v23.mVec128.m128_f32[1] = m_handleSentinel
                          / (float)(worldAabbMin->m_worldAabbMax.mVec128.m128_f32[1]
                                  - worldAabbMin->m_worldAabbMin.mVec128.m128_f32[1]);
  v23.mVec128.m128_f32[2] = m_handleSentinel
                          / (float)(worldAabbMin->m_worldAabbMax.mVec128.m128_f32[2]
                                  - worldAabbMin->m_worldAabbMin.mVec128.m128_f32[2]);
  worldAabbMin->m_quantize = (btVector3)v23.mVec128;
  v15 = (char *)sAlignedAllocFunc(0x1FFFC0u, 16);
  v16 = (int)v15;
  if ( v15 )
    `vector constructor iterator'(
      v15,
      0x40u,
      0x7FFF,
      (void *(__thiscall *)(void *))btAxisSweep3Internal<unsigned short>::Handle::Handle);
  else
    v16 = 0;
  *(float *)&worldAabbMin->m_numHandles = NAN;
  worldAabbMin->m_pHandles = (btAxisSweep3Internal<unsigned short>::Handle *)v16;
  worldAabbMin->m_firstFreeHandle = 1;
  v17 = 1;
  v18 = 1;
  do
    worldAabbMin->m_pHandles[v18++].m_minEdges[0] = ++v17;
  while ( (unsigned __int16)v17 < 0x7FFFu );
  *(_WORD *)((char *)&loc_1FFFAE + (unsigned int)worldAabbMin->m_pHandles + 2) = 0;
  m_pEdges = worldAabbMin->m_pEdges;
  v20 = 3;
  do
  {
    ++gNumAlignedAllocs;
    v21 = (btAxisSweep3Internal<unsigned short>::Edge *)sAlignedAllocFunc(0x3FFF8u, 16);
    m_pEdges[3] = v21;
    *m_pEdges++ = v21;
    --v20;
  }
  while ( v20 );
  worldAabbMin->m_pHandles->m_clientObject = 0;
  worldAabbMin->m_pHandles->m_minEdges[0] = 0;
  worldAabbMin->m_pHandles->m_maxEdges[0] = 1;
  *(float *)worldAabbMin->m_pEdges[0] = 0.0;
  worldAabbMin->m_pEdges[0][1].m_pos = worldAabbMin->m_handleSentinel;
  worldAabbMin->m_pEdges[0][1].m_handle = 0;
  worldAabbMin->m_pHandles->m_minEdges[1] = 0;
  worldAabbMin->m_pHandles->m_maxEdges[1] = 1;
  *(float *)worldAabbMin->m_pEdges[1] = 0.0;
  worldAabbMin->m_pEdges[1][1].m_pos = worldAabbMin->m_handleSentinel;
  worldAabbMin->m_pEdges[1][1].m_handle = 0;
  worldAabbMin->m_pHandles->m_minEdges[2] = 0;
  worldAabbMin->m_pHandles->m_maxEdges[2] = 1;
  *(float *)worldAabbMin->m_pEdges[2] = 0.0;
  worldAabbMin->m_pEdges[2][1].m_pos = worldAabbMin->m_handleSentinel;
  result = worldAabbMin;
  worldAabbMin->m_pEdges[2][1].m_handle = 0;
  return result;
}
