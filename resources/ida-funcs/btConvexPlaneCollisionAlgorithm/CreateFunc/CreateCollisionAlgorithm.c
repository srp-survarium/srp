void __thiscall btConvexPlaneCollisionAlgorithm::CreateFunc::CreateCollisionAlgorithm(
        btConvexPlaneCollisionAlgorithm::CreateFunc *this,
        btCollisionAlgorithmConstructionInfo *ci,
        btCollisionObject *body0,
        btCollisionObject *body1)
{
  btConvexPlaneCollisionAlgorithm *v5; // esi
  bool v6; // al
  int v7; // [esp+0h] [ebp-Ch]

  v5 = (btConvexPlaneCollisionAlgorithm *)ci->m_dispatcher1->allocateCollisionAlgorithm(ci->m_dispatcher1, 28);
  if ( this->m_swapped )
  {
    if ( !v5 )
      return;
    v6 = 1;
  }
  else
  {
    if ( !v5 )
      return;
    v6 = 0;
  }
  btConvexPlaneCollisionAlgorithm::btConvexPlaneCollisionAlgorithm(
    v5,
    ci,
    v6,
    body0,
    body1,
    (btCollisionObject *)this->m_numPerturbationIterations,
    this->m_minimumPointsPerturbationThreshold,
    v7);
}
