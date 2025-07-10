vostok::vfs::result_enum __cdecl vostok::vfs::find_async(
        char *path_to_find,
        vostok::vfs::vfs_locked_iterator *out_iterator,
        boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *find_flags,
        vostok::vfs::virtual_file_system *file_system,
        vostok::memory::base_allocator *allocator,
        vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *user_dispatch_callback)
{
  boost::function<void __cdecl(vostok::vfs::vfs_locked_iterator const &,enum vostok::vfs::result_enum)> v7; // [esp-34h] [ebp-1C0h] BYREF
  unsigned __int64 v8; // [esp-14h] [ebp-1A0h]
  vostok::memory::base_allocator *v9; // [esp-Ch] [ebp-198h]
  unsigned int v10; // [esp-8h] [ebp-194h]
  unsigned int v11; // [esp-4h] [ebp-190h]
  boost::function1<void,enum vostok::handshaking_error_types_enum> *v12; // [esp+134h] [ebp-58h]
  boost::_bi::bind_t<void,void (__cdecl*)(vostok::vfs::vfs_locked_iterator const &,enum vostok::vfs::result_enum,vostok::vfs::vfs_locked_iterator *,enum vostok::vfs::result_enum *,bool *),boost::_bi::list5<boost::arg<1>,boost::arg<2>,boost::_bi::value<vostok::vfs::vfs_locked_iterator *>,boost::_bi::value<enum vostok::vfs::result_enum *>,boost::_bi::value<bool *> > > v13; // [esp+138h] [ebp-54h]
  char *v14; // [esp+148h] [ebp-44h]
  vostok::vfs::result_enum v15; // [esp+14Ch] [ebp-40h]
  boost::_bi::bind_t<void,void (__cdecl*)(vostok::vfs::vfs_locked_iterator const &,enum vostok::vfs::result_enum,vostok::vfs::vfs_locked_iterator *,enum vostok::vfs::result_enum *,bool *),boost::_bi::list5<boost::arg<1>,boost::arg<2>,boost::_bi::value<vostok::vfs::vfs_locked_iterator *>,boost::_bi::value<enum vostok::vfs::result_enum *>,boost::_bi::value<bool *> > > v16; // [esp+154h] [ebp-38h] BYREF
  boost::function<void __cdecl(vostok::vfs::vfs_locked_iterator const &,enum vostok::vfs::result_enum)> callback; // [esp+164h] [ebp-28h] BYREF
  bool callback_ready; // [esp+187h] [ebp-5h] BYREF
  vostok::vfs::result_enum result; // [esp+188h] [ebp-4h] BYREF

  callback_ready = 0;
  result = result_error;
  v13 = *boost::bind<void,vostok::vfs::vfs_locked_iterator const &,enum vostok::vfs::result_enum,vostok::vfs::vfs_locked_iterator *,enum vostok::vfs::result_enum *,bool *,boost::arg<1>,boost::arg<2>,vostok::vfs::vfs_locked_iterator *,enum vostok::vfs::result_enum *,bool *>(
           &v16,
           vostok::vfs::helper_callback,
           *(_BYTE *)&1_26,
           2_5,
           out_iterator,
           &result,
           &callback_ready);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v13.l_.a4_.t_,
    &callback);
  if ( boost::detail::function::basic_vtable2<bool,char const *,enum survarium::hit_affects_type_enum>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::mf2<bool,survarium::artefact_lifebone_core,char const *,enum survarium::hit_affects_type_enum>,boost::_bi::list3<boost::_bi::value<survarium::artefact_lifebone_core *>,boost::arg<1>,boost::arg<2>>>>(
         (boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &> *)&`boost::function2<void,vostok::vfs::vfs_locked_iterator const &,enum vostok::vfs::result_enum>::assign_to<boost::_bi::bind_t<void,void (__cdecl *)(vostok::vfs::vfs_locked_iterator const &,enum vostok::vfs::result_enum,vostok::vfs::vfs_locked_iterator *,enum vostok::vfs::result_enum *,bool *),boost::_bi::list5<boost::arg<1>,boost::arg<2>,boost::_bi::value<vostok::vfs::vfs_locked_iterator *>,boost::_bi::value<enum vostok::vfs::result_enum *>,boost::_bi::value<bool *>>>>'::`2'::stored_vtable,
         (boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::weapon_core_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_cook *>,boost::arg<1> > >)v13,
         &callback.functor) )
  {
    v14 = (char *)&`boost::function2<void,vostok::vfs::vfs_locked_iterator const &,enum vostok::vfs::result_enum>::assign_to<boost::_bi::bind_t<void,void (__cdecl *)(vostok::vfs::vfs_locked_iterator const &,enum vostok::vfs::result_enum,vostok::vfs::vfs_locked_iterator *,enum vostok::vfs::result_enum *,bool *),boost::_bi::list5<boost::arg<1>,boost::arg<2>,boost::_bi::value<vostok::vfs::vfs_locked_iterator *>,boost::_bi::value<enum vostok::vfs::result_enum *>,boost::_bi::value<bool *>>>>'::`2'::stored_vtable.base.manager
        + 1;
    callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function2<void,vostok::vfs::vfs_locked_iterator const &,enum vostok::vfs::result_enum>::assign_to<boost::_bi::bind_t<void,void (__cdecl *)(vostok::vfs::vfs_locked_iterator const &,enum vostok::vfs::result_enum,vostok::vfs::vfs_locked_iterator *,enum vostok::vfs::result_enum *,bool *),boost::_bi::list5<boost::arg<1>,boost::arg<2>,boost::_bi::value<vostok::vfs::vfs_locked_iterator *>,boost::_bi::value<enum vostok::vfs::result_enum *>,boost::_bi::value<bool *>>>>'::`2'::stored_vtable.base.manager
                                                             + 1);
  }
  else
  {
    callback.vtable = 0;
  }
  v11 = -1;
  v10 = 0;
  v9 = allocator;
  v8 = __PAIR64__((unsigned int)file_system, (unsigned int)find_flags);
  v12 = (boost::function1<void,enum vostok::handshaking_error_types_enum> *)&v7;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(find_flags, &v7);
  boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::assign_to_own(
    v12,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&callback);
  vostok::vfs::try_find_async(
    path_to_find,
    v7,
    (vostok::vfs::find_enum)v8,
    (vostok::vfs::virtual_file_system *)HIDWORD(v8),
    v9,
    v10,
    v11);
  while ( !callback_ready )
  {
    vostok::vfs::virtual_file_system::dispatch_callbacks(file_system);
    if ( (!vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!(user_dispatch_callback)
        ? (unsigned int)boost::function3<bool,char const *,char const *,char const *>::dummy::nonnull
        : 0) != 0 )
      boost::function0<void>::operator()((boost::function0<void> *)user_dispatch_callback);
  }
  v15 = result;
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&callback);
  return v15;
}
