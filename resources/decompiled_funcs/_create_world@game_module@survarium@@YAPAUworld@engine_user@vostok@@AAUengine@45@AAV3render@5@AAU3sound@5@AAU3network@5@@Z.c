survarium::game *__cdecl survarium::game_module::create_world(
        vostok::engine_user::engine *engine,
        vostok::render::world *render_world,
        vostok::sound::world *sound,
        vostok::network::world *network)
{
  vostok::memory::doug_lea_allocator *m_variable; // esi
  DWORD CurrentThreadId; // eax
  const char *Value; // eax
  vostok::memory::doug_lea_allocator *v7; // esi
  DWORD v8; // eax
  const char *v9; // eax
  vostok::memory::doug_lea_allocator *v10; // esi
  DWORD v11; // eax
  const char *v12; // eax
  vostok::memory::doug_lea_allocator *v13; // esi
  DWORD v14; // eax
  const char *v15; // eax
  vostok::memory::doug_lea_allocator *v16; // esi
  DWORD v17; // eax
  const char *v18; // eax
  survarium::game *result; // eax
  vostok::memory::base_allocator *v20; // [esp+0h] [ebp-Ch]

  survarium::game_core_initialize();
  vostok::physics::set_memory_allocator(v20);
  m_variable = s_input_allocator.m_variable;
  CurrentThreadId = GetCurrentThreadId();
  if ( m_variable->m_user_thread_id != CurrentThreadId )
  {
    _InterlockedExchange((volatile __int32 *)&m_variable->m_user_thread_id, CurrentThreadId);
    if ( m_variable->m_thread_id_const )
      m_variable->m_user_thread_id_called = 1;
  }
  Value = (const char *)TlsGetValue(s_thread_logging_name_tls_key);
  if ( !Value )
    Value = "undefined";
  m_variable->m_user_thread_logging_name = Value;
  v7 = s_ui_allocator.m_variable;
  vostok::input::g_allocator = s_input_allocator.m_variable;
  v8 = GetCurrentThreadId();
  if ( v7->m_user_thread_id != v8 )
  {
    _InterlockedExchange((volatile __int32 *)&v7->m_user_thread_id, v8);
    if ( v7->m_thread_id_const )
      v7->m_user_thread_id_called = 1;
  }
  v9 = (const char *)TlsGetValue(s_thread_logging_name_tls_key);
  if ( !v9 )
    v9 = "undefined";
  v7->m_user_thread_logging_name = v9;
  v10 = s_ai_navigation_allocator.m_variable;
  v11 = GetCurrentThreadId();
  if ( v10->m_user_thread_id != v11 )
  {
    _InterlockedExchange((volatile __int32 *)&v10->m_user_thread_id, v11);
    if ( v10->m_thread_id_const )
      v10->m_user_thread_id_called = 1;
  }
  v12 = (const char *)TlsGetValue(s_thread_logging_name_tls_key);
  if ( !v12 )
    v12 = "undefined";
  v10->m_user_thread_logging_name = v12;
  vostok::ai::navigation::set_memory_allocator(&vostok::memory::g_mt_allocator);
  v13 = s_ai_allocator.m_variable;
  v14 = GetCurrentThreadId();
  if ( v13->m_user_thread_id != v14 )
  {
    _InterlockedExchange((volatile __int32 *)&v13->m_user_thread_id, v14);
    if ( v13->m_thread_id_const )
      v13->m_user_thread_id_called = 1;
  }
  v15 = (const char *)TlsGetValue(s_thread_logging_name_tls_key);
  if ( !v15 )
    v15 = "undefined";
  v13->m_user_thread_logging_name = v15;
  vostok::ai::set_memory_allocator(s_ai_allocator.m_variable);
  v16 = s_game_allocator.m_variable;
  v17 = GetCurrentThreadId();
  if ( v16->m_user_thread_id != v17 )
  {
    _InterlockedExchange((volatile __int32 *)&v16->m_user_thread_id, v17);
    if ( v16->m_thread_id_const )
      v16->m_user_thread_id_called = 1;
  }
  v18 = (const char *)TlsGetValue(s_thread_logging_name_tls_key);
  if ( !v18 )
    v18 = "undefined";
  v16->m_user_thread_logging_name = v18;
  if ( s_generate_shaders.m_type == type_unset )
  {
    s_generate_shaders.m_type = type_recursive;
    vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
  }
  if ( s_generate_shaders.m_type == type_recursive )
  {
    survarium::game::game(render_world, (survarium::game *)&s_game, engine, sound, network);
    _InterlockedExchange(&s_game.m_initialized, 1);
  }
  else
  {
    *(_DWORD *)s_generate_shaders_world.m_static_memory = &survarium::generate_shaders_world::`vftable';
    *(_DWORD *)&s_generate_shaders_world.m_static_memory[4] = render_world->m_game_renderer;
    s_generate_shaders_world.m_static_memory[8] = 0;
    _InterlockedExchange(&s_generate_shaders_world.m_initialized, 1);
  }
  if ( s_generate_shaders.m_type == type_unset )
  {
    s_generate_shaders.m_type = type_recursive;
    vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
  }
  result = (survarium::game *)s_generate_shaders_world.m_variable;
  if ( s_generate_shaders.m_type == type_recursive )
    return s_game.m_variable;
  return result;
}
