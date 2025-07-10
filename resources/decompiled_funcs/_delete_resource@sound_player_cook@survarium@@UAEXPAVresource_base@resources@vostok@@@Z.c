void __thiscall survarium::sound_player_cook::delete_resource(
        survarium::sound_player_cook *this,
        vostok::resources::resource_base *resource)
{
  vostok::sound::sound_world *v2; // ecx
  malloc_state *m_start_time_high; // esi

  ((void (__thiscall *)(vostok::resources::resource_base *, _DWORD))resource->~vostok::resources::resource_base)(
    resource,
    0);
  v2 = boost::get_pointer<vostok::sound::sound_scene>((vostok::sound::sound_world *)survarium::g_allocator.f_.f_);
  m_start_time_high = (malloc_state *)HIDWORD(v2->m_timer.m_start_time);
  BYTE2(v2->m_xaudio_callback_orders.m_pop_thread_id) = 0;
  vostok_mspace_free(m_start_time_high, (char *)resource);
}
