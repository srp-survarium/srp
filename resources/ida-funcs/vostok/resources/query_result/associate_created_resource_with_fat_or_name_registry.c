void __thiscall vostok::resources::query_result::associate_created_resource_with_fat_or_name_registry(
        vostok::resources::query_result *this,
        int a2)
{
  vostok::resources::name_registry_entry *v3; // edi
  vostok::resources::cook_base *cook; // eax
  vostok::resources::resource_flags *v5; // eax
  char v6; // cl
  bool v7; // dl
  vostok::resources::resource_base *v8; // ecx
  vostok::threading::mutex *v9; // ecx
  char *v10; // eax
  vostok::memory::doug_lea_allocator *v11; // ecx
  char *v12; // eax
  char *v13; // eax
  vostok::resources::resource_flags **v14; // eax
  vostok::resources::resource_flags *v15; // eax
  vostok::hash_multiset<vostok::resources::name_registry_entry,vostok::resources::name_registry_entry *,12,vostok::detail::fixed_size_policy<32768>,vostok::resources::detail::name_registry_hash,vostok::resources::detail::name_registry_equal,vostok::threading::single_threading_policy> *v16; // ecx
  int v17; // eax
  int v18; // eax
  vostok::resources::cook_base *v19; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v20; // ecx
  vostok::resources::resource_flags *v21; // ecx
  vostok::resources::base_of_intrusive_base *v22; // eax
  vostok::resources::resource_base *v23; // [esp-4h] [ebp-50h]
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v24; // [esp-4h] [ebp-50h]
  const char *v25; // [esp+0h] [ebp-4Ch]
  const char *v26; // [esp+4h] [ebp-48h]
  unsigned int v27; // [esp+8h] [ebp-44h]
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> f; // [esp+10h] [ebp-3Ch] BYREF
  vostok::hash_multiset<vostok::resources::name_registry_entry,vostok::resources::name_registry_entry *,12,vostok::detail::fixed_size_policy<32768>,vostok::resources::detail::name_registry_hash,vostok::resources::detail::name_registry_equal,vostok::threading::single_threading_policy>::iterator v29; // [esp+34h] [ebp-18h] BYREF
  int v30; // [esp+40h] [ebp-Ch]
  vostok::resources::resource_flags *v31; // [esp+44h] [ebp-8h]
  unsigned int v32; // [esp+54h] [ebp+8h]
  char v33; // [esp+57h] [ebp+Bh]
  char v34; // [esp+57h] [ebp+Bh]

  v3 = 0;
  v30 = 0;
  v31 = 0;
  if ( !*(_DWORD *)(a2 + 164) )
  {
    if ( (vostok::resources::query_result::is_translate_query(this, a2) || *(_DWORD *)(a2 + 208)
                                                                        || *(_DWORD *)(a2 + 212))
      && vostok::resources::cook_base::reuse_type(*(vostok::resources::class_id_enum *)(a2 + 132)) == reuse_true )
    {
      v9 = (vostok::threading::mutex *)strlen(*(const char **)(a2 + 248));
      if ( v9 )
      {
        if ( !*(_DWORD *)(a2 + 256) )
        {
          v32 = strlen(*(const char **)(a2 + 248)) + 21;
          v10 = type_info::raw_name(&char `RTTI Type Descriptor');
          v12 = vostok::memory::doug_lea_allocator::malloc_impl(
                  v11,
                  (int)&vostok::memory::g_resources_helper_allocator,
                  v32,
                  v10,
                  v25,
                  v26,
                  v27);
          if ( v12 )
          {
            *(_DWORD *)v12 = 0;
            *((_DWORD *)v12 + 1) = 0;
            *((_DWORD *)v12 + 2) = 0;
            *((_DWORD *)v12 + 4) = 0;
            v3 = (vostok::resources::name_registry_entry *)v12;
          }
          else
          {
            v3 = 0;
          }
          v13 = v12 + 20;
          v3->name = v13;
          v3->class_id = *(_DWORD *)(a2 + 132);
          vostok::strings::copy(v13, v32 - 20, *(char **)(a2 + 248));
          v14 = (vostok::resources::resource_flags **)(a2 + 216);
          v9 = *(vostok::threading::mutex **)(a2 + 216);
          if ( !v9
            || !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
          {
            v14 = (vostok::resources::resource_flags **)(a2 + 220);
            v9 = *(vostok::threading::mutex **)(a2 + 220);
          }
          v3->associated = (vostok::resources::resource_base *)v9;
          v15 = *v14;
          v15[14].m_flags.m_flags = (volatile int)v3;
          v31 = v15;
        }
        vostok::threading::mutex::lock(v9, (_RTL_CRITICAL_SECTION *)&s_resources_manager_buffer.m_name_registry_mutex);
        vostok::hash_multiset<vostok::resources::name_registry_entry,vostok::resources::name_registry_entry *,12,vostok::detail::fixed_size_policy<32768>,vostok::resources::detail::name_registry_hash,vostok::resources::detail::name_registry_equal,vostok::threading::single_threading_policy>::find(
          v16,
          &s_resources_manager_buffer.m_name_registry,
          &v29,
          (vostok::resources::name_registry_entry *)(a2 + 668));
        vostok::hash_multiset<vostok::resources::name_registry_entry,vostok::resources::name_registry_entry *,12,vostok::detail::fixed_size_policy<32768>,vostok::resources::detail::name_registry_hash,vostok::resources::detail::name_registry_equal,vostok::threading::single_threading_policy>::erase(
          &s_resources_manager_buffer.m_name_registry,
          v29.m_index,
          v29.m_value);
        _InterlockedAnd((volatile signed __int32 *)(a2 + 704), 0xFEFFFFFF);
        if ( !*(_DWORD *)(a2 + 256) )
          vostok::hash_multiset<vostok::resources::name_registry_entry,vostok::resources::name_registry_entry *,12,vostok::detail::fixed_size_policy<32768>,vostok::resources::detail::name_registry_hash,vostok::resources::detail::name_registry_equal,vostok::threading::single_threading_policy>::insert(
            &s_resources_manager_buffer.m_name_registry,
            v3);
        LeaveCriticalSection((LPCRITICAL_SECTION)&s_resources_manager_buffer.m_name_registry_mutex);
      }
    }
    goto LABEL_39;
  }
  cook = vostok::resources::resources_manager::find_cook(*(vostok::resources::class_id_enum *)(a2 + 132));
  if ( cook )
  {
    v6 = cook->m_flags.m_flags & 0x20;
    v7 = v6 == 32;
    if ( v6 != 32 )
      goto LABEL_13;
    if ( cook->m_reuse_type == reuse_true )
    {
      v8 = *(vostok::resources::resource_base **)(a2 + 216);
      if ( v8 )
      {
        if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
        {
          v31 = *(vostok::resources::resource_flags **)(a2 + 216);
          v23 = v8;
LABEL_22:
          vostok::resources::set_associated(*(vostok::vfs::vfs_iterator *)(a2 + 160), v23);
          goto LABEL_39;
        }
      }
    }
    if ( !v7 )
    {
LABEL_13:
      if ( cook->m_reuse_type == reuse_raw
        && *(_DWORD *)(a2 + 648)
        && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        if ( (*(_DWORD *)(a2 + 704) & 0x80000) != 0 )
          v31 = *(vostok::resources::resource_flags **)(a2 + 648);
        _InterlockedOr((volatile signed __int32 *)(*(_DWORD *)(a2 + 648) + 8), 0x10u);
        v23 = *(vostok::resources::resource_base **)(a2 + 648);
        goto LABEL_22;
      }
      if ( v7 )
        goto LABEL_39;
      if ( cook->m_reuse_type != reuse_true )
        goto LABEL_39;
      v5 = *(vostok::resources::resource_flags **)(a2 + 220);
      if ( !v5
        || !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        goto LABEL_39;
      }
      goto LABEL_21;
    }
  }
  else if ( *(_DWORD *)(a2 + 132) != 4 )
  {
    v5 = *(vostok::resources::resource_flags **)(a2 + 216);
LABEL_21:
    v31 = v5;
    v23 = (vostok::resources::resource_base *)v5;
    goto LABEL_22;
  }
LABEL_39:
  v17 = a2;
  v33 = 0;
  while ( (*(_DWORD *)(v17 + 704) & 0x4000000) == 0 )
  {
    v18 = *(_DWORD *)(v17 + 344);
    if ( v18 )
    {
      v17 = *(_DWORD *)(v18 + 32);
      if ( v17 )
        continue;
    }
    goto LABEL_45;
  }
  v33 = 1;
LABEL_45:
  v19 = vostok::resources::resources_manager::find_cook(*(vostok::resources::class_id_enum *)(a2 + 132));
  v20 = v24;
  if ( !v31
    || v19 && !v19->cache_by_game_resources_manager(v19)
    || (v30 = 1,
        boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(
          (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&s_resources_manager_buffer.m_query_finished_callback,
          &f),
        (f.vtable != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) == 0)
    || v33
    || (v34 = 1, (vostok::resources::resource_flags::cast_base_of_intrusive_base(v31)->m_flags.m_flags & 4) != 0) )
  {
    v34 = 0;
  }
  if ( (v30 & 1) != 0 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v20,
      (int *)&f);
  if ( v34 )
  {
    v21 = v31;
    *(_DWORD *)(a2 + 720) = v31;
    v22 = vostok::resources::resource_flags::cast_base_of_intrusive_base(v21);
    _InterlockedExchangeAdd(&v22->m_reference_count, 1u);
    _InterlockedOr(&v22->m_flags.m_flags, 6u);
  }
}
