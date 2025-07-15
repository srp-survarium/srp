int __usercall vostok::resources::query_result::allocate_compressed_resource_if_needed@<eax>(
        vostok::resources::query_result *this@<ecx>,
        int a2@<edi>)
{
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v2; // esi
  vostok::vfs::base_node<1> *v3; // eax
  unsigned int compressed_file_size; // ebx
  vostok::resources::resources_manager *v5; // ecx
  vostok::resources::managed_resource *managed_resource; // eax
  vostok::vfs::vfs_iterator::type_enum v7; // ecx
  int v8; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v9; // ecx
  const vostok::vfs::vfs_iterator *v11; // eax
  vostok::resources::managed_resource *v12; // ecx
  vostok::resources::query_result *v13; // ecx
  vostok::vfs::vfs_iterator v14[2]; // [esp-10h] [ebp-54h] BYREF
  vostok::vfs::vfs_iterator result; // [esp+10h] [ebp-34h] BYREF
  boost::function<void __cdecl(vostok::resources::query_result *)> callback; // [esp+20h] [ebp-24h] BYREF

  v2 = (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)(a2 + 628);
  if ( !*(_DWORD *)(a2 + 628)
    || !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    if ( !*(_DWORD *)(a2 + 164) )
      return 0;
    if ( !vostok::vfs::vfs_iterator::is_compressed((vostok::vfs::vfs_iterator *)(a2 + 160)) )
      return 0;
    v3 = vostok::vfs::vfs_iterator::data_node((vostok::vfs::vfs_iterator *)(a2 + 160));
    if ( vostok::vfs::base_node<1>::is_inlined(v3) )
      return 0;
    compressed_file_size = vostok::vfs::vfs_iterator::get_compressed_file_size((vostok::vfs::vfs_iterator *)(a2 + 160));
    managed_resource = vostok::resources::resources_manager::allocate_managed_resource(
                         v5,
                         compressed_file_size,
                         raw_data_class);
    vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::operator=(
      v2,
      managed_resource);
    if ( !v2->m_object )
    {
      *(_DWORD *)(a2 + 308) = &vostok::resources::managed_memory;
      *(_DWORD *)(a2 + 312) = compressed_file_size;
      *(_DWORD *)(a2 + 304) = 3;
      *(_DWORD *)(a2 + 256) = 7;
      boost::function2<void,unsigned int,unsigned int>::function2<void,unsigned int,unsigned int>(
        (boost::function4<void,unsigned int,float,float,char const *> *)&s_out_of_memory_callback,
        (int)&callback);
      v8 = -(callback.vtable != 0);
      if ( ((unsigned int)survarium::weapon_user_dead_state::finalize & v8) != 0 )
      {
        boost::function1<void,vostok::collision::object const &>::operator()(
          (boost::function1<void,vostok::collision::object const &> *)v8,
          &callback,
          (const vostok::collision::object *)a2);
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          v9,
          (int *)&callback);
        return 2;
      }
      boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
        (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)v8,
        (int *)&callback);
      return 0;
    }
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      if ( (*(_DWORD *)(a2 + 688) & 0x800) != 0 )
        v11 = vostok::vfs::vfs_iterator::end(&result);
      else
        v11 = (const vostok::vfs::vfs_iterator *)(a2 + 160);
      vostok::vfs::vfs_iterator::vfs_iterator(v14, v11);
      vostok::resources::managed_resource::late_set_fat_it(v12, v14[0]);
    }
    v14[0].m_type = v7;
    vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>(
      (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&v14[0].m_type,
      (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)(a2 + 628));
    vostok::resources::query_result::set_creation_source_for_resource(
      v13,
      a2,
      (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>)v14[0].m_type);
  }
  return 1;
}
