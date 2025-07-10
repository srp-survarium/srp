void __userpurge vostok::vfs::physical_path_mounter::mount_physical_folder(
        vostok::vfs::physical_path_mounter *this@<ecx>,
        unsigned int a2@<ebx>,
        vostok::fs_new::virtual_path_string *folder_path,
        vostok::vfs::base_folder_node<1> *folder,
        vostok::fs_new::native_path_string *absolute_path,
        unsigned int folder_hash)
{
  survarium::game_camera *v6; // ecx
  survarium::game_camera *v7; // ecx
  survarium::game_camera *v8; // ecx
  vostok::buffer_string *v9; // ecx
  vostok::vfs::base_node<1> *v10; // eax
  survarium::game_camera *v11; // ecx
  vostok::vfs::base_folder_node<1> *v12; // eax
  survarium::game_camera *v13; // ecx
  int v14; // [esp-Ch] [ebp-834h] BYREF
  bool v15; // [esp+7h] [ebp-821h]
  BOOL v16; // [esp+8h] [ebp-820h]
  vostok::vfs::physical_path_mounter *thisa; // [esp+Ch] [ebp-81Ch]
  vostok::vfs::base_node<1> *pointer; // [esp+24h] [ebp-804h]
  int *v19; // [esp+54h] [ebp-7D4h]
  _DWORD v20[5]; // [esp+58h] [ebp-7D0h] BYREF
  _DWORD v21[4]; // [esp+6Ch] [ebp-7BCh] BYREF
  unsigned __int64 file_size; // [esp+7Ch] [ebp-7ACh]
  char v23; // [esp+87h] [ebp-7A1h]
  vostok::fs_new::physical_path_initializer *v24; // [esp+90h] [ebp-798h]
  vostok::fs_new::physical_path_initializer *initializer; // [esp+94h] [ebp-794h]
  vostok::fs_new::device_file_system_proxy_base *p_m_device; // [esp+98h] [ebp-790h]
  vostok::fs_new::physical_path_initializer v27; // [esp+A0h] [ebp-788h] BYREF
  vostok::fs_new::physical_path_initializer result; // [esp+1E0h] [ebp-648h] BYREF
  char v29; // [esp+327h] [ebp-501h]
  vostok::vfs::base_node<1> *node; // [esp+328h] [ebp-500h]
  vostok::vfs::physical_folder_node<1> *folder_node; // [esp+32Ch] [ebp-4FCh]
  vostok::fs_new::virtual_path_string name; // [esp+330h] [ebp-4F8h] BYREF
  vostok::vfs::physical_file_node<1> *file_node; // [esp+44Ch] [ebp-3DCh]
  vostok::fs_new::physical_path_iterator it_end; // [esp+450h] [ebp-3D8h] BYREF
  vostok::fs_new::physical_path_iterator it; // [esp+590h] [ebp-298h] BYREF
  bool out_of_memory; // [esp+6D3h] [ebp-155h]
  unsigned int folder_size; // [esp+6D4h] [ebp-154h]
  vostok::intrusive_list<vostok::vfs::base_node<1>,vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper,24,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> new_nodes; // [esp+6D8h] [ebp-150h] BYREF
  vostok::fs_new::physical_path_info path_info; // [esp+6F0h] [ebp-138h] BYREF

  thisa = this;
  p_m_device = &this->m_device->m_device;
  vostok::fs_new::device_file_system_proxy_base::get_physical_path_info(p_m_device, &path_info, absolute_path);
  v29 = 0;
  survarium::weapon_user_dead_state::finalize(v6);
  folder_size = 0;
  vostok::intrusive_list<vostok::vfs::base_node<1>,vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper,24,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::intrusive_list<vostok::vfs::base_node<1>,vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper,24,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>(&new_nodes);
  out_of_memory = 0;
  initializer = vostok::fs_new::physical_path_info::children_begin(&path_info, &result);
  vostok::fs_new::physical_path_info::physical_path_info(&it, initializer);
  survarium::weapon_user_dead_state::finalize(v7);
  it.search_handle = initializer->search_handle;
  v24 = vostok::fs_new::physical_path_info::children_end(&path_info, &v27);
  vostok::fs_new::physical_path_info::physical_path_info(&it_end, v24);
  survarium::weapon_user_dead_state::finalize(v8);
  it_end.search_handle = v24->search_handle;
  while ( 1 )
  {
    v16 = it.search_handle != it_end.search_handle;
    if ( it.search_handle == it_end.search_handle )
      break;
    vostok::fs_new::virtual_path_string::virtual_path_string(&name);
    vostok::fs_new::physical_path_info::get_name<vostok::fs_new::virtual_path_string>(&it, &name);
    vostok::buffer_string::make_lowercase(v9, (int)&name);
    node = 0;
    file_node = 0;
    folder_node = 0;
    if ( it.data.type == type_file )
    {
      v23 = 0;
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)1);
      file_size = it.data.file_size;
      file_node = vostok::vfs::physical_file_node<1>::create(
                    thisa->m_args.allocator,
                    thisa->m_mount_root_base,
                    (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&name,
                    it.data.file_size);
      if ( !file_node )
      {
        out_of_memory = 1;
        break;
      }
      v21[2] = v21;
      v21[0] = 8;
      v21[1] = 8;
      _InterlockedOr(&file_node->m_file_flags.m_flags, 8u);
      node = vostok::vfs::node_cast<vostok::vfs::base_node,vostok::vfs::hard_link_node,1>((vostok::vfs::hard_link_node<1> *)file_node);
    }
    else
    {
      folder_node = vostok::vfs::physical_folder_node<1>::create(
                      thisa->m_args.allocator,
                      thisa->m_mount_root_base,
                      (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&name);
      if ( !folder_node )
      {
        out_of_memory = 1;
        break;
      }
      v20[3] = v20;
      v20[0] = 4;
      v20[1] = 4;
      v20[2] = 4;
      _InterlockedOr(&folder_node->m_folder_flags.m_flags, 4u);
      node = vostok::vfs::node_cast<vostok::vfs::base_node,vostok::vfs::physical_folder_node,1>(folder_node);
    }
    v10 = vostok::vfs::base_node<1>::sizeof_with_name(node);
    folder_size += (unsigned int)v10;
    folder_size = vostok::math::align_up<unsigned int>(folder_size, 4u);
    v19 = &v14;
    vostok::intrusive_list<vostok::vfs::base_node<1>,vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper,24,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
      &new_nodes,
      (vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper)(unsigned int)node,
      0);
    vostok::fs_new::physical_path_iterator::operator++(&it, a2);
  }
  vostok::fs_new::physical_path_iterator::~physical_path_iterator(&it_end);
  vostok::fs_new::physical_path_iterator::~physical_path_iterator(&it);
  if ( out_of_memory )
  {
    thisa->m_result = result_success;
    vostok::vfs::physical_path_mounter::free_node_list(thisa, &new_nodes);
    survarium::weapon_user_dead_state::finalize(v11);
  }
  else
  {
    pointer = new_nodes.m_first.pointer;
    if ( new_nodes.m_first.pointer )
    {
      vostok::vfs::physical_path_mounter::flatten_helper_nodes_and_merge(
        thisa,
        &new_nodes,
        folder_path,
        folder,
        folder_hash,
        folder_size,
        absolute_path);
      v12 = (vostok::vfs::base_folder_node<1> *)vostok::vfs::node_cast<vostok::vfs::base_folder_node,vostok::vfs::physical_folder_node,1>(folder);
      vostok::vfs::mounter::remove_marked_to_unlink_from_parent(v12);
    }
    out_of_memory = thisa->m_result == result_success;
    v15 = thisa->m_args.recursive == recursive_true && !out_of_memory;
    vostok::vfs::physical_folder_node<1>::set_is_scanned((vostok::vfs::physical_folder_node<1> *)folder, v15);
    survarium::weapon_user_dead_state::finalize(v13);
  }
}
