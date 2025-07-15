void __thiscall vostok::vfs::archive_mounter::on_read_sub_fat(vostok::vfs::archive_mounter *this, bool read_result)
{
  vostok::vfs::vfs_mount *v2; // edi
  vostok::vfs::base_node<1> *parent_of_submount_node; // eax
  vostok::vfs::vfs_mount *v5; // esi
  unsigned int file; // eax
  vostok::vfs::archive_mounter *v7; // ecx
  vostok::threading::simple_lock *v8; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v9; // ecx
  bool has_passed_filters; // al
  char *m_begin; // esi
  vostok::fs_new::native_path_string *physical_path; // eax
  vostok::vfs::mount_result *v13; // ecx
  const vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *v14; // eax
  const vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *v15; // edi
  vostok::vfs::mounter *v16; // ecx
  vostok::vfs::mounter *v17; // ecx
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> v18; // [esp-8h] [ebp-160h] BYREF
  vostok::vfs::base_folder_node<1> *m_result; // [esp-4h] [ebp-15Ch]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> v20; // [esp+10h] [ebp-148h] BYREF
  vostok::vfs::vfs_mount *m_object; // [esp+14h] [ebp-144h]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> v22; // [esp+18h] [ebp-140h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+20h] [ebp-138h] BYREF
  vostok::fs_new::native_path_string v24; // [esp+44h] [ebp-114h] BYREF

  v2 = 0;
  v20.m_object = 0;
  parent_of_submount_node = this->m_args.parent_of_submount_node;
  v5 = (vostok::vfs::vfs_mount *)(this->m_nodes_buffer + 24);
  if ( parent_of_submount_node )
    v2 = (vostok::vfs::vfs_mount *)vostok::vfs::cast_folder<1>(parent_of_submount_node);
  file = vostok::vfs::get_file_size<1>(this->m_args.submount_node);
  m_result = (vostok::vfs::base_folder_node<1> *)v2;
  v18.m_object = v5;
  v5[1].user_data = (void *)file;
  vostok::vfs::archive_mounter::mount_fat(
    v7,
    (int)this,
    (vostok::vfs::archive_folder_mount_root_node<1> *)v18.m_object,
    m_result);
  vostok::vfs::add_to_mount_history(this->m_mount_ptr.m_object, this->m_file_system, v8);
  if ( !vostok::core::g_log_filter_tree
    || (has_passed_filters = vostok::logging::has_passed_filters(
                               (vostok::logging::filter_tree *)&stru_7FD250,
                               (const char *)4),
        v9 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)m_result,
        has_passed_filters) )
  {
    LOWORD(v9) = this->m_args.submount_node->m_flags & 0x1000;
    v22.m_object = (vostok::vfs::vfs_mount *)"external ";
    if ( (_WORD)v9 != 4096 )
      v22.m_object = (vostok::vfs::vfs_mount *)uri;
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
      v9,
      &log_callback);
    m_begin = this->m_args.virtual_path.m_string.m_begin;
    v20.m_object = (vostok::vfs::vfs_mount *)1;
    physical_path = vostok::vfs::query_mount_arguments::get_physical_path(
                      (vostok::vfs::query_mount_arguments *)&v24,
                      (int)&this->m_args,
                      &v24);
    vostok::logging::append(
      &log_callback,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\mount_subfat.cpp",
      0x60u,
      "void __thiscall vostok::vfs::archive_mounter::on_read_sub_fat(bool)",
      (char *)&stru_7FD250,
      info,
      "mounted %ssub_fat '%s' on '%s'",
      (const char *)v22.m_object,
      physical_path->m_string.m_begin,
      m_begin);
  }
  if ( ((int)v20.m_object & 1) != 0 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v9,
      (int *)&log_callback);
  m_result = (vostok::vfs::base_folder_node<1> *)this->m_result;
  v18.m_object = (vostok::vfs::vfs_mount *)v9;
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
    &v18,
    &this->m_mount_ptr);
  vostok::vfs::mount_result::mount_result(v13, &v22, v18, (vostok::vfs::vfs_mount *)m_result);
  v15 = v14;
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
    &v20,
    v14);
  m_object = v15[1].m_object;
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::dec(&v22);
  vostok::vfs::mounter::finish(v16, (vostok::vfs::mount_result *)this, (vostok::vfs::mounter *)&v20, 0);
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::dec(&v20);
  vostok::vfs::mounter::destroy_this_if_needed(v17, (void **)&this->__vftable);
}
