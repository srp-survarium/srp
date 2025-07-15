void __thiscall vostok::resources::initialize_game_resources_manager(vostok::resources::game_resources_manager *this)
{
  boost::function<void __cdecl(vostok::vfs::vfs_iterator &)> *v1; // ecx
  boost::function<void __cdecl(vostok::vfs::vfs_iterator &)> *v2; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v3; // ecx
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> v4; // [esp-20h] [ebp-58h] BYREF
  boost::function4<void,char const *,enum survarium::hit_affects_type_enum,enum survarium::affect_event_type_enum,unsigned int> v5; // [esp+10h] [ebp-28h] BYREF
  __int64 v6; // [esp+30h] [ebp-8h] BYREF

  vostok::resources::game_resources_manager::game_resources_manager(
    this,
    (int)&vostok::resources::g_game_resources_manager);
  _InterlockedExchange(&vostok::resources::g_game_resources_manager.m_initialized, 1);
  HIDWORD(v6) = vostok::resources::g_game_resources_manager.m_variable;
  v4.vtable = 0;
  LODWORD(v6) = vostok::resources::game_resources_manager::query_finished_callback;
  if ( Scaleform::Render::RenderEvent::GetListenerStatus((vostok::particle::particle_action *)vostok::resources::game_resources_manager::query_finished_callback) )
  {
    v4.vtable = 0;
  }
  else
  {
    if ( &v4 != (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)-8 )
      *(_QWORD *)&v4.functor.obj_ptr = v6;
    v4.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::resources::resource_base *>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::resources::game_resources_manager,vostok::resources::resource_base *>,boost::_bi::list2<boost::_bi::value<vostok::resources::game_resources_manager *>,boost::arg<1>>>>'::`2'::stored_vtable
                                                       + 1);
  }
  vostok::resources::set_query_finished_callback(v4);
  HIDWORD(v6) = vostok::resources::g_game_resources_manager.m_variable;
  v4.vtable = 0;
  LODWORD(v6) = vostok::resources::game_resources_manager::out_of_memory_callback;
  if ( Scaleform::Render::RenderEvent::GetListenerStatus((vostok::particle::particle_action *)vostok::resources::game_resources_manager::out_of_memory_callback) )
  {
    v4.vtable = 0;
  }
  else
  {
    if ( &v4 != (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)-8 )
      *(_QWORD *)&v4.functor.obj_ptr = v6;
    v4.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::resources::query_result *>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::resources::game_resources_manager,vostok::resources::query_result *>,boost::_bi::list2<boost::_bi::value<vostok::resources::game_resources_manager *>,boost::arg<1>>>>'::`2'::stored_vtable
                                                       + 1);
  }
  vostok::resources::set_out_of_memory_callback(v4);
  HIDWORD(v6) = vostok::resources::g_game_resources_manager.m_variable;
  v4.vtable = 0;
  LODWORD(v6) = vostok::resources::game_resources_manager::on_resource_freed_callback;
  if ( Scaleform::Render::RenderEvent::GetListenerStatus((vostok::particle::particle_action *)vostok::resources::game_resources_manager::on_resource_freed_callback) )
  {
    v4.vtable = 0;
  }
  else
  {
    if ( &v4 != (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)-8 )
      *(_QWORD *)&v4.functor.obj_ptr = v6;
    v4.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function3<void,vostok::resources::query_result *,vostok::resources::memory_usage_type const &,enum vostok::resources::class_id_enum>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::resources::game_resources_manager,vostok::resources::query_result *,vostok::resources::memory_usage_type const &,enum vostok::resources::class_id_enum>,boost::_bi::list4<boost::_bi::value<vostok::resources::game_resources_manager *>,boost::arg<1>,boost::arg<2>,boost::arg<3>>>>'::`2'::stored_vtable
                                                       + 1);
  }
  vostok::resources::set_resource_freed_callback(v4);
  v4.functor.vostok_pointer_size_alignment[5] = vostok::resources::g_game_resources_manager.m_variable;
  v4.functor.bound_memfunc_ptr.obj_ptr = vostok::resources::game_resources_manager::on_node_hides;
  boost::function<void __cdecl (vostok::vfs::vfs_iterator &)>::operator=<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::resources::game_resources_manager,vostok::vfs::vfs_iterator &>,boost::_bi::list2<boost::_bi::value<vostok::resources::game_resources_manager *>,boost::arg<1>>>>(
    v1,
    (boost::function1<void,vostok::physics::contact_point const &> *)&s_resources_manager_buffer.m_vfs.on_node_hides,
    *((boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::resources::game_resources_manager,vostok::vfs::vfs_iterator &>,boost::_bi::list2<boost::_bi::value<vostok::resources::game_resources_manager *>,boost::arg<1> > > *)&v4.functor.data
    + 2));
  v4.functor.vostok_pointer_size_alignment[5] = vostok::resources::g_game_resources_manager.m_variable;
  v4.functor.bound_memfunc_ptr.obj_ptr = vostok::resources::game_resources_manager::on_node_unmount;
  boost::function<void __cdecl (vostok::vfs::vfs_iterator &)>::operator=<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::resources::game_resources_manager,vostok::vfs::vfs_iterator &>,boost::_bi::list2<boost::_bi::value<vostok::resources::game_resources_manager *>,boost::arg<1>>>>(
    v2,
    (boost::function1<void,vostok::physics::contact_point const &> *)&s_resources_manager_buffer.m_vfs.on_node_unmount,
    *((boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::resources::game_resources_manager,vostok::vfs::vfs_iterator &>,boost::_bi::list2<boost::_bi::value<vostok::resources::game_resources_manager *>,boost::arg<1> > > *)&v4.functor.data
    + 2));
  HIDWORD(v6) = vostok::resources::g_game_resources_manager.m_variable;
  v4.functor.vostok_pointer_size_alignment[5] = &v6;
  LODWORD(v6) = vostok::resources::game_resources_manager::on_unmount_started_callback;
  if ( Scaleform::Render::RenderEvent::GetListenerStatus((vostok::particle::particle_action *)vostok::resources::game_resources_manager::on_unmount_started_callback) )
  {
    v5.vtable = 0;
  }
  else
  {
    *(_QWORD *)&v5.functor.obj_ptr = v6;
    v5.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::resources::game_resources_manager>,boost::_bi::list1<boost::_bi::value<vostok::resources::game_resources_manager *>>>>'::`2'::stored_vtable
                                                       + 1);
  }
  boost::function4<void,char const *,enum survarium::hit_type_enum,float &,float &>::swap(
    (boost::function1<void,vostok::physics::contact_point const &> *)&s_resources_manager_buffer.m_vfs.on_unmount_started,
    &v5);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v3,
    (int *)&v5);
}
