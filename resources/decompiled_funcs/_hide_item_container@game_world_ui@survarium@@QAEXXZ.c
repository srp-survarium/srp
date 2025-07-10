void __usercall survarium::game_world_ui::hide_item_container(survarium::game_world_ui *this@<ecx>, int a2@<eax>)
{
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(a2 + 4) + 264) + 4),
    "root.hide_container_icon",
    0,
    0,
    0);
}
