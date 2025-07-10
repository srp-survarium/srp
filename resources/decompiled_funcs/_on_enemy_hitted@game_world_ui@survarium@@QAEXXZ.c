void __usercall survarium::game_world_ui::on_enemy_hitted(survarium::game_world_ui *this@<ecx>, int a2@<eax>)
{
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(a2 + 4) + 264) + 4),
    "root.crosshair_enemy_hit",
    0,
    0,
    0);
}
