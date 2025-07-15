void __cdecl vostok::vfs::find_async_expand_sub_fat(
        vostok::vfs::base_node<1> *node,
        vostok::vfs::base_node<1> *node_parent,
        vostok::vfs::async_callbacks_data *async_data,
        int increment)
{
  vostok::vfs::base_node<1> *v4; // ecx
  vostok::vfs::physical_folder_mount_root_node<1> *mount_root; // ebx
  vostok::fixed_string<260> *v6; // ecx
  int pointer; // eax
  boost::function<void __cdecl(vostok::vfs::mount_result)> *v8; // ecx
  vostok::vfs::base_node<1> *v9; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v10; // ecx
  vostok::fs_new::synchronous_device_interface *v11; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::vfs::async_callbacks_data,vostok::vfs::mount_result,unsigned int>,boost::_bi::list3<boost::_bi::value<vostok::vfs::async_callbacks_data *>,boost::arg<1>,boost::_bi::value<unsigned int> > > v12; // [esp-30h] [ebp-760h]
  boost::function<void __cdecl(vostok::vfs::mount_result)> v13; // [esp-20h] [ebp-750h] BYREF
  vostok::vfs::query_mount_arguments v14; // [esp+10h] [ebp-720h] BYREF
  vostok::fs_new::virtual_path_string v15; // [esp+4E8h] [ebp-248h] BYREF
  vostok::fs_new::virtual_path_string v16; // [esp+600h] [ebp-130h] BYREF
  void (__thiscall *v17)(vostok::vfs::async_callbacks_data *, vostok::vfs::mount_result, int); // [esp+718h] [ebp-18h]
  vostok::vfs::async_callbacks_data *v18; // [esp+71Ch] [ebp-14h]
  int v19; // [esp+720h] [ebp-10h]
  int v20[2]; // [esp+724h] [ebp-Ch] BYREF
  char v21; // [esp+72Ch] [ebp-4h]

  mount_root = vostok::vfs::base_node<1>::get_mount_root(v4, (int)node);
  v16.m_string.m_begin = v16.m_string.m_buffer;
  v16.m_string.m_end = v16.m_string.m_buffer;
  v16.m_string.m_max_end = &v16.m_separator;
  v16.m_string.m_buffer[0] = 0;
  v16.m_separator = 47;
  vostok::vfs::base_node<1>::get_full_path(node, &v16);
  vostok::fixed_string<260>::fixed_string<260>(v6, &v15.m_string, (char *)mount_root->physical_path.pointer);
  v15.m_separator = 92;
  pointer = (int)mount_root->device.pointer;
  v20[0] = 0;
  v20[1] = pointer;
  v18 = async_data;
  v19 = increment;
  v17 = vostok::vfs::async_callbacks_data::on_automatic_archive_or_subfat_mounted;
  v12.l_.a1_.t_ = (vostok::vfs::async_callbacks_data *)vostok::vfs::async_callbacks_data::on_automatic_archive_or_subfat_mounted;
  v12.l_.a3_.t_ = (unsigned int)async_data;
  v12.f_.f_ = (void (__thiscall *)(vostok::vfs::async_callbacks_data *, vostok::vfs::mount_result, unsigned int))&v13;
  v21 = 0;
  boost::function<void __cdecl (vostok::vfs::mount_result)>::function<void __cdecl (vostok::vfs::mount_result)>(
    v8,
    v12,
    increment);
  vostok::vfs::query_mount_arguments::mount_archive(
    (vostok::vfs::query_mount_arguments *)v20,
    (int)&v14,
    (vostok::vfs::query_mount_arguments *)mount_root->allocator.pointer,
    &v16.m_string,
    &v15,
    (const vostok::fs_new::native_path_string *)&v15,
    (vostok::fs_new::native_path_string *)uri,
    mount_root->async_device.pointer->m_queries.m_forward_queue.m_static_memory,
    mount_root->device.pointer != 0 ? (vostok::fs_new::asynchronous_device_interface *)v20 : 0,
    0,
    v13);
  v14.submount_node = node;
  v14.parent_of_submount_node = node_parent;
  v9 = async_data->env.node;
  v13.functor.vostok_pointer_size_alignment[5] = async_data->env.file_system;
  v14.submount_type = submount_type_subfat;
  v14.root_write_lock = v9;
  v14.unlock_after_mount = 0;
  vostok::vfs::virtual_file_system::query_mount(
    &v14,
    (vostok::threading::mutex *)v9,
    (vostok::vfs::virtual_file_system *)v13.functor.vostok_pointer_size_alignment[5]);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v10,
    (int *)&v14.callback);
  vostok::fs_new::synchronous_device_interface::~synchronous_device_interface(v11, v20);
}
