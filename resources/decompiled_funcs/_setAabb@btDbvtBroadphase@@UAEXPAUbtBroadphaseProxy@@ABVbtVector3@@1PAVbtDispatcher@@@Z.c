void __thiscall btDbvtBroadphase::setAabb(
        btDbvtBroadphase *this,
        btBroadphaseProxy *absproxy,
        btVector3 *aabbMin,
        const btVector3 *aabbMax,
        btDispatcher *__formal)
{
  bool v5; // zf
  btVector3 *v6; // edi
  btDbvtNode *m_free; // eax
  btDbvtNode *v9; // eax
  float v10; // xmm4_4
  float v11; // xmm6_4
  float v12; // xmm7_4
  float v13; // xmm5_4
  float v14; // xmm0_4
  float v15; // xmm3_4
  int v16; // eax
  _DWORD *m_multiSapParentProxy; // eax
  void **v18; // eax
  btDbvtNode *aabb_20; // [esp+AAh] [ebp-5Ch]
  const btDbvtNode *aabb_24; // [esp+AEh] [ebp-58h]
  char v21; // [esp+D1h] [ebp-35h]
  btDbvtNode *m_clientObject; // [esp+D2h] [ebp-34h]
  btDbvt **m_sets; // [esp+D2h] [ebp-34h]
  btVector3 v24; // [esp+D6h] [ebp-30h] BYREF
  __m128 volume; // [esp+E6h] [ebp-20h] BYREF
  __m128 volume_16; // [esp+F6h] [ebp-10h]

  v5 = absproxy[1].m_uniqueId == 2;
  v6 = aabbMin;
  volume = aabbMin->mVec128;
  volume_16 = aabbMax->mVec128;
  v21 = 0;
  if ( v5 )
  {
    m_clientObject = (btDbvtNode *)absproxy[1].m_clientObject;
    removeleaf(&this->m_sets[1], m_clientObject);
    m_free = this->m_sets[1].m_free;
    if ( m_free )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(m_free);
    }
    --this->m_sets[1].m_leaves;
    this->m_sets[1].m_free = m_clientObject;
    m_sets = (btDbvt **)this->m_sets;
    absproxy[1].m_clientObject = btDbvt::insert((btDbvt *)&volume, (const btDbvtAabbMm *)&volume, absproxy);
    goto LABEL_15;
  }
  ++this->m_updates_call;
  v9 = (btDbvtNode *)absproxy[1].m_clientObject;
  v24.mVec128 = _mm_or_ps(_mm_cmplt_ps(v9->volume.mx.mVec128, volume), _mm_cmplt_ps(volume_16, v9->volume.mi.mVec128));
  if ( v24.mVec128.m128_i32[2] | v24.mVec128.m128_i32[1] | v24.mVec128.m128_i32[0] )
  {
    m_sets = (btDbvt **)this->m_sets;
    btDbvt::update(this->m_sets, v9, (btDbvtAabbMm *)&volume);
    ++this->m_updates_done;
LABEL_15:
    v6 = aabbMin;
    goto LABEL_16;
  }
  v10 = aabbMin->mVec128.m128_f32[0] - absproxy->m_aabbMin.mVec128.m128_f32[0];
  v11 = aabbMin->mVec128.m128_f32[1] - absproxy->m_aabbMin.mVec128.m128_f32[1];
  v12 = aabbMin->mVec128.m128_f32[2] - absproxy->m_aabbMin.mVec128.m128_f32[2];
  v13 = this->m_prediction
      * (float)((float)(absproxy->m_aabbMax.mVec128.m128_f32[0] - absproxy->m_aabbMin.mVec128.m128_f32[0]) * 0.5);
  v14 = this->m_prediction
      * (float)((float)(absproxy->m_aabbMax.mVec128.m128_f32[1] - absproxy->m_aabbMin.mVec128.m128_f32[1]) * 0.5);
  v15 = this->m_prediction
      * (float)((float)(absproxy->m_aabbMax.mVec128.m128_f32[2] - absproxy->m_aabbMin.mVec128.m128_f32[2]) * 0.5);
  v24.mVec128.m128_f32[0] = v13;
  v24.mVec128.m128_f32[1] = v14;
  v24.mVec128.m128_u64[1] = LODWORD(v15);
  if ( v10 < 0.0 )
    v24.mVec128.m128_f32[0] = -v13;
  if ( v11 < 0.0 )
    v24.mVec128.m128_f32[1] = -v14;
  if ( v12 < 0.0 )
    v24.mVec128.m128_f32[2] = -v15;
  m_sets = (btDbvt **)this->m_sets;
  if ( btDbvt::update(this->m_sets, v9, (btDbvtAabbMm *)&volume, &v24, 0.050000001) )
  {
    ++this->m_updates_done;
LABEL_16:
    v21 = 1;
  }
  v16 = *(_DWORD *)&absproxy[1].m_collisionFilterGroup;
  if ( v16 )
    *(_DWORD *)(v16 + 56) = absproxy[1].m_multiSapParentProxy;
  else
    this->m_stageRoots[absproxy[1].m_uniqueId] = (btDbvtProxy *)absproxy[1].m_multiSapParentProxy;
  m_multiSapParentProxy = absproxy[1].m_multiSapParentProxy;
  if ( m_multiSapParentProxy )
    m_multiSapParentProxy[13] = *(_DWORD *)&absproxy[1].m_collisionFilterGroup;
  absproxy->m_aabbMin = (btVector3)v6->mVec128;
  absproxy->m_aabbMax = (btVector3)aabbMax->mVec128;
  absproxy[1].m_uniqueId = this->m_stageCurrent;
  v18 = (void **)&this->m_stageRoots[this->m_stageCurrent];
  *(_DWORD *)&absproxy[1].m_collisionFilterGroup = 0;
  absproxy[1].m_multiSapParentProxy = *v18;
  if ( *v18 )
    *((_DWORD *)*v18 + 13) = absproxy;
  *v18 = absproxy;
  if ( v21 )
  {
    v5 = !this->m_deferedcollide;
    this->m_needcleanup = 1;
    if ( v5 )
    {
      aabb_24 = (const btDbvtNode *)absproxy[1].m_clientObject;
      aabb_20 = this->m_sets[1].m_root;
      v24.mVec128.m128_i32[0] = (int)this;
      btDbvt::collideTTpersistentStack<btDbvtTreeCollider>(
        (btDbvt *)aabb_20,
        (int)&this->m_sets[1],
        aabb_20,
        aabb_24,
        (btDbvtTreeCollider *)&v24);
      btDbvt::collideTTpersistentStack<btDbvtTreeCollider>(
        *m_sets,
        (int)m_sets,
        (const btDbvtNode *)*m_sets,
        (const btDbvtNode *)absproxy[1].m_clientObject,
        (btDbvtTreeCollider *)&v24);
    }
  }
}
