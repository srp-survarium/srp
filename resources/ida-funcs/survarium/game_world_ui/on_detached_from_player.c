void __usercall survarium::game_world_ui::on_detached_from_player(
        survarium::game_world_ui *this@<ecx>,
        survarium::game_world_ui *a2@<eax>)
{
  survarium::game_world_ui *v3; // ecx

  survarium::game_world_ui::show_ammo_indicator(a2, 0);
  survarium::game_world_ui::show_quick_slots(v3, a2, 0);
}
