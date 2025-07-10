void __thiscall vostok::resources::query_result::associate_created_resource_with_fat_or_name_registry(
        vostok::resources::query_result *this,
        vostok::resources::resource_base *resource_base)
{
  vostok::resources::class_id_enum m_class_id; // edx
  vostok::resources::name_registry_entry *v4; // ebx
  int v5; // edi
  vostok::resources::cook_base *cook; // eax
  vostok::resources::resource_base *m_flags; // esi
  vostok::resources::resource_base *v8; // esi
  vostok::resources::cook_base *v9; // eax
  int type; // ecx
  vostok::resources::cook_base *v11; // eax
  unsigned int v12; // kr04_4
  int *v13; // eax
  char *m_data; // eax
  char *v15; // esi
  const char *m_lock; // edi
  vostok::vfs::base_node<1> *v17; // eax
  vostok::resources::resource_base *v18; // eax
  vostok::resources::resource_base *v19; // eax
  vostok::hash_multiset<vostok::resources::name_registry_entry,vostok::resources::name_registry_entry *,12,vostok::detail::fixed_size_policy<32768>,vostok::resources::detail::name_registry_hash,vostok::resources::detail::name_registry_equal,vostok::threading::single_threading_policy> *p_m_name_registry; // esi
  vostok::hash_multiset<vostok::resources::name_registry_entry,vostok::resources::name_registry_entry *,12,vostok::detail::fixed_size_policy<32768>,vostok::resources::detail::name_registry_hash,vostok::resources::detail::name_registry_equal,vostok::threading::single_threading_policy> *v21; // ecx
  vostok::resources::resource_base *v22; // eax
  char v23; // bl
  int v24; // ecx
  float m_last_fail_of_increasing_quality; // eax
  vostok::resources::cook_base *v26; // eax
  int v27; // eax
  int v28; // ecx
  char v29; // bl
  void (__cdecl *v30)(_BYTE *, _BYTE *, int); // eax
  volatile signed __int32 *v31; // eax
  vostok::vfs::vfs_iterator v32[2]; // [esp-10h] [ebp-60h] BYREF
  int v33; // [esp+10h] [ebp-40h]
  vostok::mutable_buffer allocation; // [esp+14h] [ebp-3Ch] BYREF
  vostok::threading::mutex_raii_impl<vostok::threading::mutex> raii; // [esp+1Ch] [ebp-34h]
  vostok::hash_multiset<vostok::resources::name_registry_entry,vostok::resources::name_registry_entry *,12,vostok::detail::fixed_size_policy<32768>,vostok::resources::detail::name_registry_hash,vostok::resources::detail::name_registry_equal,vostok::threading::single_threading_policy>::iterator it; // [esp+24h] [ebp-2Ch] BYREF
  int v37; // [esp+30h] [ebp-20h] BYREF
  _BYTE v38[24]; // [esp+38h] [ebp-18h] BYREF
  vostok::resources::resource_base *resource_basea; // [esp+54h] [ebp+4h]

  m_class_id = resource_base->m_class_id;
  v4 = 0;
  v5 = 0;
  v33 = 0;
  resource_basea = 0;
  if ( resource_base->m_fat_it.m_node )
  {
    cook = vostok::resources::resources_manager::find_cook((int)this, m_class_id);
    if ( !cook )
    {
      if ( resource_base->m_class_id == raw_data_class_no_reuse )
        goto LABEL_41;
      m_flags = (vostok::resources::resource_base *)resource_base[1].m_flags.m_flags;
      vostok::vfs::vfs_iterator::vfs_iterator(v32, &resource_base->m_fat_it);
      goto LABEL_21;
    }
    if ( (cook->m_flags.m_flags & 0x20) == 0x20 )
    {
      if ( cook->m_reuse_type == reuse_true )
      {
        m_flags = (vostok::resources::resource_base *)resource_base[1].m_flags.m_flags;
        if ( m_flags )
        {
          if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
            goto LABEL_20;
        }
      }
      if ( (cook->m_flags.m_flags & 0x20) == 0x20 )
        goto LABEL_41;
    }
    if ( cook->m_reuse_type == reuse_raw
      && resource_base[3].m_flags.m_flags
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      if ( (resource_base[3].m_parent_resources.m_lock & 0x80000) != 0 )
        v5 = resource_base[3].m_flags.m_flags;
      vostok::threading::interlocked_or((volatile int *)(resource_base[3].m_flags.m_flags + 8), 0x10u);
      v8 = (vostok::resources::resource_base *)resource_base[3].m_flags.m_flags;
      vostok::vfs::vfs_iterator::vfs_iterator(v32, &resource_base->m_fat_it);
      vostok::resources::set_associated(v8, v32[0]);
      goto LABEL_41;
    }
    if ( (cook->m_flags.m_flags & 0x20) == 0x20 )
      goto LABEL_41;
    if ( cook->m_reuse_type != reuse_true )
      goto LABEL_41;
    m_flags = (vostok::resources::resource_base *)*((_DWORD *)&resource_base[1].vostok::resources::resource_flags + 3);
    if ( !m_flags
      || !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      goto LABEL_41;
    }
LABEL_20:
    vostok::vfs::vfs_iterator::vfs_iterator(v32, &resource_base->m_fat_it);
LABEL_21:
    vostok::resources::set_associated(m_flags, v32[0]);
    v5 = (int)m_flags;
    goto LABEL_41;
  }
  v9 = vostok::resources::resources_manager::find_cook((int)this, m_class_id);
  if ( v9 && (v9->m_flags.m_flags & 8) != 0 || (type = resource_base[1].type, resource_base[1].__vftable) || type )
  {
    v11 = vostok::resources::resources_manager::find_cook(type, resource_base->m_class_id);
    if ( !v11 || v11->m_reuse_type == reuse_true )
    {
      if ( strlen((const char *)resource_base[1].m_children_resources.m_lock) )
      {
        if ( !*(_DWORD *)&resource_base[1].m_children_resources.gapC )
        {
          v12 = strlen((const char *)resource_base[1].m_children_resources.m_lock);
          v13 = vostok::memory::doug_lea_allocator::malloc_impl(&vostok::memory::g_resources_helper_allocator, v12 + 21);
          boost::_bi::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>(
            &allocation,
            (unsigned __int8 *)v13,
            v12 + 21);
          m_data = allocation.m_data;
          v4 = (vostok::resources::name_registry_entry *)allocation.m_data;
          if ( allocation.m_data )
          {
            *(_DWORD *)allocation.m_data = 0;
            v4->associated = 0;
            v4->name = 0;
            v4->next_to_delete = 0;
            m_data = allocation.m_data;
          }
          else
          {
            v4 = 0;
          }
          allocation.m_size -= 20;
          allocation.m_data = m_data + 20;
          v4->name = m_data + 20;
          v4->class_id = resource_base->m_class_id;
          v15 = allocation.m_data;
          m_lock = (const char *)resource_base[1].m_children_resources.m_lock;
          v17 = vostok::mutable_buffer::size((vostok::vfs::vfs_iterator *)&allocation);
          strcpy_s(v15, (unsigned int)v17, m_lock);
          v18 = (vostok::resources::resource_base *)resource_base[1].m_flags.m_flags;
          if ( v18
            && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
          {
            v4->associated = v18;
            v19 = (vostok::resources::resource_base *)resource_base[1].m_flags.m_flags;
          }
          else
          {
            v4->associated = (vostok::resources::resource_base *)*((_DWORD *)&resource_base[1].vostok::resources::resource_flags
                                                                 + 3);
            v19 = (vostok::resources::resource_base *)*((_DWORD *)&resource_base[1].vostok::resources::resource_flags + 3);
          }
          v19->m_name_registry_entry = v4;
          resource_basea = v19;
        }
        p_m_name_registry = &vostok::resources::g_resources_manager.m_variable->m_name_registry;
        raii.m_lock = (const vostok::threading::mutex *)&byte_20168[(unsigned int)vostok::resources::g_resources_manager.m_variable];
        vostok::threading::mutex::lock((vostok::threading::mutex *)&byte_20168[(unsigned int)vostok::resources::g_resources_manager.m_variable]);
        vostok::hash_multiset<vostok::resources::name_registry_entry,vostok::resources::name_registry_entry *,12,vostok::detail::fixed_size_policy<32768>,vostok::resources::detail::name_registry_hash,vostok::resources::detail::name_registry_equal,vostok::threading::single_threading_policy>::find(
          v21,
          (int)&it,
          p_m_name_registry,
          (vostok::resources::name_registry_entry *const)(&resource_base[3].m_reconstruction_size + 1));
        vostok::hash_multiset<vostok::resources::name_registry_entry,vostok::resources::name_registry_entry *,12,vostok::detail::fixed_size_policy<32768>,vostok::resources::detail::name_registry_hash,vostok::resources::detail::name_registry_equal,vostok::threading::single_threading_policy>::erase(
          p_m_name_registry,
          it.m_index,
          it.m_value);
        vostok::threading::interlocked_and(
          (volatile int *)&resource_base[3].m_parent_resources.vostok::threading::simple_lock,
          0xFEFFFFFF);
        if ( !*(_DWORD *)&resource_base[1].m_children_resources.gapC )
          vostok::hash_multiset<vostok::resources::name_registry_entry,vostok::resources::name_registry_entry *,12,vostok::detail::fixed_size_policy<32768>,vostok::resources::detail::name_registry_hash,vostok::resources::detail::name_registry_equal,vostok::threading::single_threading_policy>::insert(
            p_m_name_registry,
            v4);
        LeaveCriticalSection((LPCRITICAL_SECTION)raii.m_lock);
        v5 = (int)resource_basea;
      }
    }
  }
LABEL_41:
  v22 = resource_base;
  v23 = 0;
  while ( 1 )
  {
    v24 = v22[3].m_parent_resources.m_lock;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905848] & v24) != 0 )
      break;
    m_last_fail_of_increasing_quality = v22[1].m_last_fail_of_increasing_quality;
    if ( m_last_fail_of_increasing_quality != 0.0 )
    {
      v22 = *(vostok::resources::resource_base **)(LODWORD(m_last_fail_of_increasing_quality) + 32);
      if ( v22 )
        continue;
    }
    goto LABEL_47;
  }
  v23 = 1;
