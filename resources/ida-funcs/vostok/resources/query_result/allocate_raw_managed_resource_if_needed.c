int __thiscall vostok::resources::query_result::allocate_raw_managed_resource_if_needed(
        vostok::resources::query_result *this,
        int a2)
{
  vostok::resources::inplace_managed_cook *inplace_managed_cook; // edi
  vostok::resources::query_result *v4; // ecx
  vostok::resources::inplace_managed_cook_vtbl *v5; // esi
  bool resource_if_no_file; // al
  vostok::memory::managed_allocator_base *file; // eax
  vostok::resources::resources_manager *v8; // ecx
  vostok::vfs::base_node<1> *v10; // eax
  vostok::resources::managed_resource *managed_resource; // eax
  vostok::resources::managed_resource *v12; // ecx
  int v13; // edi
  vostok::resources::managed_resource *m_object; // ecx
  vostok::vfs::vfs_iterator *v15; // eax
  vostok::resources::query_result *v16; // ecx
  int v17; // [esp-10h] [ebp-54h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v18; // [esp-4h] [ebp-48h] BYREF
  int v19[8]; // [esp+10h] [ebp-34h] BYREF
  _DWORD v20[5]; // [esp+30h] [ebp-14h] BYREF
  unsigned int raw_file_size; // [esp+4Ch] [ebp+8h]
  vostok::memory::managed_allocator_base *v22; // [esp+4Ch] [ebp+8h]

  if ( vostok::resources::cook_base::find_managed_cook(*(vostok::resources::class_id_enum *)(a2 + 132))
    || vostok::resources::cook_base::find_unmanaged_cook(*(vostok::resources::class_id_enum *)(a2 + 132))
    || !vostok::resources::resources_manager::find_cook(*(vostok::resources::class_id_enum *)(a2 + 132)) )
  {
    if ( !*(_DWORD *)(a2 + 164) )
      return 0;
    v10 = *(vostok::vfs::base_node<1> **)(a2 + 168);
    if ( !v10 )
      v10 = *(vostok::vfs::base_node<1> **)(a2 + 164);
    file = (vostok::memory::managed_allocator_base *)vostok::vfs::get_file_size<1>(v10);
  }
  else
  {
    inplace_managed_cook = vostok::resources::cook_base::find_inplace_managed_cook(*(vostok::resources::class_id_enum *)(a2 + 132));
    if ( vostok::resources::query_result::need_create_resource_if_no_file(
           (vostok::resources::query_result *)v18.m_object,
           (_DWORD *)a2) )
    {
      raw_file_size = 0;
    }
    else
    {
      raw_file_size = vostok::resources::query_result_for_cook::get_raw_file_size(v4, (_DWORD *)a2);
    }
    v5 = inplace_managed_cook->__vftable;
    resource_if_no_file = vostok::resources::query_result::need_create_resource_if_no_file(v4, (_DWORD *)a2);
    file = (vostok::memory::managed_allocator_base *)v5->calculate_resource_size(
                                                       inplace_managed_cook,
                                                       raw_file_size,
                                                       (unsigned int *)(a2 + 688),
                                                       !resource_if_no_file);
  }
  v22 = file;
  managed_resource = vostok::resources::resources_manager::allocate_managed_resource(v8, file, raw_data_class);
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::operator=(
    (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)(a2 + 648),
    managed_resource);
  v13 = 0;
  if ( *(_DWORD *)(a2 + 648) )
  {
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      if ( (*(_DWORD *)(a2 + 704) & 0x800) != 0 )
      {
        memset(v20, 0, 12);
        v20[3] = 3;
        v15 = (vostok::vfs::vfs_iterator *)v20;
      }
      else
      {
        v15 = (vostok::vfs::vfs_iterator *)(a2 + 160);
      }
      vostok::resources::managed_resource::late_set_fat_it(
        (vostok::resources::managed_resource *)&v17,
        *(vostok::vfs::vfs_iterator **)(a2 + 648),
        *v15);
    }
    v18.m_object = v12;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
      &v18,
      (const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)(a2 + 648));
    vostok::resources::query_result::set_creation_source_for_resource(v16, a2, v18);
    return 1;
  }
  else
  {
    *(_DWORD *)(a2 + 324) = &vostok::resources::managed_memory;
    *(_DWORD *)(a2 + 328) = v22;
    v18.m_object = (vostok::resources::managed_resource *)v19;
    *(_DWORD *)(a2 + 320) = 3;
    *(_DWORD *)(a2 + 256) = 7;
    vostok::resources::get_out_of_memory_callback((boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)v18.m_object);
    m_object = v18.m_object;
    if ( (v19[0] != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
    {
      boost::function1<void,vostok::collision::object const &>::operator()(
        (boost::function1<void,vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> const &> *)v18.m_object,
        v19,
        (const vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)a2);
      v13 = 2;
    }
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)m_object,
      v19);
    return v13;
  }
}
