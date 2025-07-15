void __usercall btSoftBody::defaultCollisionHandler(btSoftBody *this@<esi>, btSoftBody *psb@<eax>)
{
  int collisions; // ecx
  int v4; // eax
  btCollisionShape *m_collisionShape; // ebx
  const btDbvtNode *v6; // ecx
  double v7; // st7
  btDbvtNode *m_root; // eax
  btDbvtNode *v9; // edi
  float v10; // [esp+Ch] [ebp-2Ch]
  btSoftBody *v11; // [esp+10h] [ebp-28h] BYREF
  btSoftBody *v12; // [esp+14h] [ebp-24h]
  float v13; // [esp+18h] [ebp-20h]
  btSoftColliders::CollideCL_SS v14; // [esp+1Ch] [ebp-1Ch] BYREF

  collisions = psb->m_cfg.collisions;
  v4 = (unsigned __int8)collisions & (unsigned __int8)this->m_cfg.collisions & 0x30;
  if ( v4 == 16 )
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
          (btAlignedObjectArray<GrahamVector2> *)psb->m_fdbvt.m_root,
          (btSoftColliders::CollideVF_SS *)&v11);
      v11 = psb;
      v9 = psb->m_ndbvt.m_root;
      v12 = this;
      if ( v9 )
        btDbvt::collideTT<btSoftColliders::CollideVF_SS>(
          v6,
          v9,
          (btAlignedObjectArray<GrahamVector2> *)this->m_fdbvt.m_root,
          (btSoftColliders::CollideVF_SS *)&v11);
    }
  }
  else if ( v4 == 32 && (this != psb || (collisions & 0x40) != 0) )
  {
    v14.erp = s_bm_current_air_resistance;
    memset(&v14.idt, 0, 16);
    btSoftColliders::CollideCL_SS::Process(&v14, this, psb);
  }
}


void __thiscall btSoftBody::defaultCollisionHandler(btSoftBody *this, btSoftBody *pco, int a3)
{
  int v3; // ebx
  btCollisionShape *m_collisionShape; // ecx
  btCollisionShape_vtbl *v5; // eax
  btDbvtNode *m_root; // eax
  float v7; // [esp+Ch] [ebp-B4h]
  float v8; // [esp+10h] [ebp-B0h]
  float v9; // [esp+14h] [ebp-ACh]
  float v10; // [esp+18h] [ebp-A8h]
  btSoftBody::Node policy; // [esp+20h] [ebp-A0h] BYREF
  float v12; // [esp+90h] [ebp-30h]
  float v13; // [esp+94h] [ebp-2Ch]
  float v14; // [esp+98h] [ebp-28h]
  int v15; // [esp+9Ch] [ebp-24h]
  float v16[4]; // [esp+A0h] [ebp-20h] BYREF
  btVector3 v17; // [esp+B0h] [ebp-10h] BYREF

  if ( (pco->m_cfg.collisions & 0xF) == 1 )
  {
    v3 = (*(_BYTE *)(a3 + 244) & 2) != 0 ? a3 : 0;
    v12 = *(float *)(a3 + 64);
    v13 = *(float *)(a3 + 68);
    v14 = *(float *)(a3 + 72);
    m_collisionShape = pco->m_collisionShape;
    v15 = *(_DWORD *)(a3 + 76);
    v5 = m_collisionShape->__vftable;
    policy.m_v = *(btVector3 *)(a3 + 64);
    v8 = v12 - policy.m_v.mVec128.m128_f32[0];
    v9 = v13 - policy.m_v.mVec128.m128_f32[1];
    v10 = v14 - policy.m_v.mVec128.m128_f32[2];
    v7 = v5->getMargin(m_collisionShape);
    (*(void (__thiscall **)(_DWORD, int, float *, btVector3 *))(**(_DWORD **)(a3 + 204) + 4))(
      *(_DWORD *)(a3 + 204),
      a3 + 16,
      v16,
      &v17);
    *(float *)&policy.m_tag = v16[0];
    *(float *)&policy.m_material = v16[1];
    *((float *)&policy.btSoftBody::Feature + 2) = v16[2];
    *((float *)&policy.btSoftBody::Feature + 3) = v16[3];
    policy.m_x = (btVector3)v17.mVec128;
    qmemcpy(&policy.m_f, &policy, 0x20u);
    policy.m_f.mVec128.m128_f32[0] = v16[0] - v7;
    policy.m_f.mVec128.m128_f32[1] = policy.m_f.mVec128.m128_f32[1] - v7;
    policy.m_f.mVec128.m128_f32[2] = policy.m_f.mVec128.m128_f32[2] - v7;
    policy.m_tag = pco;
    policy.m_n.mVec128.m128_f32[0] = policy.m_n.mVec128.m128_f32[0] + v7;
    policy.m_n.mVec128.m128_f32[1] = policy.m_n.mVec128.m128_f32[1] + v7;
    policy.m_n.mVec128.m128_f32[2] = policy.m_n.mVec128.m128_f32[2] + v7;
    policy.m_x.mVec128.m128_f32[0] = v7;
    m_root = pco->m_ndbvt.m_root;
    policy.m_material = (btSoftBody::Material *)a3;
    *((_DWORD *)&policy.btSoftBody::Feature + 2) = v3;
    *((float *)&policy.btSoftBody::Feature + 3) = fsqrt((float)((float)(v10 * v10) + (float)(v9 * v9)) + (float)(v8 * v8))
                                                + v7;
    if ( m_root )
      btDbvt::collideTV<btSoftColliders::CollideSDF_RS>((const btDbvtAabbMm *)&policy.m_f, m_root, &policy);
  }
  else if ( (pco->m_cfg.collisions & 0xF) == 2 )
  {
    *(float *)&policy.m_tag = s_bm_current_air_resistance;
    memset(&policy.m_material, 0, 16);
    btSoftColliders::CollideCL_RS::Process((btCollisionObject *)a3, (btSoftColliders::CollideCL_RS *)&policy, pco);
  }
}
