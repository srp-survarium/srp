btManifoldResult *__userpurge btManifoldResult::btManifoldResult@<eax>(
        btManifoldResult *this@<ecx>,
        btManifoldResult *result@<eax>,
        btCollisionObject *body0,
        btCollisionObject *body1)
{
  result->m_manifoldPtr = 0;
  result->m_body0 = (btCollisionObject *)this;
  result->__vftable = (btManifoldResult_vtbl *)&btManifoldResult::`vftable';
  result->m_body1 = body0;
  result->m_partId0 = -1;
  result->m_partId1 = -1;
  result->m_index0 = -1;
  result->m_index1 = -1;
  result->m_rootTransA = this->m_rootTransA;
  result->m_rootTransB = body0->m_worldTransform;
  return result;
}
