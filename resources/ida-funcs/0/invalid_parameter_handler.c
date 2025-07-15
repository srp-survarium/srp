void __cdecl invalid_parameter_handler(survarium::game_camera *expression)
{
  survarium::game_camera *v1; // ecx
  survarium::game_camera *v2; // ecx
  _BYTE *v3; // eax

  survarium::weapon_user_dead_state::finalize(v1);
  if ( *v3 )
    survarium::weapon_user_dead_state::finalize(expression);
  handler_base(v2);
}
