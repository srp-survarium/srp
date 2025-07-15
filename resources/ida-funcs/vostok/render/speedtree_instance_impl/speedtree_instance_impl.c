void __userpurge vostok::render::speedtree_instance_impl::speedtree_instance_impl(
        vostok::render::speedtree_instance_impl *this@<ecx>,
        int a2@<eax>,
        vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base> in_speedtree_tree_ptr)
{
  vostok::render::speedtree_tree_base *m_object; // ecx
  SpeedTree::CInstance *v5; // eax
  SpeedTree::CInstance *v6; // eax
  vostok::render::speedtree_tree_base *v7; // [esp-4h] [ebp-Ch]

  v7 = 0;
  m_object = in_speedtree_tree_ptr.m_object;
  if ( in_speedtree_tree_ptr.m_object )
  {
    v7 = in_speedtree_tree_ptr.m_object;
    m_object = (vostok::render::speedtree_tree_base *)_InterlockedExchangeAdd(
                                                        &in_speedtree_tree_ptr.m_object->m_reference_count,
                                                        1u);
  }
  vostok::render::speedtree_instance::speedtree_instance(
    (vostok::render::speedtree_instance *)m_object,
    (vostok::resources::unmanaged_resource *)a2,
    (vostok::resources::resource_ptr<vostok::render::speedtree_tree_base,vostok::resources::unmanaged_intrusive_base>)v7);
  *(_DWORD *)a2 = &stru_966A14.m_name.m_string.m_buffer[64];
  *(_DWORD *)(a2 + 340) = -1;
  v5 = (SpeedTree::CInstance *)vostok::memory::doug_lea_allocator::malloc_impl(
                                 (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                 0x24u);
  if ( v5 )
    v6 = SpeedTree::CInstance::CInstance(v5);
  else
    v6 = 0;
  *(_DWORD *)(a2 + 336) = v6;
  if ( in_speedtree_tree_ptr.m_object )
  {
    if ( !_InterlockedExchangeAdd(&in_speedtree_tree_ptr.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &in_speedtree_tree_ptr.m_object->vostok::resources::unmanaged_intrusive_base,
        in_speedtree_tree_ptr.m_object);
  }
}
