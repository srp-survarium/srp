void __userpurge stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::reserve(
        stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *this@<ecx>,
        int a2@<edi>,
        unsigned int __n)
{
  vostok::ai::planning::world_state_property *v3; // ebx
  vostok::ai::planning::world_state_property *v4; // ebp
  int v5; // esi
  vostok::ai::planning::world_state_property *v6; // eax
  vostok::ai::planning::world_state_property *v7; // esi
  vostok::ai::planning::world_state_property *v8; // eax
  vostok::ai::planning::world_state_property *v9; // ebx
  void *m_reconstruction_info_actuality_tick_high; // esi
  stlp_std::priv::_STLP_alloc_proxy<unsigned int *,unsigned int,vostok::render::std_allocator<unsigned int> > *v11; // [esp+0h] [ebp-10h]
  unsigned int __old_size; // [esp+Ch] [ebp-4h]

  v3 = *(vostok::ai::planning::world_state_property **)a2;
  if ( (*(_DWORD *)(a2 + 8) - *(_DWORD *)a2) >> 2 < __n )
  {
    if ( __n > 0x3FFFFFFF )
      stlp_std::__stl_throw_length_error("vector");
    v4 = *(vostok::ai::planning::world_state_property **)(a2 + 4);
    v5 = ((char *)v4 - (char *)v3) >> 2;
    __old_size = v5;
    v6 = (vostok::ai::planning::world_state_property *)stlp_std::priv::_STLP_alloc_proxy<vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base> *,vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base>,vostok::render::std_allocator<vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base>>>::allocate(
                                                         v11,
                                                         __n);
    if ( v3 )
    {
      v7 = v6;
      stlp_std::uninitialized_copy<void * *,void * *>(v3, v4, v6);
      v8 = *(vostok::ai::planning::world_state_property **)a2;
      v9 = v7;
      if ( *(_DWORD *)a2 )
      {
        m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
        BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
        vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v8);
      }
      v5 = __old_size;
    }
    else
    {
      v9 = v6;
    }
    *(_DWORD *)a2 = v9;
    *(_DWORD *)(a2 + 4) = (char *)v9 + 4 * v5;
    *(_DWORD *)(a2 + 8) = (char *)v9 + 4 * __n;
  }
}
