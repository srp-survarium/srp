void __thiscall vostok::debug::bugtrap::initialize(survarium::game_camera *ecx0)
{
  if ( !s_initialized_2 )
  {
    survarium::weapon_user_dead_state::finalize(ecx0);
    if ( s_bugtrap_usage )
    {
      load_library_0();
      if ( s_bugtrap_usage )
      {
        install();
        s_BT_SetActivityType((BUGTRAP_ACTIVITY_tag)(2 - (s_error_mode_0 != error_mode_silent)));
      }
    }
    s_initialized_2 = 1;
  }
}
