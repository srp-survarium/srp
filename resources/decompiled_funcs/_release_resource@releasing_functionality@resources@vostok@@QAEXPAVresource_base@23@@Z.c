void __userpurge vostok::resources::releasing_functionality::release_resource(
        int resource@<edi>,
        vostok::resources::resource_flags *a2@<ecx>,
        vostok::resources::releasing_functionality *this)
{
  vostok::flags_type<enum vostok::resources::resource_flags_enum,vostok::threading::simple_lock> *v3; // ebx
  BOOL v4; // eax
  vostok::resources::resource_base *v5; // ecx
  volatile signed __int32 *v6; // eax
  vostok::resources::unmanaged_resource *m_object; // eax
  vostok::resources::unmanaged_intrusive_base *v8; // ecx
  vostok::resources::managed_resource *v9; // [esp-4h] [ebp-1Ch]
  void *v10; // [esp+0h] [ebp-18h]
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> unmanaged_resource; // [esp+Ch] [ebp-Ch] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> managed_resource; // [esp+10h] [ebp-8h] BYREF
  vostok::resources::quality_increase_functionality functionality; // [esp+14h] [ebp-4h] BYREF

  if ( vostok::resources::resource_flags::is_pinned_by_grm(a2, (_DWORD *)resource) )
  {
    v3 = (vostok::flags_type<enum vostok::resources::resource_flags_enum,vostok::threading::simple_lock> *)(resource + 8);
    v9 = (unsigned __int8)((*(_DWORD *)(resource + 8) & 1) - 1) == 0
       ? (vostok::resources::managed_resource *)resource
       : 0;
    managed_resource.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
      &managed_resource,
      v9);
    v4 = (*(_DWORD *)(resource + 8) & 4) != 4;
    unmanaged_resource.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&unmanaged_resource,
      v4 ? 0 : (vostok::configs::binary_config *)resource);
    vostok::intrusive_double_linked_list<vostok::resources::resource_base,vostok::resources::resource_base *,156,152,vostok::threading::single_threading_policy,vostok::size_policy,vostok::debug_policy>::erase(
      (vostok::intrusive_double_linked_list<vostok::resources::resource_base,vostok::resources::resource_base *,156,152,vostok::threading::single_threading_policy,vostok::size_policy,vostok::debug_policy> *)(*(_DWORD *)(resource + 88) + 12),
      (vostok::resources::resource_base *)resource);
    if ( (*(_DWORD *)(resource + 8) & 0x80u) != 0 )
    {
      vostok::resources::quality_increase_functionality::quality_increase_functionality(&functionality, this->m_data);
      boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::resources::resource_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,136>,vostok::resources::compare_by_target_satisfaction,unsigned int,0>>::erase<vostok::resources::resource_base,vostok::resources::compare_by_target_satisfaction>(
        (boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::resources::resource_base,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,136>,vostok::resources::compare_by_target_satisfaction,unsigned int,0> > *)resource,
        &functionality.m_data->increase_quality_tree.tree_.data_.node_plus_pred_.header_plus_size_.header_,
        (vostok::resources::compare_by_target_satisfaction)functionality.m_data->increase_quality_tree.tree_.data_.node_plus_pred_.header_plus_size_.header_.parent_,
        v10);
      vostok::threading::interlocked_and((volatile int *)(resource + 8), 0xFFFFFF7F);
    }
    vostok::resources::resource_base::clean_sub_fat_and_fat_it(v5, resource);
    if ( (v3->m_flags & 1) != 0 )
    {
      v6 = (volatile signed __int32 *)(resource + 220);
    }
    else if ( (v3->m_flags & 4) != 0 )
    {
      v6 = (volatile signed __int32 *)(resource + 208);
    }
    else
    {
      v6 = 0;
    }
    _InterlockedExchangeAdd(v6, 0xFFFFFFFF);
    vostok::threading::interlocked_and(v6 + 1, 0xFFFFFFFE);
    m_object = unmanaged_resource.m_object;
    if ( unmanaged_resource.m_object )
    {
      v8 = &unmanaged_resource.m_object->vostok::resources::unmanaged_intrusive_base;
      if ( !_InterlockedExchangeAdd(&unmanaged_resource.m_object->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(v8, m_object);
    }
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&managed_resource);
  }
}
