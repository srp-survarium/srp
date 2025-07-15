void __thiscall vostok::resources::mount_by_config_helper::query_db(
        vostok::resources::mount_by_config_helper *this,
        boost::function<void __cdecl(vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock>)> *callback)
{
  vostok::fs_new::path_string_impl *v2; // ecx
  char *vtable; // edi
  vostok::memory::base_allocator *v4; // esi
  char *v5; // eax
  int v6; // eax
  vostok::resources::fs_task *v7; // eax
  boost::detail::function::vtable_base *v8; // edi
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v9; // ecx
  vostok::resources::resources_manager *v10; // [esp+0h] [ebp-23Ch]
  vostok::fs_new::virtual_path_string virtual_path; // [esp+Ch] [ebp-230h] BYREF
  vostok::fs_new::native_path_string fat_physical_path; // [esp+124h] [ebp-118h] BYREF

  vostok::fs_new::native_path_string::native_path_string(&fat_physical_path);
  vostok::fs_new::path_string_impl::assignf_with_conversion(
    v2,
    &fat_physical_path,
    (vostok::fs_new::path_string_impl *)"../../%s.db",
    (const char *const)callback[1].vtable);
  vostok::fixed_string<260>::fixed_string<260>(&virtual_path.m_string, (const vostok::fixed_string<260> *)&callback[1]);
  vtable = (char *)callback[1].vtable;
  v4 = (vostok::memory::base_allocator *)callback[10].vtable;
  virtual_path.m_separator = 47;
  v5 = type_info::raw_name(&vostok::resources::fs_task_mount `RTTI Type Descriptor');
  v6 = (int)v4->call_malloc(
              v4,
              992u,
              v5,
              "vostok::resources::query_mount_archive",
              ".\\resources_query_mount.cpp",
              244u);
  if ( v6 )
    vostok::resources::fs_task_mount::fs_task_mount(
      (vostok::resources::fs_task_mount *)&virtual_path,
      v6,
      &virtual_path,
      &fat_physical_path,
      &fat_physical_path,
      vtable,
      (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)callback,
      v4);
  else
    v7 = 0;
  vostok::resources::resources_manager::add_fs_task(v7, v10);
  v8 = callback[10].vtable;
  vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock> *)&callback[10].functor);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v9,
    (int *)callback);
  (*((void (__thiscall **)(boost::detail::function::vtable_base *, boost::function<void __cdecl(vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock>)> *, const char *, const char *, int))v8->manager
   + 6))(
    v8,
    callback,
    "vostok::resources::mount_by_config_helper::delete_this",
    ".\\resources_query_mount.cpp",
    193);
}
