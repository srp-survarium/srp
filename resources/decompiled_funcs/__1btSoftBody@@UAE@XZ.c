void __thiscall btSoftBody::~btSoftBody(btSoftBody *this)
{
  btSoftBody *m_collisionShape; // ecx
  int i; // esi
  btSoftBody::Material *v4; // eax
  int j; // esi
  void *v6; // eax
  int *m_data; // eax
  bool *v8; // eax
  btSoftBody::Cluster **v9; // eax
  btDbvt *v10; // ecx
  btDbvt::sStkNN *v11; // eax
  btDbvt *v12; // ecx
  btDbvt::sStkNN *v13; // eax
  btSoftBody::Config *v14; // ecx
  btDbvt::sStkNN *v15; // eax
  btSoftBody::Material **v16; // eax
  btSoftBody::Joint **v17; // eax
  btSoftBody::SContact *v18; // eax
  btSoftBody::RContact *v19; // eax
  btSoftBody::Anchor *v20; // eax
  btSoftBody::Tetra *v21; // eax
  btSoftBody::Face *v22; // eax
  btSoftBody::Link *v23; // eax
  btSoftBody::Node *v24; // eax
  btSoftBody::Note *v25; // eax
  float *v26; // eax
  btVector3 *v27; // eax
  btCollisionObject **v28; // eax

  m_collisionShape = (btSoftBody *)this->m_collisionShape;
  this->__vftable = (btSoftBody_vtbl *)&btSoftBody::`vftable';
  if ( m_collisionShape )
    m_collisionShape->checkCollideWithOverride(m_collisionShape, (btCollisionObject *)1);
  while ( this->m_clusters.m_size > 0 )
    btSoftBody::releaseCluster(m_collisionShape, (btSoftBody::Cluster *)this);
  for ( i = 0; i < this->m_materials.m_size; ++i )
  {
    v4 = this->m_materials.m_data[i];
    if ( v4 )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v4);
    }
  }
  for ( j = 0; j < this->m_joints.m_size; ++j )
  {
    m_collisionShape = (btSoftBody *)this->m_joints.m_data;
    v6 = (void *)*((_DWORD *)&m_collisionShape->__vftable + j);
    if ( v6 )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v6);
    }
  }
  m_data = this->m_userIndexMapping.m_data;
  if ( m_data )
  {
    if ( this->m_userIndexMapping.m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(m_data);
    }
    this->m_userIndexMapping.m_data = 0;
  }
  this->m_userIndexMapping.m_ownsMemory = 1;
  this->m_userIndexMapping.m_data = 0;
  this->m_userIndexMapping.m_size = 0;
  this->m_userIndexMapping.m_capacity = 0;
  v8 = this->m_clusterConnectivity.m_data;
  if ( v8 )
  {
    if ( this->m_clusterConnectivity.m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v8);
    }
    this->m_clusterConnectivity.m_data = 0;
  }
  this->m_clusterConnectivity.m_ownsMemory = 1;
  this->m_clusterConnectivity.m_data = 0;
  this->m_clusterConnectivity.m_size = 0;
  this->m_clusterConnectivity.m_capacity = 0;
  v9 = this->m_clusters.m_data;
  if ( v9 )
  {
    if ( this->m_clusters.m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v9);
    }
    this->m_clusters.m_data = 0;
  }
  this->m_clusters.m_ownsMemory = 1;
  this->m_clusters.m_data = 0;
  this->m_clusters.m_size = 0;
  this->m_clusters.m_capacity = 0;
  btDbvt::clear((btDbvt *)m_collisionShape);
  v11 = this->m_cdbvt.m_stkStack.m_data;
  if ( v11 )
  {
    if ( this->m_cdbvt.m_stkStack.m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v11);
    }
    this->m_cdbvt.m_stkStack.m_data = 0;
  }
  this->m_cdbvt.m_stkStack.m_ownsMemory = 1;
  this->m_cdbvt.m_stkStack.m_data = 0;
  this->m_cdbvt.m_stkStack.m_size = 0;
  this->m_cdbvt.m_stkStack.m_capacity = 0;
  btDbvt::clear(v10);
  v13 = this->m_fdbvt.m_stkStack.m_data;
  if ( v13 )
  {
    if ( this->m_fdbvt.m_stkStack.m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v13);
    }
    this->m_fdbvt.m_stkStack.m_data = 0;
  }
  this->m_fdbvt.m_stkStack.m_ownsMemory = 1;
  this->m_fdbvt.m_stkStack.m_data = 0;
  this->m_fdbvt.m_stkStack.m_size = 0;
  this->m_fdbvt.m_stkStack.m_capacity = 0;
  btDbvt::clear(v12);
  v15 = this->m_ndbvt.m_stkStack.m_data;
  if ( v15 )
  {
    if ( this->m_ndbvt.m_stkStack.m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v15);
    }
    this->m_ndbvt.m_stkStack.m_data = 0;
  }
  this->m_ndbvt.m_stkStack.m_ownsMemory = 1;
  this->m_ndbvt.m_stkStack.m_data = 0;
  this->m_ndbvt.m_stkStack.m_size = 0;
  this->m_ndbvt.m_stkStack.m_capacity = 0;
  v16 = this->m_materials.m_data;
  if ( v16 )
  {
    if ( this->m_materials.m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v16);
    }
    this->m_materials.m_data = 0;
  }
  this->m_materials.m_ownsMemory = 1;
  this->m_materials.m_data = 0;
  this->m_materials.m_size = 0;
  this->m_materials.m_capacity = 0;
  v17 = this->m_joints.m_data;
  if ( v17 )
  {
    if ( this->m_joints.m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v17);
    }
    this->m_joints.m_data = 0;
  }
  this->m_joints.m_ownsMemory = 1;
  this->m_joints.m_data = 0;
  this->m_joints.m_size = 0;
  this->m_joints.m_capacity = 0;
  v18 = this->m_scontacts.m_data;
  if ( v18 )
  {
    if ( this->m_scontacts.m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v18);
    }
    this->m_scontacts.m_data = 0;
  }
  this->m_scontacts.m_ownsMemory = 1;
  this->m_scontacts.m_data = 0;
  this->m_scontacts.m_size = 0;
  this->m_scontacts.m_capacity = 0;
  v19 = this->m_rcontacts.m_data;
  if ( v19 )
  {
    if ( this->m_rcontacts.m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v19);
    }
    this->m_rcontacts.m_data = 0;
  }
  this->m_rcontacts.m_ownsMemory = 1;
  this->m_rcontacts.m_data = 0;
  this->m_rcontacts.m_size = 0;
  this->m_rcontacts.m_capacity = 0;
  v20 = this->m_anchors.m_data;
  if ( v20 )
  {
    if ( this->m_anchors.m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v20);
    }
    this->m_anchors.m_data = 0;
  }
  this->m_anchors.m_ownsMemory = 1;
  this->m_anchors.m_data = 0;
  this->m_anchors.m_size = 0;
  this->m_anchors.m_capacity = 0;
  v21 = this->m_tetras.m_data;
  if ( v21 )
  {
    if ( this->m_tetras.m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v21);
    }
    this->m_tetras.m_data = 0;
  }
  this->m_tetras.m_ownsMemory = 1;
  this->m_tetras.m_data = 0;
  this->m_tetras.m_size = 0;
  this->m_tetras.m_capacity = 0;
  v22 = this->m_faces.m_data;
  if ( v22 )
  {
    if ( this->m_faces.m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v22);
    }
    this->m_faces.m_data = 0;
  }
  this->m_faces.m_ownsMemory = 1;
  this->m_faces.m_data = 0;
  this->m_faces.m_size = 0;
  this->m_faces.m_capacity = 0;
  v23 = this->m_links.m_data;
  if ( v23 )
  {
    if ( this->m_links.m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v23);
    }
    this->m_links.m_data = 0;
  }
  this->m_links.m_ownsMemory = 1;
  this->m_links.m_data = 0;
  this->m_links.m_size = 0;
  this->m_links.m_capacity = 0;
  v24 = this->m_nodes.m_data;
  if ( v24 )
  {
    if ( this->m_nodes.m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v24);
    }
    this->m_nodes.m_data = 0;
  }
  this->m_nodes.m_ownsMemory = 1;
  this->m_nodes.m_data = 0;
  this->m_nodes.m_size = 0;
  this->m_nodes.m_capacity = 0;
  v25 = this->m_notes.m_data;
  if ( v25 )
  {
    if ( this->m_notes.m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v25);
    }
    this->m_notes.m_data = 0;
  }
  this->m_notes.m_ownsMemory = 1;
  this->m_notes.m_data = 0;
  this->m_notes.m_size = 0;
  this->m_notes.m_capacity = 0;
  v26 = this->m_pose.m_wgh.m_data;
  if ( v26 )
  {
    if ( this->m_pose.m_wgh.m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v26);
    }
    this->m_pose.m_wgh.m_data = 0;
  }
  this->m_pose.m_wgh.m_ownsMemory = 1;
  this->m_pose.m_wgh.m_data = 0;
  this->m_pose.m_wgh.m_size = 0;
  this->m_pose.m_wgh.m_capacity = 0;
  v27 = this->m_pose.m_pos.m_data;
  if ( v27 )
  {
    if ( this->m_pose.m_pos.m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v27);
    }
    this->m_pose.m_pos.m_data = 0;
  }
  this->m_pose.m_pos.m_ownsMemory = 1;
  this->m_pose.m_pos.m_data = 0;
  this->m_pose.m_pos.m_size = 0;
  this->m_pose.m_pos.m_capacity = 0;
  btSoftBody::Config::~Config(v14, (int)&this->m_cfg);
  v28 = this->m_collisionDisabledObjects.m_data;
  if ( v28 )
  {
    if ( this->m_collisionDisabledObjects.m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v28);
    }
    this->m_collisionDisabledObjects.m_data = 0;
  }
  this->m_collisionDisabledObjects.m_data = 0;
  this->m_collisionDisabledObjects.m_size = 0;
  this->m_collisionDisabledObjects.m_capacity = 0;
  this->m_collisionDisabledObjects.m_ownsMemory = 1;
  this->__vftable = (btSoftBody_vtbl *)&btCollisionObject::`vftable';
}
