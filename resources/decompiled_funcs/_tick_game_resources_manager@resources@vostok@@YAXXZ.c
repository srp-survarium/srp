void __usercall vostok::resources::tick_game_resources_manager(
        vostok::resources::game_resources_manager *a1@<ecx>,
        double a2@<st0>)
{
  if ( vostok::resources::g_game_resources_manager.m_initialized )
    vostok::resources::game_resources_manager::tick(a1, vostok::resources::g_game_resources_manager.m_variable, a2);
}
