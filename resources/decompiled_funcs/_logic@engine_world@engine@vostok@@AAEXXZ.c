void __thiscall vostok::engine::engine_world::logic(vostok::engine::engine_world *this)
{
  vostok::engine::engine_world *m_pending; // ecx
  vostok::command_line::key::type_enum m_type; // eax
  vostok::resources::resources_manager *v4; // ecx
  vostok::sound::world_user *v5; // eax
  vostok::apc::callback *v6; // edi
  volatile __int32 *v7; // ebp
  survarium::game_camera *v8; // eax
  vostok::tasks::thread_pool *v9; // ecx
  vostok::tasks::thread_pool *v10; // ecx
  vostok::render::engine::renderer *m_engine_renderer; // eax
  vostok::apc::callback *v12; // edi
  volatile __int32 *p_m_pending; // ebp
  survarium::game_camera *v14; // eax
  boost::bad_function_call v15; // [esp+18h] [ebp-220h] BYREF
  boost::bad_function_call v16; // [esp+128h] [ebp-110h] BYREF

  g_threads.m_begin[1].m_thread_id = GetCurrentThreadId();
  vostok::apc::process(logic);
  while ( !this->m_destruction_started )
  {
    vostok::engine::engine_world::logic_tick(m_pending, (int)this);
    if ( this->m_logic_frame_id <= this->m_render_world->m_engine_renderer->m_render_engine_world->m_frame_id + 1
      || (m_pending = (vostok::engine::engine_world *)this->m_destruction_started) != 0 )
    {
      v12 = g_threads.m_begin + 1;
      m_pending = (vostok::engine::engine_world *)g_threads.m_begin[1].m_pending;
      p_m_pending = &g_threads.m_begin[1].m_pending;
      if ( m_pending )
      {
        if ( !v12->m_callback.vtable )
        {
          boost::bad_function_call::bad_function_call(&v16);
          boost::throw_exception(v14);
          stlp_std::__Named_exception::~__Named_exception((stlp_std::out_of_range *)&v16);
        }
        (*(void (__cdecl **)(boost::detail::function::function_buffer *))(((int)v12->m_callback.vtable & 0xFFFFFFFE) + 4))(&v12->m_callback.functor);
        m_pending = (vostok::engine::engine_world *)_InterlockedExchange(p_m_pending, 0);
      }
    }
    else
    {
      do
      {
        if ( vostok::resources::g_resources_manager.m_initialized )
        {
          m_type = vostok::threading::g_debug_single_thread.m_type;
          if ( vostok::threading::g_debug_single_thread.m_type == type_unset )
          {
            vostok::threading::g_debug_single_thread.m_type = type_recursive;
            vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
            m_type = vostok::threading::g_debug_single_thread.m_type;
          }
          if ( m_type != type_recursive )
          {
            if ( m_type == type_unset )
            {
              vostok::threading::g_debug_single_thread.m_type = type_recursive;
              vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
              m_type = vostok::threading::g_debug_single_thread.m_type;
            }
            if ( m_type != type_recursive )
            {
              vostok::resources::resources_manager::resources_thread_tick((vostok::resources::resources_manager *)m_pending);
              vostok::resources::resources_manager::cooker_thread_tick(v4);
            }
          }
          vostok::resources::resources_manager::dispatch_callbacks(vostok::resources::g_resources_manager.m_variable, 0);
        }
        v5 = this->m_sound_world->get_logic_world_user(this->m_sound_world);
        vostok::sound::world_user::dispatch_callbacks(v5);
        this->m_network_world->dispatch_callbacks(this->m_network_world);
        vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::render::base_command,vostok::render::base_command,4>,vostok::intrusive_spsc_queue<vostok::render::base_command,vostok::render::base_command,4>>::owner_delete_processed_items(
          &this->m_render_world->m_logic_channel.m_channel,
          &this->m_render_world->m_logic_channel.m_channel);
        if ( !this->m_game_enabled || this->m_last_game_enabled_value )
        {
          v6 = g_threads.m_begin + 1;
          v7 = &g_threads.m_begin[1].m_pending;
          if ( g_threads.m_begin[1].m_pending )
          {
            if ( !v6->m_callback.vtable )
            {
              boost::bad_function_call::bad_function_call(&v15);
              boost::throw_exception(v8);
              stlp_std::__Named_exception::~__Named_exception((stlp_std::out_of_range *)&v15);
            }
            (*(void (__cdecl **)(boost::detail::function::function_buffer *))(((int)v6->m_callback.vtable & 0xFFFFFFFE)
                                                                            + 4))(&v6->m_callback.functor);
            _InterlockedExchange(v7, 0);
          }
          else
          {
            if ( s_thread_pool.m_initialized && TlsGetValue(s_thread_affinity_tls_key) )
              vostok::tasks::thread_pool::on_current_thread_locks(v9);
            Sleep(1u);
            if ( s_thread_pool.m_initialized && TlsGetValue(s_thread_affinity_tls_key) )
              vostok::tasks::thread_pool::on_current_thread_unlocks(v10);
          }
        }
        else
        {
          --this->m_logic_frame_id;
        }
        m_engine_renderer = this->m_render_world->m_engine_renderer;
        m_pending = (vostok::engine::engine_world *)m_engine_renderer->m_render_engine_world;
      }
      while ( this->m_logic_frame_id > m_engine_renderer->m_render_engine_world->m_frame_id + 1
           && !this->m_destruction_started );
    }
  }
  vostok::apc::process(logic);
}
