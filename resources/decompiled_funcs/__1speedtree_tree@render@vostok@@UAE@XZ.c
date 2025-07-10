void __thiscall vostok::render::speedtree_tree::~speedtree_tree(vostok::render::speedtree_tree *this)
{
  vostok::render::grass_render_model *m_object; // ebp
  _BYTE *v3; // esi
  void *v4; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  vostok::render::grass_render_model *v6; // ebp
  _BYTE *v7; // esi
  void *v8; // eax
  void *v9; // esi
  vostok::render::grass_render_model *v10; // ebp
  _BYTE *v11; // esi
  void *v12; // eax
  void *v13; // esi
  vostok::render::grass_render_model *v14; // ebp
  _BYTE *v15; // esi
  void *v16; // eax
  void *v17; // esi
  vostok::render::grass_render_model *v18; // ebp
  _BYTE *v19; // esi
  void *v20; // eax
  void *v21; // esi
  vostok::render::lod_render_info *m_lod_render_info; // ebp
  void *v23; // esi
  vostok::render::lod_entry *v24; // eax
  int v25; // [esp+14h] [ebp-4h]

  this->vostok::render::speedtree_tree_base::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (vostok::render::speedtree_tree_vtbl *)&stru_962594.m_parent_task.m_next_task_in_full_queue;
  this->SpeedTree::CCore::__vftable = (SpeedTree::CCore_vtbl *)&(&stru_962594.m_parent_task.m_function.vtable)[1];
  if ( this->m_branch_component )
  {
    m_object = vostok::render::g_allocator.m_object;
    v3 = __RTCastToVoid((void **)&this->m_branch_component->__vftable);
    ((void (__thiscall *)(vostok::render::speedtree_tree_component *, _DWORD))this->m_branch_component->~vostok::render::speedtree_tree_component)(
      this->m_branch_component,
      0);
    if ( v3 )
    {
      v4 = v3;
      m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick);
      BYTE2(m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v4);
    }
    this->m_branch_component = 0;
  }
  if ( this->m_frond_component )
  {
    v6 = vostok::render::g_allocator.m_object;
    v7 = __RTCastToVoid((void **)&this->m_frond_component->__vftable);
    ((void (__thiscall *)(vostok::render::speedtree_tree_component *, _DWORD))this->m_frond_component->~vostok::render::speedtree_tree_component)(
      this->m_frond_component,
      0);
    if ( v7 )
    {
      v8 = v7;
      v9 = (void *)HIDWORD(v6->m_reconstruction_info_actuality_tick);
      BYTE2(v6->m_children_resources.m_lock) = 0;
      vostok_mspace_free(v9, v8);
    }
    this->m_frond_component = 0;
  }
  if ( this->m_leafmesh_component )
  {
    v10 = vostok::render::g_allocator.m_object;
    v11 = __RTCastToVoid((void **)&this->m_leafmesh_component->__vftable);
    ((void (__thiscall *)(vostok::render::speedtree_tree_component *, _DWORD))this->m_leafmesh_component->~vostok::render::speedtree_tree_component)(
      this->m_leafmesh_component,
      0);
    if ( v11 )
    {
      v12 = v11;
      v13 = (void *)HIDWORD(v10->m_reconstruction_info_actuality_tick);
      BYTE2(v10->m_children_resources.m_lock) = 0;
      vostok_mspace_free(v13, v12);
    }
    this->m_leafmesh_component = 0;
  }
  if ( this->m_leafcard_component )
  {
    v14 = vostok::render::g_allocator.m_object;
    v15 = __RTCastToVoid((void **)&this->m_leafcard_component->__vftable);
    ((void (__thiscall *)(vostok::render::speedtree_tree_component *, _DWORD))this->m_leafcard_component->~vostok::render::speedtree_tree_component)(
      this->m_leafcard_component,
      0);
    if ( v15 )
    {
      v16 = v15;
      v17 = (void *)HIDWORD(v14->m_reconstruction_info_actuality_tick);
      BYTE2(v14->m_children_resources.m_lock) = 0;
      vostok_mspace_free(v17, v16);
    }
    this->m_leafcard_component = 0;
  }
  if ( this->m_billboard_component )
  {
    v18 = vostok::render::g_allocator.m_object;
    v19 = __RTCastToVoid((void **)&this->m_billboard_component->__vftable);
    ((void (__thiscall *)(vostok::render::speedtree_tree_component_billboard *, _DWORD))this->m_billboard_component->~vostok::render::speedtree_tree_component_billboard)(
      this->m_billboard_component,
      0);
    if ( v19 )
    {
      v20 = v19;
      v21 = (void *)HIDWORD(v18->m_reconstruction_info_actuality_tick);
      BYTE2(v18->m_children_resources.m_lock) = 0;
      vostok_mspace_free(v21, v20);
    }
    this->m_billboard_component = 0;
  }
  m_lod_render_info = this->m_lod_render_info;
  v25 = 4;
  do
  {
    if ( m_lod_render_info->num_lods )
    {
      v23 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
      v24 = m_lod_render_info->lods - 1;
      BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free(v23, (void *)v24);
    }
    ++m_lod_render_info;
    --v25;
  }
  while ( v25 );
  SpeedTree::CCore::~CCore(&this->SpeedTree::CCore);
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
