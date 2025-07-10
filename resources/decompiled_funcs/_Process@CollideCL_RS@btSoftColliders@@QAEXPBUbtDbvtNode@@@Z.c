void __userpurge btSoftColliders::CollideCL_RS::Process(
        const btDbvtNode *leaf@<eax>,
        btSoftColliders::CollideCL_RS *this)
{
  btSoftBody::Cluster *v2; // ebx
  btCollisionObject *m_colObj; // eax
  const btTransform *p_m_worldTransform; // esi
  const btTransform *Identity; // edi
  btCollisionObject *v6; // ecx
  btSoftBody::CJoint *v7; // ecx
  btSoftBody::CJoint *v8; // eax
  btSoftBody::CJoint *v9; // ebx
  btSoftColliders::CollideCL_RS *v10; // edx
  btSoftBody *psb; // edi
  int m_capacity; // ecx
  int m_size; // eax
  btAlignedObjectArray<btSoftBody::Joint *> *p_m_joints; // edi
  int v15; // esi
  int v16; // edx
  int v17; // eax
  _DWORD *v18; // ecx
  btSoftBody::Joint **m_data; // eax
  btSoftBody::CJoint **v20; // eax
  btSoftBody::Body v21; // [esp+784h] [ebp-1FCh]
  btSoftBody::Body v22; // [esp+790h] [ebp-1F0h]
  btConvexShape *shape1; // [esp+7B8h] [ebp-1C8h]
  btConvexShape *shape1a; // [esp+7B8h] [ebp-1C8h]
  btSoftBody::CJoint *v25; // [esp+7BCh] [ebp-1C4h]
  btVector3 guess; // [esp+7C0h] [ebp-1C0h] BYREF
  btConvexShape shape0; // [esp+7D0h] [ebp-1B0h] BYREF
  const vostok::math::float4x4 *v28; // [esp+7E0h] [ebp-1A0h]
  const vostok::math::float4x4 *v29; // [esp+7E4h] [ebp-19Ch]
  const vostok::math::float4x4 *v30; // [esp+7E8h] [ebp-198h]
  int v31; // [esp+7ECh] [ebp-194h]
  int v32; // [esp+800h] [ebp-180h]
  btSoftBody::Cluster *v33; // [esp+810h] [ebp-170h]
  btGjkEpaSolver2::sResults results; // [esp+820h] [ebp-160h] BYREF
  btSoftBody::CJoint __that; // [esp+870h] [ebp-110h] BYREF

  v2 = (btSoftBody::Cluster *)leaf->childs[0];
  m_colObj = this->m_colObj;
  shape0.m_shapeType = 35;
  shape0.m_userPointer = 0;
  v28 = clear_value;
  v29 = clear_value;
  v30 = clear_value;
  v31 = 0;
  shape0.__vftable = (btConvexShape_vtbl *)&btSoftClusterCollisionShape::`vftable';
  v33 = v2;
  v32 = 0;
  shape1 = (btConvexShape *)m_colObj->m_collisionShape;
  if ( (m_colObj->m_collisionFlags & 3) == 0 || !v2->m_containsAnchor )
  {
    guess.mVec128.m128_u64[0] = (unsigned int)clear_value;
    guess.mVec128.m128_u64[1] = 0;
    p_m_worldTransform = &m_colObj->m_worldTransform;
    Identity = btTransform::getIdentity();
    if ( btGjkEpaSolver2::Distance(&shape0, Identity, shape1, p_m_worldTransform, &guess, &results)
      || btGjkEpaSolver2::Penetration(&shape0, Identity, shape1, p_m_worldTransform, &guess, &results, 0) )
    {
      __that.__vftable = (btSoftBody::CJoint_vtbl *)&btSoftBody::Joint::`vftable';
      `vector constructor iterator'(
        (char *)__that.m_bodies,
        0xCu,
        2,
        (void *(__thiscall *)(void *))vostok::render::vector<vostok::render::lpv_render_surface>::vector<vostok::render::lpv_render_surface>);
      v6 = this->m_colObj;
      __that.m_delete = 0;
      __that.__vftable = (btSoftBody::CJoint_vtbl *)&btSoftBody::CJoint::`vftable';
      v22.m_soft = 0;
      v22.m_collisionObject = v6;
      v22.m_rigid = (v6->m_internalType & 2) != 0 ? (btRigidBody *)v6 : 0;
      v21.m_soft = v2;
      *(_QWORD *)&v21.m_rigid = 0;
      if ( btSoftColliders::ClusterBase::SolveContact(&results, this, v21, v22, &__that) )
      {
        ++gNumAlignedAllocs;
        if ( sAlignedAllocFunc(0x110u, 16) )
        {
          btSoftBody::CJoint::CJoint(v7);
          v9 = v8;
          v25 = v8;
        }
        else
        {
          v9 = 0;
          v25 = 0;
        }
        btSoftBody::CJoint::operator=(v9, &__that);
        v10 = this;
        psb = this->psb;
        m_capacity = psb->m_joints.m_capacity;
        m_size = psb->m_joints.m_size;
        p_m_joints = &psb->m_joints;
        if ( m_size == m_capacity )
        {
          v15 = 2 * m_size;
          if ( !m_size )
            v15 = 1;
          if ( m_capacity < v15 )
          {
            if ( v15 )
            {
              ++gNumAlignedAllocs;
              shape1a = (btConvexShape *)sAlignedAllocFunc(4 * v15, 16);
            }
            else
            {
              shape1a = 0;
            }
            v16 = p_m_joints->m_size;
            v17 = 0;
            if ( v16 > 0 )
            {
              v18 = &shape1a->__vftable;
              do
              {
                if ( v18 )
                {
                  *v18 = p_m_joints->m_data[v17];
                  v9 = v25;
                }
                ++v17;
                ++v18;
              }
              while ( v17 < v16 );
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
            v10 = this;
            p_m_joints->m_ownsMemory = 1;
            p_m_joints->m_data = (btSoftBody::Joint **)shape1a;
            p_m_joints->m_capacity = v15;
          }
        }
        v20 = (btSoftBody::CJoint **)&p_m_joints->m_data[p_m_joints->m_size];
        if ( v20 )
          *v20 = v9;
        ++p_m_joints->m_size;
        if ( (v10->m_colObj->m_collisionFlags & 3) != 0 )
        {
          v9->m_erp = v10->psb->m_cfg.kSKHR_CL * v9->m_erp;
          v9->m_split = v10->psb->m_cfg.kSK_SPLT_CL * v9->m_split;
        }
        else
        {
          v9->m_erp = v10->psb->m_cfg.kSRHR_CL * v9->m_erp;
          v9->m_split = v10->psb->m_cfg.kSR_SPLT_CL * v9->m_split;
        }
      }
    }
  }
}
