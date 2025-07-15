void __usercall vostok::resources::resources_manager::delete_delayed_managed_resources(
        vostok::resources::resources_manager *this@<ecx>,
        int a2@<eax>)
{
  vostok::resources::managed_resource *v3; // edi
  vostok::resources::managed_resource *m_next_delay_delete; // esi
  vostok::resources::resources_manager *v5; // [esp+0h] [ebp-Ch]

  if ( *(_DWORD *)((char *)&loc_2033C + a2) )
  {
    vostok::threading::mutex::lock((vostok::threading::mutex *)((char *)boost::detail::function::functor_manager_common<boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> const &,unsigned int,vostok::render::light_props *>,boost::_bi::list4<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::value<unsigned int>,boost::_bi::value<vostok::render::light_props *>>>>::manage_small
                                                              + a2));
    v3 = *(vostok::resources::managed_resource **)((char *)&loc_2033C + a2);
    *(_DWORD *)((char *)&loc_2033C + a2) = 0;
    *(_DWORD *)((char *)&loc_2033E + a2 + 2) = 0;
    *(int *)((char *)&dword_20318 + a2) = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)((char *)boost::detail::function::functor_manager_common<boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> const &,unsigned int,vostok::render::light_props *>,boost::_bi::list4<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::value<unsigned int>,boost::_bi::value<vostok::render::light_props *>>>>::manage_small
                                            + a2));
    if ( v3 )
    {
      do
      {
        m_next_delay_delete = v3->m_next_delay_delete;
        vostok::resources::resources_manager::free_managed_resource(v5, v3);
        v3 = m_next_delay_delete;
      }
      while ( m_next_delay_delete );
    }
  }
}
