void __usercall survarium::lobby_menu::switch_to_level_loading(survarium::lobby_menu *this@<ecx>, int a2@<esi>)
{
  survarium::lobby_menu::show_match_making(
    *(survarium::lobby_menu **)(*(_DWORD *)(a2 + 168) + 884),
    *(survarium::lobby_menu **)(*(_DWORD *)(a2 + 168) + 884),
    1);
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(a2 + 220) + 264) + 4),
    "root.switch_to_loading",
    0,
    0,
    0);
}
