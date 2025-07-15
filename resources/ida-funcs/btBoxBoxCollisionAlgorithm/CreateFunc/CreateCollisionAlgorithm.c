void __thiscall btBoxBoxCollisionAlgorithm::CreateFunc::CreateCollisionAlgorithm(
        btBoxBoxCollisionAlgorithm::CreateFunc *this,
        btCollisionAlgorithmConstructionInfo *ci,
        btCollisionObject *body0,
        btCollisionObject *body1)
{
  btBoxBoxCollisionAlgorithm *v4; // esi
  btCollisionObject *v5; // [esp+0h] [ebp-8h]

  v4 = (btBoxBoxCollisionAlgorithm *)ci->m_dispatcher1->allocateCollisionAlgorithm(ci->m_dispatcher1, 16);
  if ( v4 )
    btBoxBoxCollisionAlgorithm::btBoxBoxCollisionAlgorithm(v4, ci, body0, body1, v5);
}
