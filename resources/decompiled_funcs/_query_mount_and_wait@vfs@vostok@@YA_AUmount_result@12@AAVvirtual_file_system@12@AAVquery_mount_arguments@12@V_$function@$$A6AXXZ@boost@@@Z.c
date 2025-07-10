vostok::vfs::mount_result *__cdecl vostok::vfs::query_mount_and_wait(
        vostok::vfs::mount_result *result,
        vostok::vfs::virtual_file_system *vfs,
        vostok::vfs::query_mount_arguments *args,
        boost::function<void __cdecl(void)> dispatch_callback)
{
  boost::_bi::bind_t<void,void (__cdecl*)(vostok::vfs::mount_result,vostok::vfs::mount_result *,bool *),boost::_bi::list3<boost::arg<1>,boost::_bi::value<vostok::vfs::mount_result *>,boost::_bi::value<bool *> > > v5; // [esp-10h] [ebp-198h]
  boost::function1<void,vostok::vfs::mount_result> v6; // [esp+144h] [ebp-44h] BYREF
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> other; // [esp+164h] [ebp-24h] BYREF
  boost::_bi::bind_t<void,void (__cdecl*)(vostok::vfs::mount_result,vostok::vfs::mount_result *,bool *),boost::_bi::list3<boost::arg<1>,boost::_bi::value<vostok::vfs::mount_result *>,boost::_bi::value<bool *> > > v8; // [esp+16Ch] [ebp-1Ch] BYREF
  vostok::vfs::mount_result resulta; // [esp+17Ch] [ebp-Ch] BYREF
  bool finished; // [esp+187h] [ebp-1h] BYREF

  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
    &other,
    0);
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
    &resulta.mount,
    &other);
  resulta.result = result_error;
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(&other);
  finished = 0;
  v5 = *boost::bind<void,vostok::vfs::mount_result,vostok::vfs::mount_result *,bool *,boost::arg<1>,vostok::vfs::mount_result *,bool *>(
          &v8,
          vostok::vfs::on_mounted,
          *(_BYTE *)&1_25,
          &resulta,
          &finished);
  boost::function1<void,vostok::vfs::mount_result>::function1<void,vostok::vfs::mount_result>(&v6, v5, 0);
  boost::function1<unsigned int,char const *>::swap(
    (boost::function2<bool,char const *,enum survarium::hit_affects_type_enum> *)&v6,
    (boost::function2<bool,char const *,enum survarium::hit_affects_type_enum> *)&args->callback);
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v6);
  do
  {
    finished = 0;
    while ( !finished )
    {
      vostok::vfs::virtual_file_system::query_mount(vfs, args);
      if ( args->asynchronous_device )
        vostok::fs_new::asynchronous_device_interface::dispatch_callbacks(args->asynchronous_device);
      if ( (!vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!((vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&dispatch_callback)
          ? (unsigned int)boost::function3<bool,char const *,char const *,char const *>::dummy::nonnull
          : 0) != 0 )
        boost::function0<void>::operator()(&dispatch_callback);
      vostok::vfs::virtual_file_system::dispatch_callbacks(vfs);
    }
  }
  while ( resulta.result == result_requery );
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
    &result->mount,
    &resulta.mount);
  result->result = resulta.result;
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(&resulta.mount);
  boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&dispatch_callback);
  return result;
}
