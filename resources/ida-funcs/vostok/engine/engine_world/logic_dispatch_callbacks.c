void __thiscall vostok::engine::engine_world::logic_dispatch_callbacks(vostok::engine::engine_world *this)
{
  vostok::engine::engine_world *v1; // esi
  int v2; // edi
  vostok::sound::sound_order **v3; // ebx
  vostok::sound::sound_order *m_next_for_orders; // ecx
  vostok::sound::sound_order *v5; // esi
  __int32 v6; // eax
  int v7; // ecx
  __int32 v8; // edx
  int p_m_tail; // edi
  vostok::render::base_command *v10; // esi
  int v11; // eax
  vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,8>,vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,8> > *v12; // [esp+0h] [ebp-10h]

  v1 = this;
  vostok::resources::dispatch_callbacks((vostok::command_line::key *)this);
  v2 = (int)v1->m_sound_world->get_logic_world_user(v1->m_sound_world);
  v3 = (vostok::sound::sound_order **)(v2 + 268);
  while ( 1 )
  {
    m_next_for_orders = (*v3)->m_next_for_orders;
    if ( !m_next_for_orders )
      break;
    v5 = *v3;
    *v3 = m_next_for_orders;
    vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,8>,vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,8>>::delete_value(
      v5,
      v12);
    v1 = this;
  }
  while ( 1 )
  {
    v6 = *(_DWORD *)(v2 + 64);
    v7 = *(_DWORD *)(v6 + 8);
    if ( !v7 )
      break;
    *(_DWORD *)(v2 + 64) = v7;
    *(_DWORD *)(v6 + 8) = 0;
    v8 = _InterlockedExchange((volatile __int32 *)(*(_DWORD *)(v2 + 68) + 8), v6);
    *(_DWORD *)(v2 + 68) = v6;
    (*(void (__fastcall **)(int, __int32))(*(_DWORD *)v7 + 4))(v7, v8);
  }
  v1->m_network_world->dispatch_callbacks(v1->m_network_world);
  p_m_tail = (int)&v1->m_render_world->m_logic_channel.m_channel.m_backward_queue.m_tail;
  while ( 1 )
  {
    v10 = *(vostok::render::base_command **)p_m_tail;
    v11 = *(_DWORD *)(*(_DWORD *)p_m_tail + 8);
    if ( !v11 )
      break;
    *(_DWORD *)p_m_tail = v11;
    vostok::one_way_threads_channel<vostok::intrusive_mpsc_queue<vostok::render::base_command,vostok::render::base_command,8>,vostok::intrusive_spsc_queue<vostok::render::base_command,vostok::render::base_command,8>>::delete_value(v10);
  }
}
