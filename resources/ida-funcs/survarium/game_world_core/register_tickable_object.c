void __usercall survarium::game_world_core::register_tickable_object(
        survarium::game_world_core *this@<ecx>,
        int a2@<eax>)
{
  survarium::game_world_core *i; // edx
  unsigned int v3; // eax
  bool v4; // [esp+7h] [ebp-1h] BYREF

  for ( i = *(survarium::game_world_core **)(a2 + 49536);
        i;
        i = (survarium::game_world_core *)i->m_game_events_history.m_items.m_last )
  {
    if ( i == this )
      goto LABEL_6;
  }
  i = 0;
LABEL_6:
  if ( debug_macro_helper_ignore_always_42 || !i )
  {
    if ( !*(_DWORD *)(a2 + 51176) )
      *(_DWORD *)(a2 + 51176) = this;
    this->m_game_events_history.m_items.m_first = *(survarium::game_event_history_item **)(a2 + 49540);
    this->m_game_events_history.m_items.m_last = 0;
    if ( *(_DWORD *)(a2 + 49536) )
      *(_DWORD *)(*(_DWORD *)(a2 + 49540) + 8) = this;
    else
      *(_DWORD *)(a2 + 49536) = this;
    *(_DWORD *)(a2 + 49540) = this;
  }
  else
  {
    v3 = occurances_left_24;
    if ( occurances_left_24 == -1 )
      v3 = 10;
    occurances_left_24 = v3 - 1;
    if ( v3 )
    {
      v4 = 0;
      vostok::debug::on_error(
        &v4,
        process_error_false,
        (bool *)"!found",
        ".\\game_world_core.cpp",
        "survarium::game_world_core::register_tickable_object",
        (const char *)0x4D9);
      if ( vostok::debug::is_debugger_present() || v4 )
        __debugbreak();
    }
  }
}
