void __userpurge btSoftColliders::CollideCL_SS::Process(
        btSoftColliders::CollideCL_SS *this@<esi>,
        btSoftBody *psa@<eax>,
        btSoftBody *psb)
{
  btCollisionShape *m_collisionShape; // ebx
  double v6; // st7
  float *p_kDF; // eax
  const btDbvtNode *v8; // ecx
  double v9; // st7
  btDbvtNode *m_root; // edi
  float psba; // [esp+14h] [ebp+4h]

  this->idt = psa->m_sst.isdt;
  m_collisionShape = psa->m_collisionShape;
  psba = psb->m_collisionShape->getMargin(psb->m_collisionShape);
  v6 = ((double (__thiscall *)(btCollisionShape *))m_collisionShape->getMargin)(m_collisionShape);
  p_kDF = &psb->m_cfg.kDF;
  v8 = (const btDbvtNode *)&psa->m_cfg.kDF;
  this->m_margin = v6 + psba;
  if ( psb->m_cfg.kDF > psa->m_cfg.kDF )
    p_kDF = &psa->m_cfg.kDF;
  v9 = *p_kDF;
  this->bodies[0] = psa;
  this->friction = v9;
  this->bodies[1] = psb;
  m_root = psa->m_cdbvt.m_root;
  if ( m_root )
    btDbvt::collideTT<btSoftColliders::CollideCL_SS>(v8, m_root, (btSoftColliders::CollideCL_SS *)psb->m_cdbvt.m_root);
}
