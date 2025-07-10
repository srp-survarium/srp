void __usercall btSoftBody::defaultCollisionHandler(btSoftBody *this@<ecx>, btSoftBody *psb@<eax>)
{
  int collisions; // ecx
  int v5; // eax
  btCollisionShape *m_collisionShape; // ebx
  double v7; // st7
  btDbvtNode *m_root; // eax
  btDbvtNode *v9; // edi
  float v10; // [esp+Ch] [ebp-2Ch]
  btSoftBody *v11; // [esp+10h] [ebp-28h] BYREF
  btSoftBody *v12; // [esp+14h] [ebp-24h]
  float v13; // [esp+18h] [ebp-20h]
  btSoftColliders::CollideCL_SS docollide; // [esp+1Ch] [ebp-1Ch] BYREF

  collisions = psb->m_cfg.collisions;
  v5 = (unsigned __int8)collisions & (unsigned __int8)this->m_cfg.collisions & 0x30;
  if ( v5 == 16 )
  {
    if ( this != psb )
    {
      m_collisionShape = psb->m_collisionShape;
      v10 = this->m_collisionShape->getMargin(this->m_collisionShape);
      v7 = ((double (__thiscall *)(btCollisionShape *))m_collisionShape->getMargin)(m_collisionShape);
      m_root = this->m_ndbvt.m_root;
      v11 = this;
      v13 = v7 + v10;
      v12 = psb;
      if ( m_root )
        btDbvt::collideTT<btSoftColliders::CollideVF_SS>(
          (const btDbvtNode *)&v11,
          m_root,
          psb->m_fdbvt.m_root,
          (btSoftColliders::CollideVF_SS *)&v11);
      v11 = psb;
      v9 = psb->m_ndbvt.m_root;
      v12 = this;
      if ( v9 )
        btDbvt::collideTT<btSoftColliders::CollideVF_SS>(
          this->m_fdbvt.m_root,
          v9,
          this->m_fdbvt.m_root,
          (btSoftColliders::CollideVF_SS *)&v11);
    }
  }
  else if ( v5 == 32 && (this != psb || (collisions & 0x40) != 0) )
  {
    LODWORD(docollide.erp) = clear_value;
    memset(&docollide.idt, 0, 16);
    btSoftColliders::CollideCL_SS::Process(&docollide, this, psb);
  }
}
