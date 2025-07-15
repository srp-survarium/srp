int __thiscall vostok::resources::query_result::allocate_compressed_resource_if_needed(
        vostok::resources::query_result *this,
        int a2)
{
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v3; // esi
  int v5; // edx
  int v6; // eax
  vostok::vfs::base_node<1> *v7; // eax
  vostok::resources::resources_manager *v8; // ecx
  vostok::resources::managed_resource *managed_resource; // eax
  vostok::resources::managed_resource *v10; // ecx
  int v11; // edi
  vostok::resources::managed_resource *m_object; // ecx
  vostok::vfs::vfs_iterator *v13; // eax
  vostok::resources::query_result *v14; // ecx
  int v15; // [esp-10h] [ebp-54h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v16; // [esp-4h] [ebp-48h] BYREF
  int v17[8]; // [esp+10h] [ebp-34h] BYREF
  _DWORD v18[5]; // [esp+30h] [ebp-14h] BYREF
  vostok::memory::managed_allocator_base *compressed_file; // [esp+4Ch] [ebp+8h]

  v3 = (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)(a2 + 644);
  if ( *(_DWORD *)(a2 + 644)
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    return 1;
  }
  if ( !*(_DWORD *)(a2 + 164) || !vostok::vfs::vfs_iterator::is_compressed((vostok::vfs::vfs_iterator *)(a2 + 160)) )
    return 0;
  v6 = *(_DWORD *)(v5 + 8);
  if ( !v6 )
    v6 = *(_DWORD *)(v5 + 4);
  if ( (*(_BYTE *)(v6 + 48) & 0x40) != 0 )
    return 0;
  v7 = *(vostok::vfs::base_node<1> **)(v5 + 8);
  if ( !v7 )
    v7 = *(vostok::vfs::base_node<1> **)(v5 + 4);
  compressed_file = (vostok::memory::managed_allocator_base *)vostok::vfs::get_compressed_file_size<1>(v7);
  managed_resource = vostok::resources::resources_manager::allocate_managed_resource(
                       v8,
                       compressed_file,
                       raw_data_class);
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::operator=(
    v3,
    managed_resource);
  v11 = 0;
  if ( v3->m_object )
  {
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      if ( (*(_DWORD *)(a2 + 704) & 0x800) != 0 )
      {
        memset(v18, 0, 12);
        v18[3] = 3;
        v13 = (vostok::vfs::vfs_iterator *)v18;
      }
      else
      {
        v13 = (vostok::vfs::vfs_iterator *)(a2 + 160);
      }
      vostok::resources::managed_resource::late_set_fat_it(
        (vostok::resources::managed_resource *)&v15,
        (vostok::vfs::vfs_iterator *)v3->m_object,
        *v13);
    }
    v16.m_object = v10;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
      &v16,
      v3);
    vostok::resources::query_result::set_creation_source_for_resource(v14, a2, v16);
    return 1;
  }
  *(_DWORD *)(a2 + 324) = &vostok::resources::managed_memory;
  *(_DWORD *)(a2 + 328) = compressed_file;
  v16.m_object = (vostok::resources::managed_resource *)v17;
  *(_DWORD *)(a2 + 320) = 3;
  *(_DWORD *)(a2 + 256) = 7;
  vostok::resources::get_out_of_memory_callback((boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)v16.m_object);
  m_object = v16.m_object;
  if ( (v17[0] != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
  {
    boost::function1<void,vostok::collision::object const &>::operator()(
      (boost::function1<void,vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> const &> *)v16.m_object,
      v17,
      (const vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)a2);
    v11 = 2;
  }
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)m_object,
    v17);
  return v11;
}
