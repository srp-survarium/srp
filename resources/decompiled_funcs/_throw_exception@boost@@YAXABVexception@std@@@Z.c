void __cdecl boost::throw_exception(survarium::game_camera *exception)
{
  survarium::game_camera *v1; // ecx
  survarium::game_camera *v2; // ecx
  _BYTE *v3; // eax

  survarium::weapon_user_dead_state::finalize(v1);
  if ( *v3 )
    survarium::weapon_user_dead_state::finalize(exception);
  survarium::weapon_user_dead_state::finalize(v2);
}
