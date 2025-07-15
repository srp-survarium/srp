void __thiscall btDbvtBroadphase::aabbTest(
        btDbvtBroadphase *this,
        const btVector3 *aabbMin,
        const btVector3 *aabbMax,
        btBroadphaseAabbCallback *aabbCallback)
{
  btDbvtNode *m_root; // eax
  btDbvtNode *v6; // ebx
  BroadphaseAabbTester policy; // [esp+Ch] [ebp-24h] BYREF
  btDbvtAabbMm vol; // [esp+10h] [ebp-20h] BYREF

  vol.mi = (btVector3)aabbMin->mVec128;
  vol.mx.mVec128.m128_u64[0] = aabbMax->mVec128.m128_u64[0];
  vol.mx.mVec128.m128_i32[2] = aabbMax->mVec128.m128_i32[2];
  policy.m_aabbCallback = aabbCallback;
  m_root = this->m_sets[0].m_root;
  vol.mx.mVec128.m128_i32[3] = aabbMax->mVec128.m128_i32[3];
  if ( m_root )
    btDbvt::collideTV<BroadphaseAabbTester>(&vol, (btAlignedObjectArray<GrahamVector2> *)m_root, &policy);
  v6 = this->m_sets[1].m_root;
  if ( v6 )
    btDbvt::collideTV<BroadphaseAabbTester>(&vol, (btAlignedObjectArray<GrahamVector2> *)v6, &policy);
}
