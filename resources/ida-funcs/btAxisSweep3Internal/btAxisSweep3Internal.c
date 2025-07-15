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
  btHashedOverlappingPairCache *v8; // eax
  btHashedOverlappingPairCache *v9; // eax
  btOverlappingPairCache *v10; // eax
  void *v11; // eax
  btDbvtBroadphase *v12; // eax
  float m_handleSentinel; // xmm3_4
  btAxisSweep3Internal<unsigned short>::Handle *v14; // eax
  btAxisSweep3Internal<unsigned short>::Handle *v15; // ecx
  int i; // edx
  __int16 v17; // ax
  int v18; // ecx
  btAxisSweep3Internal<unsigned short>::Edge **m_pEdges; // esi
  btAxisSweep3Internal<unsigned short>::Edge *v20; // eax
  int v21; // ecx
  btAxisSweep3Internal<unsigned short>::Edge **v22; // eax
  btAxisSweep3Internal<unsigned short>::Edge *v23; // edx
  btHashedOverlappingPairCache *v25; // [esp-4h] [ebp-24h]
  btDbvtBroadphase *v26; // [esp-4h] [ebp-24h]
  int v27; // [esp+Ch] [ebp-14h]
  unsigned __int64 v28; // [esp+14h] [ebp-Ch]

  worldAabbMin->m_bpHandleMask = -2;
  worldAabbMin->__vftable = (btAxisSweep3Internal<unsigned short>_vtbl *)&btAxisSweep3Internal<unsigned short>::`vftable';
  worldAabbMin->m_handleSentinel = -1;
  worldAabbMin->m_pairCache = 0;
  worldAabbMin->m_userPairCallback = 0;
  worldAabbMin->m_ownsPairCache = 0;
  worldAabbMin->m_invalidPair = 0;
  worldAabbMin->m_raycastAccelerator = 0;
  v8 = (btHashedOverlappingPairCache *)btAlignedAllocInternal(0x4Cu);
  if ( v8 )
    v9 = btHashedOverlappingPairCache::btHashedOverlappingPairCache(v25, v8);
  else
    v9 = 0;
  worldAabbMin->m_pairCache = v9;
  worldAabbMin->m_ownsPairCache = 1;
  v10 = (btOverlappingPairCache *)btAlignedAllocInternal(0x18u);
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
  worldAabbMin->m_nullPairCache = v10;
  v11 = btAlignedAllocInternal(0x9Cu);
  if ( v11 )
    v12 = btDbvtBroadphase::btDbvtBroadphase(
            v26,
            (int)v11,
            (btHashedOverlappingPairCache *)worldAabbMin->m_nullPairCache);
  else
    v12 = 0;
  worldAabbMin->m_raycastAccelerator = v12;
  v12->m_deferedcollide = 1;
  worldAabbMin->m_worldAabbMin = (btVector3)worldAabbMax->mVec128;
  worldAabbMin->m_worldAabbMax = (btVector3)handleMask->mVec128;
  m_handleSentinel = (float)worldAabbMin->m_handleSentinel;
  *(float *)&v28 = m_handleSentinel
                 / (float)(worldAabbMin->m_worldAabbMax.mVec128.m128_f32[1]
                         - worldAabbMin->m_worldAabbMin.mVec128.m128_f32[1]);
  *((float *)&v28 + 1) = m_handleSentinel
                       / (float)(worldAabbMin->m_worldAabbMax.mVec128.m128_f32[2]
                               - worldAabbMin->m_worldAabbMin.mVec128.m128_f32[2]);
  worldAabbMin->m_quantize.mVec128.m128_f32[0] = m_handleSentinel
                                               / (float)(worldAabbMin->m_worldAabbMax.mVec128.m128_f32[0]
                                                       - worldAabbMin->m_worldAabbMin.mVec128.m128_f32[0]);
  *(unsigned __int64 *)((char *)worldAabbMin->m_quantize.mVec128.m128_u64 + 4) = v28;
  worldAabbMin->m_quantize.mVec128.m128_i32[3] = 0;
  v14 = (btAxisSweep3Internal<unsigned short>::Handle *)btAlignedAllocInternal(0x1FFFC0u);
  if ( v14 )
  {
    v15 = v14;
    for ( i = 32766; i >= 0; --i )
    {
      v15->m_clientObject = 0;
      v15->m_multiSapParentProxy = 0;
      ++v15;
    }
  }
  else
  {
    v14 = 0;
  }
  worldAabbMin->m_pHandles = v14;
  worldAabbMin->m_maxHandles = 0x7FFF;
  worldAabbMin->m_numHandles = 0;
  v17 = 1;
  worldAabbMin->m_firstFreeHandle = 1;
  v18 = 1;
  do
    worldAabbMin->m_pHandles[v18++].m_minEdges[0] = ++v17;
  while ( (unsigned __int16)v17 < 0x7FFFu );
  *(_WORD *)((char *)&loc_1FFFB0 + (unsigned int)worldAabbMin->m_pHandles) = 0;
  m_pEdges = worldAabbMin->m_pEdges;
  v27 = 3;
  do
  {
    v20 = (btAxisSweep3Internal<unsigned short>::Edge *)btAlignedAllocInternal((unsigned int)&loc_3FFF6 + 2);
    m_pEdges[3] = v20;
    *m_pEdges++ = v20;
    --v27;
  }
  while ( v27 );
  worldAabbMin->m_pHandles->m_clientObject = 0;
  v21 = 54;
  v22 = worldAabbMin->m_pEdges;
  do
  {
    *(_WORD *)((char *)worldAabbMin->m_pHandles + v21 - 6) = 0;
    *(_WORD *)((char *)&worldAabbMin->m_pHandles->m_clientObject + v21) = 1;
    (*v22)->m_pos = 0;
    (*v22)->m_handle = 0;
    (*v22)[1].m_pos = worldAabbMin->m_handleSentinel;
    v23 = *v22;
    v21 += 2;
    ++v22;
    v23[1].m_handle = 0;
  }
  while ( v21 < 60 );
  return worldAabbMin;
}
