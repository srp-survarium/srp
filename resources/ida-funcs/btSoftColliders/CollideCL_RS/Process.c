void __userpurge btSoftColliders::CollideCL_RS::Process(
        btCollisionObject *colOb@<eax>,
        btSoftColliders::CollideCL_RS *this,
        btSoftBody *ps)
{
  btCollisionShape *m_collisionShape; // edi
  double v5; // st7
  btCollisionObject *m_colObj; // eax
  float m_friction; // xmm0_4
  float *p_kDF; // eax
  bool v9; // cc
  float m_margin; // xmm0_4
  btDbvtNode *m_root; // eax
  float v12; // [esp+Ch] [ebp-64h] BYREF
  float v13[4]; // [esp+10h] [ebp-60h] BYREF
  _DWORD v14[4]; // [esp+20h] [ebp-50h] BYREF
  btDbvtAabbMm vol; // [esp+30h] [ebp-40h] BYREF
  _DWORD v16[8]; // [esp+50h] [ebp-20h] BYREF

  this->psb = ps;
  this->m_colObj = colOb;
  this->idt = ps->m_sst.isdt;
  m_collisionShape = ps->m_collisionShape;
  v12 = colOb->m_collisionShape->getMargin(colOb->m_collisionShape);
  v5 = ((double (__thiscall *)(btCollisionShape *))m_collisionShape->getMargin)(m_collisionShape);
  m_colObj = this->m_colObj;
  this->m_margin = v5 + v12;
  m_friction = m_colObj->m_friction;
  p_kDF = &this->psb->m_cfg.kDF;
  v9 = m_friction <= *p_kDF;
  v12 = m_friction;
  if ( v9 )
    p_kDF = &v12;
  this->friction = *p_kDF;
  colOb->m_collisionShape->getAabb(
    colOb->m_collisionShape,
    &colOb->m_worldTransform,
    (btVector3 *)v13,
    (btVector3 *)v14);
  *(float *)v16 = v13[0];
  *(float *)&v16[1] = v13[1];
  m_margin = this->m_margin;
  *(float *)&v16[2] = v13[2];
  *(float *)&v16[3] = v13[3];
  v16[4] = v14[0];
  m_root = ps->m_cdbvt.m_root;
  v16[5] = v14[1];
  v16[6] = v14[2];
  v16[7] = v14[3];
  qmemcpy(&vol, v16, sizeof(vol));
  vol.mi.mVec128.m128_f32[0] = v13[0] - m_margin;
  vol.mi.mVec128.m128_f32[1] = vol.mi.mVec128.m128_f32[1] - m_margin;
  vol.mi.mVec128.m128_f32[2] = vol.mi.mVec128.m128_f32[2] - m_margin;
  vol.mx.mVec128.m128_f32[1] = vol.mx.mVec128.m128_f32[1] + m_margin;
  vol.mx.mVec128.m128_f32[0] = vol.mx.mVec128.m128_f32[0] + m_margin;
  vol.mx.mVec128.m128_f32[2] = vol.mx.mVec128.m128_f32[2] + m_margin;
  if ( m_root )
    btDbvt::collideTV<btSoftColliders::CollideCL_RS>(&vol, m_root, this);
}


