void __thiscall btDbvtBroadphase::rayTest(
        btDbvtBroadphase *this,
        const btVector3 *rayFrom,
        const btVector3 *rayTo,
        btBroadphaseRayCallback *rayCallback,
        const btVector3 *aabbMin,
        const btVector3 *aabbMax)
{
  btDbvtNode *m_root; // eax
  btDbvtNode *v8; // edi
  BroadphaseRayTester depth; // [esp+1Ch] [ebp-4h] BYREF

  m_root = this->m_sets[0].m_root;
  depth.m_rayCallback = rayCallback;
  if ( m_root )
    btDbvt::rayTestInternal<BroadphaseRayTester>(
      (const btDbvtNode *)&rayCallback->m_rayDirectionInverse,
      &m_root->volume.mi,
      rayFrom,
      &rayCallback->m_rayDirectionInverse,
      (btAlignedObjectArray<GrahamVector2> *)rayCallback->m_signs,
      rayCallback->m_lambda_max,
      aabbMin,
      aabbMax,
      &depth);
  v8 = this->m_sets[1].m_root;
  if ( v8 )
    btDbvt::rayTestInternal<BroadphaseRayTester>(
      (const btDbvtNode *)this,
      &v8->volume.mi,
      rayFrom,
      &rayCallback->m_rayDirectionInverse,
      (btAlignedObjectArray<GrahamVector2> *)rayCallback->m_signs,
      rayCallback->m_lambda_max,
      aabbMin,
      aabbMax,
      &depth);
}
