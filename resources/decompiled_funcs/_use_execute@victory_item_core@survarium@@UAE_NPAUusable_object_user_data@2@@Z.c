char __thiscall survarium::victory_item_core::use_execute(
        survarium::victory_item_core *this,
        survarium::usable_object_user_data *user)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  return 1;
}
