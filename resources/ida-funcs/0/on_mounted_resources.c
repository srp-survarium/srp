void __cdecl on_mounted_resources(
        vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock> *out_mount,
        vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *out_config_ptr,
        vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock> result)
{
  boost::function<void __cdecl(vostok::resources::queries_result &)> *v3; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v4; // ecx
  boost::_bi::bind_t<void,void (__cdecl*)(vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *),boost::_bi::list2<boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *> > > v5; // [esp-8h] [ebp-30h]
  int v6; // [esp+0h] [ebp-28h]
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+8h] [ebp-20h] BYREF

  if ( !result.m_object )
    vostok::debug::terminate("Cannot mount resources. Please reinstall an application and try again.");
  vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock>::operator=(
    &result,
    out_mount);
  v5.l_.a2_.t_ = out_config_ptr;
  v5.f_ = (void (__cdecl *)(vostok::resources::queries_result *, vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *))on_shader_masks_ready;
  boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
    v3,
    (boost::_bi::bind_t<void,void (__cdecl*)(vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *),boost::_bi::list2<boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *> > > *)&callback,
    v5,
    v6);
  vostok::resources::query_resource(
    "resources/shaders/masks",
    &callback,
    (vostok::variant<32> *)0x20,
    &vostok::memory::g_mt_allocator,
    0,
    0,
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v4,
    (int *)&callback);
  vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock>::dec(&result);
}
