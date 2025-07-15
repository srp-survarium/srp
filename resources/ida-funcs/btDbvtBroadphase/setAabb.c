void __thiscall btDbvtBroadphase::setAabb(
        btDbvtBroadphase *this,
        int absproxy,
        const btVector3 *aabbMin,
        const btVector3 *aabbMax,
        btDispatcher *__formal)
{
  bool v5; // zf
  btDbvtNode *v6; // eax
  float v7; // xmm4_4
  float v8; // xmm5_4
  float v9; // xmm6_4
  float v10; // xmm0_4
  float v11; // xmm2_4
  float m_prediction; // xmm3_4
  float v13; // xmm7_4
  float v14; // xmm1_4
  float v15; // xmm3_4
  btDbvtBroadphase *pbp; // eax
  int m_stageCurrent; // ecx
  btDbvt *v18; // ecx
  btDbvt *v19; // ecx
  char v20; // [esp+17h] [ebp-4Dh]
  btDbvtTreeCollider policy; // [esp+18h] [ebp-4Ch] BYREF
  btDbvt *m_sets; // [esp+20h] [ebp-44h]
  btVector3 v23; // [esp+24h] [ebp-40h] BYREF
  float v24; // [esp+38h] [ebp-2Ch]
  __m128 v25; // [esp+44h] [ebp-20h] BYREF
  __m128 v26; // [esp+54h] [ebp-10h]

  v25.m128_u64[0] = aabbMin->mVec128.m128_u64[0];
  v5 = *(_DWORD *)(absproxy + 60) == 2;
  v25.m128_u64[1] = aabbMin->mVec128.m128_u64[1];
  v26.m128_u64[0] = aabbMax->mVec128.m128_u64[0];
  v26.m128_i32[2] = aabbMax->mVec128.m128_i32[2];
  policy.pbp = this;
  v26.m128_i32[3] = aabbMax->mVec128.m128_i32[3];
  v20 = 0;
  if ( v5 )
  {
    btDbvt::remove(&this->m_sets[1], *(btDbvtNode **)(absproxy + 48));
    m_sets = policy.pbp->m_sets;
    *(_DWORD *)(absproxy + 48) = btDbvt::insert((btDbvt *)&v25, policy.pbp->m_sets, &v25, absproxy);
LABEL_14:
    v20 = 1;
    goto LABEL_15;
  }
  ++this->m_updates_call;
  v6 = *(btDbvtNode **)(absproxy + 48);
  v23.mVec128 = _mm_or_ps(_mm_cmplt_ps(v6->volume.mx.mVec128, v25), _mm_cmplt_ps(v26, v6->volume.mi.mVec128));
  if ( v23.mVec128.m128_i32[2] | v23.mVec128.m128_i32[1] | v23.mVec128.m128_i32[0] )
  {
    m_sets = this->m_sets;
    btDbvt::update(m_sets, m_sets, v6, &v25);
LABEL_13:
    ++policy.pbp->m_updates_done;
    goto LABEL_14;
  }
  v7 = aabbMin->mVec128.m128_f32[0] - *(float *)(absproxy + 16);
  v8 = aabbMin->mVec128.m128_f32[1] - *(float *)(absproxy + 20);
  v9 = aabbMin->mVec128.m128_f32[2] - *(float *)(absproxy + 24);
  v10 = (float)(*(float *)(absproxy + 32) - *(float *)(absproxy + 16)) * 0.5;
  v11 = (float)(*(float *)(absproxy + 40) - *(float *)(absproxy + 24)) * 0.5;
  m_prediction = this->m_prediction;
  v24 = (float)(*(float *)(absproxy + 36) - *(float *)(absproxy + 20)) * 0.5;
  v13 = m_prediction * v10;
  v14 = m_prediction * v24;
  v15 = m_prediction * v11;
  v23.mVec128.m128_u64[0] = __PAIR64__(LODWORD(v14), LODWORD(v13));
  v23.mVec128.m128_u64[1] = LODWORD(v15);
  if ( v7 < 0.0 )
    v23.mVec128.m128_i32[0] = LODWORD(v13) ^ _mask__NegFloat_;
  if ( v8 < 0.0 )
    v23.mVec128.m128_i32[1] = LODWORD(v14) ^ _mask__NegFloat_;
  if ( v9 < 0.0 )
    v23.mVec128.m128_i32[2] = LODWORD(v15) ^ _mask__NegFloat_;
  m_sets = this->m_sets;
  if ( btDbvt::update((btDbvtAabbMm *)&v25, &v23, this->m_sets, (btDbvt *)v6, 0.050000001) )
    goto LABEL_13;
LABEL_15:
  listremove_btDbvtProxy_((btDbvtProxy *)absproxy, &policy.pbp->m_stageRoots[*(_DWORD *)(absproxy + 60)]);
  *(_QWORD *)(absproxy + 16) = aabbMin->mVec128.m128_u64[0];
  *(_DWORD *)(absproxy + 24) = aabbMin->mVec128.m128_i32[2];
  pbp = policy.pbp;
  *(_DWORD *)(absproxy + 28) = aabbMin->mVec128.m128_i32[3];
  *(btVector3 *)(absproxy + 32) = (btVector3)aabbMax->mVec128;
  *(_DWORD *)(absproxy + 60) = pbp->m_stageCurrent;
  m_stageCurrent = pbp->m_stageCurrent;
  *(_DWORD *)(absproxy + 52) = 0;
  v18 = (btDbvt *)&pbp->m_stageRoots[m_stageCurrent];
  *(_DWORD *)(absproxy + 56) = v18->m_root;
  if ( v18->m_root )
    v18->m_root[1].volume.mi.mVec128.m128_i32[1] = absproxy;
  v18->m_root = (btDbvtNode *)absproxy;
  if ( v20 )
  {
    v5 = !pbp->m_deferedcollide;
    pbp->m_needcleanup = 1;
    if ( v5 )
    {
      policy.pbp = pbp;
      btDbvt::collideTTpersistentStack<btDbvtTreeCollider>(
        v18,
        (int)&pbp->m_sets[1],
        pbp->m_sets[1].m_root,
        *(const btDbvtNode **)(absproxy + 48),
        &policy);
      btDbvt::collideTTpersistentStack<btDbvtTreeCollider>(
        v19,
        (int)m_sets,
        m_sets->m_root,
        *(const btDbvtNode **)(absproxy + 48),
        &policy);
    }
  }
}
