void __thiscall vostok::resources::query_result::set_deleter_object_if_needed(
        vostok::resources::query_result *this,
        vostok::resources::query_result *out_is_new_resource)
{
  const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *p_m_unmanaged_resource; // ebx
  vostok::resources::unmanaged_resource *m_object; // eax
  vostok::resources::unmanaged_resource *v4; // edi
  vostok::vfs::vfs_iterator *fat_it_zero_if_physical_path_it; // eax
  vostok::vfs::vfs_iterator::type_enum v6; // ecx
  vostok::resources::query_result *v7; // ecx
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *p_m_managed_resource; // edi
  vostok::resources::managed_resource *v9; // eax
  vostok::vfs::vfs_iterator *v10; // ebx
  vostok::resources::managed_resource *v11; // ecx
  vostok::vfs::vfs_iterator::type_enum v12; // ecx
  vostok::resources::query_result *v13; // ecx
  vostok::vfs::vfs_iterator v14[2]; // [esp-10h] [ebp-34h] BYREF
  vostok::vfs::vfs_iterator v15; // [esp+10h] [ebp-14h] BYREF

  if ( this )
    LOBYTE(this->__vftable) = 0;
  p_m_unmanaged_resource = (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&out_is_new_resource->m_unmanaged_resource;
  m_object = out_is_new_resource->m_unmanaged_resource.m_object;
  if ( m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    if ( m_object->m_creation_source == creation_source_unset )
    {
      if ( this )
        LOBYTE(this->__vftable) = 1;
      vostok::resources::query_result::set_deleter_object(
        this,
        (int)out_is_new_resource,
        p_m_unmanaged_resource->m_object);
      v4 = p_m_unmanaged_resource->m_object;
      fat_it_zero_if_physical_path_it = vostok::resources::query_result::get_fat_it_zero_if_physical_path_it(
                                          out_is_new_resource,
                                          &v15);
      v4 = (vostok::resources::unmanaged_resource *)((char *)v4 + 160);
      v4->__vftable = (vostok::resources::unmanaged_resource_vtbl *)fat_it_zero_if_physical_path_it->m_hashset;
      v4 = (vostok::resources::unmanaged_resource *)((char *)v4 + 4);
      v4->__vftable = (vostok::resources::unmanaged_resource_vtbl *)fat_it_zero_if_physical_path_it->m_node;
      v4 = (vostok::resources::unmanaged_resource *)((char *)v4 + 4);
      v4->__vftable = (vostok::resources::unmanaged_resource_vtbl *)fat_it_zero_if_physical_path_it->m_link_target;
      v4->type = fat_it_zero_if_physical_path_it->m_type;
      v14[0].m_type = v6;
      vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
        (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v14[0].m_type,
        p_m_unmanaged_resource);
      vostok::resources::query_result::set_creation_source_for_resource(
        v7,
        (int)out_is_new_resource,
        (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)v14[0].m_type);
    }
  }
  else
  {
    p_m_managed_resource = &out_is_new_resource->m_managed_resource;
    v9 = out_is_new_resource->m_managed_resource.m_object;
    if ( v9
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
      && v9->m_creation_source == creation_source_unset )
    {
      if ( this )
        LOBYTE(this->__vftable) = 1;
      v10 = (vostok::vfs::vfs_iterator *)p_m_managed_resource->m_object;
      vostok::resources::query_result::get_fat_it_zero_if_physical_path_it(out_is_new_resource, v14);
      vostok::resources::managed_resource::late_set_fat_it(v11, v10, v14[0]);
      v14[0].m_type = v12;
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
        (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&v14[0].m_type,
        p_m_managed_resource);
      vostok::resources::query_result::set_creation_source_for_resource(
        v13,
        (int)out_is_new_resource,
        (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>)v14[0].m_type);
    }
  }
}
