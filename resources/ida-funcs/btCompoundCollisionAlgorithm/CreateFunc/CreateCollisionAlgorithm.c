void __thiscall btCompoundCollisionAlgorithm::CreateFunc::CreateCollisionAlgorithm(
        btCompoundCollisionAlgorithm::CreateFunc *this,
        btCollisionAlgorithmConstructionInfo *ci,
        btCollisionObject *body0,
        btCollisionObject *body1)
{
  btCompoundCollisionAlgorithm *v4; // eax

  v4 = (btCompoundCollisionAlgorithm *)ci->m_dispatcher1->allocateCollisionAlgorithm(ci->m_dispatcher1, 44);
  if ( v4 )
    btCompoundCollisionAlgorithm::btCompoundCollisionAlgorithm(v4, body0, body1);
}
