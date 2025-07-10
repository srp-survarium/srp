char __thiscall survarium::victory_items_container_core::use_execute(
        survarium::victory_items_container_core *this,
        survarium::usable_object_user_data *user)
{
  survarium::game_camera *v2; // ecx

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize(v2);
  return 1;
}
