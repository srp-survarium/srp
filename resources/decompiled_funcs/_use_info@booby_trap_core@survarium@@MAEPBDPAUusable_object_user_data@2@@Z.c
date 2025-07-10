const char *__thiscall survarium::booby_trap_core::use_info(
        survarium::booby_trap_core *this,
        survarium::usable_object_user_data *user)
{
  survarium::game_camera *v2; // ecx
  survarium::base_player *user_player; // [esp+Ch] [ebp-4h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  user_player = user->owner->cast_to_base_player(user->owner);
  survarium::weapon_user_dead_state::finalize(v2);
  if ( survarium::booby_trap_core::can_defuse((survarium::booby_trap_core *)((char *)this - 328), user_player) )
    return "st_defuse_trap";
  else
    return (const char *)&buf;
}
