void __thiscall survarium::weapon_core::process_finger_correction(
        survarium::weapon_core *this,
        unsigned int current_time_in_ms,
        survarium::game_camera *user_matrices)
{
  _BYTE *v3; // eax

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( *v3 )
    survarium::weapon_user_dead_state::finalize(user_matrices);
}
