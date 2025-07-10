void __thiscall vostok::render::grass_world::~grass_world(
        vostok::render::grass_world *this,
        vostok::render::grass_world *thisa)
{
  vostok::collision::space_partitioning_tree *m_patches_tree; // esi
  void (__thiscall *insert)(vostok::collision::space_partitioning_tree *, vostok::collision::object *, const vostok::math::float4x4 *); // edi
  _BYTE *v4; // ebx
  void **M_start; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  void **v7; // eax
  void *v8; // esi
  void **v9; // eax
  void *v10; // esi
  vostok::render::trample_desc *v11; // eax
  void *v12; // esi

  thisa->__vftable = (vostok::render::grass_world_vtbl *)&vostok::render::grass_world::`vftable';
  vostok::render::grass_world::clear(this, thisa);
  m_patches_tree = thisa->m_patches_tree;
  if ( m_patches_tree )
  {
    insert = m_patches_tree[4].insert;
    v4 = __RTCastToVoid((void **)&thisa->m_patches_tree->__vftable);
    ((void (__thiscall *)(vostok::collision::space_partitioning_tree *, _DWORD))m_patches_tree->~vostok::collision::space_partitioning_tree)(
      m_patches_tree,
      0);
    (*(void (__thiscall **)(void (__thiscall *)(vostok::collision::space_partitioning_tree *, vostok::collision::object *, const vostok::math::float4x4 *), _BYTE *))(*(_DWORD *)insert + 24))(
      insert,
      v4);
  }
  M_start = thisa->m_visible_patches._M_impl._M_start;
  if ( M_start )
  {
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, M_start);
  }
  v7 = thisa->m_patches._M_impl._M_start;
  if ( v7 )
  {
    v8 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v8, v7);
  }
  v9 = thisa->m_templates._M_impl._M_start;
  if ( v9 )
  {
    v10 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v10, v9);
  }
  v11 = thisa->m_trample_array._M_impl._M_start;
  if ( v11 )
  {
    v12 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v12, v11);
  }
  vostok::resources::unmanaged_resource::~unmanaged_resource(thisa);
}
