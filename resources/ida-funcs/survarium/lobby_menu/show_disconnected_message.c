void __thiscall survarium::lobby_menu::show_disconnected_message(survarium::lobby_menu *this, int b_show, char a3)
{
  const char *v3; // ecx

  v3 = "root.show_sync";
  if ( !a3 )
    v3 = "root.close_sync";
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(b_show + 1600) + 264) + 4),
    v3,
    0,
    0,
    0);
}