void __usercall btSoftColliders::CollideCL_RS::Process(
        btSoftColliders::CollideCL_RS *this@<edi>,
        const btDbvtNode *leaf@<eax>,
        btConvexInternalShape *a3@<ecx>)
{
  btDbvtNode *v3; // esi
  btCollisionObject *m_colObj; // eax
  const btTransform *Identity; // eax
  btSoftBody::Joint *v6; // ecx
  btCollisionObject *v7; // ecx
  btSoftBody::CJoint *v8; // eax
  btSoftBody::CJoint *v9; // esi
  btSoftBody::CJoint *v10; // ecx
  const btSoftBody::CJoint *v11; // ebx
  btSoftBody *psb; // esi
  int m_capacity; // ecx
  int m_size; // eax
  btAlignedObjectArray<btSoftBody::Joint *> *p_m_joints; // esi
  int v16; // ecx
  _DWORD *v17; // eax
  const btSoftBody::CJoint **v18; // eax
  btSoftBody *v19; // eax
  float kSK_SPLT_CL; // xmm0_4
  btSoftBody::Body v21; // [esp-20h] [ebp-200h]
  btSoftBody::Body v22; // [esp-14h] [ebp-1F4h]
  const btConvexShape *m_collisionShape; // [esp-10h] [ebp-1F0h]
  const btTransform *p_m_worldTransform; // [esp-Ch] [ebp-1ECh]
  btSoftBody::Joint *v25; // [esp-4h] [ebp-1E4h]
  int v26; // [esp+14h] [ebp-1CCh]
  _DWORD *v27; // [esp+18h] [ebp-1C8h]
  int v28; // [esp+1Ch] [ebp-1C4h]
  btVector3 guess; // [esp+20h] [ebp-1C0h] BYREF
  btConvexInternalShape shape0; // [esp+30h] [ebp-1B0h] BYREF
  btDbvtNode *v31; // [esp+70h] [ebp-170h]
  btGjkEpaSolver2::sResults results; // [esp+80h] [ebp-160h] BYREF
  btSoftBody::Joint v33; // [esp+D0h] [ebp-110h] BYREF

  v3 = leaf->childs[0];
  btConvexInternalShape::btConvexInternalShape(a3, &shape0);
  m_colObj = this->m_colObj;
  shape0.__vftable = (btConvexInternalShape_vtbl *)&btSoftClusterCollisionShape::`vftable';
  v31 = v3;
  shape0.m_collisionMargin = 0.0;
  if ( (m_colObj->m_collisionFlags & 3) == 0 || !v3[8].volume.mi.mVec128.m128_i8[12] )
  {
    p_m_worldTransform = &m_colObj->m_worldTransform;
    m_collisionShape = (const btConvexShape *)m_colObj->m_collisionShape;
    guess.mVec128.m128_u64[0] = LODWORD(s_bm_current_air_resistance);
    guess.mVec128.m128_u64[1] = 0;
    Identity = btTransform::getIdentity();
    if ( btGjkEpaSolver2::SignedDistance(&shape0, Identity, m_collisionShape, p_m_worldTransform, &guess, &results) )
    {
      btSoftBody::Joint::Joint(v6, (int)&v33);
      v7 = this->m_colObj;
      v22.m_collisionObject = (v7->m_internalType & 2) != 0 ? v7 : 0;
      *(_QWORD *)&v22.m_soft = 0;
      *(_QWORD *)&v21.m_rigid = (unsigned int)v3;
      v21.m_soft = (btSoftBody::Cluster *)&results;
      v33.__vftable = (btSoftBody::Joint_vtbl *)&btSoftBody::CJoint::`vftable';
      if ( btSoftColliders::ClusterBase::SolveContact(
             (btSoftColliders::ClusterBase *)v7,
             (const btVector3 *)this,
             (const btGjkEpaSolver2::sResults *)this,
             v21,
             v22,
             (btSoftBody::CJoint *)v7,
             (int)&v33) )
      {
        v8 = (btSoftBody::CJoint *)btAlignedAllocInternal(0x110u);
        v9 = v8;
        v10 = (btSoftBody::CJoint *)v25;
        if ( v8 )
        {
          btSoftBody::Joint::Joint(v25, (int)v8);
          v9->__vftable = (btSoftBody::CJoint_vtbl *)&btSoftBody::CJoint::`vftable';
          v11 = v9;
        }
        else
        {
          v11 = 0;
        }
        btSoftBody::CJoint::operator=(v10, v11, &v33);
        psb = this->psb;
        m_capacity = psb->m_joints.m_capacity;
        m_size = psb->m_joints.m_size;
        p_m_joints = &psb->m_joints;
        if ( m_size == m_capacity )
        {
          v26 = m_size ? 2 * m_size : 1;
          if ( m_capacity < v26 )
          {
            if ( v26 )
              v27 = btAlignedAllocInternal(4 * v26);
            else
              v27 = 0;
            v16 = 0;
            v28 = p_m_joints->m_size;
            if ( v28 > 0 )
            {
              v17 = v27;
              do
              {
                if ( v17 )
                  *v17 = p_m_joints->m_data[v16];
                ++v16;
                ++v17;
              }
              while ( v16 < v28 );
            }
            if ( p_m_joints->m_data )
            {
              if ( p_m_joints->m_ownsMemory )
                btAlignedFreeInternal(p_m_joints->m_data);
              p_m_joints->m_data = 0;
            }
            p_m_joints->m_data = (btSoftBody::Joint **)v27;
            p_m_joints->m_ownsMemory = 1;
            p_m_joints->m_capacity = v26;
          }
        }
        v18 = (const btSoftBody::CJoint **)&p_m_joints->m_data[p_m_joints->m_size];
        if ( v18 )
          *v18 = v11;
        ++p_m_joints->m_size;
        v19 = this->psb;
        if ( (this->m_colObj->m_collisionFlags & 3) != 0 )
        {
          v11->m_erp = v19->m_cfg.kSKHR_CL * v11->m_erp;
          kSK_SPLT_CL = this->psb->m_cfg.kSK_SPLT_CL;
        }
        else
        {
          v11->m_erp = v19->m_cfg.kSRHR_CL * v11->m_erp;
          kSK_SPLT_CL = this->psb->m_cfg.kSR_SPLT_CL;
        }
        v11->m_split = kSK_SPLT_CL * v11->m_split;
      }
    }
  }
}
