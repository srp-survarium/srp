vostok::resources::query_result *__cdecl vostok::resources::get_associated_query_result(vostok::vfs::vfs_iterator it)
{
  void (__cdecl *manager)(const boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, boost::detail::function::functor_manager_operation_type); // eax
  vostok::resources::query_result *query; // esi
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::resources::association_callback_helper,vostok::vfs::vfs_association * &>,boost::_bi::list2<boost::_bi::value<vostok::resources::association_callback_helper *>,boost::arg<1> > > v4; // [esp-8h] [ebp-4Ch]
  vostok::resources::association_callback_helper helper; // [esp+8h] [ebp-3Ch] BYREF
  boost::function<void __cdecl(vostok::vfs::vfs_association * &)> callback; // [esp+20h] [ebp-24h] BYREF

  v4.l_.a1_.t_ = &helper;
  v4.f_.f_ = vostok::resources::association_callback_helper::get_query;
  memset(&helper, 0, 20);
  helper.associated = 0;
  callback.vtable = 0;
  boost::function1<void,vostok::vfs::vfs_association * &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::resources::association_callback_helper,vostok::vfs::vfs_association * &>,boost::_bi::list2<boost::_bi::value<vostok::resources::association_callback_helper *>,boost::arg<1>>>>(
    (boost::function1<void,vostok::vfs::vfs_association * &> *)&helper,
    (boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::resources::association_callback_helper,vostok::vfs::vfs_association * &>,boost::_bi::list2<boost::_bi::value<vostok::resources::association_callback_helper *>,boost::arg<1> > > *)&callback,
    v4);
  vostok::vfs::vfs_iterator::access_association(&it, &callback);
  if ( callback.vtable )
  {
    if ( ((int)callback.vtable & 1) == 0 )
    {
      manager = boost::function1<void,vostok::vfs::vfs_association * &>::get_vtable((boost::function1<void,vostok::vfs::base_node<1> *> *)&callback)->base.manager;
      if ( manager )
        manager(&callback.functor, &callback.functor, destroy_functor_tag);
    }
  }
  query = helper.query;
  if ( helper.unmanaged.m_object && !_InterlockedExchangeAdd(&helper.unmanaged.m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &helper.unmanaged.m_object->vostok::resources::unmanaged_intrusive_base,
      helper.unmanaged.m_object);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&helper.managed);
  return query;
}
