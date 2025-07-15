char __thiscall vostok::vfs::query_notification_operation::try_convert_to_virtual_path(
        vostok::vfs::query_notification_operation *this,
        const vostok::fs_new::native_path_string *physical_path)
{
  const vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *v2; // eax
  survarium::game_camera *v3; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v4; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v6; // ecx
  vostok::vfs::mount_result v7[2]; // [esp-8h] [ebp-1ACh] BYREF
  vostok::vfs::query_notification_operation *thisa; // [esp+8h] [ebp-19Ch]
  vostok::vfs::mount_root_node_base<1> *v9; // [esp+Ch] [ebp-198h]
  const vostok::variant<32> **v10; // [esp+10h] [ebp-194h]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *v11; // [esp+134h] [ebp-70h]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *v12; // [esp+138h] [ebp-6Ch]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> other; // [esp+13Ch] [ebp-68h] BYREF
  vostok::vfs::mount_root_node_base<1> *v14; // [esp+140h] [ebp-64h]
  const vostok::variant<32> **v15; // [esp+144h] [ebp-60h]
  boost::_bi::bind_t<bool,boost::_mfi::mf3<bool,vostok::vfs::query_notification_operation,char const *,char const *,char const *>,boost::_bi::list4<boost::_bi::value<vostok::vfs::query_notification_operation *>,boost::arg<1>,boost::arg<2>,boost::arg<3> > > f; // [esp+154h] [ebp-50h]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> v17; // [esp+160h] [ebp-44h] BYREF
  int v18; // [esp+164h] [ebp-40h]
  char v19; // [esp+16Eh] [ebp-36h]
  char v20; // [esp+16Fh] [ebp-35h]
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> v21; // [esp+170h] [ebp-34h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > result; // [esp+174h] [ebp-30h] BYREF
  boost::function3<bool,char const *,char const *,char const *> v23; // [esp+17Ch] [ebp-28h] BYREF

  thisa = this;
  if ( vostok::fs_new::path_string_impl::length(this->m_virtual_path) )
  {
    v7[0].result = (unsigned __int8)3_5;
    v7[0].mount.m_object = (vostok::vfs::vfs_mount *)(unsigned __int8)2_6;
    f = (boost::_bi::bind_t<bool,boost::_mfi::mf3<bool,vostok::vfs::query_notification_operation,char const *,char const *,char const *>,boost::_bi::list4<boost::_bi::value<vostok::vfs::query_notification_operation *>,boost::arg<1>,boost::arg<2>,boost::arg<3> > >)*boost::bind<void,vostok::sound::sound_debug_stats,vostok::sound::sound_debug_stats *>(&result, (void (__thiscall *)(vostok::sound::sound_debug_stats *))vostok::vfs::query_notification_operation::mounts_filter, (vostok::sound::sound_debug_stats *)thisa);
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>((boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)f.f_.f_);
    boost::function3<bool,char const *,char const *,char const *>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::mf3<bool,vostok::vfs::query_notification_operation,char const *,char const *,char const *>,boost::_bi::list4<boost::_bi::value<vostok::vfs::query_notification_operation *>,boost::arg<1>,boost::arg<2>,boost::arg<3>>>>(
      &v23,
      f);
    v2 = vostok::vfs::find_in_mount_history(
           &v21,
           (const boost::function<bool __cdecl(char const *,char const *,char const *)> *)&v23,
           &thisa->m_file_system->mount_history);
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::operator=(
      &thisa->m_mount,
      v2);
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(&v21);
    boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v23);
    v20 = 0;
    survarium::weapon_user_dead_state::finalize(v3);
    v15 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
            v4,
            (int)&thisa->m_mount);
    v14 = (vostok::vfs::mount_root_node_base<1> *)v15[13];
    thisa->m_mount_root = v14;
    thisa->m_mount_id = thisa->m_mount_root->mount_id;
    return 1;
  }
  else if ( vostok::vfs::convert_physical_to_virtual_path(
              &thisa->m_file_system->mount_history,
              thisa->m_virtual_path,
              physical_path,
              0,
              &thisa->m_mount) )
  {
    v10 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
            v6,
            (int)&thisa->m_mount);
    v9 = (vostok::vfs::mount_root_node_base<1> *)v10[13];
    thisa->m_mount_root = v9;
    thisa->m_mount_id = thisa->m_mount_root->mount_id;
    return 1;
  }
  else
  {
    v19 = 0;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v6);
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
      &other,
      0);
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
      &v17,
      &other);
    v18 = 0;
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(&other);
    v11 = &v17;
    v12 = (vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> *)v7;
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
      &v7[0].mount,
      &v17);
    v12[1].m_object = v11[1].m_object;
    boost::function1<void,vostok::vfs::mount_result>::operator()(
      &thisa->m_callback->boost::function1<void,vostok::vfs::mount_result>,
      v7[0]);
    vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(&v17);
    return 0;
  }
}
