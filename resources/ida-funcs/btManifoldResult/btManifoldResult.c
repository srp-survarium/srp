void __stdcall btManifoldResult::btManifoldResult(btManifoldResult *this)
{
  btCollisionObject *body0; // edx
  btCollisionObject *body1; // ecx

  this->m_body0 = body0;
  this->m_body1 = body1;
  this->__vftable = (btManifoldResult_vtbl *)&btManifoldResult::`vftable';
  this->m_manifoldPtr = 0;
  this->m_partId0 = -1;
  this->m_partId1 = -1;
  this->m_index0 = -1;
  this->m_index1 = -1;
  this->m_rootTransA = body0->m_worldTransform;
  this->m_rootTransB = body1->m_worldTransform;
}
