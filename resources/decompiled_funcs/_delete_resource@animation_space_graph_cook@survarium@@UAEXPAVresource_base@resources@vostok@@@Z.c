void __thiscall survarium::animation_space_graph_cook::delete_resource(
        survarium::animation_space_graph_cook *this,
        vostok::resources::resource_base *resource)
{
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *p_m_last; // edi
  vostok::resources::resource_base *v3; // esi
  vostok::sound::sound_world *v4; // eax
  malloc_state *m_start_time_high; // esi

  p_m_last = (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&resource[1].m_parent_resources.m_last;
  v3 = (vostok::resources::resource_base *)(&resource[1].m_parent_resources.m_last
                                          + 73 * resource[1].m_parent_resources.m_thread_id);
  if ( &resource[1].m_parent_resources.m_last != (vostok::resources::resource_link **)v3 )
  {
    do
    {
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(p_m_last);
      p_m_last += 73;
    }
    while ( p_m_last != (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)v3 );
  }
  ((void (__thiscall *)(vostok::resources::resource_base *, _DWORD))resource->~vostok::resources::resource_base)(
    resource,
    0);
  v4 = boost::get_pointer<vostok::sound::sound_scene>((vostok::sound::sound_world *)survarium::g_allocator.f_.f_);
  m_start_time_high = (malloc_state *)HIDWORD(v4->m_timer.m_start_time);
  BYTE2(v4->m_xaudio_callback_orders.m_pop_thread_id) = 0;
  vostok_mspace_free(m_start_time_high, (char *)resource);
}
