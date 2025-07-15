void __usercall vostok::vfs::physical_path_mounter::mount_hot(
        vostok::vfs::physical_path_mounter *this@<ecx>,
        int a2@<eax>)
{
  vostok::vfs::physical_folder_mount_root_node<1> *v3; // eax
  vostok::vfs::physical_path_mounter *v4; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v5; // ecx
  bool has_passed_filters; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v7; // [esp-4h] [ebp-3Ch]
  const char *v8; // [esp-4h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+10h] [ebp-28h] BYREF
  vostok::vfs::base_node<1> *v10; // [esp+30h] [ebp-8h] BYREF
  int v11; // [esp+34h] [ebp-4h]

  v11 = 0;
  v3 = vostok::vfs::node_cast<vostok::vfs::mount_root_node_base,vostok::vfs::base_node,1>(*(vostok::vfs::base_node<1> **)(a2 + 1288));
  v10 = 0;
  *(_DWORD *)(a2 + 1312) = v3;
  *(_DWORD *)(a2 + 1320) = v3->mount_id;
  if ( vostok::vfs::physical_path_mounter::find_node_on_virtual_path(v4, a2, &v10) )
  {
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)&stru_7FD250,
                                 (const char *)4),
          v5 = v7,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v5,
        &log_callback);
      v8 = *(const char **)(a2 + 72);
      v11 = 1;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\mount_hot.cpp",
        0x5Bu,
        "void __thiscall vostok::vfs::physical_path_mounter::mount_hot(void)",
        (char *)&stru_7FD250,
        info,
        "node '%s' already exists...",
        v8);
    }
    if ( (v11 & 1) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v5,
        (int *)&log_callback);
  }
  else
  {
    vostok::vfs::physical_path_mounter::mount_hot_branch((vostok::vfs::physical_path_mounter *)v5, a2);
  }
}
