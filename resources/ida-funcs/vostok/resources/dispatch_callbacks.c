void __thiscall vostok::resources::dispatch_callbacks(vostok::command_line::key *this)
{
  vostok::command_line::key *v1; // ecx

  if ( vostok::resources::g_resources_manager_initialized )
  {
    if ( vostok::command_line::key::is_set(this, (int)&vostok::threading::g_debug_single_thread) )
      vostok::resources::tick(v1);
    vostok::resources::resources_manager::dispatch_callbacks(&s_resources_manager_buffer, 0);
  }
}
