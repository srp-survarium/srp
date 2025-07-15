void __thiscall vostok::resources::game_resources_manager::on_node_unmount(
        vostok::resources::game_resources_manager *this,
        vostok::vfs::vfs_iterator *it)
{
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v2; // ecx
  void *m_object; // eax
  bool has_passed_filters; // al
  vostok::vfs::vfs_iterator *v5; // ecx
  char *m_begin; // esi
  const char **v7; // eax
  vostok::vfs::vfs_iterator v8; // [esp-10h] [ebp-370h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v9; // [esp-4h] [ebp-364h]
  void *v10; // [esp+10h] [ebp-350h]
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> result; // [esp+14h] [ebp-34Ch] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v12; // [esp+18h] [ebp-348h] BYREF
  int v13; // [esp+1Ch] [ebp-344h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+20h] [ebp-340h] BYREF
  vostok::fs_new::virtual_path_string v15; // [esp+40h] [ebp-320h] BYREF
  _BYTE v16[524]; // [esp+154h] [ebp-20Ch] BYREF

  v8 = *it;
  v13 = 0;
  vostok::resources::get_associated_unmanaged_resource_ptr(
    (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&result,
    v8);
  vostok::resources::get_associated_managed_resource_ptr(&v12, *it);
  m_object = result.m_object;
  if ( !result.m_object
    || (v2 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr) == 0 )
  {
    m_object = v12.m_object;
  }
  v10 = m_object;
  if ( m_object )
  {
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)&stru_802D94,
                                 (const char *)2),
          v2 = v9,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v2,
        &log_callback);
      v13 = 1;
      m_begin = vostok::vfs::vfs_iterator::get_virtual_path(v5, (vostok::fs_new::virtual_path_string *)it, &v15)->m_string.m_begin;
      v7 = (const char **)(*(int (__thiscall **)(void *, _BYTE *))(*(_DWORD *)v10 + 4))(v10, v16);
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\game_resman.cpp",
        0x4Fu,
        "void __thiscall vostok::resources::game_resources_manager::on_node_unmount(class vostok::vfs::vfs_iterator &)",
        (char *)&stru_802D94,
        error,
        "resource %s is still associated with fat-node %s!",
        *v7,
        m_begin);
    }
    if ( (v13 & 1) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v2,
        (int *)&log_callback);
  }
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v12);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&result);
}
