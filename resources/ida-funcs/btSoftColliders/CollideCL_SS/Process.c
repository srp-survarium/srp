void __userpurge btSoftColliders::CollideCL_SS::Process(
        btSoftColliders::CollideCL_SS *this@<edi>,
        btSoftBody *psa@<eax>,
        btSoftBody *psb)
{
  btCollisionShape *m_collisionShape; // ecx
  double v6; // st7
  btCollisionShape *v7; // ecx
  double v8; // st7
  float *p_kDF; // eax
  const btDbvtNode *v10; // ecx
  btDbvtNode *m_root; // esi
  btCollisionShape *v12; // [esp+14h] [ebp+8h]
  float v13; // [esp+14h] [ebp+8h]

  this->idt = psa->m_sst.isdt;
  m_collisionShape = psb->m_collisionShape;
  v12 = psa->m_collisionShape;
  v6 = ((double (__thiscall *)(btCollisionShape *))m_collisionShape->getMargin)(m_collisionShape);
  v7 = v12;
  v13 = v6;
  v8 = ((double (__thiscall *)(btCollisionShape *))v7->getMargin)(v7);
  p_kDF = &psb->m_cfg.kDF;
  v10 = (const btDbvtNode *)&psa->m_cfg.kDF;
  this->m_margin = v8 + v13;
  if ( psb->m_cfg.kDF > psa->m_cfg.kDF )
    p_kDF = &psa->m_cfg.kDF;
  this->friction = *p_kDF;
  this->bodies[0] = psa;
  this->bodies[1] = psb;
  m_root = psa->m_cdbvt.m_root;
  if ( m_root )
    btDbvt::collideTT<btSoftColliders::CollideCL_SS>(
      v10,
      m_root,
      (btAlignedObjectArray<GrahamVector2> *)psb->m_cdbvt.m_root,
      this);
}


