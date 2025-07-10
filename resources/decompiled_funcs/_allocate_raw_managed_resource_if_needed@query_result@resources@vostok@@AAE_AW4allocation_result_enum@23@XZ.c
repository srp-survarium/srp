int __usercall vostok::resources::query_result::allocate_raw_managed_resource_if_needed@<eax>(
        vostok::resources::query_result *this@<ecx>,
        int a2@<edi>)
{
  vostok::resources::cook_base *cook; // eax
  unsigned int v3; // eax
  vostok::resources::cook_base *v4; // eax
  vostok::resources::cook_base *v5; // eax
  vostok::resources::query_result *m_flags; // ecx
  vostok::resources::cook_base *v7; // esi
  vostok::resources::query_result *v8; // ecx
  unsigned int raw_file_size; // ebp
  vostok::resources::cook_base_vtbl *v10; // ebx
  bool resource_if_no_file; // al
  unsigned int file_size; // eax
  vostok::resources::resources_manager *v13; // ecx
  unsigned int v14; // ebx
  vostok::resources::managed_resource *managed_resource; // eax
  vostok::resources::managed_resource *m_object; // eax
  boost::function1<void,vostok::collision::object const &> *v17; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v18; // ecx
  const vostok::vfs::vfs_iterator *v20; // eax
  vostok::resources::managed_resource *v21; // ecx
  vostok::resources::query_result *v22; // ecx
  vostok::resources::resource_base::creation_source_enum v23; // eax
  vostok::vfs::vfs_iterator v24; // [esp-10h] [ebp-5Ch] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v25; // [esp+10h] [ebp-3Ch] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v26; // [esp+14h] [ebp-38h] BYREF
  vostok::vfs::vfs_iterator result; // [esp+18h] [ebp-34h] BYREF
  boost::function<void __cdecl(vostok::resources::query_result *)> callback; // [esp+28h] [ebp-24h] BYREF

  cook = vostok::resources::resources_manager::find_cook(*(vostok::resources::class_id_enum *)(a2 + 132));
  if ( cook && (v3 = cook->m_flags.m_flags, (v3 & 0x20) != 0) && (v3 & 0x18) == 0
    || (v4 = vostok::resources::resources_manager::find_cook(*(vostok::resources::class_id_enum *)(a2 + 132))) != 0
    && (v4->m_flags.m_flags & 0x38) == 0
    || !vostok::resources::resources_manager::find_cook(*(vostok::resources::class_id_enum *)(a2 + 132)) )
  {
    if ( !*(_DWORD *)(a2 + 164) )
      return 0;
    file_size = vostok::vfs::vfs_iterator::get_file_size((vostok::vfs::vfs_iterator *)(a2 + 160));
  }
  else
  {
    v5 = vostok::resources::resources_manager::find_cook(*(vostok::resources::class_id_enum *)(a2 + 132));
    if ( v5 )
    {
      m_flags = (vostok::resources::query_result *)v5->m_flags.m_flags;
      if ( ((unsigned __int8)m_flags & 0x20) == 0
        || ((unsigned __int8)m_flags & 0x10) == 0
        || ((unsigned __int8)m_flags & 8) != 0 )
      {
        v5 = 0;
      }
      v7 = v5;
    }
    else
    {
      v7 = 0;
    }
    if ( vostok::resources::query_result::need_create_resource_if_no_file(m_flags) )
      raw_file_size = 0;
    else
      raw_file_size = vostok::resources::query_result_for_cook::get_raw_file_size(v8);
    v10 = v7->__vftable;
    resource_if_no_file = vostok::resources::query_result::need_create_resource_if_no_file(v8);
    file_size = ((int (__thiscall *)(vostok::resources::cook_base *, unsigned int, int, bool))v10[1].calculate_quality_levels_count)(
                  v7,
                  raw_file_size,
                  a2 + 672,
                  !resource_if_no_file);
  }
  v14 = file_size;
  managed_resource = vostok::resources::resources_manager::allocate_managed_resource(v13, file_size, raw_data_class);
  v25.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &v25,
    managed_resource);
  m_object = v25.m_object;
  v25.m_object = *(vostok::resources::managed_resource **)(a2 + 632);
  *(_DWORD *)(a2 + 632) = m_object;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&v25);
  if ( !*(_DWORD *)(a2 + 632) )
  {
    *(_DWORD *)(a2 + 308) = &vostok::resources::managed_memory;
    *(_DWORD *)(a2 + 312) = v14;
    *(_DWORD *)(a2 + 304) = 3;
    *(_DWORD *)(a2 + 256) = 7;
    boost::function2<void,unsigned int,unsigned int>::function2<void,unsigned int,unsigned int>(
      (boost::function4<void,unsigned int,float,float,char const *> *)&s_out_of_memory_callback,
      (int)&callback);
    if ( (callback.vtable != 0 ? (unsigned int)survarium::weapon_user_dead_state::finalize : 0) != 0 )
    {
      boost::function1<void,vostok::collision::object const &>::operator()(
        v17,
        &callback,
        (const vostok::collision::object *)a2);
      boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
        v18,
        (int *)&callback);
      return 2;
    }
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)v17,
      (int *)&callback);
    return 0;
  }
  if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    if ( (*(_DWORD *)(a2 + 688) & 0x800) != 0 )
      v20 = vostok::vfs::vfs_iterator::end(&result);
    else
      v20 = (const vostok::vfs::vfs_iterator *)(a2 + 160);
    vostok::vfs::vfs_iterator::vfs_iterator(&v24, v20);
    vostok::resources::managed_resource::late_set_fat_it(v21, v24);
  }
  v26.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &v26,
    (const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)(a2 + 632));
  v23 = vostok::resources::query_result::creation_source_for_resource(v22, a2);
  v26.m_object->m_creation_source = v23;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&v26);
  return 1;
}
