void __usercall survarium::game_world_ui::clear_player(survarium::game_world_ui *this@<ecx>, int a2@<esi>)
{
  survarium::game_world_ui *v2; // ecx
  survarium::game_world_ui *v3; // ecx

  *(_BYTE *)(a2 + 493) = 0;
  survarium::game_world_ui::show_quick_slots(this, a2, 0);
  survarium::game_world_ui::show_oxygene(v2, a2, 0);
  survarium::game_world_ui::show_stamina(v3, a2, 0);
  memset(a2 + 500, 0, 0x50u);
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(a2 + 8) + 264) + 4),
    "root.reset_damage_indicator",
    0,
    0,
    0);
}
