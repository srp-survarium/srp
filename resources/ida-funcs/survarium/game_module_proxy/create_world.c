survarium::game *__thiscall survarium::game_module_proxy::create_world(
        survarium::game_module_proxy *this,
        vostok::engine_user::engine_vtbl *engine,
        vostok::sound::world *render_world,
        vostok::engine_user::engine_vtbl *sound,
        vostok::engine_user::engine_vtbl *network)
{
  vostok::memory::doug_lea_allocator *v5; // ecx
  vostok::memory::doug_lea_allocator *v6; // ecx
  vostok::memory::doug_lea_allocator *v7; // ecx
  survarium::game *v8; // ecx
  vostok::memory::base_allocator *v10; // [esp+0h] [ebp-4h]

  vostok::physics::set_memory_allocator(v10);
  vostok::memory::doug_lea_allocator::user_current_thread_id(v5, (int)s_input_allocator.m_variable);
  vostok::input::g_allocator = s_input_allocator.m_variable;
  vostok::memory::doug_lea_allocator::user_current_thread_id(v6, (int)s_ai_allocator.m_variable);
  vostok::ai::g_allocator = s_ai_allocator.m_variable;
  vostok::memory::doug_lea_allocator::user_current_thread_id(v7, (int)s_game_allocator.m_variable);
  survarium::game::game(
    v8,
    (survarium::flash_text_manager *)&s_game,
    engine,
    (vostok::engine_user::engine_vtbl *)render_world,
    sound,
    network);
  _InterlockedExchange(&s_game.m_initialized, 1);
  return s_game.m_variable;
}