void __userpurge btSoftColliders::CollideCL_SS::Process(
        const btDbvtNode *la@<eax>,
        int a2@<ecx>,
        const btGjkEpaSolver2::sResults *this,
        const btDbvtNode *lb)
{
  btDbvtNode *v4; // esi
  btDbvtNode *v5; // edi
  btSoftBody *v6; // eax
  btConvexInternalShape_vtbl *v7; // ecx
  unsigned int v8; // xmm0_4
  unsigned int v9; // xmm2_4
  unsigned int v10; // xmm3_4
  const btTransform *v11; // eax
  btSoftBody::Joint *v12; // ecx
  const btSoftBody::CJoint *v13; // edi
  btSoftColliders::ClusterBase *v14; // ecx
  btSoftBody::CJoint *v15; // eax
  btSoftBody::CJoint *v16; // esi
  btSoftBody::CJoint *v17; // ecx
  btSoftBody *v18; // esi
  int m_capacity; // ecx
  int m_size; // eax
  btAlignedObjectArray<btSoftBody::Joint *> *p_m_joints; // esi
  int v22; // edi
  int v23; // edx
  int v24; // ecx
  _DWORD *v25; // eax
  const btSoftBody::CJoint **v26; // eax
  float *v27; // eax
  btSoftBody::Body v28; // [esp-20h] [ebp-250h]
  btSoftBody::Body v29; // [esp-14h] [ebp-244h]
  const btTransform *Identity; // [esp-Ch] [ebp-23Ch]
  btSoftBody::Joint *v31; // [esp-4h] [ebp-234h]
  const btSoftBody::CJoint *v32; // [esp+14h] [ebp-21Ch]
  _DWORD *v33; // [esp+18h] [ebp-218h]
  int v34; // [esp+1Ch] [ebp-214h]
  btVector3 guess; // [esp+20h] [ebp-210h] BYREF
  btConvexInternalShape shape0; // [esp+30h] [ebp-200h] BYREF
  btDbvtNode *v37; // [esp+70h] [ebp-1C0h]
  btConvexInternalShape shape1; // [esp+80h] [ebp-1B0h] BYREF
  btDbvtNode *v39; // [esp+C0h] [ebp-170h]
  btGjkEpaSolver2::sResults results; // [esp+D0h] [ebp-160h] BYREF
  btSoftBody::Joint v41; // [esp+120h] [ebp-110h] BYREF

  v4 = la->childs[0];
  v5 = lb->childs[0];
  v6 = (btSoftBody *)this->witnesses[0].mVec128.m128_i32[1];
  if ( v6 == (btSoftBody *)this->witnesses[0].mVec128.m128_i32[2]
    && v6->m_clusterConnectivity.m_size
    && (a2 = v6->m_clusters.m_size,
        v6->m_clusterConnectivity.m_data[a2 * v5[8].volume.mx.mVec128.m128_i32[0] + v4[8].volume.mx.mVec128.m128_i32[0]]) )
  {
    ++`btSoftColliders::CollideCL_SS::Process'::`16'::count;
  }
  else
  {
    btConvexInternalShape::btConvexInternalShape((btConvexInternalShape *)a2, &shape0);
    shape0.__vftable = (btConvexInternalShape_vtbl *)&btSoftClusterCollisionShape::`vftable';
    v37 = v4;
    shape0.m_collisionMargin = 0.0;
    btConvexInternalShape::btConvexInternalShape(
      (btConvexInternalShape *)&btSoftClusterCollisionShape::`vftable',
      &shape1);
    shape1.__vftable = v7;
    *(float *)&v8 = v4[5].volume.mi.mVec128.m128_f32[2] - v5[5].volume.mi.mVec128.m128_f32[2];
    *(float *)&v9 = v4[5].volume.mi.mVec128.m128_f32[1] - v5[5].volume.mi.mVec128.m128_f32[1];
    *(float *)&v10 = v4[5].volume.mi.mVec128.m128_f32[0] - v5[5].volume.mi.mVec128.m128_f32[0];
    v39 = v5;
    shape1.m_collisionMargin = 0.0;
    guess.mVec128.m128_u64[0] = __PAIR64__(v9, v10);
    guess.mVec128.m128_u64[1] = v8;
    Identity = btTransform::getIdentity();
    v11 = btTransform::getIdentity();
    if ( btGjkEpaSolver2::SignedDistance(&shape0, v11, &shape1, Identity, &guess, &results) )
    {
      btSoftBody::Joint::Joint(v12, (int)&v41);
      *(_QWORD *)&v29.m_rigid = (unsigned int)v5;
      v13 = 0;
      *(_QWORD *)&v28.m_rigid = (unsigned int)v4;
      v29.m_soft = 0;
      v28.m_soft = (btSoftBody::Cluster *)&results;
      v41.__vftable = (btSoftBody::Joint_vtbl *)&btSoftBody::CJoint::`vftable';
      if ( btSoftColliders::ClusterBase::SolveContact(v14, 0, this, v28, v29, 0, (int)&v41) )
      {
        v15 = (btSoftBody::CJoint *)btAlignedAllocInternal(0x110u);
        v16 = v15;
        v17 = (btSoftBody::CJoint *)v31;
        if ( v15 )
        {
          btSoftBody::Joint::Joint(v31, (int)v15);
          v16->__vftable = (btSoftBody::CJoint_vtbl *)&btSoftBody::CJoint::`vftable';
          v13 = v16;
        }
        v32 = v13;
        btSoftBody::CJoint::operator=(v17, v13, &v41);
        v18 = (btSoftBody *)this->witnesses[0].mVec128.m128_i32[1];
        m_capacity = v18->m_joints.m_capacity;
        m_size = v18->m_joints.m_size;
        p_m_joints = &v18->m_joints;
        if ( m_size == m_capacity )
        {
          if ( m_size )
            v22 = 2 * m_size;
          else
            v22 = 1;
          v34 = v22;
          if ( m_capacity < v22 )
          {
            if ( v22 )
              v33 = btAlignedAllocInternal(4 * v22);
            else
              v33 = 0;
            v23 = p_m_joints->m_size;
            v24 = 0;
            if ( v23 > 0 )
            {
              v25 = v33;
              do
              {
                if ( v25 )
                {
                  *v25 = p_m_joints->m_data[v24];
                  v22 = v34;
                }
                ++v24;
                ++v25;
              }
              while ( v24 < v23 );
            }
            if ( p_m_joints->m_data )
            {
              if ( p_m_joints->m_ownsMemory )
                btAlignedFreeInternal(p_m_joints->m_data);
              p_m_joints->m_data = 0;
            }
            p_m_joints->m_ownsMemory = 1;
            p_m_joints->m_data = (btSoftBody::Joint **)v33;
            p_m_joints->m_capacity = v22;
          }
          v13 = v32;
        }
        v26 = (const btSoftBody::CJoint **)&p_m_joints->m_data[p_m_joints->m_size];
        if ( v26 )
          *v26 = v13;
        ++p_m_joints->m_size;
        v27 = (float *)(this->witnesses[0].mVec128.m128_i32[2] + 356);
        if ( *(float *)(this->witnesses[0].mVec128.m128_i32[1] + 356) > *v27 )
          v27 = (float *)(this->witnesses[0].mVec128.m128_i32[1] + 356);
        v13->m_erp = v13->m_erp * *v27;
        v13->m_split = (float)((float)(*(float *)(this->witnesses[0].mVec128.m128_i32[1] + 368)
                                     + *(float *)(this->witnesses[0].mVec128.m128_i32[2] + 368))
                             * v13->m_split)
                     * 0.5;
      }
    }
  }
}
