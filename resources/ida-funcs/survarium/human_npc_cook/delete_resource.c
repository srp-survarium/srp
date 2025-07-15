void __thiscall survarium::human_npc_cook::delete_resource(
        survarium::human_npc_cook *this,
        vostok::resources::resource_base *resource)
{
  vostok::sound::sound_world *v2; // ebx
  char *v3; // edi
  malloc_state *m_start_time_high; // esi

  v2 = boost::get_pointer<vostok::sound::sound_scene>((vostok::sound::sound_world *)survarium::g_allocator.f_.f_);
  if ( resource )
  {
    v3 = __RTCastToVoid((void **)&resource->__vftable);
    ((void (__thiscall *)(vostok::resources::resource_base *, _DWORD))resource->~vostok::resources::resource_base)(
      resource,
      0);
    if ( v3 )
    {
      m_start_time_high = (malloc_state *)HIDWORD(v2->m_timer.m_start_time);
      BYTE2(v2->m_xaudio_callback_orders.m_pop_thread_id) = 0;
      vostok_mspace_free(m_start_time_high, v3);
    }
  }
}
