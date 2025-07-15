void __userpurge btBoxBoxCollisionAlgorithm::CreateFunc::CreateCollisionAlgorithm(
        btBoxBoxCollisionAlgorithm::CreateFunc *this@<ecx>,
        btCollisionObject *a2@<edi>,
        btCollisionAlgorithmConstructionInfo *ci,
        btCollisionObject *body0,
        btCollisionObject *body1)
{
  btBoxBoxCollisionAlgorithm *v5; // esi

  v5 = (btBoxBoxCollisionAlgorithm *)ci->m_dispatcher1->allocateCollisionAlgorithm(ci->m_dispatcher1, 16);
  if ( v5 )
    btBoxBoxCollisionAlgorithm::btBoxBoxCollisionAlgorithm(v5, (btPersistentManifold *)body0, ci, a2, body1);
}
