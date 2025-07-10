void __usercall vostok::resources::resources_manager::dispatch_created_resources(
        vostok::resources::resources_manager *this@<ecx>,
        int a2@<eax>)
{
  vostok::resources::query_result *v3; // ebx
  vostok::resources::query_result *v4; // ecx
  vostok::resources::query_result *m_next_in_device_manager; // esi

  vostok::resources::resources_manager::delete_delayed_unmanaged_resources(this);
  if ( *(_DWORD *)((char *)&loc_20444 + a2) )
  {
    _InterlockedExchange((volatile __int32 *)((char *)&loc_20415 + a2 + 3), 1);
    if ( *(_DWORD *)((char *)&loc_20444 + a2) )
    {
      vostok::threading::mutex::lock((vostok::threading::mutex *)(a2 + 132136));
      v3 = *(vostok::resources::query_result **)((char *)&loc_20444 + a2);
      *(_DWORD *)((char *)&loc_20444 + a2) = 0;
      *(_DWORD *)((char *)&loc_20448 + a2) = 0;
      *(_DWORD *)((char *)boost::detail::function::functor_manager_common<boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::render::engine::world>,boost::_bi::list1<boost::_bi::value<vostok::render::engine::world *>>>>::manage_small
                + a2) = 0;
      LeaveCriticalSection((LPCRITICAL_SECTION)(a2 + 132136));
      v4 = v3;
      if ( v3 )
      {
        do
        {
          m_next_in_device_manager = v4->m_next_in_device_manager;
          vostok::resources::query_result::on_create_resource_end(v4);
          v4 = m_next_in_device_manager;
        }
        while ( m_next_in_device_manager );
      }
    }
    _InterlockedExchange((volatile __int32 *)((char *)&loc_20415 + a2 + 3), 0);
  }
}
