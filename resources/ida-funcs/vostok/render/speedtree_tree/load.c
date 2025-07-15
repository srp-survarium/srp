void __usercall vostok::render::speedtree_tree::load(
        vostok::render::speedtree_tree *this@<esi>,
        unsigned __int8 *data@<ecx>,
        unsigned int size@<eax>)
{
  vostok::render::speedtree_tree_component_branch *v3; // eax
  vostok::render::speedtree_tree_component_branch *v4; // ecx
  vostok::render::speedtree_tree_component *v5; // eax
  vostok::render::speedtree_tree_component_frond *v6; // eax
  vostok::render::speedtree_tree_component_frond *v7; // ecx
  vostok::render::speedtree_tree_component *v8; // eax
  vostok::render::speedtree_tree_component_leafmesh *v9; // eax
  vostok::render::speedtree_tree_component_leafmesh *v10; // ecx
  vostok::render::speedtree_tree_component *v11; // eax
  vostok::render::speedtree_tree_component_leafcard *v12; // eax
  vostok::render::speedtree_tree_component_leafcard *v13; // ecx
  vostok::render::speedtree_tree_component *v14; // eax
  void *v15; // eax
  vostok::render::speedtree_tree_component_billboard *v16; // ecx
  vostok::render::speedtree_tree_component_billboard *v17; // eax

  SpeedTree::CCore::LoadTree(&this->SpeedTree::CCore, data, size, 0, 1.0);
  if ( this != (vostok::render::speedtree_tree *)-560 )
  {
    if ( this->m_sGeometry.m_nNumBranchLods )
    {
      v3 = (vostok::render::speedtree_tree_component_branch *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                                (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                                                0x70u);
      if ( v3 )
        vostok::render::speedtree_tree_component_branch::speedtree_tree_component_branch(v4, v3, this);
      else
        v5 = 0;
      this->m_branch_component = v5;
    }
    if ( this->m_sGeometry.m_nNumFrondLods )
    {
      v6 = (vostok::render::speedtree_tree_component_frond *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                               (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                                               0x70u);
      if ( v6 )
        vostok::render::speedtree_tree_component_frond::speedtree_tree_component_frond(v7, v6, this);
      else
        v8 = 0;
      this->m_frond_component = v8;
    }
    if ( this->m_sGeometry.m_nNumLeafMeshLods )
    {
      v9 = (vostok::render::speedtree_tree_component_leafmesh *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                                  (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                                                  0x70u);
      if ( v9 )
        vostok::render::speedtree_tree_component_leafmesh::speedtree_tree_component_leafmesh(v10, v9, this);
      else
        v11 = 0;
      this->m_leafmesh_component = v11;
    }
    if ( this->m_sGeometry.m_nNumLeafCardLods )
    {
      v12 = (vostok::render::speedtree_tree_component_leafcard *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                                   (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                                                   0x70u);
      if ( v12 )
        vostok::render::speedtree_tree_component_leafcard::speedtree_tree_component_leafcard(v13, v12, this);
      else
        v14 = 0;
      this->m_leafcard_component = v14;
    }
    if ( this->m_abGeometryTypesPresent[4] )
    {
      v15 = vostok::memory::doug_lea_allocator::malloc_impl(
              (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
              0x74u);
      if ( v15 )
      {
        vostok::render::speedtree_tree_component_billboard::speedtree_tree_component_billboard(v16, (int)v15, this);
        this->m_billboard_component = v17;
      }
      else
      {
        this->m_billboard_component = 0;
      }
    }
  }
}
