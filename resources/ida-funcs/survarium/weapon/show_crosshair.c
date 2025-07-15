void __usercall survarium::weapon::show_crosshair(survarium::weapon *this@<ecx>, int a2@<eax>)
{
  survarium::game_world_ui *v2; // edx

  v2 = *(survarium::game_world_ui **)(a2 + 4024);
  if ( v2 )
    survarium::game_world_ui::show_crosshair(v2, 1);
}
