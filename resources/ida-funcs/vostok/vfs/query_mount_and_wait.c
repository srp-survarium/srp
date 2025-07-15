vostok::vfs::mount_result *__cdecl vostok::vfs::query_mount_and_wait(
        vostok::vfs::mount_result *result,
        vostok::vfs::virtual_file_system *vfs,
        vostok::vfs::query_mount_arguments *args,
        boost::function<void __cdecl(void)> dispatch_callback)
{
  vostok::vfs::vfs_mount *v4; // ecx
  vostok::vfs::query_mount_arguments *v5; // ebx
  vostok::vfs::mount_result *v6; // ecx
  vostok::particle::particle_action *v7; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v8; // ecx
  vostok::threading::mutex *v9; // ecx
  vostok::fs_new::asynchronous_device_interface *v10; // ecx
  vostok::one_way_threads_channel_with_response<vostok::fs_new::asynchronous_device_query,vostok::intrusive_mpsc_queue<vostok::fs_new::asynchronous_device_query,vostok::threads_channel_query_base_helper<vostok::fs_new::asynchronous_device_query>,0>,vostok::fs_new::null_device_query> *p_m_queries; // esi
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock> v13; // [esp-8h] [ebp-54h] BYREF
  int v14; // [esp-4h] [ebp-50h]
  boost::function4<void,char const *,enum survarium::hit_affects_type_enum,enum survarium::affect_event_type_enum,unsigned int> v15; // [esp+10h] [ebp-3Ch] BYREF
  __int64 v16; // [esp+30h] [ebp-1Ch] BYREF
  char *v17; // [esp+38h] [ebp-14h]
  void (__cdecl *v18)(vostok::vfs::mount_result, vostok::vfs::mount_result *, bool *); // [esp+3Ch] [ebp-10h]
  vostok::vfs::mount_result *v19; // [esp+40h] [ebp-Ch]
  char *v20; // [esp+44h] [ebp-8h]

  v5 = args;
  v14 = 1;
  v13.m_object = v4;
  vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>(
    &v13,
    0);
  vostok::vfs::mount_result::mount_result(v6, &result->mount, v13, (vostok::vfs::vfs_mount *)v14);
  v19 = result;
  v20 = (char *)&args + 3;
  v18 = vostok::vfs::on_mounted;
  LODWORD(v16) = vostok::vfs::on_mounted;
  HIDWORD(v16) = result;
  v14 = (int)&v16;
  HIBYTE(args) = 0;
  v17 = (char *)&args + 3;
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(v7) )
  {
    v15.vtable = 0;
  }
  else
  {
    *(_QWORD *)&v15.functor.obj_ptr = v16;
    v15.functor.vostok_pointer_size_alignment[2] = v17;
    v15.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::vfs::mount_result>::assign_to<boost::_bi::bind_t<void,void (__cdecl *)(vostok::vfs::mount_result,vostok::vfs::mount_result *,bool *),boost::_bi::list3<boost::arg<1>,boost::_bi::value<vostok::vfs::mount_result *>,boost::_bi::value<bool *>>>>'::`2'::stored_vtable
                                                        + 1);
  }
  boost::function4<void,char const *,enum survarium::hit_type_enum,float &,float &>::swap(
    (boost::function1<void,vostok::physics::contact_point const &> *)&v5->callback,
    &v15);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v8,
    (int *)&v15);
  do
  {
    HIBYTE(args) = 0;
    do
    {
      vostok::vfs::virtual_file_system::query_mount(v5, v9, vfs);
      p_m_queries = &v5->asynchronous_device->m_queries;
      if ( p_m_queries )
        vostok::fs_new::asynchronous_device_interface::dispatch_callbacks(v10, p_m_queries);
      if ( (dispatch_callback.vtable != 0 ? (unsigned int)vostok::memory::process_allocator::finalize_impl : 0) != 0 )
        boost::function0<void>::operator()((boost::function0<bool> *)v10, &dispatch_callback);
      vostok::vfs::virtual_file_system::dispatch_callbacks((vostok::vfs::virtual_file_system *)v10, &vfs->mount_history);
    }
    while ( !HIBYTE(args) );
  }
  while ( result->result == result_cannot_lock );
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v9,
    (int *)&dispatch_callback);
  return result;
}