LABEL_47:
  v26 = vostok::resources::resources_manager::find_cook(v24, resource_base->m_class_id);
  if ( !v5 || v26 && !v26->cache_by_game_resources_manager(v26) )
    goto LABEL_54;
  v33 = 1;
  boost::function2<void,unsigned int,unsigned int>::function2<void,unsigned int,unsigned int>(
    (boost::function4<void,unsigned int,float,float,char const *> *)((char *)&dword_205B0
                                                                   + (unsigned int)vostok::resources::g_resources_manager.m_variable),
    (int)&v37);
  v27 = v37;
  v28 = -(v37 != 0);
  if ( ((unsigned int)survarium::weapon_user_dead_state::finalize & v28) == 0 || v23 )
    goto LABEL_55;
  if ( (vostok::resources::resource_flags::cast_base_of_intrusive_base((vostok::resources::resource_flags *)v28, v5)->m_flags.m_flags
      & 4) != 0 )
  {
LABEL_54:
    v27 = v37;
LABEL_55:
    v29 = 0;
    goto LABEL_56;
  }
  v27 = v37;
  v29 = 1;
LABEL_56:
  if ( (v33 & 1) != 0 )
  {
    if ( v27 )
    {
      if ( (v27 & 1) == 0 )
      {
        v30 = *(void (__cdecl **)(_BYTE *, _BYTE *, int))(v27 & 0xFFFFFFFE);
        if ( v30 )
          v30(v38, v38, 2);
      }
    }
  }
  if ( v29 )
  {
    resource_base[3].m_parent_resources.m_last = (vostok::resources::resource_link *)v5;
    if ( (*(_DWORD *)(v5 + 8) & 1) != 0 && v5 )
    {
      v31 = (volatile signed __int32 *)(v5 + 220);
    }
    else if ( (*(_DWORD *)(v5 + 8) & 4) != 0 && v5 )
    {
      v31 = (volatile signed __int32 *)(v5 + 208);
    }
    else
    {
      v31 = 0;
    }
    _InterlockedExchangeAdd(v31, 1u);
    vostok::threading::interlocked_or(v31 + 1, 6u);
  }
}
