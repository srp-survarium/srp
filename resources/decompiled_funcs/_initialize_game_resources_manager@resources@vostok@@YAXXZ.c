void __thiscall vostok::resources::initialize_game_resources_manager(vostok::resources::game_resources_manager *ecx0)
{
  void (__cdecl *v1)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void (__cdecl *v2)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  char *v3; // esi
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::resources::game_resources_manager,vostok::resources::resource_base *>,boost::_bi::list2<boost::_bi::value<vostok::resources::game_resources_manager *>,boost::arg<1> > > v4; // [esp-28h] [ebp-54h]
  boost::function<void __cdecl(vostok::resources::resource_base *)> v5; // [esp-20h] [ebp-4Ch] BYREF
  boost::function<void __cdecl(vostok::resources::query_result *)> v6; // [esp+8h] [ebp-24h] BYREF

  vostok::resources::game_resources_manager::game_resources_manager(
    ecx0,
    (int)&vostok::resources::g_game_resources_manager);
  _InterlockedExchange(&vostok::resources::g_game_resources_manager.m_initialized, 1);
  v4.l_.a1_.t_ = vostok::resources::g_game_resources_manager.m_variable;
  v4.f_.f_ = (void (__thiscall *)(vostok::resources::game_resources_manager *, vostok::resources::resource_base *))vostok::resources::game_resources_manager::query_finished_callback;
  v5.vtable = 0;
  boost::function1<void,vostok::resources::resource_base *>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::resources::game_resources_manager,vostok::resources::resource_base *>,boost::_bi::list2<boost::_bi::value<vostok::resources::game_resources_manager *>,boost::arg<1>>>>(
    (boost::function1<void,vostok::resources::resource_base *> *)vostok::resources::g_game_resources_manager.m_variable,
    (boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::resources::game_resources_manager,vostok::resources::resource_base *>,boost::_bi::list2<boost::_bi::value<vostok::resources::game_resources_manager *>,boost::arg<1> > > *)&v5,
    v4);
  vostok::resources::set_query_finished_callback(v5);
  v5.functor.vostok_pointer_size_alignment[5] = vostok::resources::g_game_resources_manager.m_variable;
  v5.functor.bound_memfunc_ptr.obj_ptr = vostok::resources::game_resources_manager::out_of_memory_callback;
  v6.vtable = 0;
  boost::function1<void,vostok::resources::query_result *>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::resources::game_resources_manager,vostok::resources::query_result *>,boost::_bi::list2<boost::_bi::value<vostok::resources::game_resources_manager *>,boost::arg<1>>>>(
    (boost::function1<void,vostok::resources::query_result *> *)vostok::resources::g_game_resources_manager.m_variable,
    (boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::resources::game_resources_manager,vostok::resources::query_result *>,boost::_bi::list2<boost::_bi::value<vostok::resources::game_resources_manager *>,boost::arg<1> > > *)&v6,
    *((boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::resources::game_resources_manager,vostok::resources::query_result *>,boost::_bi::list2<boost::_bi::value<vostok::resources::game_resources_manager *>,boost::arg<1> > > *)&v5.functor.data
    + 2));
  boost::function<void __cdecl (vostok::resources::query_result *)>::operator=(&v6);
  if ( v6.vtable )
  {
    if ( ((int)v6.vtable & 1) == 0 )
    {
      v1 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v6.vtable & 0xFFFFFFFE);
      if ( v1 )
        v1(&v6.functor, &v6.functor, 2);
    }
  }
  v5.functor.vostok_pointer_size_alignment[5] = vostok::resources::g_game_resources_manager.m_variable;
  v5.functor.bound_memfunc_ptr.obj_ptr = vostok::resources::game_resources_manager::on_resource_freed_callback;
  v6.vtable = 0;
  boost::function3<void,vostok::resources::query_result *,vostok::resources::memory_usage_type const &,enum vostok::resources::class_id_enum>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::resources::game_resources_manager,vostok::resources::query_result *,vostok::resources::memory_usage_type const &,enum vostok::resources::class_id_enum>,boost::_bi::list4<boost::_bi::value<vostok::resources::game_resources_manager *>,boost::arg<1>,boost::arg<2>,boost::arg<3>>>>(
    (boost::function3<void,vostok::resources::query_result *,vostok::resources::memory_usage_type const &,enum vostok::resources::class_id_enum> *)vostok::resources::g_game_resources_manager.m_variable,
    (boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::resources::game_resources_manager,vostok::resources::query_result *,vostok::resources::memory_usage_type const &,enum vostok::resources::class_id_enum>,boost::_bi::list4<boost::_bi::value<vostok::resources::game_resources_manager *>,boost::arg<1>,boost::arg<2>,boost::arg<3> > > *)&v6,
    *((boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::resources::game_resources_manager,vostok::resources::query_result *,vostok::resources::memory_usage_type const &,enum vostok::resources::class_id_enum>,boost::_bi::list4<boost::_bi::value<vostok::resources::game_resources_manager *>,boost::arg<1>,boost::arg<2>,boost::arg<3> > > *)&v5.functor.data
    + 2));
  boost::function<void __cdecl (vostok::resources::query_result *,vostok::resources::memory_usage_type const &,enum vostok::resources::class_id_enum)>::operator=((boost::function<void __cdecl(vostok::resources::query_result *,vostok::resources::memory_usage_type const &,enum vostok::resources::class_id_enum)> *)&v6);
  if ( v6.vtable )
  {
    if ( ((int)v6.vtable & 1) == 0 )
    {
      v2 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v6.vtable & 0xFFFFFFFE);
      if ( v2 )
        v2(&v6.functor, &v6.functor, 2);
    }
  }
  v3 = (char *)&loc_20600 + (unsigned int)vostok::resources::g_resources_manager.m_variable;
  v5.functor.bound_memfunc_ptr.obj_ptr = vostok::resources::game_resources_manager::on_node_hides;
  v5.functor.vostok_pointer_size_alignment[3] = (char *)&loc_20600
                                              + (unsigned int)vostok::resources::g_resources_manager.m_variable
                                              + (_DWORD)&loc_20186
                                              + 2;
  boost::function<void __cdecl (vostok::vfs::vfs_iterator &)>::operator=<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::resources::game_resources_manager,vostok::vfs::vfs_iterator &>,boost::_bi::list2<boost::_bi::value<vostok::resources::game_resources_manager *>,boost::arg<1>>>>(
    (boost::function<void __cdecl(vostok::vfs::vfs_iterator &)> *)vostok::resources::g_game_resources_manager.m_variable,
    *(boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::resources::game_resources_manager,vostok::vfs::vfs_iterator &>,boost::_bi::list2<boost::_bi::value<vostok::resources::game_resources_manager *>,boost::arg<1> > > *)(&v5.functor.data + 12),
    (unsigned int)vostok::resources::g_game_resources_manager.m_variable);
  v5.functor.bound_memfunc_ptr.obj_ptr = vostok::resources::game_resources_manager::on_node_unmount;
  v5.functor.vostok_pointer_size_alignment[3] = &byte_20168[(_DWORD)v3];
  boost::function<void __cdecl (vostok::vfs::vfs_iterator &)>::operator=<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::resources::game_resources_manager,vostok::vfs::vfs_iterator &>,boost::_bi::list2<boost::_bi::value<vostok::resources::game_resources_manager *>,boost::arg<1>>>>(
    (boost::function<void __cdecl(vostok::vfs::vfs_iterator &)> *)vostok::resources::g_game_resources_manager.m_variable,
    *(boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::resources::game_resources_manager,vostok::vfs::vfs_iterator &>,boost::_bi::list2<boost::_bi::value<vostok::resources::game_resources_manager *>,boost::arg<1> > > *)(&v5.functor.data + 12),
    (unsigned int)vostok::resources::g_game_resources_manager.m_variable);
  v5.functor.vostok_pointer_size_alignment[5] = vostok::resources::g_game_resources_manager.m_variable;
  v5.functor.bound_memfunc_ptr.obj_ptr = vostok::resources::game_resources_manager::on_unmount_started_callback;
  boost::function<void __cdecl (void)>::operator=<boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::resources::game_resources_manager>,boost::_bi::list1<boost::_bi::value<vostok::resources::game_resources_manager *>>>>(
    (boost::function<void __cdecl(void)> *)vostok::resources::g_game_resources_manager.m_variable,
    (boost::function0<void> *)((char *)&dword_201A8 + (_DWORD)v3),
    *((boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::resources::game_resources_manager>,boost::_bi::list1<boost::_bi::value<vostok::resources::game_resources_manager *> > > *)&v5.functor.data
    + 2));
}
