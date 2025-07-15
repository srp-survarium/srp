void __cdecl vostok::vfs::find_async_expand_physical(
        vostok::vfs::base_node<1> *node,
        vostok::vfs::base_node<1> *node_parent,
        vostok::vfs::async_callbacks_data *async_data,
        vostok::vfs::recursive_bool recursive,
        int increment)
{
  vostok::vfs::base_node<1> *v5; // ecx
  vostok::vfs::physical_folder_mount_root_node<1> *mount_root; // ebx
  vostok::vfs::base_node<1> *v7; // ecx
  int pointer; // eax
  bool v9; // zf
  vostok::vfs::async_callbacks_data *v10; // esi
  boost::function<void __cdecl(vostok::vfs::mount_result)> *v11; // ecx
  boost::function<void __cdecl(vostok::vfs::mount_result)> *v12; // ecx
  boost::function4<void,char const *,enum survarium::hit_affects_type_enum,enum survarium::affect_event_type_enum,unsigned int> *v13; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v14; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v15; // ecx
  vostok::fs_new::synchronous_device_interface *v16; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::vfs::async_callbacks_data,vostok::vfs::mount_result,unsigned int>,boost::_bi::list3<boost::_bi::value<vostok::vfs::async_callbacks_data *>,boost::arg<1>,boost::_bi::value<unsigned int> > > v17; // [esp-10h] [ebp-764h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::vfs::async_callbacks_data,vostok::vfs::mount_result>,boost::_bi::list2<boost::_bi::value<vostok::vfs::async_callbacks_data *>,boost::arg<1> > > v18; // [esp-Ch] [ebp-760h]
  vostok::vfs::query_mount_arguments *v19; // [esp-4h] [ebp-758h]
  vostok::vfs::virtual_file_system *file_system; // [esp-4h] [ebp-758h]
  vostok::fs_new::native_path_string __formal; // [esp+10h] [ebp-744h] BYREF
  vostok::vfs::query_mount_arguments args; // [esp+128h] [ebp-62Ch] BYREF
  vostok::fs_new::virtual_path_string v23; // [esp+600h] [ebp-154h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::vfs::async_callbacks_data,vostok::vfs::mount_result,unsigned int>,boost::_bi::list3<boost::_bi::value<vostok::vfs::async_callbacks_data *>,boost::arg<1>,boost::_bi::value<unsigned int> > > v24; // [esp+718h] [ebp-3Ch] BYREF
  void (__thiscall *v25)(vostok::vfs::async_callbacks_data *, vostok::vfs::mount_result, int); // [esp+738h] [ebp-1Ch]
  vostok::vfs::async_callbacks_data *v26; // [esp+73Ch] [ebp-18h]
  int v27; // [esp+740h] [ebp-14h]
  int v28[2]; // [esp+744h] [ebp-10h] BYREF
  char v29; // [esp+74Ch] [ebp-8h]

  mount_root = vostok::vfs::base_node<1>::get_mount_root(v5, (int)node);
  v23.m_string.m_begin = v23.m_string.m_buffer;
  v23.m_string.m_end = v23.m_string.m_buffer;
  v23.m_string.m_max_end = &v23.m_separator;
  v23.m_string.m_buffer[0] = 0;
  v23.m_separator = 47;
  vostok::vfs::base_node<1>::get_full_path(node, &v23);
  vostok::vfs::get_node_physical_path<vostok::vfs::base_node,1>(node, v7, &__formal);
  pointer = (int)mount_root->device.pointer;
  v28[0] = 0;
  v28[1] = pointer;
  v29 = 0;
  vostok::vfs::query_mount_arguments::query_mount_arguments(v19, (int)&args);
  args.allocator = mount_root->allocator.pointer;
  vostok::buffer_string::operator=(&v23.m_string, &args.virtual_path.m_string);
  args.asynchronous_device = mount_root->async_device.pointer;
  v9 = (node->m_flags & 1) == 0;
  args.synchronous_device = mount_root->device.pointer != 0 ? (vostok::fs_new::synchronous_device_interface *)v28 : 0;
  if ( v9 )
  {
    args.type = mount_type_archive;
    vostok::buffer_string::operator=(&__formal.m_string, &args.fat_physical_path.m_string);
    v26 = async_data;
    v27 = increment;
    v25 = vostok::vfs::async_callbacks_data::on_automatic_archive_or_subfat_mounted;
    v17.l_.a1_.t_ = (vostok::vfs::async_callbacks_data *)vostok::vfs::async_callbacks_data::on_automatic_archive_or_subfat_mounted;
    v17.l_.a3_.t_ = (unsigned int)async_data;
    v17.f_.f_ = (void (__thiscall *)(vostok::vfs::async_callbacks_data *, vostok::vfs::mount_result, unsigned int))&v24;
    boost::function<void __cdecl (vostok::vfs::mount_result)>::function<void __cdecl (vostok::vfs::mount_result)>(
      v12,
      v17,
      increment);
    boost::function4<void,char const *,enum survarium::hit_type_enum,float &,float &>::swap(
      (boost::function1<void,vostok::physics::contact_point const &> *)&args.callback,
      v13);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v14,
      (int *)&v24);
    v10 = async_data;
  }
  else
  {
    args.type = mount_type_physical_path;
    vostok::buffer_string::operator=(&__formal.m_string, &args.physical_path.m_string);
    v10 = async_data;
    v18.l_.a1_.t_ = (vostok::vfs::async_callbacks_data *)vostok::vfs::async_callbacks_data::on_lazy_mounted;
    v18.f_.f_ = (void (__thiscall *)(vostok::vfs::async_callbacks_data *, vostok::vfs::mount_result))&args.callback;
    boost::function<void __cdecl (vostok::vfs::mount_result)>::operator=<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::vfs::async_callbacks_data,vostok::vfs::mount_result>,boost::_bi::list2<boost::_bi::value<vostok::vfs::async_callbacks_data *>,boost::arg<1>>>>(
      v11,
      v18,
      (unsigned int)async_data);
  }
  file_system = v10->env.file_system;
  args.recursive = recursive;
  v9 = (node->m_flags & 1) == 1;
  args.parent_of_submount_node = node_parent;
  args.root_write_lock = v10->env.node;
  args.submount_node = node;
  args.unlock_after_mount = 0;
  args.submount_type = 2 * !v9 + 1;
  vostok::vfs::virtual_file_system::query_mount(&args, (vostok::threading::mutex *)args.submount_type, file_system);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v15,
    (int *)&args.callback);
  vostok::fs_new::synchronous_device_interface::~synchronous_device_interface(v16, v28);
}
