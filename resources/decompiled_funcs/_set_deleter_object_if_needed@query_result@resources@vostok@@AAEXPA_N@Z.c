void __usercall vostok::resources::query_result::set_deleter_object_if_needed(
        vostok::resources::query_result *this@<ecx>,
        int a2@<edi>)
{
  int v2; // eax
  vostok::resources::unmanaged_resource **v3; // ebx
  vostok::resources::query_result *v4; // ecx
  int v5; // eax
  const vostok::vfs::vfs_iterator *v6; // ebp
  vostok::resources::managed_resource *v7; // ecx
  vostok::resources::query_result *v8; // ecx
  vostok::resources::resource_base::creation_source_enum v9; // eax
  vostok::vfs::vfs_iterator v10; // [esp-10h] [ebp-34h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v11; // [esp+Ch] [ebp-18h] BYREF
  vostok::vfs::vfs_iterator result; // [esp+10h] [ebp-14h] BYREF

  if ( this )
    LOBYTE(this->__vftable) = 0;
  v2 = *(_DWORD *)(a2 + 220);
  v3 = (vostok::resources::unmanaged_resource **)(a2 + 220);
  if ( v2
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    if ( !*(_DWORD *)(v2 + 192) )
    {
      if ( this )
        LOBYTE(this->__vftable) = 1;
      vostok::resources::query_result::set_deleter_object(this, *v3);
      if ( (*(_DWORD *)(a2 + 688) & 0x800) != 0 )
        vostok::vfs::vfs_iterator::end(&result);
      else
        vostok::vfs::vfs_iterator::vfs_iterator(&result, (const vostok::vfs::vfs_iterator *)(a2 + 160));
      (*v3)->m_fat_it = result;
      v10.m_type = type_unset;
      vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
        (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v10.m_type,
        (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(a2 + 220));
      vostok::resources::query_result::set_creation_source_for_resource(
        v4,
        a2,
        (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>)v10.m_type);
    }
  }
  else
  {
    v5 = *(_DWORD *)(a2 + 216);
    if ( v5
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
      && !*(_DWORD *)(v5 + 192) )
    {
      if ( this )
        LOBYTE(this->__vftable) = 1;
      v6 = *(const vostok::vfs::vfs_iterator **)(a2 + 216);
      vostok::resources::query_result::get_fat_it_zero_if_physical_path_it(
        this,
        (const vostok::vfs::vfs_iterator *)a2,
        &v10);
      vostok::resources::managed_resource::late_set_fat_it(v7, v6, v10);
      v11.m_object = 0;
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
        &v11,
        (const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)(a2 + 216));
      v9 = vostok::resources::query_result::creation_source_for_resource(v8, a2);
      v11.m_object->m_creation_source = v9;
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&v11);
    }
  }
}
