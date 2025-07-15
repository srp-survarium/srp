void __thiscall btDbvtBroadphase::aabbTest(
        btDbvtBroadphase *this,
        const btVector3 *aabbMin,
        const btVector3 *aabbMax,
        btBroadphaseAabbCallback *aabbCallback)
{
  btDbvtNode *m_root; // eax
  btDbvtNode *v6; // esi
  BroadphaseAabbTester policy; // [esp+4Ch] [ebp-24h] BYREF
  btDbvtAabbMm vol; // [esp+50h] [ebp-20h] BYREF

  policy.m_aabbCallback = aabbCallback;
  vol.mi = (btVector3)aabbMin->mVec128;
  vol.mx.mVec128.m128_u64[0] = aabbMax->mVec128.m128_u64[0];
  m_root = this->m_sets[0].m_root;
  vol.mx.mVec128.m128_u64[1] = aabbMax->mVec128.m128_u64[1];
  if ( m_root )
    btDbvt::collideTV<BroadphaseAabbTester>(&vol, m_root, &policy);
  v6 = this->m_sets[1].m_root;
  if ( v6 )
    btDbvt::collideTV<BroadphaseAabbTester>(&vol, v6, &policy);
}
