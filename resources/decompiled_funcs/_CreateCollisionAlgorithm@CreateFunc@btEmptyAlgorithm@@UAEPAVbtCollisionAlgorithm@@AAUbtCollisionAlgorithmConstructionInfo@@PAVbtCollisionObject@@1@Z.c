btCollisionAlgorithm *__thiscall btEmptyAlgorithm::CreateFunc::CreateCollisionAlgorithm(
        btEmptyAlgorithm::CreateFunc *this,
        btCollisionAlgorithmConstructionInfo *ci,
        btCollisionObject *body0,
        btCollisionObject *body1)
{
  btCollisionAlgorithm *result; // eax

  result = (btCollisionAlgorithm *)ci->m_dispatcher1->allocateCollisionAlgorithm(ci->m_dispatcher1, 8);
  if ( !result )
    return 0;
  result->__vftable = (btCollisionAlgorithm_vtbl *)&btCollisionAlgorithm::`vftable';
  result->m_dispatcher = ci->m_dispatcher1;
  result->__vftable = (btCollisionAlgorithm_vtbl *)&btEmptyAlgorithm::`vftable';
  return result;
}
