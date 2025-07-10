void __cdecl vostok::debug::bugtrap::change_usage(
        vostok::debug::error_mode error_mode,
        vostok::debug::bugtrap_usage bugtrap_usage)
{
  survarium::game_camera *v2; // ecx

  survarium::weapon_user_dead_state::finalize(v2);
  s_bugtrap_usage = bugtrap_usage;
  s_error_mode_0 = error_mode;
}
