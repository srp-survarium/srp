int __thiscall vostok::resources::query_result::allocate_final_managed_resource_if_needed(
        vostok::resources::query_result *this,
        int a2)
{
  vostok::resources::query_result *v3; // ecx
  vostok::const_buffer *v4; // eax
  const char *m_data; // esi
  vostok::resources::managed_cook_vtbl *v6; // edi
  bool resource_if_no_file; // al
  vostok::resources::query_result *v8; // ecx
  vostok::resources::query_result *v9; // ecx
  vostok::resources::managed_resource *managed_resource; // eax
  int v11; // edi
  vostok::resources::managed_resource *m_object; // ecx
  vostok::vfs::vfs_iterator *v14; // eax
  vostok::resources::managed_resource *v15; // ecx
  vostok::resources::query_result *v16; // ecx
  int v17; // [esp-10h] [ebp-6Ch] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v18; // [esp-4h] [ebp-60h] BYREF
  int v19[8]; // [esp+10h] [ebp-4Ch] BYREF
  _DWORD v20[4]; // [esp+30h] [ebp-2Ch] BYREF
  const char *v21; // [esp+40h] [ebp-1Ch] BYREF
  _DWORD v22[2]; // [esp+48h] [ebp-14h] BYREF
  vostok::const_buffer pinned_raw_buffer; // [esp+50h] [ebp-Ch] BYREF
  vostok::resources::managed_cook *managed_cook; // [esp+64h] [ebp+8h]
  vostok::memory::managed_allocator_base *v25; // [esp+64h] [ebp+8h]

  managed_cook = vostok::resources::cook_base::find_managed_cook(*(vostok::resources::class_id_enum *)(a2 + 132));
  if ( vostok::resources::query_result::need_create_resource_if_no_file(
         (vostok::resources::query_result *)v18.m_object,
         (_DWORD *)a2) )
  {
    v22[0] = 0;
    v22[1] = 0;
    v4 = (vostok::const_buffer *)v22;
  }
  else
  {
    v4 = vostok::resources::query_result::pin_raw_buffer((vostok::resources::query_result *)a2, &v21);
  }
  m_data = v4->m_data;
  pinned_raw_buffer.m_size = v4->m_size;
  v6 = managed_cook->__vftable;
  pinned_raw_buffer.m_data = m_data;
  resource_if_no_file = vostok::resources::query_result::need_create_resource_if_no_file(v3, (_DWORD *)a2);
  v25 = (vostok::memory::managed_allocator_base *)((int (__thiscall *)(vostok::resources::managed_cook *, const char *, unsigned int, bool))v6->calculate_resource_size)(
                                                    managed_cook,
                                                    m_data,
                                                    pinned_raw_buffer.m_size,
                                                    !resource_if_no_file);
  if ( !vostok::resources::query_result::need_create_resource_if_no_file(v8, (_DWORD *)a2) )
    vostok::resources::query_result::unpin_raw_buffer(v9, &pinned_raw_buffer);
  if ( !v25 )
    return 1;
  managed_resource = vostok::resources::resources_manager::allocate_managed_resource(
                       (vostok::resources::resources_manager *)v9,
                       v25,
                       *(vostok::resources::class_id_enum *)(a2 + 132));
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::operator=(
    (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)(a2 + 216),
    managed_resource);
  v11 = 0;
  if ( *(_DWORD *)(a2 + 216) )
  {
    if ( (*(_DWORD *)(a2 + 704) & 0x800) != 0 )
    {
      memset(v20, 0, 12);
      v20[3] = 3;
      v14 = (vostok::vfs::vfs_iterator *)v20;
    }
    else
    {
      v14 = (vostok::vfs::vfs_iterator *)(a2 + 160);
    }
    vostok::resources::managed_resource::late_set_fat_it(
      (vostok::resources::managed_resource *)&v17,
      *(vostok::vfs::vfs_iterator **)(a2 + 216),
      *v14);
    v18.m_object = v15;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
      &v18,
      (const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)(a2 + 216));
    vostok::resources::query_result::set_creation_source_for_resource(v16, a2, v18);
    return 1;
  }
  *(_DWORD *)(a2 + 324) = &vostok::resources::managed_memory;
  *(_DWORD *)(a2 + 328) = v25;
  v18.m_object = (vostok::resources::managed_resource *)v19;
  *(_DWORD *)(a2 + 320) = 4;
  *(_DWORD *)(a2 + 256) = 7;
  vostok::resources::get_out_of_memory_callback((boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)v18.m_object);
  m_object = v18.m_object;
  if ( (v19[0] != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
  {
    boost::function1<void,vostok::collision::object const &>::operator()(
      (boost::function1<void,vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> const &> *)v18.m_object,
      v19,
      (const vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)a2);
    v11 = 2;
  }
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)m_object,
    v19);
  return v11;
}
