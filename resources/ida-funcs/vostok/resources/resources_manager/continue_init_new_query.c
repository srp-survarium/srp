void __thiscall vostok::resources::resources_manager::continue_init_new_query(
        vostok::resources::resources_manager *this,
        vostok::resources::query_result *query)
{
  vostok::vfs::base_node<1> *m_link_target; // ebx
  vostok::vfs::base_node<1> *m_node; // esi
  vostok::vfs::vfs_hashset *m_hashset; // edi
  vostok::vfs::vfs_iterator::type_enum m_type; // eax
  vostok::resources::memory_usage_type *p_m_memory_usage_self; // ebx
  survarium::pure_game_effect_emitter_base *v7; // ecx
  vostok::resources::query_result_for_cook *v8; // ecx
  vostok::resources::query_result *associated_query_result; // eax
  vostok::resources::query_result *v10; // ecx
  _BYTE v11[20]; // [esp-14h] [ebp-158h] BYREF
  vostok::resources::reallocating_bool v12; // [esp+0h] [ebp-144h]
  vostok::fs_new::native_path_string v13; // [esp+10h] [ebp-134h] BYREF
  vostok::vfs::vfs_hashset *v14; // [esp+128h] [ebp-1Ch] BYREF
  vostok::vfs::base_node<1> *v15; // [esp+12Ch] [ebp-18h]
  vostok::vfs::base_node<1> *v16; // [esp+130h] [ebp-14h]
  vostok::vfs::vfs_iterator::type_enum v17; // [esp+134h] [ebp-10h]
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> other; // [esp+138h] [ebp-Ch] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> result; // [esp+13Ch] [ebp-8h] BYREF

  m_link_target = query->m_fat_it.m_link_target;
  m_node = query->m_fat_it.m_node;
  m_hashset = query->m_fat_it.m_hashset;
  m_type = query->m_fat_it.m_type;
  v14 = m_hashset;
  v15 = m_node;
  v16 = m_link_target;
  v17 = m_type;
  if ( m_node )
  {
    vostok::vfs::vfs_iterator::get_physical_path((vostok::vfs::vfs_iterator *)query, (int)&v14, &v13);
    vostok::resources::cook_base::reuse_type(query->m_class_id);
    *(_DWORD *)&v11[4] = m_hashset;
    *(_DWORD *)&v11[8] = m_node;
    *(_DWORD *)&v11[12] = m_link_target;
    *(_DWORD *)&v11[16] = v17;
    vostok::resources::get_associated_unmanaged_resource_ptr(&other, *(vostok::vfs::vfs_iterator *)&v11[4]);
    if ( other.m_object
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      *(_DWORD *)&v11[16] = vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr;
      p_m_memory_usage_self = &other.m_object->m_memory_usage_self;
      vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
        (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v11[16],
        &other);
      vostok::resources::query_result_for_cook::set_unmanaged_resource(
        p_m_memory_usage_self,
        v7,
        (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)query,
        *(vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v11[16]);
      _InterlockedOr(&query->m_flags, (unsigned int)&loc_3FFFF + 1);
      vostok::resources::query_result::end_query_might_destroy_this(
        (vostok::resources::query_result *)&query->m_flags,
        (int)query);
    }
    else
    {
      *(_DWORD *)&v11[4] = m_hashset;
      *(_DWORD *)&v11[8] = m_node;
      *(_DWORD *)&v11[12] = m_link_target;
      *(_DWORD *)&v11[16] = v17;
      vostok::resources::get_associated_managed_resource_ptr(&result, *(vostok::vfs::vfs_iterator *)&v11[4]);
      if ( result.m_object
        && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        if ( (result.m_object->m_flags.m_flags & 0x10) != 0 )
        {
          vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::operator=(
            &result,
            &query->m_raw_managed_resource);
          _InterlockedOr(&query->m_flags, 0x80000u);
          vostok::resources::query_result::on_file_operation_end(
            (vostok::resources::query_result *)&query->m_flags,
            (int)query);
        }
        else
        {
          *(_DWORD *)&v11[16] = vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr;
          vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
            (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&v11[16],
            &result);
          vostok::resources::query_result_for_cook::set_managed_resource(
            v8,
            (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)query,
            *(vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&v11[16]);
          _InterlockedOr(&query->m_flags, (unsigned int)&loc_3FFFF + 1);
          vostok::resources::query_result::end_query_might_destroy_this(
            (vostok::resources::query_result *)&query->m_flags,
            (int)query);
        }
      }
      else
      {
        *(_DWORD *)&v11[4] = m_hashset;
        *(_DWORD *)&v11[8] = m_node;
        *(_DWORD *)&v11[12] = m_link_target;
        *(_DWORD *)&v11[16] = v17;
        associated_query_result = vostok::resources::get_associated_query_result(*(vostok::vfs::vfs_iterator *)&v11[4]);
        if ( associated_query_result )
        {
          vostok::resources::query_result::add_referrer(query, v10, associated_query_result, v12);
        }
        else
        {
          if ( (query->m_flags & 2) != 0 && vostok::resources::cook_base::reuse_type(query->m_class_id) )
          {
            *(_DWORD *)v11 = v14;
            *(_DWORD *)&v11[4] = v15;
            *(_DWORD *)&v11[8] = v16;
            *(_DWORD *)&v11[12] = v17;
            vostok::resources::set_associated(*(vostok::vfs::vfs_iterator *)v11, query);
          }
          vostok::resources::allocate_functionality::prepare_raw_resource(query, 0, v12);
        }
      }
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&result);
    }
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&other);
  }
  else
  {
    vostok::resources::resources_manager::init_query_with_no_fat_it(query);
  }
}
