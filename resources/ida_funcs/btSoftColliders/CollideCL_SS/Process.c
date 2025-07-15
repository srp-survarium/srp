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


void __userpurge btSoftColliders::CollideCL_SS::Process(
        const btDbvtNode *la@<eax>,
        const btDbvtNode *lb@<ecx>,
        btSoftColliders::CollideCL_SS *this)
{
  btSoftBody::Cluster *v3; // ebx
  btSoftBody::Cluster *v4; // esi
  btSoftBody *v5; // eax
  unsigned int v6; // xmm2_4
  unsigned int v7; // xmm3_4
  unsigned int v8; // xmm0_4
  const btTransform *Identity; // edi
  btSoftBody::CJoint *v10; // ecx
  btSoftBody::CJoint *v11; // eax
  btSoftColliders::CollideCL_SS *v12; // ebx
  btSoftBody *v13; // edi
  int m_capacity; // ecx
  int m_size; // eax
  btAlignedObjectArray<btSoftBody::Joint *> *p_m_joints; // edi
  int v17; // esi
  int v18; // edx
  int v19; // eax
  const btTransform *v20; // ecx
  btSoftBody::Joint **m_data; // eax
  btSoftBody::CJoint **v22; // eax
  btSoftBody *v23; // ecx
  float kSSHR_CL; // xmm0_4
  float *p_kSSHR_CL; // ecx
  float *v26; // eax
  btSoftBody::Body v27; // [esp+A2Ch] [ebp-24Ch]
  btSoftBody::Body v28; // [esp+A38h] [ebp-240h]
  const btTransform *wtrs1; // [esp+A60h] [ebp-218h]
  const btTransform *wtrs1a; // [esp+A60h] [ebp-218h]
  btSoftBody::CJoint *v31; // [esp+A64h] [ebp-214h]
  btVector3 guess; // [esp+A68h] [ebp-210h] BYREF
  btConvexShape shape1; // [esp+A78h] [ebp-200h] BYREF
  const vostok::math::float4x4 *v34; // [esp+A88h] [ebp-1F0h]
  const vostok::math::float4x4 *v35; // [esp+A8Ch] [ebp-1ECh]
  const vostok::math::float4x4 *v36; // [esp+A90h] [ebp-1E8h]
  int v37; // [esp+A94h] [ebp-1E4h]
  int v38; // [esp+AA8h] [ebp-1D0h]
  btSoftBody::Cluster *v39; // [esp+AB8h] [ebp-1C0h]
  btConvexShape shape0; // [esp+AC8h] [ebp-1B0h] BYREF
  const vostok::math::float4x4 *v41; // [esp+AD8h] [ebp-1A0h]
  const vostok::math::float4x4 *v42; // [esp+ADCh] [ebp-19Ch]
  const vostok::math::float4x4 *v43; // [esp+AE0h] [ebp-198h]
  int v44; // [esp+AE4h] [ebp-194h]
  int v45; // [esp+AF8h] [ebp-180h]
  btSoftBody::Cluster *v46; // [esp+B08h] [ebp-170h]
  btGjkEpaSolver2::sResults results; // [esp+B18h] [ebp-160h] BYREF
  btSoftBody::CJoint __that; // [esp+B68h] [ebp-110h] BYREF

  v3 = (btSoftBody::Cluster *)la->childs[0];
  v4 = (btSoftBody::Cluster *)lb->childs[0];
  v5 = this->bodies[0];
  if ( v5 == this->bodies[1]
    && v5->m_clusterConnectivity.m_size
    && v5->m_clusterConnectivity.m_data[v5->m_clusters.m_size * v4->m_clusterIndex + v3->m_clusterIndex] )
  {
    ++`btSoftColliders::CollideCL_SS::Process'::`16'::count;
  }
  else
  {
    *(float *)&v6 = v3->m_com.mVec128.m128_f32[1] - v4->m_com.mVec128.m128_f32[1];
    *(float *)&v7 = v3->m_com.mVec128.m128_f32[0] - v4->m_com.mVec128.m128_f32[0];
    v41 = clear_value;
    v42 = clear_value;
    v43 = clear_value;
    v34 = clear_value;
    v35 = clear_value;
    v36 = clear_value;
    *(float *)&v8 = v3->m_com.mVec128.m128_f32[2] - v4->m_com.mVec128.m128_f32[2];
    shape0.m_shapeType = 35;
    shape0.m_userPointer = 0;
    v44 = 0;
    shape0.__vftable = (btConvexShape_vtbl *)&btSoftClusterCollisionShape::`vftable';
    v46 = v3;
    v45 = 0;
    shape1.m_shapeType = 35;
    shape1.m_userPointer = 0;
    v37 = 0;
    shape1.__vftable = (btConvexShape_vtbl *)&btSoftClusterCollisionShape::`vftable';
    v39 = v4;
    v38 = 0;
    guess.mVec128.m128_u64[0] = __PAIR64__(v6, v7);
    guess.mVec128.m128_u64[1] = v8;
    wtrs1 = btTransform::getIdentity();
    Identity = btTransform::getIdentity();
    if ( btGjkEpaSolver2::Distance(&shape0, Identity, &shape1, wtrs1, &guess, &results)
      || btGjkEpaSolver2::Penetration(&shape0, Identity, &shape1, wtrs1, &guess, &results, 0) )
    {
      __that.__vftable = (btSoftBody::CJoint_vtbl *)&btSoftBody::Joint::`vftable';
      `vector constructor iterator'(
        (char *)__that.m_bodies,
        0xCu,
        2,
        (void *(__thiscall *)(void *))vostok::render::vector<vostok::render::lpv_render_surface>::vector<vostok::render::lpv_render_surface>);
      __that.m_delete = 0;
      __that.__vftable = (btSoftBody::CJoint_vtbl *)&btSoftBody::CJoint::`vftable';
      v28.m_soft = v4;
      *(_QWORD *)&v28.m_rigid = 0;
      v27.m_soft = v3;
      *(_QWORD *)&v27.m_rigid = 0;
      if ( btSoftColliders::ClusterBase::SolveContact(&results, this, v27, v28, &__that) )
      {
        ++gNumAlignedAllocs;
        if ( sAlignedAllocFunc(0x110u, 16) )
        {
          btSoftBody::CJoint::CJoint(v10);
          v31 = v11;
          btSoftBody::CJoint::operator=(v11, &__that);
        }
        else
        {
          v31 = 0;
          btSoftBody::CJoint::operator=(0, &__that);
        }
        v12 = this;
        v13 = this->bodies[0];
        m_capacity = v13->m_joints.m_capacity;
        m_size = v13->m_joints.m_size;
        p_m_joints = &v13->m_joints;
        if ( m_size == m_capacity )
        {
          v17 = 2 * m_size;
          if ( !m_size )
            v17 = 1;
          if ( m_capacity < v17 )
          {
            if ( v17 )
            {
              ++gNumAlignedAllocs;
              wtrs1a = (const btTransform *)sAlignedAllocFunc(4 * v17, 16);
            }
            else
            {
              wtrs1a = 0;
            }
            v18 = p_m_joints->m_size;
            v19 = 0;
            if ( v18 > 0 )
            {
              v20 = wtrs1a;
              do
              {
                if ( v20 )
                {
                  v20->m_basis.m_el[0].mVec128.m128_i32[0] = (int)p_m_joints->m_data[v19];
                  v12 = this;
                }
                ++v19;
                v20 = (const btTransform *)((char *)v20 + 4);
              }
              while ( v19 < v18 );
            }
            m_data = p_m_joints->m_data;
            if ( m_data )
            {
              if ( p_m_joints->m_ownsMemory )
              {
                ++gNumAlignedFree;
                sAlignedFreeFunc(m_data);
              }
              p_m_joints->m_data = 0;
            }
            p_m_joints->m_ownsMemory = 1;
            p_m_joints->m_data = (btSoftBody::Joint **)wtrs1a;
            p_m_joints->m_capacity = v17;
          }
        }
        v22 = (btSoftBody::CJoint **)&p_m_joints->m_data[p_m_joints->m_size];
        if ( v22 )
          *v22 = v31;
        ++p_m_joints->m_size;
        v23 = v12->bodies[0];
        kSSHR_CL = v23->m_cfg.kSSHR_CL;
        p_kSSHR_CL = &v23->m_cfg.kSSHR_CL;
        v26 = &v12->bodies[1]->m_cfg.kSSHR_CL;
        if ( kSSHR_CL > *v26 )
          v26 = p_kSSHR_CL;
        v31->m_erp = *v26 * v31->m_erp;
        v31->m_split = (float)((float)(v12->bodies[1]->m_cfg.kSS_SPLT_CL + v12->bodies[0]->m_cfg.kSS_SPLT_CL)
                             * v31->m_split)
                     * 0.5;
      }
    }
  }
}
