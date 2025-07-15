void __thiscall vostok::resources::tick(vostok::command_line::key *this)
{
  vostok::resources::resources_manager *v1; // ecx
  vostok::resources::resources_manager *v2; // ecx

  if ( vostok::command_line::key::is_set(this, (int)&vostok::threading::g_debug_single_thread) )
  {
    vostok::resources::resources_manager::resources_thread_tick(v1);
    vostok::resources::resources_manager::cooker_thread_tick(v2);
  }
}
